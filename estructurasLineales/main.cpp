#include "ListaSimple.hpp"

int main(){
    ListaSimple * lista = new ListaSimple(); //Crear una lista en el heap
    lista->agregarInicio(4);
    lista->agregarInicio(8);
    lista->agregarInicio(10);
    lista->imprimirLista();
    //head-> 10 -> 8 -> 4


    ListaSimple listaStack; //Crear un lista en el stack
    listaStack.agregarInicio(5);
    listaStack.agregarInicio(10);
    listaStack.agregarInicio(60);
    listaStack.imprimirLista();
}