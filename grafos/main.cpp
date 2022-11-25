#include "Grafo.hpp"

int main(){
    Grafo<string> * ejemplo = new Grafo<string>();
    ejemplo->insertarNodoGrafo("CDMX");
    ejemplo->insertarNodoGrafo("GDL");
    ejemplo->insertarNodoGrafo("OAX");
    ejemplo->insertarNodoGrafo("MER");
    ejemplo->insertarNodoGrafo("VER");
    ejemplo->insertarNodoGrafo("MTY");
    ejemplo->insertarNodoGrafo("TLX");
    ejemplo->insertarNodoGrafo("MEX");

    ejemplo->agregarArco("MEX","CDMX",30);
    ejemplo->agregarArco("MEX","OAX",300);
    ejemplo->agregarArco("OAX","GDL",2000);
    ejemplo->agregarArco("GDL","MTY",1000);
    ejemplo->agregarArco("TLX","VER",150);
    ejemplo->agregarArco("CDMX","VER",450);

    ejemplo->imprimirGrafo();
}