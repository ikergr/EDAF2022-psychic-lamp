#include "BST.hpp"

NodoBST<T>::NodoBST(){
    this->raiz=nullptr;
    this->numNodos=0;
}

//getters y setters
NodoBST<T> * NodoBST<T>::getRaiz(){return this->raiz;}
int NodoBST<T>::getNumNodos(){return this->numNodos;}
void NodoBST<T>::setRaiz(NodoBST<T> * raiz){this->raiz=raiz;}
void NodoBST<T>::setNumNodos(int numNodos){this->numNodos=numNodos;}