//Bibliotecas
#include <iostream> //entradas y salidas de nuestro programa
#include <stdlib.h> //Generar números aleatorios
#include <time.h> //tiempo de la computadora
//Espacio de nombre
using namespace std;

//Función para generar arreglos con números aleatorios
void generarArreglo(int arreglo[],int tam){
    //inicializar la semilla de generacion de números aleatorios
    srand((unsigned)time(0));
    for(int i=0;i<tam;i++)
        arreglo[i]=rand()%100; //Genera un número pseudoaleatorio de 0 a 99
}

void imprimirArreglo(int arreglo[],int tam){
    for(int i=0;i<tam;i++)
        cout<<arreglo[i]<<" ";
    cout<<endl;
}
//main
int main(){
    int tam;
    cout<<"Ingrese el tamaño del arreglo:";
    cin>>tam;
    //Declaracion del arreglo
    int arreglo[tam];
    //Generar un arreglo aleatorio 
    generarArreglo(arreglo,tam);
    imprimirArreglo(arreglo,tam);
}