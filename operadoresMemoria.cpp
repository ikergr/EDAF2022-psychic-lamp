#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main(){
    // Crear una variable en el stack con valor de 48
    int var1 = 48;
    // Crear una variable nueva en el stack con el valor de var1
    int var2 = var1;
    // Crear un apuntador (pointer)
    int * var3;
    //Asignar la dirección del espacio de memoria de var1 a var3
    var3 = &var1;
    //Crear una referencia a la variable var1
    int &var4 = var1;
    cout<<"var1: " <<var1<<endl;
    cout<<"direccion de var1: "<<&var1<<endl; 
    cout<<"var2:" <<var2<<endl;
    cout<<"direccion de var2: "<<&var2<<endl; 
    cout<<"direccion apuntada de var3:" <<var3 <<endl;
    cout<<"valor de la direccion que apunta var3: " << *var3<<endl;
    cout<<"var4:"<<var4<<endl;
    cout<<"direccion de var4"<<&var4<<endl;
}