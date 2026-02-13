#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Seleccion{
char nombre[20];
int PG,PE,PP;
int GF,GC;
int DG;
int puntos;
double rendimiento;
};

void simular(Seleccion &s){

s.GF=0; s.GC=0;

for(int i=0;i<s.PG;i++){
    int gf=rand()%5+1;
    int gc=rand()%gf;
    s.GF+=gf; s.GC+=gc;
}

for(int i=0;i<s.PE;i++){
    int g=rand()%5;
    s.GF+=g; s.GC+=g;
}

for(int i=0;i<s.PP;i++){
    int gc=rand()%5+1;
    int gf=rand()%gc;
    s.GF+=gf; s.GC+=gc;
}

s.puntos=s.PG*3+s.PE;
s.DG=s.GF-s.GC;
s.rendimiento=(double)s.puntos/(100*3)*100;
}

void ordenar(Seleccion s[],int n){
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(s[j].puntos>s[i].puntos ||
(s[j].puntos==s[i].puntos && s[j].DG>s[i].DG) ||
(s[j].puntos==s[i].puntos && s[j].DG==s[i].DG && s[j].GF>s[i].GF)){
Seleccion t=s[i];
s[i]=s[j];
s[j]=t;
}
}

int main(){
srand(time(0));
Seleccion s[5];
strcpy(s[0].nombre,"Pais_1");
strcpy(s[1].nombre,"Pais_2");
strcpy(s[2].nombre,"Pais_3");
strcpy(s[3].nombre,"Pais_4");
strcpy(s[4].nombre,"Pais_5");
for(int i=0;i<5;i++){
    s[i].PG=rand()%101;
    s[i].PE=rand()%(101-s[i].PG);
    s[i].PP=100-s[i].PG-s[i].PE;
    simular(s[i]);
}

ordenar(s,5);

cout<<"Seleccion PG  PE  PP  GF  GC  DG  Pts  Rend\n";
cout<<"-------------------------------------------\n";

for(int i=0;i<5;i++)
    cout<<s[i].nombre<<"    "
        <<s[i].PG<<"  "
        <<s[i].PE<<"  "
        <<s[i].PP<<"  "
        <<s[i].GF<<"  "
        <<s[i].GC<<"  "
        <<s[i].DG<<"  "
        <<s[i].puntos<<"  "
        <<s[i].rendimiento<<"\n";

cout<<"\nCAMPEON: "<<s[0].nombre<<"| Puntaje: "<<s[0].puntos<<"| DG: "<<s[0].DG<<"| Rendimiento: "<<s[0].rendimiento<<"%"<<endl;
}