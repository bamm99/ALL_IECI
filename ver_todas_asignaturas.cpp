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

void verTodasAsignaturas() {
    cout << "Asignaturas por semestre:" << endl;
    for (int semestre = 0; semestre < semestres.size(); semestre++) {
        cout << "Semestre " << semestre + 1 << ":" << endl;
        for (int i = 0; i < semestres[semestre].size(); i++) {
            cout << i + 1 << ". " << semestres[semestre][i] << endl;
        }
        cout << endl;
    }
}
