#include <iostream>
using namespace std;

struct Polinomio{
    int grado;
    double* coef;
};
//Creare un polinomio reservando la memoria

Polinomio crearPol(int grado){

    Polinomio p;
    p.grado = grado;
    p.coef = new double[grado+1];

    return p;
}

// para sumar los tres polinomios:
Polinomio sumar3(Polinomio a, Polinomio b, Polinomio c){

    int maxg = max(a.grado, max(b.grado,c.grado));
    Polinomio r = crearPol(maxg);

    for(int i=0;i<=maxg;i++) r.coef[i]=0;

    for(int i=0;i<=a.grado;i++) r.coef[maxg-a.grado+i]+=a.coef[i];
    for(int i=0;i<=b.grado;i++) r.coef[maxg-b.grado+i]+=b.coef[i];
    for(int i=0;i<=c.grado;i++) r.coef[maxg-c.grado+i]+=c.coef[i];

    return r;
}
//primero voy a multiplicar 2 polinomios "a", "b" en este caso para q me de un polinomio "d"
Polinomio multiplicar(Polinomio a, Polinomio b){

    Polinomio d = crearPol(a.grado+b.grado);

    for(int i=0;i<=d.grado;i++) d.coef[i]=0;

    for(int i=0;i<=a.grado;i++)
        for(int j=0;j<=b.grado;j++)
            d.coef[i+j]+=a.coef[i]*b.coef[j];

    return d;
}

//para tener el producto de los 3 ahora usare el producto del polinomio "d" anteriormente creado y lo multiplicare con el polinomio "c"
Polinomio producto3(Polinomio a, Polinomio b, Polinomio c){
    return multiplicar(multiplicar(a,b),c);
}

void mostrar(Polinomio p){

    for(int i=0;i<=p.grado;i++){
        cout<<p.coef[i]<<"x^"<<p.grado-i;
        if(i<p.grado) cout<<" + ";
    }
    cout<<endl;
}

int main(){

    //profesor la primera salida sera del enunciado del examen el segundo seran polinomios nuevos
    Polinomio p1=crearPol(2);
    p1.coef[0]=3; p1.coef[1]=4; p1.coef[2]=-1;

    Polinomio p2=crearPol(1);
    p2.coef[0]=4; p2.coef[1]=-5;

    Polinomio p3=crearPol(2);
    p3.coef[0]=4; p3.coef[1]=10; p3.coef[2]=2;
//para mostrar la suma de los polinomios
    cout<<"Suma:\n";
    mostrar(sumar3(p1,p2,p3));
//para mostrar el producto de losm polinomios
    cout<<"Producto:\n";
    mostrar(producto3(p1,p2,p3));
}
//los codigos los estoy ejecutando en windowspowershell ya q mi pc no tiene linux