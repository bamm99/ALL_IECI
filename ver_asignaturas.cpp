#include <iostream>
#include <vector>
#include <string>
#include <fstream> // Librería para trabajar con archivos

using namespace std;
extern void listar(std::string ftp_url);
extern bool DownloadFile(const std::string& url, std::ofstream* outfile); // Incluir la declaración de DownloadFile

vector<vector<string>> semestre = {
        {"Algebra 1", "Nociones de Computacion e Informatica", "Algoritmos y Bases de la Programacion", "Introduccion a la Ingenieria", "Comunicacion y Argumentacion"},
        {"Algebra 2", "Calculo 1", "Algoritmos y Programacion", "Estructuras Discretas para Ciencias de la Programacion"},
        {"Estadisticas y Probabilidades", "Calculo 2", "Estructura de Datos", "Administracion General", "Economia"},
        {"Arquitectura de Computadores", "Paradigmas de la Programacion", "Analisis de Algoritmos y Teoria de Automatas", "Ingles 1", "Practica Profesional 1"},
        {"Metodologia de Desarrollo", "Base de Datos", "Sistemas de Informacion", "Sistemas Financieros y Contables", "Ingles 2"},
        {"Inteligencia Artificial", "Sistemas Operativos", "Ingenieria de Software", "Formulacion y Evaluacion de Proyectos", "Ingles 3", "Electivos de Especialidad"},
        {"Electivos de Especialidad", "Comunicacion de Datos y Redes", "Taller de Desarrollo", "Gestion Empresarial", "Ingles 4"},
        {"Electivos de Especialidad", "Proyecto Final de Carrera"}
};

void verAsignatura(int semestre2) {
    if (semestre2 < 1 || semestre2 > 8) {
        cout << "Semestre invalido" << endl;
    } else {
        cout << "Asignaturas del semestre " << semestre2 << ":" << endl;
        for (int i = 0; i < semestre[semestre2 - 1].size(); i++) {
            cout << i + 1 << ". " << semestre[semestre2 - 1][i] << endl;
        }

        std::string sem = "semestre";
        std::string semftp = sem + std::to_string(semestre2);

        int asignatura;
        cout << "Ingrese el numero de la asignatura que desea visualizar (1-" << semestre[semestre2 - 1].size() << "): ";
        cin >> asignatura;

        std::string asig = "asignatura";
        std::string asigftp = asig + std::to_string(asignatura);
        std::string ftpurl = "ftp://192.168.1.117:21/" +semftp + "/" +asigftp +"/";

        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "Biblioteca de la asignatura " << asignatura << ":" << endl;
        cout << endl;

        listar(ftpurl);

        cout << endl;
        cout << "----------------------------------------" << endl;
        int opcion;
        cout << "Ingrese el numero del archivo/link que desea descargar: ";
        cin >> opcion;

        // Verificar si el número de archivo seleccionado es válido
        if (opcion >= 1 && opcion <= semestre[semestre2 - 1].size()) {
            // Obtener el nombre del archivo seleccionado
            std::string file_to_download = semestre[semestre2 - 1][opcion - 1];

            // Modificar el nombre del archivo para que sea compatible con el sistema de archivos de Linux
            for (char& c : file_to_download) {
                if (c == ' ' || c == '/') {
                    c = '_';
                }
            }

            // Obtener el directorio "Descargas" en Linux
            std::string home_dir = getenv("HOME");
            std::string downloads_dir = home_dir + "/Descargas/";

            // Construir la URL completa del archivo a descargar
            std::string file_url = ftpurl + file_to_download;

            // Crear un objeto ofstream para escribir el archivo local
            std::ofstream outfile(downloads_dir + file_to_download, std::ofstream::binary);

            if (outfile) {
                // Descargar el archivo
                if (DownloadFile(file_url, &outfile)) {
                    cout << "Descarga completada. El archivo se encuentra en: " << downloads_dir << file_to_download << endl;
                } else {
                    cout << "No se pudo descargar el archivo." << endl;
                }
            } else {
                cout << "No se pudo crear el archivo local." << endl;
            }
        } else {
            cout << "Opción inválida. El número de archivo seleccionado no es válido." << endl;
        }
    }
}