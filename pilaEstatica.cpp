#include <iostream>
using namespace std;

struct Nodo{
    int dato; //Almacena el valor del nodo
    Nodo* siguiente; //Puntero al siguiente nodo
};

class PilaDinamica{
    private:
    Nodo* cima; //Apunta al nodo en la cima de la pila

    public:
    PilaDinamica() : cima(nullptr) { } //Constructor e inicializamos la cima vacía

    ~PilaDinamica() { //Destructor se asegura de liberar la memoria de todos los nodos
        while (cima != nullptr){ //Ciclo para verificar si cima es diferente o igual a nullptr (vacio)
            pop(); //Llamamos a la funcion pop para vaciar la pila
        }
    }

    void push(int valor){
        Nodo* nuevo = new Nodo; //Creamos un nuevo nodo
        nuevo->dato = valor; //Le asignamos el valor recibido
        nuevo->siguiente = cima; //El nuevo nodo apunta a la antigua cima
        cima = nuevo; //Actualiza la cima a este nuevo nodo
    }

    int pop(){
        if(cima == nullptr){ //Si cima es igual a nullptr
            cout << "Pila vacía (underflow)." << endl; //Imprimimos en pantalla
            return -1; //Valor de error 
        }
        Nodo* temp = cima; //Guardamos en un nodo temporal lo que contiene cima
        int valor = temp->dato; //Accedemos al valor almacenado y lo guardamos en la variable valor
        cima = cima->siguiente; //Movemos el dato de cima al nodo siguiente
        delete temp; //Liberamos la memoria del nodo eliminado
        return valor; //Retornamos el valor eliminado 
    }

    int peek(){
        if(cima == nullptr){ //Si cima es igual a nullptr
            cout <<"Pila vacía." <<endl; //Imprimimos en pantalla
            return -1; //Valor de error
        }
        return cima->dato; //Devuelve el valor en la cima sin eliminarlo
    }
};

int main(){
    PilaDinamica pila; //Creamos un objeto pila de la clase PilaDinamica
    pila.push(100); //Insertamos el primer dato
    pila.push(200); //Insertamos el segundo dato
    pila.push(300); //Insertamos el tercer dato
    cout <<"Elemento en la cima: " << pila.peek() <<endl; //Debería mostrar 300
    cout <<"Elemento eliminado: " << pila.pop() <<endl; //300
    cout <<"Elemento eliminado: " << pila.pop() <<endl; //200
    return 0; //Fin del programa
}