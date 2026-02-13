#include<iostream>
#include<cstring>
using namespace std;

struct Producto{
int codigo;
char* nombre;
double precio;
int stock;
};

Producto crearProducto(int codigo,const char* nombre,double precio,int stock){
Producto p;
p.codigo=codigo;

p.nombre=new char[strlen(nombre)+1];
strcpy(p.nombre,nombre);

p.precio=precio;
p.stock=stock;

return p;
}

Producto* crearInventario(int n){
Producto* inv=new Producto[n];

inv[0]=crearProducto(100,"Teclado",10.5,5);
inv[1]=crearProducto(101,"Mouse",21,10);
inv[2]=crearProducto(102,"Monitor",31.5,15);
inv[3]=crearProducto(103,"Laptop",42,20);
inv[4]=crearProducto(104,"Impresora",52.5,25);

return inv;
}

Producto* buscarProducto(Producto* inv,int n,int codigo){
for(int i=0;i<n;i++)
if(inv[i].codigo==codigo)
return &inv[i];
return nullptr;
}

void liberarInventario(Producto* inv,int n){
for(int i=0;i<n;i++)
delete[] inv[i].nombre;

delete[] inv;
}

int main(){

int n=5;
Producto* inv=crearInventario(n);

for(int i=0;i<n;i++)
    cout<<"Codigo: "<<inv[i].codigo<<" | Nombre: "<<inv[i].nombre<<" | Precio:  "<<inv[i].precio<<" | Stock: "<<inv[i].stock<<endl;

Producto* p=buscarProducto(inv,n,102);

if(p!=nullptr)
    cout<<"Encontrado: "<<p->nombre<<" "<<p->precio<<endl;

liberarInventario(inv,n);
}