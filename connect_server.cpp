#include <iostream>
#include <string>
#include <curl/curl.h>
#include <fstream> // Librería para trabajar con archivos
#include <unistd.h> // Librería para obtener directorio de descargas en Linux

using namespace std;

// Estructura para almacenar la información de la respuesta del servidor FTP
struct FtpResponse {
    std::string url;
    std::string listing;
};

// Función de escritura para recibir los datos del listado de archivos
size_t WriteCallback(void* contents, size_t size, size_t nmemb, FtpResponse* output) {
    size_t total_size = size * nmemb;
    output->listing.append(static_cast<char*>(contents), total_size);
    return total_size;
}

// Función para obtener la lista de archivos
bool GetFtpListing(const std::string& ftp_url, const std::string& username, const std::string& password, std::string& listing) {
    // Inicializar libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Crear un objeto CURL
    CURL* curl = curl_easy_init();

    if (curl) {
        FtpResponse response;
        response.url = ftp_url;

        // Configurar la URL del servidor FTP
        curl_easy_setopt(curl, CURLOPT_URL, response.url.c_str());

        // Si requiere autenticación, proporcionar usuario y contraseña
        if (!username.empty() && !password.empty()) {
            std::string credentials = username + ":" + password;
            curl_easy_setopt(curl, CURLOPT_USERPWD, credentials.c_str());
        }

        // Configurar la función de escritura para recibir los datos del listado de archivos
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Realizar la solicitud
        CURLcode res = curl_easy_perform(curl);

        // Comprobar si la solicitud fue exitosa
        if (res == CURLE_OK) {
            // Extraer solo los nombres de los directorios del resultado
            size_t start_pos = 0;
            size_t end_pos = 0;
            int file_count = 0; // Contador de archivos
            while (true) {
                end_pos = response.listing.find('\n', start_pos);
                if (end_pos == std::string::npos)
                    break;
                std::string file_line = response.listing.substr(start_pos, end_pos - start_pos);
                size_t file_name_start = file_line.find_last_of(' ');
                if (file_name_start != std::string::npos) {
                    std::string file_name = file_line.substr(file_name_start + 1);
                    if (!file_name.empty() && file_name != "." && file_name != "..") {
                        file_count++;
                        listing += std::to_string(file_count) + ". " + file_name + "\n"; // Mostrar el número del archivo
                    }
                }
                start_pos = end_pos + 1;
            }
        } else {
            // Mostrar el error en caso de que falle la solicitud
            std::cerr << "Error al obtener el listado de archivos: " << curl_easy_strerror(res) << std::endl;
        }

        // Limpiar y cerrar la conexión
        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Error al inicializar libcurl." << std::endl;
    }

    // Finalizar libcurl
    curl_global_cleanup();

    return true;
}

// Modificar la firma de la función DownloadFile para que reciba un puntero a ofstream
bool DownloadFile(const std::string& file_url, std::ofstream* fp) {
    // Inicializar libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Crear un objeto CURL
    CURL* curl = curl_easy_init();

    if (curl) {
        // Configurar la URL del archivo a descargar
        curl_easy_setopt(curl, CURLOPT_URL, file_url.c_str());

        // Configurar la función de escritura para recibir los datos del archivo
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](void* contents, size_t size, size_t nmemb, std::ofstream* fp) {
            // Escribir los datos recibidos en el ofstream
            return fp->write(static_cast<char*>(contents), size * nmemb);
        });

        // Configurar el ofstream como el parámetro para la función de escritura
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        // Realizar la solicitud
        CURLcode res = curl_easy_perform(curl);

        // Limpiar y cerrar la conexión
        curl_easy_cleanup(curl);

        // Comprobar si la descarga fue exitosa
        if (res == CURLE_OK) {
            return true;
        } else {
            std::cerr << "Error al descargar el archivo: " << curl_easy_strerror(res) << std::endl;
        }
    } else {
        std::cerr << "Error al inicializar libcurl." << std::endl;
    }

    // Finalizar libcurl
    curl_global_cleanup();

    return false;
}

void descargarArchivo(std::string ftp_url, int opcion) {
    std::string username = "benja";
    std::string password = "5426";

    std::string listing;
    if (GetFtpListing(ftp_url, username, password, listing)) {
        std::cout << "Listado de archivos:\n" << listing << std::endl;

        std::string file_to_download;
        size_t start_pos = listing.find(std::to_string(opcion) + ".");
        if (start_pos != std::string::npos) {
            start_pos = listing.find(' ', start_pos);
            size_t end_pos = listing.find('\n', start_pos);
            if (end_pos != std::string::npos) {
                file_to_download = listing.substr(start_pos + 1, end_pos - start_pos - 1);
                std::cout << "Descargando archivo: " << file_to_download << std::endl;

                std::string download_dir = getenv("HOME");
                std::ofstream outfile(download_dir + "/descargas/" + file_to_download, std::ofstream::binary); // Abrir el archivo en modo binario
                if (outfile.is_open()) {
                    std::string file_url = ftp_url + file_to_download;
                    if (DownloadFile(file_url, &outfile)) {
                        std::cout << "Archivo descargado exitosamente." << std::endl;
                    } else {
                        std::cerr << "Error al descargar el archivo." << std::endl;
                    }
                    outfile.close(); // Cerrar el archivo después de la descarga
                } else {
                    std::cerr << "Error al abrir el archivo para escribir." << std::endl;
                }
            } else {
                std::cerr << "Opción inválida." << std::endl;
            }
        } else {
            std::cerr << "Opción inválida." << std::endl;
        }
    }
}

void listar(std::string ftp_url) {
    std::string username = "benja";
    std::string password = "5426";

    std::string listing;
    if (GetFtpListing(ftp_url, username, password, listing)) {
        std::cout << "Listado de archivos:\n" << listing << std::endl;

        int opcion;
        std::cout << "Ingrese el número del archivo que desea descargar: ";
        std::cin >> opcion;

        descargarArchivo(ftp_url, opcion);
    }
}

