#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> semestres = {
        {"Algebra 1", "Nociones de Computacion e Informatica", "Algoritmos y Bases de la Programacion", "Introduccion a la Ingenieria", "Comunicacion y Argumentacion"},
        {"Algebra 2", "Calculo 1", "Algoritmos y Programacion", "Estructuras Discretas para Ciencias de la Programacion"},
        {"Estadisticas y Probabilidades", "Calculo 2", "Estructura de Datos", "Administracion General", "Economia"},
        {"Arquitectura de Computadores", "Paradigmas de la Programacion", "Analisis de Algoritmos y Teoria de Automatas", "Ingles 1", "Practica Profesional 1"},
        {"Metodologia de Desarrollo", "Base de Datos", "Sistemas de Informacion", "Sistemas Financieros y Contables", "Ingles 2"},
        {"Inteligencia Artificial", "Sistemas Operativos", "Ingenieria de Software", "Formulacion y Evaluacion de Proyectos", "Ingles 3", "Electivos de Especialidad"},
        {"Electivos de Especialidad", "Comunicacion de Datos y Redes", "Taller de Desarrollo", "Gestion Empresarial", "Ingles 4"},
        {"Electivos de Especialidad", "Proyecto Final de Carrera"}
};

vector<vector<string>> asig_docs = {
        {"documento 1", "documento 2", "documento 3"}
};

vector<vector<string>> asig_libs = {
        {"libro 1", "libro 2", "libro 3"}
};

vector<vector<string>> asig_extras = {
        {"extra 1", "extra 2", "extra 3"}
};

void verAsignatura(int semestre) {
    if (semestre < 1 || semestre > 8) {
        cout << "Semestre invalido" << endl;
    } else {
        cout << "Asignaturas del semestre " << semestre << ":" << endl;
        for (int i = 0; i < semestres[semestre - 1].size(); i++) {
            cout << i + 1 << ". " << semestres[semestre - 1][i] << endl;
        }
        int asignatura;
        cout << "Ingrese el numero de la asignatura que desea visualizar (1-" << semestres[semestre - 1].size() << "): ";
        cin >> asignatura;
        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "Biblioteca de la asignatura " << asignatura << ":" << endl;
        cout << endl;
        cout << "Documentos: " << endl;
        int contador = 1;
        for (int i = 0; i < asig_docs[0].size(); i++) {
            cout << "   " << contador << ". " << asig_docs[0][i] << endl;
            contador++;
        }
        cout << "Libros: " << endl;
        for (int i = 0; i < asig_libs[0].size(); i++) {
            cout << "   " << contador << ". " << asig_libs[0][i] << endl;
            contador++;
        }
        cout << "Extras:" << endl;
        for (int i = 0; i < asig_extras[0].size(); i++) {
            cout << "   " << contador << ". " << asig_extras[0][i] << endl;
            contador++;
        }
        cout << endl;
        cout << "----------------------------------------" << endl;
        int opcion;
        cout << "Ingrese el numero del archivo/link que desea revisar: ";
        cin >> opcion;

        // Aquí puedes implementar la lógica para preguntar al usuario si le funcionó o no,
        // y ofrecer posibles soluciones en caso de problemas.
    }
}
