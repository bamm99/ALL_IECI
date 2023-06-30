//
// Created by benja on 29-06-2023.
//
#include <iostream>
#include <string>

using namespace std;

void verCursoBasicoLinux() {
    cout << "Curso básico de Linux" << endl;
    cout << "Comandos de gestión de archivos:" << endl;
    cout << "1. mkdir: Crear un directorio" << endl;
    cout << "2. rm: Eliminar archivos o directorios" << endl;
    cout << "3. cp: Copiar archivos o directorios" << endl;
    cout << "4. ls: Listar archivos y directorios" << endl;
    cout << "5. touch: Crear un archivo vacío" << endl;

    int opcion;
    cout << "Ingrese el número del comando que desea aprender: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "mkdir: El comando mkdir se utiliza para crear un directorio en Linux." << endl;
            cout << "Uso: mkdir nombre_directorio" << endl;
            cout << "Ejemplo: mkdir documentos" << endl;
            break;
        case 2:
            cout << "rm: El comando rm se utiliza para eliminar archivos y directorios en Linux." << endl;
            cout << "Uso: rm nombre_archivo" << endl;
            cout << "Ejemplo: rm archivo.txt" << endl;
            break;
        case 3:
            cout << "cp: El comando cp se utiliza para copiar archivos y directorios en Linux." << endl;
            cout << "Uso: cp origen destino" << endl;
            cout << "Ejemplo: cp archivo.txt carpeta/" << endl;
            break;
        case 4:
            cout << "ls: El comando ls se utiliza para listar los archivos y directorios en el directorio actual." << endl;
            cout << "Uso: ls" << endl;
            cout << "Ejemplo: ls" << endl;
            break;
        case 5:
            cout << "touch: El comando touch se utiliza para crear un archivo vacío en Linux." << endl;
            cout << "Uso: touch nombre_archivo" << endl;
            cout << "Ejemplo: touch archivo.txt" << endl;
            break;
        default:
            cout << "Opción inválida" << endl;
            break;
    }

    // Preguntar si le funcionó el comando y ofrecer posibles soluciones en caso de problemas
    string respuesta;
    cout << "¿Te funcionó el comando? (Sí/No): ";
    cin >> respuesta;

    if (respuesta == "No") {
        // Ofrecer posibles soluciones
        cout << "Posibles soluciones:" << endl;
        cout << "- Verificar que estás ejecutando el q con los permisos necesarios." << endl;
        cout << "- Verificar la sintaxis del comando.qdl;
        cout << "- Comprobar que el archivo o directoqste." << endl;

        // Preguntar nuevamente si le funcionó el comq
        cout << "¿Te funcionó el comando después de iq las soluciones? (Sí/No): ";
        cin >> respuesta;
    }

    // Aquí puedes continuar con la lógica de acuerdoqespuesta del usuario
}

void verCursoIntermedioLinux() {
    // Aquí puedes implementar la lógica para el cursqmedio de Linux
    cout << "Curso intermedio de Linux" << endl;
}

void verCursoAvanzadoLinux() {
    // Aquí puedes implementar la lógica para el curso avanzado de Linux
    cout << "Curso avanzado de Linux" << endl;
}
