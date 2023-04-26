#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<vector<string > > semestres = {
            {"Algebra 1", "Nociones de Computacion e Informatica", "Algoritmos y Bases de la Programacion", "Introduccion a la Ingenieria", "Comunicacion y Argumentacion"},
            {"Algebra 2", "Calculo 1", "Algoritmos y Programacion", "Estructuras Discretas para Ciencias de la Programacion"},
            {"Estadisticas y Probabilidades", "Calculo 2", "Estructura de Datos", "Administracion General", "Economia"},
            {"Arquitectura de Computadores", "Paradigmas de la Programacion", "Analisis de Algoritmos y Teoria de Automatas", "Ingles 1", "Practica Profesional 1"},
            {"Metodologia de Desarrollo", "Base de Datos", "Sistemas de Informacion", "Sistemas Financieros y Contables", "Ingles 2"},
            {"Inteligencia Artificial", "Sistemas Operativos", "Ingenieria de Software", "Formulacion y Evaluacion de Proyectos", "Ingles 3", "Electivos de Especialidad"},
            {"Electivos de Especialidad", "Comunicacion de Datos y Redes", "Taller de Desarrollo", "Gestion Empresarial", "Ingles 4"},
            {"Electivos de Especialidad", "Proyecto Final de Carrera"}
    };
    vector<vector<string> > asig_docs ={
            {"documento 1", "documento 2", "documento 3"}
    };
    vector<vector<string>> asig_libs ={
            {"libro 1", "libro 2", "libro 3"}
    };
    vector<vector<string>> asig_extras ={
            {"extra 1", "extra 2", "extra 3"}
    };
    int opcion;
    cout << "----------------------------------------" << endl;
    cout << "Bienvenido a ALL_IECI" << endl;
    cout << "Software creado por Benjamin Mosso" << endl;
    cout << "Estudiante de Ingenieria de Ejecucion en computacion e informatica" << endl;
    cout << "Universidad Del Bio-Bio" << endl;

    do {
        cout << "----------------------------------------" << endl;
        cout << "               Menu" << endl;
        cout << "1. ver asignatura de un semestre" << endl;
        cout << "2. Ver todas las asignaturas" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;

        if (opcion == 1) {
            int sem;
            cout << "Ingrese el semestre que desea visualizar (1-8): ";
            cin >> sem;
            cout << endl;

            if (sem < 1 || sem > 8) {
                cout << "Semestre invalido" << endl;
            } else {
                cout << "Asignaturas del semestre " << sem << ":" << endl;
                for (int i = 0; i < semestres[sem-1].size(); i++) {
                    cout << i+1 << ". " << semestres[sem-1][i] << endl;
                }
                int asig;
                cout << "Ingrese el numero de la asignatura que desea visualizar (1-" << semestres[sem-1].size() << "): "<< flush;
                cin >> asig;
                cout << endl;
                cout << "----------------------------------------" << endl;
                cout << "Biblioteca de la asignatura " << asig << ":" << endl;
                cout << endl;
                cout << "Documentos: " << endl;
                int cont = 1;
                for (int i = 0; i < asig_docs[0].size(); ++i) {
                    cout << "   " << cont << ". " << asig_docs[0][i] << endl;
                    cont++;
                }
                cout << "Libros: " << endl;
                for (int i = 0; i < asig_libs[0].size(); ++i) {
                    cout << "   " << cont << ". " << asig_libs[0][i] << endl;
                    cont++;
                }
                cout << "Extras:" << endl;
                for (int i = 0; i < asig_extras[0].size(); ++i) {
                    cout << "   " << cont << ". " << asig_extras[0][i] << endl;
                    cont++;
                }
                cout << endl;
                cout << "----------------------------------------" << endl;
                int opt;
                cout << "ingrese el numero del archivo/link que desea revizar:";
                cin >> opt;
            }
        }else if (opcion == 2 ) {
            cout << "Asignaturas por semestre:" << endl;
            for (int sem = 0; sem < semestres.size(); sem++) {
                cout << "Semestre " << sem + 1 << ":" << endl;
                for (int i = 0; i < semestres[sem].size(); i++) {
                    cout << i + 1 << ". " << semestres[sem][i] << endl;
                }
                cout << endl;
            }
        }else if (opcion != 0) {
            cout << "Opcion invalida" << endl;
        }
    } while (opcion != 0);
    cout << "Gracias por usar el programa" << endl;
    return 0;
}
