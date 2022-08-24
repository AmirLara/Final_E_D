#pragma once

#include <stdlib.h>
using namespace std;

//
// Curtain.h
//
// Este ADT implementa una cortina (lista de listas) sobre un arreglo bidimensional
// El tipo de elementos a almacenar puede redefinirlo el usuario con el tipo LengthType
// La m�xima cantidad de elementos por lista est� limitada por la constante MAX_LENGTH
// La m�xima cantidad de listas est� limitada por la constante MAX_LIST

typedef unsigned int CurtainPositionType;
typedef unsigned int ListPositionType;
typedef unsigned int CurtainLengthType;
typedef unsigned int ListLengthType;

// �nico que puede cambiar el usuario
typedef unsigned int ItemType;
const ListLengthType MAX_LENGTH = 15;
const CurtainLengthType MAX_LIST = 10;
// aqu� termina


class Curtain
{
public:
	//
	// Curtain
	//
	// Prop�sito: Inicializa una cortina vac�a.
	// Argumentos: No tiene.
	// Efecto colateral: La cortina es inicializada en vac�o.
	//
	Curtain();

	//
	// ~Curtain
	//
	// Prop�sito: Destruye una cortina.
	// Argumentos: No tiene.
	// Efecto colateral: Todos los elementos de la cortina son eliminados.
	//
	~Curtain();

	//
	// CurtainEmpty
	//
	// Prop�sito: Verifica si una cortina es vac�a.
	// Argumentos: No tiene.
	// Retorna: True si la cortina es vac�a, False en cualquier otro caso.
	// Efecto colateral: No tiene.
	//
	bool CurtainEmpty() const;

	//
	// CurtainFull
	//
	// Prop�sito: Verifica si una cortina est� llena.
	// Argumentos: No tiene.
	// Retorna: True si la cortina est� lena, False en cualquier otro caso.
	// Efecto colateral: No tiene.
	//
	bool CurtainFull() const;

	//
	// CurtainLength
	//
	// Prop�sito: Devolver la cantidad de listas almacenados en una cortina.
	// Argumentos: No tiene.
	// Retorna: Retorna un dato del tipo LengthType con la cantidad de listas almacenados en
	// la cortina. Si no hay listas almacenadas retorna 0.
	// Efecto colateral: No tiene.
	//
	CurtainLengthType CurtainLength() const;

	//
	// CurtainInsert
	//
	// Prop�sito: Inserta un lista en una posici�n p.
	// Argumentos: 
	//	a: Lista a insertar (se pasa como un arreglo).
	// 	count_a: cantidad de elementos en a.
	// 	p: Posici�n de la cortina en la que se desea insertar la lista.
	// Retorna: Retorna True si fue posible insertar la lista, False en cualquier otro caso.
	// Precondiciones: La cortina no puede estar llena y la posici�n p tiene que ser una posici�n
	// v�lida.
	// Efecto colateral: Las listas desde la posici�n p son recorridos hacia el final
	// de la cortina para crear espacio para la lista a insertar.
	//
	bool CurtainInsert(ItemType a[], unsigned int count_a,  CurtainPositionType p);

	//
	// CurtainUpdate
	//
	// Prop�sito: Actualizar la informaci�n de la lista que est� en la posici�n p de la cortina.
	// Argumentos: 
	//	a: Lista (en un arreglo) con la nueva informaci�n.
	// 	count_a: Cantidad de elementos en a.
	// 	p: Posici�n de la lista de la cortina que se desea actualizar.
	// Retorna: Retorna True si fue posible actualizar la lista, False en cualquier otro caso.
	// Precondiciones: La cortina no puede estar vac�a y la posici�n p tiene que ser una posici�n
	// v�lida.
	// Efecto colateral: No hay.
	//
	bool CurtainUpdate(ItemType a[], unsigned int count_a, CurtainPositionType p);

	//
	// CurtainAdd
	//
	// Prop�sito: Adiciona una lista a una cortina.
	// Argumentos: 
	//	a: lista (como arreglo) a a�adir a la cortina.
	// 	count_a: Cantidad de elementos en a.
	// Retorna: Retorna True si fue posible a�adir la lista, False en cualquier otro caso.
	// Precondiciones: La cortina no puede estar llena.
	// 
	//
	bool CurtainAdd(ItemType a[], unsigned int count_a);

	//
	// CurtainDelete
	//
	// Prop�sito: Eliminar la lista que ocupa la posici�n p en la cortina.
	// Argumentos: 
	//	p: Posici�n de la cortina que se desa eliminar.
	// Retorna: Retorna True si fue posible eliminar la lista, False en cualquier otro caso.
	// Precondiciones: La cortina no puede estar vac�a y la posici�n p tiene que ser una posici�n
	// v�lida.
	// Efecto colateral: Listas desde la posici�n Next(p) son recorridas hacia el inicio
	// de la cortina para ocupar el espacio de la lista eliminada.
	//
	bool CurtainDelete(CurtainPositionType p);

	//
	// CurtainSearch
	//
	// Prop�sito: Buscar si una lista (dada como un arreglo) aparece en una cortina.
	// Argumentos: 
	//	a: Lista a buscar (dada como un arreglo).
	// 	count_a: Cantidad de elementos en a.
	// 	p: Posici�n de la cortina en la que aparece la lista.
	// Retorna: Retorna a trav�s del argumento p la posici�n en la que aparece la lista en la
	// cortina y retorna True en el m�todo. Si no est� el m�todo retorna False y en p se retorna NULL. 
	// Si aparece en m�s de una posici�n, retornar� la primera
	// o sea la m�s cercana al inicio de la cortina.
	// Precondiciones: La cortina no puede estar vac�a.
	// 
	//
	bool CurtainSearch(ItemType a[], unsigned int count_a, CurtainPositionType& p) const;

	//
	// CurtainObtain
	//
	// Prop�sito: Devuelve la lista que est� en la posici�n p en una cortina.
	// Argumentos: 
	//	a: Lista (como un arreglo) a devolver.
	// 	count_a: Cantidad de elementos en a.
	// 	p: Posici�n de la cortina en la que aparece la lista.
	// Retorna: Retorna a trav�s del argumento a la lista que est� en la posici�n p de la
	// cortina y retorna True en el m�todo. Si no est� el m�todo retorna False. 
	// Precondiciones: La cortina no puede estar vac�a y la posici�n p tiene que ser una posici�n
	// v�lida.
	// 
	//
	bool CurtainObtain(ItemType a[], unsigned int& count_a, CurtainPositionType p) const;

	//
	// CurtainFirst
	//
	// Prop�sito: Devuelve la primera posici�n de una cortina.
	// Argumentos: No tiene.
	// Retorna: Retorna un dato del tipo CurtainPositionType con la primera posici�n de la cortina. Si 
	// la cortina est� vac�a devuelve NULL.
	// Efecto colateral: No tiene.
	//
	CurtainPositionType CurtainFirst() const;

	//
	// CurtainLast
	//
	// Prop�sito: Devuelve la �ltima posici�n de una cortina.
	// Argumentos: No tiene.
	// Retorna: Retorna un dato del tipo CurtainPositionType con la �ltima posici�n de la 
	// cortina. Si la cortina est� vac�a devuelve NULL.
	// Efecto colateral: No tiene.
	//
	CurtainPositionType CurtainLast() const;

	//
	// CurtainNext
	//
	// Prop�sito: Devuelve la posici�n siguiente a una posici�n p de una cortina.
	// Argumentos: 
	// 	   p: Posici�n de la cortina para conocer la siguiente posici�n.
	// Retorna: Retorna un dato del tipo CurtainPositionType con la posici�n siguiente a p de 
	// la cortina. Si la cortina est� vac�a devuelve NULL o si p es la �ltima posici�n de la 
	// cortina.
	// Efecto colateral: No tiene.
	//
	CurtainPositionType CurtainNext(CurtainPositionType p) const;

	//
	// CurtainPrevious
	//
	// Prop�sito: Devuelve la posici�n anterior a una posici�n p de una cortina.
	// Argumentos: 
	// 	   p: Posici�n de la cortina para conocer la anterior.
	// Retorna: Retorna un dato del tipo CurtainPositionType con la posicion anterior a p de la 
	// cortina. Si la cortina est� vac�a devuelve NULL, o si p es la primera posici�n de la 
	// cortina.
	// Efecto colateral: No tiene
	//
	CurtainPositionType CurtainPrevious(CurtainPositionType p) const;

	//
	// ListEmpty
	//
	// Prop�sito: Verifica si una lista es vac�a en una cortina.
	// Argumentos: 
	// 	   p: Posici�n de la lista en la cortina
	// Retorna: True si la lista es vac�a, False en cualquier otro caso.
	// Efecto colateral: No tiene.
	//
	bool ListEmpty(CurtainPositionType p) const;

	//
	// ListFull
	//
	// Prop�sito: Verifica si una lista de la posici�n p de una cortina est� llena.
	// Argumentos: 
	// 	   p: Posici�n de la lista en la cortina.
	// Retorna: True si la lista est� llena, False en cualquier otro caso.
	// Efecto colateral: No tiene.
	//
	bool ListFull(CurtainPositionType p) const;

	//
	// ListLength
	//
	// Prop�sito: Devolver la cantidad de elementos almacenados en una lista de una posicion p de 
	// una cortina.
	// Argumentos: 
	// 	   p: Posici�n de la lista en la cortina.
	// Retorna: Retorna un dato del tipo ListLengthType con la cantidad de elementos almacenados 
	// en la lista. Si no hay elementos almacenados retorna 0.
	// Efecto colateral: No tiene.
	//
	ListLengthType ListLength(CurtainPositionType p) const;

	//
	// ListInsert
	//
	// Prop�sito: Inserta un elemento en una posici�n p_element de una lista que est� en la posici�n
	// p_list de la cortina.
	// Argumentos: 
	//	a: Elemento a insertar.
	// 	p_list: Posici�n de la lista en la cortina.
	//  p_element: Posici�n de la lista en la que se desa insertar el elmento a.
	// Retorna: Retorna True si fue posible insertar el elemento, False en cualquier otro caso.
	// Precondiciones: La lista no puede estar llena y la posici�n p_element tiene que ser una 
	// posici�n v�lida de la lista y p_list una posici�n v�lida de la cortina.
	// Efecto colateral: Los elementos desde la posici�n p_element son recorridos hacia el final
	// de la lista para crear espacio para el elemento a insertar.
	//
	bool ListInsert(ItemType a, ListPositionType p_element, CurtainPositionType p_list);

	//
	// ListUpdate
	//
	// Prop�sito: Actualizar un elemento en una posici�n p_element de una lista que est� en la posici�n
	// p_list de la cortina.
	// Argumentos: 
	//	a: Elemento a actualizar.
	// 	p_list: Posici�n de la lista en la cortina.
	//  p_element: Posici�n de la lista en la que se desea actualizar el elmento a.
	// Retorna: Retorna True si fue posible actualizar el elemento, False en cualquier otro caso.
	// Precondiciones: La lista no puede estar llena y la posici�n p_element tiene que ser una 
	// posici�n v�lida de la lista y p_list una posici�n v�lida de la cortina.
	// Efecto colateral: No hay.
	//
	bool ListUpdate(ItemType a, ListPositionType p_element, CurtainPositionType p_list);

	//
	// ListAdd
	//
	// Prop�sito: Adiciona un elemento a una lista de la cortina.
	// Argumentos: 
	//	a: Elemento a a�adir a la lista.
	// 	p: Posici�n de la lista en la cortina.
	// Retorna: Retorna True si fue posible insertar el elemento, False en cualquier otro caso.
	// Precondiciones: La lista no puede estar llena.
	// 
	//
	bool ListAdd(ItemType a, CurtainPositionType p_list);

	//
	// ListDelete
	//
	// Prop�sito: Eliminar el elemento que ocupa la posicion p de la lista de la cortina.
	// Argumentos: 
	//	p_element: Posici�n de la lista del elemento que se desa eliminar.
	// 	p_list: Lista de la cortina de la que se desea eliminar el elemento.
	// Retorna: Retorna True si fue posible eliminar el elemento, False en cualquier otro caso.
	// Precondiciones: La lista no puede estar vac�a y ambas posiciones tiene que ser v�lida.
	// Efecto colateral: Los elementos desde la posici�n Next(p_element) son recorridos hacia el 
	// inicio de la lista para ocupar el espacio del elemento eliminado.
	//
	bool ListDelete(ListPositionType p_element, CurtainPositionType p_list);

	//
	// ListSearch
	//
	// Prop�sito: Buscar si un elemento aparece en una lista de la cortina.
	// Argumentos: 
	//	a: Elemento a buscar.
	// 	p_list: Posici�n de la lista de la cortina.
	// 	p_element: Posici�n del elemento buscado.
	// Retorna: Retorna a trav�s del argumento p_element la posici�n en la que aparece el elemento
	// en la lista que cupa la posici�n p_list en la cortina y retorna True en el m�todo. Si no 
	// est� el m�todo retorna False y en p_element se retorna NULL. Si aparece en m�s de una 
	// posici�n, retornar� la primera o sea la m�s cercana al inicio de la lista.
	// Precondiciones: La lista no puede estar vac�a.
	// 
	//
	bool ListSearch(ItemType a, CurtainPositionType p_list, ListPositionType& p) const;

	//
	// ListObtain
	//
	// Prop�sito: Devuelve el elemento que est� en la posici�n p_element en una lista.
	// Argumentos: 
	//	a: Elemento a devolver.
	// 	p_element: Posici�n de la lista en la que aparece el elemento.
	// 	p_list: Posici�n de la lista en la cortina.
	// Retorna: Retorna a trav�s del argumento a el elemento que est� en la posici�n p_element de 
	// la lista y retorna True en el m�todo. Si no est� el m�todo retorna False. 
	// Precondiciones: La lista no puede estar vac�a y la posici�n p_element y p_list tienen
	// que ser posiciones v�lidas.
	// 
	//
	bool ListObtain(ItemType& a, CurtainPositionType p_list, ListPositionType p_element) const;

	//
	// ListFirst
	//
	// Prop�sito: Devuelve la primera posicion de una lista.
	// Argumentos: 
	// 	   p_list: Posici�n de la lista en la cortina.
	// Retorna: Retorna un dato del tipo ListPositionType con la primera posicion de la lista. Si 
	// la lista est� vac�a devuelve NULL.
	// Efecto colateral: No tiene.
	//
	ListPositionType ListFirst(CurtainPositionType p_list) const;

	//
	// ListLast
	//
	// Prop�sito: Devuelve la �ltima posicion de una lista.
	// Argumentos: 
	//     p_list: Posici�n de la lista en la cortina.
	// Retorna: Retorna un dato del tipo ListPositionType con la �ltima posici�n de la lista. Si 
	// la lista est� vac�a devuelve NULL.
	// Efecto colateral: No tiene.
	//
	ListPositionType ListLast(CurtainPositionType p_list) const;

	//
	// ListNext
	//
	// Prop�sito: Devuelve la posici�n siguiente a una posici�n p_element de una lista de la cortina.
	// Argumentos: 
	// 	   p_element: Posici�n de la lista para conocer la siguiente.
	// 	   p_list: Posici�n de la lista en la cortina.
	// Retorna: Retorna un dato del tipo ListPositionType con la posici�n siguiente a p_element de
	// la lista. Si la lista est� vac�a devuelve NULL o si p_element es la �ltima posici�n de la lista.
	// Efecto colateral: No tiene.
	//
	ListPositionType ListNext(CurtainPositionType p_list, ListPositionType p_element) const;

	//
	// ListPrevious
	//
	// Prop�sito: Devuelve la posicion anterior a una posici�n p_element de una lista de la cortina.
	// Argumentos: 
	// 	   p_element: Posici�n de la lista para conocer la anterior posici�n.
	// 	   p_list: Posici�n de la lista en la cortina.
	// Retorna: Retorna un dato del tipo ListPositionType con la posici�n anterior a p_element de
	// la lista. Si la lista est� vac�a devuelve NULL o si p_element es la primera posici�n de la lista.
	// Efecto colateral: No tiene.
	//
	ListPositionType ListPrevious(CurtainPositionType p_list, ListPositionType p_element) const;




private:

	CurtainLengthType List_Count;
	ItemType Data[MAX_LIST+1][MAX_LENGTH+1];

	//
	// ValidCurtainPosition
	// 
	// Verifica si una posici�n en la cortina es v�lida.
	//
	bool ValidCurtainPosition(CurtainPositionType p_curtain) const;

	//
	// ValidListPosition
	// 
	// Verifica si una posici�n en la lista es v�lida.
	//
	bool ValidListPosition(CurtainPositionType p_curtain, ListPositionType p_lis) const;
	
};

