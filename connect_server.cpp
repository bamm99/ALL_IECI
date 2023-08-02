#include <iostream>
#include <string>
#include <curl/curl.h>

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

void listar(std::string ftp_url) {
    // Usuario y contraseña (si es necesario)
    std::string username = "benja";
    std::string password = "5426";

    std::string listing;

    if (GetFtpListing(ftp_url, username, password, listing)) {
        // Imprimir el listado de archivos (solo los nombres)
        std::cout << "Listado de archivos:\n" << listing << std::endl;
    }
}
