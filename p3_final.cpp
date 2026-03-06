#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Proyecto {
    int id;
    char titulo[40];
    double presupuesto;
    int duracionMeses;
};
int main() {
    fstream f("proyectos.dat", ios::in | ios::out | ios::binary);
    if (!f) {
        f.open("proyectos.dat", ios::out | ios::binary);
        f.close();
        f.open("proyectos.dat", ios::in | ios::out | ios::binary);
    }
    Proyecto nuevo;
    cout << "ingrese nuevo proyecto\n";
    cout << "ID: ";
    cin >> nuevo.id;
    cout << "titulo: ";
    cin.ignore();
    cin.getline(nuevo.titulo, 40);
    cout << "presupuesto: ";
    cin >> nuevo.presupuesto;
    cout << "duracion en meses: ";
    cin >> nuevo.duracionMeses;
    Proyecto temp;
    f.seekg(0);
    while (f.read((char*)&temp, sizeof(Proyecto))) {
        if (temp.id==nuevo.id) {
            cout << "error: ID repetido\n";
            f.close();
            return 0;
        }
    }
    f.clear();
    f.seekg(0);
    int n = 0;
    while (f.read((char*)&temp, sizeof(Proyecto))) {
        n++;
    }
    //creo el arreglo temporal
    Proyecto* lista = new Proyecto[n + 1];
    f.clear();
    f.seekg(0);
    for (int i = 0; i < n; i++) {
        f.read((char*)&lista[i], sizeof(Proyecto));
    }
    int pos = n;
    for (int i = 0; i < n; i++) {
        if (nuevo.presupuesto > lista[i].presupuesto) {
            pos = i;
            break;
        }
    }
    for (int i = n; i > pos; i--) {
        lista[i] = lista[i - 1];
    }
    lista[pos] = nuevo;
    n++;
    //ahora para reescribir el archivo
    f.close();
    f.open("proyectos.dat", ios::out | ios::binary);
    for (int i = 0; i < n; i++) {
        f.write((char*)&lista[i], sizeof(Proyecto));
    }
    f.close();
    f.open("proyectos.dat", ios::in | ios::binary);
    cout << "\nProyectos\n";
    while (f.read((char*)&temp, sizeof(Proyecto))) {
        cout << "ID: " << temp.id << endl;
        cout << "Titulo: " << temp.titulo << endl;
        cout << "Presupuesto: " << temp.presupuesto << endl;
        cout << "Duracion: " << temp.duracionMeses << " meses\n";
    }
    f.close();
    delete[] lista;
    return 0;
}