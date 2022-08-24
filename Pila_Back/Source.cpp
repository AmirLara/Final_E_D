#include "stack.h"
#include <iostream>

#pragma warning(disable: 6262)

using namespace std;

int main(int argc, char* argv[])
{
	Stack S1;
	//Ejemplo con int
	ItemType a;
	bool b;

	//Se comprueba que la lista esta vacia por lo que regresa true.
	b = S1.Empty();
	//La lista no esta llena por lo que regresa false
	b = S1.Full();

	//Se apilan 4 elementos
	S1.Push(1);
	S1.Push(2);
	S1.Push(3);
	S1.Push(4);

	//Comprueba si esta vacia la pila, al no estarlo regresa false.
	b = S1.Empty();
	//Regresa el elemento que se encuentra en top
	a = S1.Top();
	//Eliminamos todos los datos de la pila dejandola vacia.
	S1.Pop();
	S1.Pop();
	S1.Pop();
	S1.Pop();
	//Trata de eliminar el elemento tope, al estar vacia la pila regresa NULL
	S1.Pop();
	//Al estar vacia la pila regresa NULL
	a = S1.Top();
	//Da la longitud de la pila.
	cout << "Longitud de la pila " << S1.Length() << endl;
	//Destruye la pila.
	S1.~Stack();

	return 0;
}