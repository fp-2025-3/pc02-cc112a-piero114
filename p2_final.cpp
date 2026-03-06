#include <iostream>
using namespace std;
struct Punto{
    double x;
    double y;
};
void leerPunto(Punto* p){
    cout<<"Ingrese x: ";
    cin>>p->x;
    cout<<"Ingrese y: ";
    cin>>p->y;
}
double distanciaOrigen(const Punto* p){
    return (p->x * p->x + p->y * p->y);
}
Punto* masLejano(Punto* p1, Punto* p2){
    double d1 = distanciaOrigen(p1);
    double d2 = distanciaOrigen(p2);
    if(d1 > d2)
        return p1;
    else
        return p2;
}
int main(){
    Punto* p1;
    Punto* p2;
    cout<<"Punto 1"<<endl;
    leerPunto(p1);
    cout<<"Punto 2"<<endl;
    leerPunto(p2);
    Punto* lejano = masLejano(p1,p2);
    cout<<"El punto mas alejaod del centro es: "<<endl;
    cout<<"("<<lejano->x<<","<<lejano->y<<")"<<endl;
    return 0;
}