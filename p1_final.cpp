#include <iostream>
using namespace std;

int** crearMatriz(int n, int m) {
    int** M = new int*[n];
    for(int i = 0; i < n; i++){
        M[i] = new int[m];
    }
    return M;
}
void llenarMatriz(int** M, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            M[i][j] = (i + 1) * (j + 1);
        }
    }
}
int* sumaFilas(int** M, int n, int m){
    int* v = new int[n];
    for(int i = 0; i < n; i++){
        v[i] = 0;

        for(int j = 0; j < m; j++){
            v[i] += M[i][j];
        }
    }
    return v;
}
void liberarMatriz(int** M, int n){
    for(int i = 0; i < n; i++){
        delete[] M[i];
    }
    delete[] M;
}
int main(){
    int n,m;
    cout<<"Ingrese n y m: ";
    cin>>n>>m;
    int** M = crearMatriz(n,m);
    llenarMatriz(M,n,m);
    int* v = sumaFilas(M,n,m);
    cout<<"Vector suma de filas:"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    delete[] v;
    liberarMatriz(M,n);
    return 0;
}
