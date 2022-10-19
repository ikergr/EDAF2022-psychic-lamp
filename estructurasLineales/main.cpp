#include "ListaSimple.hpp"
#include "ListaCircular.hpp"
#include <string>

int main(){
    ListaSimple * lista = new ListaSimple(); //Crear una lista en el heap
    lista->agregarInicio(4);
    lista->agregarInicio(8);
    lista->agregarInicio(10);
    lista->imprimirLista();
    //head-> 10 -> 8 -> 4 -> nullptr
    lista->agregarFin(319);
    lista->imprimirLista();
    //head-> 10 -> 8 -> 4 -> 319 -> nullptr
    
    cout<<"Valor:" <<lista->buscarNodo(1)->getDato()<<" "<<endl;



    ListaSimple listaStack; //Crear un lista en el stack
    listaStack.agregarInicio(5);
    listaStack.agregarInicio(10);
    listaStack.agregarInicio(60);
    listaStack.imprimirLista();

    cout<<"*******************"<<endl;

    ListaCircular<string> * listaC = new ListaCircular<string>();
    listaC->agregarInicio("CEM");
    listaC->agregarInicio("TEC");
    listaC->imprimirLista();
    //last->CEM->TEC--->last
    listaC->agregarFin("21");
    //last->21->TEC->CEM---->last

}