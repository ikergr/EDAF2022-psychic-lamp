#include "Nodo.hpp"

class ListaSimple{
    //Atributos
    private:
        Nodo * head;
        int tam;
    //Metodos
    public:
        ListaSimple(){
            this->head=nullptr;
            this->tam=0;
        }

        void agregarInicio(int dato){
            //Crear el nuevo nodo y actualizar la referencia
            Nodo * nuevo = new Nodo(dato,this->head);
            //Actualizar al head de la lista con el nuevo nodo
            this->head=nuevo;
            //Actualizar tamaño
            this->tam++;
        }

        void agregarFin(int dato){
            //Crear el nuevo nodo
            Nodo * nuevo = new Nodo(dato, nullptr);
            //Verificar el caso si la lista esta vacia o tiene valores
            if(this->head){ //la lista tiene valores
                Nodo * nodo = this->head;
                //Encontrar el último nodo
                while(nodo->getSiguiente())
                    nodo=nodo->getSiguiente();
                nodo->setSiguiente(nuevo); //Actualiza el siguiente del ultimo nodo con el nodo nuevo
            }else{//Lista vacia
                this->head=nuevo;
            }
            this->tam++;
        }

        Nodo * buscarNodo(int dato){
            Nodo * nodo= this->head;
            while(nodo){
                if(nodo->getDato()==dato)
                    return nodo;
                nodo=nodo->getSiguiente();
            }
            return nullptr;
        }


        void imprimirLista(){
            Nodo * nodoActual=this->head;
            cout<<"head -> ";
            while(nodoActual){
                cout<<nodoActual->getDato()<<" -> ";
                nodoActual=nodoActual->getSiguiente();
            }
            cout<<"nullptr"<<endl;
        }
};