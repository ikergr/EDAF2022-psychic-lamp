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

void metodoSeleccion(int arreglo [],int n){
    int i,j,indiceMenor,aux;
    //Pasadas
    for(i=0;i<n-1;i++){ //O(n)
        indiceMenor=i;
        //Búsqueda del indice del valor menor
        for(j=i+1;j<n;j++) //O(n)
            if(arreglo[j]<arreglo[indiceMenor]) //O(1)
                indiceMenor=j; //Actualiaza el indice menor actual
        //Swap
        aux=arreglo[i];
        arreglo[i]=arreglo[indiceMenor];
        arreglo[indiceMenor]=aux;
    }
}

void metodoInsercion(int arreglo[],int n){
    int i, j, aux;
    for(i=1;i<n;i++){ //O(n)
        j=i;
        aux=arreglo[i];
        while(j>0&&aux<arreglo[j-1]){
            arreglo[j]=arreglo[j-1];
            j--;
        }
        arreglo[j]=aux;
    }
}

void merge(int arreglo[], int inicio,int mitad,int fin){
    //i -> indice para parte izq, j -> indice parte derecha
    //k -> indice del arreglo a ordenar
    int i, j, k; 
    //Numero de elementos de la parte izq
    int nizq = mitad-inicio+1;
    //Numero de elementos de la parte der
    int nder =fin-mitad;
    //Declarar arreglos auxiliares de izq y der
    int izq[nizq], der[nder];
    //Copiar los datos del arreglo original en izq y der
    for(i=0;i<nizq;i++)
        izq[i]=arreglo[inicio+i];
    for(j=0;j<nder;j++)
        der[j]=arreglo[mitad+j+1];
    //Realizar el merge
    i=0;
    j=0;
    k=inicio;
    while(i<nizq&&j<nder){
        //Determinar el valor menor
        if(izq[i]<=der[j])
            arreglo[k++]=izq[i++];
        else
            arreglo[k++]=der[j++];        
    }
    //Vaciar remanentes
    //La parte derecha se acabo vaciamos la parte izquierda en el arreglo
    while(i<nizq)
        arreglo[k++]=izq[i++];
    //La parte izquierda se acabo vaciamos la parte derecha en el arreglo
    while(j<nder)
        arreglo[k++]=der[j++];    
}

//FuncionRecursiva
void mergeSort(int arreglo[], int inicio,int fin){
    //Caso recursivo
    if(inicio<fin){
        //Obtener el indice a la mitad
        int mitad = inicio+(fin-inicio)/2;
        //Izquierdo
        mergeSort(arreglo,inicio,mitad);
        //Derecho
        mergeSort(arreglo,mitad+1,fin);
        merge(arreglo,inicio,mitad,fin);
    }
    //Caso base
}

int particion(int arreglo[], int inicio, int fin){
    return 0;
}

//QuickSort recursiva
void quickSort(int arreglo[],int inicio, int fin){
    //Caso recursivo
    if(inicio<fin){
        //Encontrar la posición final (indice del pivote dentro del arreglo) y 
        //además colocar los elementos menores a la izquierda y los mayores a la derecha
        int pivote = particion(arreglo,inicio, fin);
        //Partición izquierda
        quickSort(arreglo,inicio,pivote-1);
        //Partición derecha
        quickSort(arreglo,pivote+1,fin);
    }
    //Caso base
}

int busquedaBinaria(int arreglo[],int clave, int n){
    int inicio,mitad,fin, valorCentral;
    inicio=0;
    fin=n-1;
    while(inicio<=fin){
        mitad=(inicio+fin)/2;
        valorCentral=arreglo[mitad];
        if(clave==valorCentral)
            return mitad;
        else if(clave<valorCentral) //izq
            fin=mitad-1;
        else //der
            inicio=mitad+1;
    }
    return -1;
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
    mergeSort(arreglo,0,tam-1);
    imprimirArreglo(arreglo,tam);
}
