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
//Complejidad de O(n^2)
void metodoIntercambio(int arreglo [],int n){
    int i,j,aux;    
    //Pasadas 
    for(i=0;i<n-1;i++){  //O(n)
        //Indice del elemento a comparar con i
        for(j=i+1;j<n;j++){  //O(n)
            //Validar si el elemento [i] es menor que el elemento [j]
            if(arreglo[j]<arreglo[i]){ // 4 operaciones O(1)
                aux= arreglo[j];
                arreglo[j]=arreglo[i];
                arreglo[i]=aux;
            }
        }
    }
}
//O(n^2)
void metodoBurbuja(int arreglo [], int n){
    int i,j,aux;
    bool flag = true;
    //Control de pasadas
    for(i=0;i<(n-1)&&flag;i++){  // O(n)
        flag=false; //O(1)
        for(j=0;j<n-1-i;j++){ // O(n)
            //Verificar si se hacen intercambios
            if(arreglo[j+1]<arreglo[j]){ //O(1)
                aux=arreglo[j];
                arreglo[j]=arreglo[j+1];
                arreglo[j+1]=aux;
                flag=true; //Hubo un intercambio
            }
        }
    }
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
    metodoBurbuja(arreglo,tam);
    imprimirArreglo(arreglo,tam);
}