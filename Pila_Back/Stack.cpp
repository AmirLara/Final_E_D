#include "Stack.h"

#pragma warning(disable: 26495)

//
// Stack:
//
// Prop�sito: Inicializa una pila vac�a.
// Argumentos: No tiene.
// Efecto colateral: La pila es inicializada en vac�o.
//
Stack::Stack()
{
    TopStack = NULL;
	Data_Count = 0;
}

//
// ~Stack:
//
// Prop�sito: Destruye una pila.
// Argumentos: No tiene.
// Efecto colateral: Todos los elementos de la pila son eliminados.
//
Stack::~Stack()
{
    if (!Empty())
	{
		node* temp;
		while (TopStack != NULL)
		{
			temp = TopStack;
			TopStack = TopStack->previous_node;
			free(temp);
		}
	}
}

//
// Empty:
//
// Prop�sito: Verifica si una pila es vac�a.
// Argumentos: No tiene.
// Retorna: True si la pila es vac�a, False en cualquier otro caso.
// Efecto colateral: No tiene.
//
bool Stack::Empty() const
{
	return !Data_Count;
}

//
// Full:
//
// Prop�sito: Verifica si una pila est� llena.
// Argumentos: No tiene.
// Retorna: True si la pila est� llena, False en cualquier otro caso.
// Efecto colateral: No tiene.
//
bool Stack::Full() const
{
	node* temp = (node*)malloc(sizeof(node));
	if (temp != NULL)
	{
		free(temp);
		return false;
	}
	else
		return true;
}

//
// Length:
//
// Prop�sito: Devolver la cantidad de elementos almacenados en una pila.
// Argumentos: No tiene.
// Retorna: Retorna un dato del tipo LengthType con la cantidad de elementos almacenados en la pila.
// Si no hay elementos almacenados retorna 0.
// Efecto colateral: No tiene.
//
LengthType Stack::Length() const
{
	return Data_Count;
}

//
// Pop
//
// Prop�sito: Desapila un elemento.
// Argumentos: No tiene.
// Retorna: Retorna el elemento sacado de la lista.
// Precondiciones: La pila no puede estar vac�a.
// Efecto colateral: No tiene.
//
ItemType Stack::Pop()
{
    PositionType p; 
    ItemType elem;
	if (Empty())
		return NULL;
    if (Data_Count == 1)
	{
        elem = TopStack -> element;
		free(TopStack);
		TopStack = NULL;
		Data_Count--;
        return elem;
	}
	else
	{
        p = TopStack;
        elem = TopStack -> element;
        TopStack = TopStack->previous_node;
        free(p);
        Data_Count--;
		return elem; 
    }
}

//
// Push
//
// Prop�sito: Apila un elemento en la lista.
// Argumentos: "a" es el elemento a apilar.
// Retorna: Retorna True si fue posible apilar el elemento, False en cualquier otro caso.
// Precondiciones: La lista no puede estar llena.
// Efecto colateral: No tiene.
//
bool Stack::Push(ItemType a)
{
	if(Full())
        return false;
    else
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->previous_node = TopStack;
        temp->element = a;
        TopStack = temp;
        Data_Count++;
        return true;
    }
}

//
// Top
//
// Prop�sito: Devuelve el elemento que est� en el tope de una pila sin sacarlo.
// Argumentos: No tiene .
// Retorna: Retorna el elemento del tope de la pila. 
// Precondiciones: La pila no puede estar vac�a.
//
ItemType Stack::Top() const
{
	if (TopStack == NULL)
		return NULL;
    else
        return TopStack->element;   
}
