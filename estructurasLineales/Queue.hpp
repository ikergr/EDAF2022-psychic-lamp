#include "ListaCircular.hpp"

template <typename T>
class Queue{
    ListaCircular<T> * queue;
    public:
        Queue(){
            this->queue=new ListaCircular<T>();
        }
        void push(T dato){
            this->queue->agregarFin(dato);
        }
        NodoT<T> * front(){
            if(this->queue->getLast())
                return this->queue->getLast()->getSiguiente();
            return nullptr;
        }
        void imprimirQueue(){
            this->queue->imprimirListaCircular();
        }
        NodoT<T> * pop(){
            return this->queue->eliminarInicio();
        }        
};