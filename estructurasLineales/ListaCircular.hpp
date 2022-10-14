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
                Nodo<T> * nuevo = new NodoT<T>(dato,this->last->getSiguiente());
                //Actualizar el apuntado de last y conectarlo al nuevo nodo
                this->last->setSiguiente(nuevo);
            }else{ //Lista vacia
                NodoT<T> * nuevo = new NodoT<T>(dato,nullptr); //Crear el nuevo nodo
                nuevo->setSiguiente(nuevo); //Como solo hay un nodo el apuntador siguiente será así mismo
                this->last= nuevo; // El nuevo nodo será el último y el primero al mismo tiempo 
            }
        }
} 