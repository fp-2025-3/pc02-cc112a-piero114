#include <iostream>
#include <cstring>
using namespace std;

//aqui uso la memoria dinamica q me dio el enunciado
struct Producto{
    int codigo;
    char* nombre;   // cadena dinamica
    double precio;
    int stock;
};

//funcion para crear un producto reservando la memoria para el nombre
Producto crearProducto(int codigo,const char* nombre,double precio,int stock){

    Producto p;

    p.codigo=codigo;

    // reservo memoria exacta para el nombre
    p.nombre=new char[strlen(nombre)+1];

    // copio la cadena
    strcpy(p.nombre,nombre);

    p.precio=precio;
    p.stock=stock;

    return p;
}

//creo un inventario para los productos
Producto* crearInventario(int n){

    Producto* inv=new Producto[n];

    // datos del ejemplo del examen
    inv[0]=crearProducto(100,"CPU",11.5,6);
    inv[1]=crearProducto(101,"Mouse",31,11);
    inv[2]=crearProducto(102,"Silla",9.5,18);
    inv[3]=crearProducto(103,"Laptop",72,20);
    inv[4]=crearProducto(104,"GPU",54.5,24);

    return inv;
}

//para la busqueda del producto segun el codigo
Producto* buscarProducto(Producto* inv,int n,int codigo){

    for(int i=0;i<n;i++)
        if(inv[i].codigo==codigo)
            return &inv[i];

    return NULL;
}
//para mostar los productos del inventario segun el enunciado
void mostrarInventario(Producto* inv,int n){

    cout<<"INVENTARIO\n";

    for(int i=0;i<n;i++){
        cout<<"Codigo: "<<inv[i].codigo
            <<" | Nombre: "<<inv[i].nombre
            <<" | Precio: "<<inv[i].precio
            <<" | Stock: "<<inv[i].stock<<endl;
    }
}

//para liberar la memoria del inventario
void liberarInventario(Producto* inv,int n){

    for(int i=0;i<n;i++)
        delete[] inv[i].nombre;

    delete[] inv;
}

int main(){

    int n=5;

    //creo inventario dinamico
    Producto* inventario=crearInventario(n);

    mostrarInventario(inventario,n);

    cout<<"\nBuscando producto con codigo 102...\n";

    Producto* p=buscarProducto(inventario,n,102);

    if(p!=NULL)
        cout<<"Producto encontrado: "<<p->nombre
            <<" | Precio: "<<p->precio<<endl;

    liberarInventario(inventario,n);

    return 0;
}
//aqui lo mismo q la 1 profesor primero puse la salida del examen osea del ejemplo de salida y el otro un ejemplo mio