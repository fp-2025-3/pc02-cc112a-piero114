#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    ifstream archivo("notas.txt");
    ofstream reporte("reporteAlumnos.txt");

    if(!archivo){
        cout<<"error al abrir notas.txt"<<endl;
        return 1;
    }
    if(!reporte){
        cout<<"error al generar el reporte"<<endl;
        return 1;
    }

    int codigo;
    string nombre;
    double n1,n2,n3,promedio;

    int totalEstudiantes = 0;
    double sumaPromedios = 0;

    double maxProm = -1;
    double minProm = 21;

    string nombreMax, nombreMin;

    while(archivo>>codigo>>nombre>>n1>>n2>>n3){
        promedio = (n1+n2+n3)/3.0;
        string condicion;
        //para los jalados segun la regla academica:
        if(n1 < 5|n2 < 5|n3 < 5){
            condicion = "DESAPROBADO POR REGLA ACADEMICA";
        }
        //para los jalados:
        else if(promedio >= 10){
            condicion = "APROBADO";
        }
        //para los desaprobados(fuera de la condicion de regla academica):
        else{
            condicion = "DESAPROBADO";
        }
        reporte << codigo << " "
                << nombre << " "
                << promedio << " "
                << condicion << endl;
        // ahora para las estadisticas:
        totalEstudiantes++;
        sumaPromedios += promedio;
        if(promedio > maxProm){
            maxProm = promedio;
            nombreMax = nombre;
        }
        if(promedio < minProm){
            minProm = promedio;
            nombreMin = nombre;
        }
    }
    double promedioGeneral = 0;
    if(totalEstudiantes > 0)
        promedioGeneral = sumaPromedios / totalEstudiantes;
    reporte << "\n---------------------------\n";
    reporte << "Total estudiantes: " << totalEstudiantes << endl;
    reporte << "Promedio general: " << promedioGeneral << endl;
    reporte << "Mayor promedio: " << nombreMax << " (" << maxProm << ")" << endl;
    reporte << "Menor promedio: " << nombreMin << " (" << minProm << ")" << endl;
    archivo.close();
    reporte.close();
    //añadire esta parte para que en la salida de la consola salga el contenido del archivo de texto
    ifstream mostrar("reporteAlumnos.txt");
    if(!mostrar){
        cout<<"Error al abrir el reporte para mostrar"<<endl;
        return 1;
    }

    string linea;
    while(getline(mostrar, linea)){
        cout<<linea<<endl;
    }
    mostrar.close();
    return 0;
}