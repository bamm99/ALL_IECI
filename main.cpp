#include <iostream>

using namespace std;

// Declaración de las funciones externas en los archivos separados
extern void verAsignatura(int semestre);
extern void verTodasAsignaturas();
extern void verCursoLinux();

int main() {
    int opcion;

    cout << "----------------------------------------" << endl;
    cout << "Bienvenido a ALL_IECI" << endl;
    cout << "Software creado por Benjamin Mosso" << endl;
    cout << "Estudiante de Ingenieria de Ejecucion en computacion e informatica" << endl;
    cout << "Universidad Del Bio-Bio" << endl;

    do {
        cout << "----------------------------------------" << endl;
        cout << "               Menu" << endl;
        cout << "1. Ver asignatura de un semestre" << endl;
        cout << "2. Ver todas las asignaturas" << endl;
        cout << "3. Ver curso de autoaprendizaje Linux" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1: {
                int semestre;
                cout << "Ingrese el semestre que desea visualizar (1-8): ";
                cin >> semestre;
                cout << endl;

                verAsignatura(semestre);
                break;
            }
            case 2:
                verTodasAsignaturas();
                break;
            case 3:
                verCursoLinux();
                break;
            case 0:
                cout << "Gracias por usar el programa" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}