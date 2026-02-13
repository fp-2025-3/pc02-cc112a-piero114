#include<iostream>
using namespace std;

struct Polinomio{
int grado;
int *coef;
};

Polinomio crearPolinomio(int grado, int valores[]){
Polinomio p;
p.grado = grado;

p.coef = new int[grado+1];

for(int i=0;i<=grado;i++)
    p.coef[i] = valores[i];

return p;
}

Polinomio sumar(Polinomio a, Polinomio b){
int gradoMax = max(a.grado,b.grado);

Polinomio r;
r.grado = gradoMax;
r.coef = new int[gradoMax+1];

for(int i=0;i<=gradoMax;i++){
    int va = (i<=a.grado)? a.coef[i]:0;
    int vb = (i<=b.grado)? b.coef[i]:0;
    r.coef[i]=va+vb;
}
return r;
}

Polinomio multiplicar(Polinomio a, Polinomio b){
Polinomio r;
r.grado = a.grado + b.grado;
r.coef = new int[r.grado+1];

for(int i=0;i<=r.grado;i++)
    r.coef[i]=0;

for(int i=0;i<=a.grado;i++)
    for(int j=0;j<=b.grado;j++)
        r.coef[i+j]+=a.coef[i]*b.coef[j];

return r;
}

void imprimir(Polinomio p){
for(int i=p.grado;i>=0;i--){
if(p.coef[i]!=0){
cout<<p.coef[i]<<"x^"<<i;
if(i>0) cout<<" + ";
}
}
cout<<endl;
}

int main(){

int v1[]={3,0,1};
int v2[]={5,-4};
int v3[]={1,0,3};

Polinomio p1=crearPolinomio(2,v1);
Polinomio p2=crearPolinomio(1,v2);
Polinomio p3=crearPolinomio(2,v3);

cout<<"Polinomio 1: "; imprimir(p1);
cout<<"Polinomio 2: "; imprimir(p2);
cout<<"Polinomio 3: "; imprimir(p3);

Polinomio suma = sumar(sumar(p1,p2),p3);
cout<<"\nSuma de los tres: ";
imprimir(suma);

Polinomio prod = multiplicar(multiplicar(p1,p2),p3);
cout<<"Producto de los tres: ";
imprimir(prod);

return 0;
}