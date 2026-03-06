#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
//estructura para guardar los datos de los paises
struct Seleccion{
    char nombre[20];
    int PG, PE, PP; 
    int GF, GC;
    int DG;
    int puntos;
    double rend;
};

//esta funciopn para generar los goles segun los resultados
void generarEstadisticas(Seleccion &x){

    x.GF = 0;
    x.GC = 0;

    //para los partidos ganados
    for(int i=0; i<x.PG; i++){
        int gf = rand()%5 + 1;  //aqui tiene q marcar almenos 1
        int gc = rand()%gf;     //aqui recibe menos goles de los q marcara
        x.GF += gf;
        x.GC += gc;
    }

    //para los partidos empatados
    for(int i=0; i<x.PE; i++){
        int g = rand()%5;
        x.GF += g;
        x.GC += g;
    }

    //para los partidos perdidos
    for(int i=0; i<x.PP; i++){
        int gc = rand()%5 + 1;
        int gf = rand()%gc;     //esto es pq tiene q meter menos q el rival
        x.GF += gf;
        x.GC += gc;
    }

    //para los puntos
    x.puntos = x.PG*3 + x.PE;
    //para la diferencia de goles
    x.DG = x.GF - x.GC;
    //para el rendimiento
    x.rend = (double)x.puntos / 300 * 100;
}
//aqui hare el ordenamiento burbuja
void ordenarTabla(Seleccion v[], int n){

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){

            if(v[j+1].puntos > v[j].puntos ||
              (v[j+1].puntos == v[j].puntos && v[j+1].DG > v[j].DG)){
                Seleccion aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

int main(){

    srand(time(0));

    Seleccion equipo[5];

    //agrego el nombre de los paises
    strcpy(equipo[0].nombre,"Pais1");
    strcpy(equipo[1].nombre,"Pais2");
    strcpy(equipo[2].nombre,"Pais3");
    strcpy(equipo[3].nombre,"Pais4");
    strcpy(equipo[4].nombre,"Pais5");

    // para la generacion de datos:
    for(int i=0;i<5;i++){
        equipo[i].PG = rand()%101;
        equipo[i].PE = rand()%(101 - equipo[i].PG);
        equipo[i].PP = 100 - equipo[i].PG - equipo[i].PE;//aqui genero de los 100 partidos primero los ganados luego los empatados y al final los perdidos


        generarEstadisticas(equipo[i]);
    }
    ordenarTabla(equipo,5);

    cout<<"Seleccion   PG   PE   PP   GF   GC   DG   Pts   Rend(%)\n";
    cout<<"-------------------------------------------------------\n";

    for(int i=0;i<5;i++){
        cout<<equipo[i].nombre<<"   "<<equipo[i].PG<<"    "<<equipo[i].PE<<"    "<<equipo[i].PP<<"    "<<equipo[i].GF<<"    "<<equipo[i].GC<<"    "<<equipo[i].DG<<"    "<<equipo[i].puntos<<"    "<<equipo[i].rend<<"\n";
    }

    cout<<"\nCAMPEON: "<<equipo[0].nombre<<"| Puntaje: "<<equipo[0].puntos<<"| DG: "<<equipo[0].DG<<"| Rendimiento: "<<equipo[0].rend<<"%"<<endl;

    return 0;
}
//profesor aqui no tendre la misma salida del q mande en el pdf de la misma pc del viernes ya q el resultado es aleatorio :(