#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

//Paso de parámetros por valor (copia)
void funcion1(int param){
    cout<<"Valor param: "<<param<<endl;
    param=34;
    cout<<"Valor param: "<<param<<endl;
    cout<<"Direccion de param:"<<&param<<endl;
}

//Paso de parámetros por referencia
void funcion2(int &param){
    cout<<"Valor param: "<<param<<endl;
    param=34;
    cout<<"Valor param: "<<param<<endl;
    cout<<"Direccion de param:"<<&param<<endl;
}

//Paso de parámetros por apuntador
void funcion3(int *param){
    cout<<"Valor param: "<<*param<<endl;
    *param=34;
    cout<<"Valor param: "<<*param<<endl;
    cout<<"Direccion de param:"<<param<<endl;
}

class Ejemplo{
    private:
        int valor;
    public:
        int getValor(){return this->valor;}
        void setValor(int valor){this->valor=valor;}
        Ejemplo(int valor){
            this->valor=valor;
        }
        Ejemplo(){
            this->valor=0;
        }
};

//Sobrecarga el operador << para que pueda imprimir vectores
template<class T>
ostream& operator<<(ostream&stream, const vector<T>& valores){
    stream<<"[ ";
    copy(begin(valores), end(valores), ostream_iterator<T>(stream," "));
    stream<<"]";
    return stream;
}



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
    cout<<"direccion de var4:"<<&var4<<endl;

    var1=33;

    cout<<"var1: " <<var1<<endl;
    cout<<"direccion de var1: "<<&var1<<endl; 
    cout<<"var2:" <<var2<<endl;
    cout<<"direccion de var2: "<<&var2<<endl; 
    cout<<"direccion apuntada de var3:" <<var3 <<endl;
    cout<<"valor de la direccion que apunta var3: " << *var3<<endl;
    cout<<"var4:"<<var4<<endl;
    cout<<"direccion de var4:"<<&var4<<endl;

    var3=&var2;

    cout<<"var1: " <<var1<<endl;
    cout<<"direccion de var1: "<<&var1<<endl; 
    cout<<"var2:" <<var2<<endl;
    cout<<"direccion de var2: "<<&var2<<endl; 
    cout<<"direccion apuntada de var3:" <<var3 <<endl;
    cout<<"valor de la direccion que apunta var3: " << *var3<<endl;
    cout<<"var4:"<<var4<<endl;
    cout<<"direccion de var4:"<<&var4<<endl;

    cout<<"***************************"<<endl<<endl;
    cout<<"---f1--"<<endl;
    funcion1(var1);
    cout<<"var1: " <<var1<<endl;
    cout<<"direccion de var1: "<<&var1<<endl;
    cout<<"---f2--"<<endl;
    funcion2(var1);
    cout<<"var1: " <<var1<<endl;
    cout<<"direccion de var1: "<<&var1<<endl;
    cout<<"---f3--"<<endl;
    funcion3(&var2);
    cout<<"var2: " <<var2<<endl;
    cout<<"direccion de var2: "<<&var2<<endl;

    //Crear objetos en el stack
    
    //Se crea una instancia de la clase Ejemplo en el stack
    //llamando Ejemplo()
    Ejemplo obj1;
    //Se crea una instancia de la clase Ejemplo en el stack
    //llamando Ejemplo(int valor)    
    Ejemplo obj2(22);
    cout<<"++++Clases y objetos++++"<<endl;
    cout<<obj1.getValor()<<endl;
    cout<<obj2.getValor()<<endl;

    //Heap
    //Se crea una instancia de la clase Ejemplo en el heap
    //llamando Ejemplo()
    Ejemplo * obj3 = new Ejemplo();
    //llamando Ejemplo(int valor)
    Ejemplo * obj4 = new Ejemplo(35);

    //Acceso al contenido
    cout<<obj3->getValor()<<endl;
    cout<<obj4->getValor()<<endl;
    //La forma sin flecha
    cout<<(*obj4).getValor()<<endl;

    delete obj3;
    delete obj4;

    //Vectores

    cout<<"*************Vectores************"<<endl;
    vector<int> a {2,3,4,5,6,7,8}; 
    vector<int> b {a};
    vector<int> * c = nullptr; // apuntador a vector<int>
    c=&a;
    vector<int> &d=b; //referencia a vector<int>  

    cout<<a<<endl;

    vector<Ejemplo> vec1 = {obj1,obj2};
    vector<Ejemplo*> vec2 = {obj3,obj4};
   
}