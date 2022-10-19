#include "NodoT.hpp"

template <typename T>
class ListaCircular{
    NodoT<T> * last;
    int tam;
    public:
        ListaCircular<T>(){
            this->last=nullptr;
            this->tam=0;
        }

        void agregarInicio(T dato){ //O(1)
            if(this->last){ //Lista circular tiene nodos
                //Crea un nuevo nodo y el apuntador siguiente lo apunta al primero (this->last->getSiguiente())
                nodoActual<T> * nuevo = new NodoT<T>(dato,this->last->getSiguiente());
                //Actualizar el apuntado de last y conectarlo al nuevo nodo
                this->last->setSiguiente(nuevo);
            }else{ //Lista vacia
                NodoT<T> * nuevo = new NodoT<T>(dato,nullptr); //Crear el nuevo nodo
                nuevo->setSiguiente(nuevo); //Como solo hay un nodo el apuntador siguiente será así mismo
                this->last= nuevo; // El nuevo nodo será el último y el primero al mismo tiempo 
            }
        }

        void agregarFin(T dato){
            if(this->last){ //Lista circular tiene nodos
                //Crea un nuevo nodo y el apuntador siguiente apunta al primero (this->last->getSiguiente())
                NodoT<T> * nuevo = new NodoT<T>(dato,this->last->getSiguiente());
                //Actualizar el apuntador de last y conectarlo con el nuevo nodo
                this->last->setSiguiente(nuevo);                
                this->last=nuevo;
            }else{ //Lista vacia
                NodoT<T> * nuevo = new NodoT<T>(dato,nullptr); //Crear el nuevo nodo
                nuevo->setSiguiente(nuevo); //Como solo hay un nodo el apuntador siguiente será así mismo
                this->last= nuevo; // El nuevo nodo será el último y el primero al mismo tiempo 
            }
        }

        void imprimirListaCircular(){
            if(this->last){
                NodoT<T> * nodo = this->last->getSiguiente();
                do{
                    cout<<nodo->getDato()<<" ";
                    node= nodo->getSiguiente();
                }while(nodo!=this->last->getSiguiente());
            }
            cout<<endl;
        }
} 