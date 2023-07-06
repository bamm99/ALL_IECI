//
// Created by benja on 29-06-2023.
//
#include <iostream>
#include <string>

using namespace std;

void funciona () {
    // Preguntar si le funcionó el comando y ofrecer posibles soluciones en caso de problemas
    string respuesta;
    cout << "¿Te funcionó el comando? (Sí/No): ";
    cin >> respuesta;

    if (respuesta == "No") {
        // Ofrecer posibles soluciones
        cout << "Posibles soluciones:" << endl;
        cout << "- Verificar que estás ejecutando el comando con los permisos necesarios." << endl;
        cout << "- Verificar la sintaxis del comando." << endl;
        cout << "- Comprobar que el archivo o directorio." << endl;

        // Preguntar nuevamente si le funcionó el comq
        cout << "¿Te funcionó el comando después de las soluciones? (Sí/No): ";
        cin >> respuesta;
        cout << "aparece chat bot aqui magicamente" << endl;

    }
}

void verCursoBasicoLinux() {
            cout << "----------------------------------------" << endl;
            cout << "Curso Básico de Linux" << endl;
            cout << "En este curso aprenderás los comandos básicos de Linux." << endl;
            cout << "Principalmente, aprenderás a crear, editar y eliminar archivos y directorios." << endl;
            cout << "También aprenderás a navegar entre directorios y a ver el contenido de un archivo." << endl;
            cout << "----------------------------------------" << endl;
            std::cout << "Presiona la tecla Enter para continuar..." << std::endl;
            std::cin.ignore(); // Ignorar cualquier entrada previa
            std::cin.get();    // Esperar hasta que se presione Enter
            cout << "----------------------------------------" << endl;
            cout << "mkdir: El comando mkdir se utiliza para crear un directorio en Linux." << endl;
            cout << "Uso: mkdir nombre_directorio" << endl;
            cout << "Ejemplo: mkdir documentos" << endl;
            funciona();
            cout << "cd: El comando cd se utiliza para cambiar de directorio en Linux." << endl;
            cout << "Uso: cd nombre_directorio" << endl;
            cout << "Ejemplo: cd documentos" << endl;
            funciona();
            cout << "pwd: El comando pwd se utiliza para mostrar el directorio de trabajo actual." << endl;
            cout << "Uso: pwd" << endl;
            cout << "Ejemplo: pwd" << endl;
            funciona();
            cout << "touch: El comando touch se utiliza para crear un archivo vacío en Linux." << endl;
            cout << "Uso: touch nombre_archivo" << endl;
            cout << "Ejemplo: touch archivo.txt" << endl;
            funciona();
            cout << "nano: El comando nano se utiliza para editar archivos de texto en Linux." << endl;
            cout << "Uso: nano nombre_archivo" << endl;
            cout << "Ejemplo: nano archivo.txt" << endl;
            cout << "Para guardar los cambios presione Ctrl + O y luego Ctrl + X para salir." << endl;
            funciona();
            cout << "cat: El comando cat se utiliza para mostrar el contenido de un archivo en Linux." << endl;
            cout << "Uso: cat nombre_archivo" << endl;
            cout << "Ejemplo: cat archivo.txt" << endl;
            funciona();
            cout << "grep: El comando grep se utiliza para buscar texto en un archivo en Linux." << endl;
            cout << "Uso: grep texto_a_buscar nombre_archivo" << endl;
            cout << "Ejemplo: grep hola archivo.txt" << endl;
            funciona();
            cout << "less: El comando less se utiliza para mostrar el contenido de un archivo en Linux." << endl;
            cout << "Uso: less nombre_archivo" << endl;
            cout << "Ejemplo: less archivo.txt" << endl;
            funciona();
            cout << "head: El comando head se utiliza para mostrar las primeras líneas de un archivo en Linux." << endl;
            cout << "Uso: head nombre_archivo" << endl;
            cout << "Ejemplo: head archivo.txt" << endl;
            funciona();
            cout << "tail: El comando tail se utiliza para mostrar las últimas líneas de un archivo en Linux." << endl;
            cout << "Uso: tail nombre_archivo" << endl;
            cout << "Ejemplo: tail archivo.txt" << endl;
            funciona();
            cout << "wc: El comando wc se utiliza para contar líneas, palabras y caracteres en un archivo en Linux." << endl;
            cout << "Uso: wc nombre_archivo" << endl;
            cout << "Ejemplo: wc archivo.txt" << endl;
            funciona();
            cout << "sort: El comando sort se utiliza para ordenar las líneas de un archivo en Linux." << endl;
            cout << "Uso: sort nombre_archivo" << endl;
            cout << "Ejemplo: sort archivo.txt" << endl;
            funciona();
            cout << "uniq: El comando uniq se utiliza para eliminar líneas duplicadas de un archivo en Linux." << endl;
            cout << "Uso: uniq nombre_archivo" << endl;
            cout << "Ejemplo: uniq archivo.txt" << endl;
            funciona();
            cout << "mv: El comando mv se utiliza para mover archivos y directorios en Linux." << endl;
            cout << "Uso: mv origen destino" << endl;
            cout << "Ejemplo: mv archivo.txt documentos/" << endl;
            funciona();
            cout << "ls: El comando ls se utiliza para listar los archivos y directorios en el directorio actual." << endl;
            cout << "Uso: ls" << endl;
            cout << "Ejemplo: ls" << endl;
            funciona();
            cout << "cp: El comando cp se utiliza para copiar archivos y directorios en Linux." << endl;
            cout << "Uso: cp origen destino" << endl;
            cout << "Ejemplo: para este ejemplo primero usaremos el comando 'mkdir carpeta' \ny luego usaremos 'cp archivo.txt carpeta/'" << endl;
            funciona();
            cout << "rm: El comando rm se utiliza para eliminar archivos y directorios en Linux." << endl;
            cout << "Uso: rm nombre_archivo" << endl;
            cout << "Ejemplo: rm archivo.txt" << endl;
            funciona();
}

void verCursoIntermedioLinux() {
    cout << "Curso intermedio de Linux" << endl;
    cout << "En este curso aprenderás a utilizar los compiladores de codigo mas comunes de Linux." << endl;
    cout << "Principalmente, aprenderás a compilar y ejecutar programas en C ,C++, Java y python." << endl;
    while (int resp = 0){
        cout << "----------------------------------------" << endl;
        cout << "       compiladores " << endl;
        cout << " 1.- C " << endl;
        cout << " 2.- C++ " << endl;
        cout << " 3.- Java " << endl;
        cout << " 4.- Python " << endl;
        cout << " 0.- Salir " << endl;
        cout << "Ingresa una opción: ";
        cin >> resp;

        switch (resp) {
            case 1:
                cout << "Compilador de C" << endl;
                cout << "Para compilar un programa en C, primero debes tener instalado el compilador gcc." << endl;
                cout << "Para instalarlo, debes ejecutar el siguiente comando en la terminal: sudo apt-get install gcc" << endl;
                cout << "Para compilar un programa en C, debes ejecutar el siguiente comando en la terminal: gcc nombre_programa.c -o nombre_programa" << endl;
                cout << "Para ejecutar un programa en C, debes ejecutar el siguiente comando en la terminal: ./nombre_programa" << endl;
                funciona();
                break;
            case 2:
                cout << "Compilador de C++" << endl;
                cout << "Para compilar un programa en C++, primero debes tener instalado el compilador g++." << endl;
                cout << "Para instalarlo, debes ejecutar el siguiente comando en la terminal: sudo apt-get install g++" << endl;
                cout << "Para compilar un programa en C++, debes ejecutar el siguiente comando en la terminal: g++ nombre_programa.cpp -o nombre_programa" << endl;
                cout << "Para ejecutar un programa en C++, debes ejecutar el siguiente comando en la terminal: ./nombre_programa" << endl;
                funciona();
                break;
            case 3:
                cout << "Compilador de Java" << endl;
                cout << "Para compilar un programa en Java, primero debes tener instalado el compilador javac." << endl;
                cout << "Para instalarlo, debes ejecutar el siguiente comando en la terminal: sudo apt-get install javac" << endl;
                cout << "Para compilar un programa en Java, debes ejecutar el siguiente comando en la terminal: javac nombre_programa.java" << endl;
                cout << "Para ejecutar un programa en Java, debes ejecutar el siguiente comando en la terminal: java nombre_programa" << endl;
                funciona();
                break;
            case 4:
                cout << "Compilador de Python" << endl;
                cout << "Para compilar un programa en Python, primero debes tener instalado el compilador python." << endl;
                cout << "Para instalarlo, debes ejecutar el siguiente comando en la terminal: sudo apt-get install python" << endl;
                cout << "Para ejecutar un programa en Python, debes ejecutar el siguiente comando en la terminal: python nombre_programa.py" << endl;
                funciona();
                break;
            case 0:
                resp = 0;
                cout << "Saliendo..." << endl;
                break;
        }
    }
}

void verCursoAvanzadoLinux() {
    cout << "Curso avanzado de Linux" << endl;
    cout << "En este curso aprenderás a montar el entorno de desarrollo para el stack MERN para desarrollo web." << endl;
    cout << "Principalmente, aprenderás a instalar NodeJS, MongoDB y ExpressJS." << endl;
    cout << "También aprenderás a utilizar el manejador de paquetes npm." << endl;
    cout << "Por último, aprenderás a utilizar el manejador de versiones git." << endl;
    cout << "Para instalar NodeJS, debes ejecutar el siguiente comando en la terminal: sudo apt-get install nodejs" << endl;
    cout << "Para instalar MongoDB, debes ejecutar el siguiente comando en la terminal: sudo apt-get install mongodb" << endl;
    cout << "Para instalar ExpressJS, debes ejecutar el siguiente comando en la terminal: sudo apt-get install express" << endl;
    cout << "Para instalar npm, debes ejecutar el siguiente comando en la terminal: sudo apt-get install npm" << endl;
    cout << "Para instalar git, debes ejecutar el siguiente comando en la terminal: sudo apt-get install git" << endl;
    funciona();
    cout << "Para crear un proyecto de NodeJS, debes ejecutar el siguiente comando en la terminal: npm init" << endl;
    cout << "Para instalar un paquete de NodeJS, debes ejecutar el siguiente comando en la terminal: npm install nombre_paquete" << endl;
    cout << "Para instalar un paquete de NodeJS de forma global, debes ejecutar el siguiente comando en la terminal: npm install -g nombre_paquete" << endl;
    cout << "Para instalar un paquete de NodeJS de forma dev, debes ejecutar el siguiente comando en la terminal: npm install --save-dev nombre_paquete" << endl;


    funciona();
    cout << "Para crear un repositorio de git, debes ejecutar el siguiente comando en la terminal: git init" << endl;
    cout << "Para agregar un archivo al repositorio de git, debes ejecutar el siguiente comando en la terminal: git add nombre_archivo" << endl;
    cout << "Para agregar todos los archivos al repositorio de git, debes ejecutar el siguiente comando en la terminal: git add ." << endl;
    cout << "Para agregar un commit al repositorio de git, debes ejecutar el siguiente comando en la terminal: git commit -m 'mensaje'" << endl;
    cout << "Para agregar un repositorio remoto de git, debes ejecutar el siguiente comando en la terminal: git remote add origin url_repositorio" << endl;
    cout << "Para subir los cambios al repositorio remoto de git, debes ejecutar el siguiente comando en la terminal: git push -u origin master" << endl;
    funciona();
    cout << "Para clonar un repositorio de git, debes ejecutar el siguiente comando en la terminal: git clone url_repositorio" << endl;
    cout << "Para actualizar un repositorio de git, debes ejecutar el siguiente comando en la terminal: git pull" << endl;
    cout << "Para ver el estado de un repositorio de git, debes ejecutar el siguiente comando en la terminal: git status" << endl;
    cout << "Para ver el historial de un repositorio de git, debes ejecutar el siguiente comando en la terminal: git log" << endl;
    cout << "Para ver el historial de un repositorio de git de forma gráfica, debes ejecutar el siguiente comando en la terminal: git log --graph" << endl;
    funciona();
    cout << "Para crear una rama en un repositorio de git, debes ejecutar el siguiente comando en la terminal: git branch nombre_rama" << endl;
    cout << "Para cambiar de rama en un repositorio de git, debes ejecutar el siguiente comando en la terminal: git checkout nombre_rama" << endl;
    cout << "Para fusionar una rama en un repositorio de git, debes ejecutar el siguiente comando en la terminal: git merge nombre_rama" << endl;
    cout << "Para borrar una rama en un repositorio de git, debes ejecutar el siguiente comando en la terminal: git branch -d nombre_rama" << endl;
    funciona();

}

