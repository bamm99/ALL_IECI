#include <iostream>
#include <vector>
#include <string>
#include "config.h"

using namespace std;
extern void listar(std::string ftp_url);

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
        std::string ftpurl = "ftp://"+config::ftp_IP +":" + config::ftp_port +"/" +semftp + "/" +asigftp +"/";


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

    }
}