#pragma once

#include <stdlib.h>
#include <string>
using namespace std;

//
// Stack.h
//
// Este ADT implementa una pila sobre un arreglo.
// El tipo de elementos a almacenar puede redefinirlo el usuario con el tipo ItemType.
// La m�xima cantidad de elementos de la pila est� limitada por la constante MAX_LENGTH.
//

// Unico que puede cambir el usuario.
typedef int ItemType;
// aqu� termina.

struct node
{
	ItemType element;
	node* previous_node;
};

typedef node* PositionType;
typedef unsigned int LengthType;

class Stack
{
public:
	//
	// Stack:
	//
	// Prop�sito: Inicializa una pila vac�a.
	// Argumentos: No tiene.
	// Efecto colateral: La pila es inicializada en vac�o.
	//
	Stack();

	//
	// ~Stack:
	//
	// Prop�sito: Destruye una pila.
	// Argumentos: No tiene.
	// Efecto colateral: Todos los elementos de la pila son eliminados.
	//
	~Stack();

	//
	// Empty:
	//
	// Prop�sito: Verifica si una pila es vac�a.
	// Argumentos: No tiene.
	// Retorna: True si la pila es vac�a, False en cualquier otro caso.
	// Efecto colateral: No tiene.
	//
	bool Empty() const;

	//
	// Full:
	//
	// Prop�sito: Verifica si una pila est� llena.
	// Argumentos: No tiene.
	// Retorna: True si la pila est� llena, False en cualquier otro caso.
	// Efecto colateral: No tiene.
	//
	bool Full() const;

	//
	// Length:
	//
	// Prop�sito: Devolver la cantidad de elementos almacenados en una pila.
	// Argumentos: No tiene.
	// Retorna: Retorna un dato del tipo LengthType con la cantidad de elementos almacenados en la pila.
	// Si no hay elementos almacenados retorna 0.
	// Efecto colateral: No tiene.
	//
	LengthType Length() const;

	//
	// Pop
	//
	// Prop�sito: Desapila un elemento.
	// Argumentos: No tiene.
	// Retorna: Retorna el elemento sacado de la lista.
	// Precondiciones: La pila no puede estar vac�a.
	// Efecto colateral: No tiene.
	//
	ItemType Pop();

	//
	// Push
	//
	// Prop�sito: Apila un elemento en la lista.
	// Argumentos: "a" es el elemento a apilar.
	// Retorna: Retorna True si fue posible apilar el elemento, False en cualquier otro caso.
	// Precondiciones: La lista no puede estar llena.
	// Efecto colateral: No tiene.
	//
	bool Push(ItemType a);

	//
	// Top
	//
	// Prop�sito: Devuelve el elemento que est� en el tope de una pila sin sacarlo.
	// Argumentos: No tiene.
	// Retorna: Retorna el elemento del tope de la pila. 
	// Precondiciones: La pila no puede estar vac�a.
	// 
	ItemType Top() const;

	

private:

	LengthType Data_Count;
	node* TopStack;
		
};

