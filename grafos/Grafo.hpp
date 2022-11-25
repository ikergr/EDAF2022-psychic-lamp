#include "NodoGrafo.hpp"
#include "Queue.hpp"

template <typename T>
class Grafo{
    private:
        int tam;
        ListaSimple<NodoGrafo<T> *> * nodos;
    public:
        Grafo(){
            this->tam=0;
            this->nodos = new ListaSimple<NodoGrafo<T> *>();
        }
        //buscarNodoGrafo

        NodoGrafo<T> * buscarNodoGrafo(T valor){
            NodoT<NodoGrafo<T>*> * actual= this->nodos->getHead();
            while(actual){
                //Busqueda del valor dentro de los NodoT
                if(actual->getDato()->getValor()==valor)
                    return actual->getDato();
                actual=actual->getSiguiente();
            }
            return nullptr;
        }

        //insertarNodoGrafo
        void insertarNodoGrafo(T valor){
            //Si el nodo no existe
            if(!this->buscarNodoGrafo(valor)){
                this->nodos->agregarInicio(new NodoGrafo<T>(valor));
                this->tam++;
            }else
                cout<<"Nodo existente"<<endl;
        }

        //AgregarArco
        void agregarArco(T valorNodoOrigen, T valorNodoDestino, int peso){
            //Validar la existencia de los nodos origen y destino
            NodoGrafo<T> * origen=this->buscarNodoGrafo(valorNodoOrigen);
            NodoGrafo<T> * destino=this->buscarNodoGrafo(valorNodoDestino);
            if(origen&&destino)
                origen->getArcos()->agregarInicio(new Arco<T>(valorNodoDestino,peso));
            else    
                cout<<"Ambos nodos origen y destino deben de existir"<<endl;
        }

        //Imprimir grafo
        //Adolfo, Marco Antonio Caudillo, Emiliano, Rodrigo Hdz 2pts
        //Arturo, Brisa 1 pts
        void imprimirGrafo(){
            NodoT<NodoGrafo<T>*> * nodo = this->nodos->getHead();
            //Recorrer la lista de nodos
            while(nodo){
                cout<<"Nodo:"<<nodo->getDato()->getValor()<<":";
                NodoT<Arco<T>*> * arco = nodo->getDato()->getArcos()->getHead();
                //Recorre la lista de adyacencia
                while(arco){
                    cout<<"->"<<arco->getDato()->getValor()<<":"<<arco->getDato()->getPeso()<<" ";
                    arco=arco->getSiguiente();
                }
                cout<<endl;
                nodo=nodo->getSiguiente();
            }
            cout<<endl;
        }


        //Breadth First
        void BreadthFirst(NodoGrafo<T> * nodoG){
            //Crear la queue 
            if(this->nodos->getHead()){
                Queue<NodoGrafo<T> *> * queue = new Queue<NodoGrafo<T> *>();
                queue->push(nodoG);
                nodoG->setProcesado(true);
                while(queue->front()){
                    //Sacamos un elemento de la queue
                    NodoGrafo<T> * aux = queue->pop()->getDato();
                    //Imprimir el valor
                    cout<<aux->getValor()<<" ";
                    //Checar las conexiones sin procesar
                    NodoT<Arco<T>*> * nodeA= aux->getArcos()->getHead();
                    while (nodeA){
                        NodoGrafo<T> * vecino= this->buscarNodoGrafo(nodeA->getDato()->getValor());
                        if(!vecino->getProcesado()){
                            vecino->setProcesado(true);
                            //Meter al queue
                            queue->push(vecino);
                        }                  
                        nodeA=nodeA->getSiguiente();
                    }
                }
                cout<<endl;
            }else
                cout<<"Grafo vacio"<<endl;                 
        }
};