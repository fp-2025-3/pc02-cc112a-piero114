#include <iostream>
#include <cstring>
using namespace std;
//uso las estructuras que decia el examen
struct Item{
    char* descripcion;   // memoria dinámica
    int cantidad;
    double precioUnitario;
};

struct Pedido{
    int numeroPedido;
    char* nombreCliente; // memoria dinámica
    Item* items;         // arreglo dinámico
    int cantidadItems;
};

//funcion para crear un item reservando memoria para la descripcion
Item crearItem(const char* descripcion, int cantidad, double precio){

    Item it;

    it.descripcion = new char[strlen(descripcion)+1];
    strcpy(it.descripcion, descripcion);

    it.cantidad = cantidad;
    it.precioUnitario = precio;

    return it;
}

//aqu una funcion para crear un pedido reservando memoria para el nombre del cliente y el arreglo de items
Pedido* crearPedido(int numero, const char* cliente, int cantidadItems){

    Pedido* p = new Pedido;

    p->numeroPedido = numero;
    p->cantidadItems = cantidadItems;

    //tengo q reservar memoria para cliente
    p->nombreCliente = new char[strlen(cliente)+1];
    strcpy(p->nombreCliente, cliente);

    //y tambien tengo q reservar arreglo dinámico de items
    p->items = new Item[cantidadItems];

    return p;
}

double calcularTotal(const Pedido* p){

    double total = 0;

    for(int i=0;i<p->cantidadItems;i++)
        total += p->items[i].cantidad * p->items[i].precioUnitario;

    return total;
}

Item* itemMasCaro(Pedido* p){

    if(p->cantidadItems==0) return nullptr;

    int pos=0;

    for(int i=1;i<p->cantidadItems;i++){
        if(p->items[i].precioUnitario > p->items[pos].precioUnitario)
            pos=i;
    }

    return &p->items[pos];
}
//para liberar la memoria del pedido
void liberarPedido(Pedido* p){

    for(int i=0;i<p->cantidadItems;i++)
        delete[] p->items[i].descripcion;

    delete[] p->items;
    delete[] p->nombreCliente;
    delete p;
}
//para mostrar el pedido segun los datos del enunciado
void mostrarPedido(const Pedido* p){

    cout<<"Pedido N°: "<<p->numeroPedido<<endl;
    cout<<"Cliente: "<<p->nombreCliente<<endl;

    cout<<"\nItems:\n";
// para mostrar los items
    for(int i=0;i<p->cantidadItems;i++){
        cout<<"- "<<p->items[i].descripcion
            <<" | Cant: "<<p->items[i].cantidad
            <<" | Precio: "<<p->items[i].precioUnitario<<endl;
    }

    cout<<"\nTotal: "<<calcularTotal(p)<<endl;

    Item* caro = itemMasCaro((Pedido*)p);

    if(caro)
        cout<<"Item mas caro: "<<caro->descripcion
            <<" | Precio: "<<caro->precioUnitario<<endl;
}

int main(){

    Pedido* p = crearPedido(101,"Francisco Saavedra",3);
    p->items[0] = crearItem("Monitor",3,300);
    p->items[1] = crearItem("USB",4,400);
    p->items[2] = crearItem("Celular",1,100);

    mostrarPedido(p);

    liberarPedido(p);

    return 0;
}
//lo mismo q la 1 y la 3 profesor primero puse el ejemplo de salida del enunciado y luego uno mio