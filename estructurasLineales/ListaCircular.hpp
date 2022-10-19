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

        NodoT<T> * getLast(){return this->last;}
        int getTam(){return this->tam;}
        void setLast(NodoT<T> * last){this->last=last;}
        void setTam(int tam){this->tam=tam;}
        
        NodoT<T> * eliminarInicio(){
            if(this->last){
                NodoT<T> * nodoInicial = this->last->getSiguiente();
                if(this->getTam()==1)
                    this->last=nullptr;
                else
                    this->last->setSiguiente(nodoInicial->getSiguiente());
                this->setTam(this->getTam()-1);
                    //this->last->setSiguiente(this->last->getSiguiente()->getSiguiente());
                nodoInicial->setSiguiente(nullptr);
                return nodoInicial;
            }
            return nullptr;
        }

        void agregarInicio(T dato){ //O(1)
            if(this->last){ //Lista circular tiene nodos
                //Crea un nuevo nodo y el apuntador siguiente lo apunta al primero (this->last->getSiguiente())
                NodoT<T> * nuevo = new NodoT<T>(dato,this->last->getSiguiente());
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
            cout<<"Lista circular"<<endl;
            if(this->last){
                NodoT<T> * nodo = this->last->getSiguiente();
                do{
                    cout<<nodo->getDato()<<" ";
                    nodo= nodo->getSiguiente();
                }while(nodo!=this->last->getSiguiente());
            }
            cout<<endl;
        }
}; 