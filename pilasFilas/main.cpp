#include "Fila.hpp"
#include "Pila.hpp"


#include <string>

int main(){
    Pila<int> pila1;//Stack
    pila1.push(45);
    pila1.push(100);
    pila1.push(12);
    pila1.imprimirPila(); //->12 100 45
    cout<<pila1.pop()->getDato()<<endl; //-> 12
    pila1.imprimirPila(); //-> 100 45

    Fila<string> fila1;//Stack
    fila1.push("Metroid");
    fila1.push("Mario Kart");
    fila1.push("Pokemon");
    fila1.imprimirFila(); // ->Metroid, Mario Kart, Pokemon
    cout<<fila1.pop()->getDato()<<endl; // Metroid
    fila1.imprimirFila(); // -> Mario Kart, Pokemon

    
    return 0;
}