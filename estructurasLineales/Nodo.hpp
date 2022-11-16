#include <iostream>
using namespace std;

class Nodo{
    //atributos
    private:
        int dato;
        Nodo * siguiente;
    //metodos
    public:
        int getDato(){return this->dato;}
        void setDato(int dato){this->dato=dato;}
        Nodo * getSiguiente(){return this->siguiente;}
        void setSiguiente(Nodo * siguiente){this->siguiente=siguiente;}
        //Constructores
        Nodo(int dato,Nodo * siguiente){
            this->dato=dato;
            this->siguiente=siguiente;
        }
        Nodo(){
            this->dato=0;
            this->siguiente=nullptr;
        }       
        //Destructores
        ~Nodo(){
            cout<<"Destructor"<<endl;
        }
};