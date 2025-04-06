#include <iostream>
using namespace std;

class pilaEstatica { //Definimos una clase
private:
	static const int MAX = 10; //Tamaño fijo de la pila
	int arr[MAX]; //Declaramos un arreglo de tipo entero que contiene el tamaño fijo de la pila "10"
	int top; //Índice del último elemento insertado

public:
	pilaEstatica() : top(-1) { } //Inicializa la pila e inicializa top en -1 "Constructor" 
	bool push(int valor) { //Declaramos una función de tipo boolean 
		if (top >= MAX - 1) { //Si el índice del último elemento insertado es mayor o igual a el tamaño del array
			cout << "Pila está llena (overflow)." << endl; //Imprimimos en pantalla
			return false; //Retornamos false y terminamos el programa
		}
		arr[++top] = valor; //Incrementa top e inserta el valor
		return true; //Retornamos true
	}

	int pop() { //Declaramos una función que eliminara datos
		if (top < 0) { //Si el indice del último elemento insertado es menor a 0
			cout << "Pila está vacía (underflow)." << endl; //Imprimimos en pantalla
			return -1; //Retornamos el valor del error
		}
		return arr[top--]; //Devuelve el elemento y decrementamos top
	}

	int peek() const { //Declaramos una funcion que nos permitira saber si la pila esta vacía
		if (top < 0) { //Si top es menor a 0
			cout << "Pila vacía." << endl; //Imprimimos en pantalla
			return -1; //Retornamos el valor del error
		}
		return arr[top]; //Retornamos el valor que contiene top
	}
};

int main() {
	pilaEstatica pila; //Llamamos a la función de pilaEstatica
	pila.push(10); //Insertamos un dato
	pila.push(20); //Insertamos un dato
	pila.push(30); //Insertamos un dato
	cout << "Elemento en la cima: " << pila.peek() << endl; //Debería mostrar 30
	cout << "Elemento eliminado: " << pila.pop() << endl; //30
	cout << "Elemento eliminado: " << pila.pop() << endl; //20
	return 0; //Finalizamos el programa
}