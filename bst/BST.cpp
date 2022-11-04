#include "BST.hpp"

//Constructor
template<class T>
BST<T>::BST(){
    this->raiz=nullptr;
    this->numNodos=0;
}

//getters y setters
template<class T>
NodoBST<T> * BST<T>::getRaiz(){return this->raiz;}
template<class T>
int BST<T>::getNumNodos(){return this->numNodos;}
template<class T>
void BST<T>::setRaiz(NodoBST<T> * raiz){this->raiz=raiz;}
template<class T>
void BST<T>::setNumNodos(int numNodos){this->numNodos=numNodos;}

template<class T>
void BST<T>::agregarNodo(T dato){
    NodoBST<T> * actual = this->raiz;
    NodoBST<T> * padre;
    if(this->raiz){ //Arbol no esta vacio
        if(this->buscarNodo(dato))//
            cout<<"Nodo existente"<<endl;
        else{
            //Encontrar al nodo padre
            while(actual){
                padre=actual;
                //Relación de orden (izq menor o der mayor)
                if(dato<actual->getDato())
                    actual=actual->getIzq();
                else
                    actual=actual->getDer();
            }
            padre->getDato()>dato?padre->setIzq(new NodoBST<T>(padre,dato)):padre->setDer(new NodoBST<T>(padre,dato));
            this->numNodos++;
        }
    }else{ //Arbol esta vacio
        this->raiz= new NodoBST<T>(nullptr,dato);
        this->numNodos++;
    } 
}

template <class T>
NodoBST<T> * BST<T>::buscarNodo(T dato){
    //Crear el apuntado a nodo raiz
    NodoBST<T> * actual = this->raiz;
    while(actual){
        //Si el dato del nodo actual es el valor que busco
        if(actual->getDato()==dato)
            return actual;
        else
            actual=actual->getDato()>dato?actual->getIzq():actual->getDer();        
    }
    return nullptr;
}
