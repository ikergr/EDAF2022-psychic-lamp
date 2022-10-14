/*
vector<int>
vector<Bitacora *>
vector<float>
*/

//Template

/*
ListaCircular<int>
ListaCircular<float>
ListaCircular<Bitacora *>
*/
#include  <iostream>
using namespace std;

template <typename T> // T va configurar el tipo de dato
class NodoT{
    T dato;
    NodoT<T> * siguiente;
    public:
        T getDato(){return this->dato;}
        void setDato(T dato){this->dato=dato;}
        NodoT<T> * getSiguiente(){return this->siguiente;}
        void setSiguiente(NodoT<T> * siguiente){this->siguiente=siguiente;}

        NodoT<T>(){
            this->dato=NULL;
            this->siguiente=nullptr;
        }

        NodoT<T>(T dato, NodoT<T> * siguiente){
            this->dato=dato;
            this->siguiente=siguiente;
        }
}