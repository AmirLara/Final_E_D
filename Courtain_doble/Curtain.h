#pragma once

#include <stdlib.h>
using namespace std;

//
// Curtain.h
//
// Este ADT implementa una cortina (lista de listas) sobre un arreglo bidimensional
// El tipo de elementos a almacenar puede redefinirlo el usuario con el tipo LengthType
// La máxima cantidad de elementos por lista está limitada por la constante MAX_LENGTH
// La máxima cantidad de listas está limitada por la constante MAX_LIST

typedef unsigned int CurtainPositionType;
typedef unsigned int ListPositionType;
typedef unsigned int CurtainLengthType;
typedef unsigned int ListLengthType;

// único que puede cambiar el usuario
typedef unsigned int ItemType;
const ListLengthType MAX_LENGTH = 15;
const CurtainLengthType MAX_LIST = 10;
// aquí termina


class Curtain
{
public:
	//
	// Curtain
	//
	// Propósito: Inicializa una cortina vacía.
	// Argumentos: No tiene.
	// Efecto colateral: La cortina es inicializada en vacío.
	//
	Curtain();

	//
	// ~Curtain
	//
	// Propósito: Destruye una cortina.
	// Argumentos: No tiene.
	// Efecto colateral: Todos los elementos de la cortina son eliminados.
	//
	~Curtain();

	//
	// CurtainEmpty
	//
	// Propósito: Verifica si una cortina es vacía.
	// Argumentos: No tiene.
	// Retorna: True si la cortina es vacía, False en cualquier otro caso.
	// Efecto colateral: No tiene.
	//
	bool CurtainEmpty() const;

	//
	// CurtainFull
	//
	// Propósito: Verifica si una cortina está llena.
	// Argumentos: No tiene.
	// Retorna: True si la cortina está lena, False en cualquier otro caso.
	// Efecto colateral: No tiene.
	//
	bool CurtainFull() const;

	//
	// CurtainLength
	//
	// Propósito: Devolver la cantidad de listas almacenados en una cortina.
	// Argumentos: No tiene.
	// Retorna: Retorna un dato del tipo LengthType con la cantidad de listas almacenados en
	// la cortina. Si no hay listas almacenadas retorna 0.
	// Efecto colateral: No tiene.
	//
	CurtainLengthType CurtainLength() const;

	//
	// CurtainInsert
	//
	// Propósito: Inserta un lista en una posición p.
	// Argumentos: 
	//	a: Lista a insertar (se pasa como un arreglo).
	// 	count_a: cantidad de elementos en a.
	// 	p: Posición de la cortina en la que se desea insertar la lista.
	// Retorna: Retorna True si fue posible insertar la lista, False en cualquier otro caso.
	// Precondiciones: La cortina no puede estar llena y la posición p tiene que ser una posición
	// válida.
	// Efecto colateral: Las listas desde la posición p son recorridos hacia el final
	// de la cortina para crear espacio para la lista a insertar.
	//
	bool CurtainInsert(ItemType a[], unsigned int count_a,  CurtainPositionType p);

	//
	// CurtainUpdate
	//
	// Propósito: Actualizar la información de la lista que está en la posición p de la cortina.
	// Argumentos: 
	//	a: Lista (en un arreglo) con la nueva información.
	// 	count_a: Cantidad de elementos en a.
	// 	p: Posición de la lista de la cortina que se desea actualizar.
	// Retorna: Retorna True si fue posible actualizar la lista, False en cualquier otro caso.
	// Precondiciones: La cortina no puede estar vacía y la posición p tiene que ser una posición
	// válida.
	// Efecto colateral: No hay.
	//
	bool CurtainUpdate(ItemType a[], unsigned int count_a, CurtainPositionType p);

	//
	// CurtainAdd
	//
	// Propósito: Adiciona una lista a una cortina.
	// Argumentos: 
	//	a: lista (como arreglo) a añadir a la cortina.
	// 	count_a: Cantidad de elementos en a.
	// Retorna: Retorna True si fue posible añadir la lista, False en cualquier otro caso.
	// Precondiciones: La cortina no puede estar llena.
	// 
	//
	bool CurtainAdd(ItemType a[], unsigned int count_a);

	//
	// CurtainDelete
	//
	// Propósito: Eliminar la lista que ocupa la posición p en la cortina.
	// Argumentos: 
	//	p: Posición de la cortina que se desa eliminar.
	// Retorna: Retorna True si fue posible eliminar la lista, False en cualquier otro caso.
	// Precondiciones: La cortina no puede estar vacía y la posición p tiene que ser una posición
	// válida.
	// Efecto colateral: Listas desde la posición Next(p) son recorridas hacia el inicio
	// de la cortina para ocupar el espacio de la lista eliminada.
	//
	bool CurtainDelete(CurtainPositionType p);

	//
	// CurtainSearch
	//
	// Propósito: Buscar si una lista (dada como un arreglo) aparece en una cortina.
	// Argumentos: 
	//	a: Lista a buscar (dada como un arreglo).
	// 	count_a: Cantidad de elementos en a.
	// 	p: Posición de la cortina en la que aparece la lista.
	// Retorna: Retorna a través del argumento p la posición en la que aparece la lista en la
	// cortina y retorna True en el método. Si no está el método retorna False y en p se retorna NULL. 
	// Si aparece en más de una posición, retornará la primera
	// o sea la más cercana al inicio de la cortina.
	// Precondiciones: La cortina no puede estar vacía.
	// 
	//
	bool CurtainSearch(ItemType a[], unsigned int count_a, CurtainPositionType& p) const;

	//
	// CurtainObtain
	//
	// Propósito: Devuelve la lista que está en la posición p en una cortina.
	// Argumentos: 
	//	a: Lista (como un arreglo) a devolver.
	// 	count_a: Cantidad de elementos en a.
	// 	p: Posición de la cortina en la que aparece la lista.
	// Retorna: Retorna a través del argumento a la lista que está en la posición p de la
	// cortina y retorna True en el método. Si no está el método retorna False. 
	// Precondiciones: La cortina no puede estar vacía y la posición p tiene que ser una posición
	// válida.
	// 
	//
	bool CurtainObtain(ItemType a[], unsigned int& count_a, CurtainPositionType p) const;

	//
	// CurtainFirst
	//
	// Propósito: Devuelve la primera posición de una cortina.
	// Argumentos: No tiene.
	// Retorna: Retorna un dato del tipo CurtainPositionType con la primera posición de la cortina. Si 
	// la cortina está vacía devuelve NULL.
	// Efecto colateral: No tiene.
	//
	CurtainPositionType CurtainFirst() const;

	//
	// CurtainLast
	//
	// Propósito: Devuelve la última posición de una cortina.
	// Argumentos: No tiene.
	// Retorna: Retorna un dato del tipo CurtainPositionType con la última posición de la 
	// cortina. Si la cortina está vacía devuelve NULL.
	// Efecto colateral: No tiene.
	//
	CurtainPositionType CurtainLast() const;

	//
	// CurtainNext
	//
	// Propósito: Devuelve la posición siguiente a una posición p de una cortina.
	// Argumentos: 
	// 	   p: Posición de la cortina para conocer la siguiente posición.
	// Retorna: Retorna un dato del tipo CurtainPositionType con la posición siguiente a p de 
	// la cortina. Si la cortina está vacía devuelve NULL o si p es la última posición de la 
	// cortina.
	// Efecto colateral: No tiene.
	//
	CurtainPositionType CurtainNext(CurtainPositionType p) const;

	//
	// CurtainPrevious
	//
	// Propósito: Devuelve la posición anterior a una posición p de una cortina.
	// Argumentos: 
	// 	   p: Posición de la cortina para conocer la anterior.
	// Retorna: Retorna un dato del tipo CurtainPositionType con la posicion anterior a p de la 
	// cortina. Si la cortina está vacía devuelve NULL, o si p es la primera posición de la 
	// cortina.
	// Efecto colateral: No tiene
	//
	CurtainPositionType CurtainPrevious(CurtainPositionType p) const;

	//
	// ListEmpty
	//
	// Propósito: Verifica si una lista es vacía en una cortina.
	// Argumentos: 
	// 	   p: Posición de la lista en la cortina
	// Retorna: True si la lista es vacía, False en cualquier otro caso.
	// Efecto colateral: No tiene.
	//
	bool ListEmpty(CurtainPositionType p) const;

	//
	// ListFull
	//
	// Propósito: Verifica si una lista de la posición p de una cortina está llena.
	// Argumentos: 
	// 	   p: Posición de la lista en la cortina.
	// Retorna: True si la lista está llena, False en cualquier otro caso.
	// Efecto colateral: No tiene.
	//
	bool ListFull(CurtainPositionType p) const;

	//
	// ListLength
	//
	// Propósito: Devolver la cantidad de elementos almacenados en una lista de una posicion p de 
	// una cortina.
	// Argumentos: 
	// 	   p: Posición de la lista en la cortina.
	// Retorna: Retorna un dato del tipo ListLengthType con la cantidad de elementos almacenados 
	// en la lista. Si no hay elementos almacenados retorna 0.
	// Efecto colateral: No tiene.
	//
	ListLengthType ListLength(CurtainPositionType p) const;

	//
	// ListInsert
	//
	// Propósito: Inserta un elemento en una posición p_element de una lista que está en la posición
	// p_list de la cortina.
	// Argumentos: 
	//	a: Elemento a insertar.
	// 	p_list: Posición de la lista en la cortina.
	//  p_element: Posición de la lista en la que se desa insertar el elmento a.
	// Retorna: Retorna True si fue posible insertar el elemento, False en cualquier otro caso.
	// Precondiciones: La lista no puede estar llena y la posición p_element tiene que ser una 
	// posición válida de la lista y p_list una posición válida de la cortina.
	// Efecto colateral: Los elementos desde la posición p_element son recorridos hacia el final
	// de la lista para crear espacio para el elemento a insertar.
	//
	bool ListInsert(ItemType a, ListPositionType p_element, CurtainPositionType p_list);

	//
	// ListUpdate
	//
	// Propósito: Actualizar un elemento en una posición p_element de una lista que está en la posición
	// p_list de la cortina.
	// Argumentos: 
	//	a: Elemento a actualizar.
	// 	p_list: Posición de la lista en la cortina.
	//  p_element: Posición de la lista en la que se desea actualizar el elmento a.
	// Retorna: Retorna True si fue posible actualizar el elemento, False en cualquier otro caso.
	// Precondiciones: La lista no puede estar llena y la posición p_element tiene que ser una 
	// posición válida de la lista y p_list una posición válida de la cortina.
	// Efecto colateral: No hay.
	//
	bool ListUpdate(ItemType a, ListPositionType p_element, CurtainPositionType p_list);

	//
	// ListAdd
	//
	// Propósito: Adiciona un elemento a una lista de la cortina.
	// Argumentos: 
	//	a: Elemento a añadir a la lista.
	// 	p: Posición de la lista en la cortina.
	// Retorna: Retorna True si fue posible insertar el elemento, False en cualquier otro caso.
	// Precondiciones: La lista no puede estar llena.
	// 
	//
	bool ListAdd(ItemType a, CurtainPositionType p_list);

	//
	// ListDelete
	//
	// Propósito: Eliminar el elemento que ocupa la posicion p de la lista de la cortina.
	// Argumentos: 
	//	p_element: Posición de la lista del elemento que se desa eliminar.
	// 	p_list: Lista de la cortina de la que se desea eliminar el elemento.
	// Retorna: Retorna True si fue posible eliminar el elemento, False en cualquier otro caso.
	// Precondiciones: La lista no puede estar vacía y ambas posiciones tiene que ser válida.
	// Efecto colateral: Los elementos desde la posición Next(p_element) son recorridos hacia el 
	// inicio de la lista para ocupar el espacio del elemento eliminado.
	//
	bool ListDelete(ListPositionType p_element, CurtainPositionType p_list);

	//
	// ListSearch
	//
	// Propósito: Buscar si un elemento aparece en una lista de la cortina.
	// Argumentos: 
	//	a: Elemento a buscar.
	// 	p_list: Posición de la lista de la cortina.
	// 	p_element: Posición del elemento buscado.
	// Retorna: Retorna a través del argumento p_element la posición en la que aparece el elemento
	// en la lista que cupa la posición p_list en la cortina y retorna True en el método. Si no 
	// está el método retorna False y en p_element se retorna NULL. Si aparece en más de una 
	// posición, retornará la primera o sea la más cercana al inicio de la lista.
	// Precondiciones: La lista no puede estar vacía.
	// 
	//
	bool ListSearch(ItemType a, CurtainPositionType p_list, ListPositionType& p) const;

	//
	// ListObtain
	//
	// Propósito: Devuelve el elemento que está en la posición p_element en una lista.
	// Argumentos: 
	//	a: Elemento a devolver.
	// 	p_element: Posición de la lista en la que aparece el elemento.
	// 	p_list: Posición de la lista en la cortina.
	// Retorna: Retorna a través del argumento a el elemento que está en la posición p_element de 
	// la lista y retorna True en el método. Si no está el método retorna False. 
	// Precondiciones: La lista no puede estar vacía y la posición p_element y p_list tienen
	// que ser posiciones válidas.
	// 
	//
	bool ListObtain(ItemType& a, CurtainPositionType p_list, ListPositionType p_element) const;

	//
	// ListFirst
	//
	// Propósito: Devuelve la primera posicion de una lista.
	// Argumentos: 
	// 	   p_list: Posición de la lista en la cortina.
	// Retorna: Retorna un dato del tipo ListPositionType con la primera posicion de la lista. Si 
	// la lista está vacía devuelve NULL.
	// Efecto colateral: No tiene.
	//
	ListPositionType ListFirst(CurtainPositionType p_list) const;

	//
	// ListLast
	//
	// Propósito: Devuelve la última posicion de una lista.
	// Argumentos: 
	//     p_list: Posición de la lista en la cortina.
	// Retorna: Retorna un dato del tipo ListPositionType con la última posición de la lista. Si 
	// la lista está vacía devuelve NULL.
	// Efecto colateral: No tiene.
	//
	ListPositionType ListLast(CurtainPositionType p_list) const;

	//
	// ListNext
	//
	// Propósito: Devuelve la posición siguiente a una posición p_element de una lista de la cortina.
	// Argumentos: 
	// 	   p_element: Posición de la lista para conocer la siguiente.
	// 	   p_list: Posición de la lista en la cortina.
	// Retorna: Retorna un dato del tipo ListPositionType con la posición siguiente a p_element de
	// la lista. Si la lista está vacía devuelve NULL o si p_element es la última posición de la lista.
	// Efecto colateral: No tiene.
	//
	ListPositionType ListNext(CurtainPositionType p_list, ListPositionType p_element) const;

	//
	// ListPrevious
	//
	// Propósito: Devuelve la posicion anterior a una posición p_element de una lista de la cortina.
	// Argumentos: 
	// 	   p_element: Posición de la lista para conocer la anterior posición.
	// 	   p_list: Posición de la lista en la cortina.
	// Retorna: Retorna un dato del tipo ListPositionType con la posición anterior a p_element de
	// la lista. Si la lista está vacía devuelve NULL o si p_element es la primera posición de la lista.
	// Efecto colateral: No tiene.
	//
	ListPositionType ListPrevious(CurtainPositionType p_list, ListPositionType p_element) const;




private:

	CurtainLengthType List_Count;
	ItemType Data[MAX_LIST+1][MAX_LENGTH+1];

	//
	// ValidCurtainPosition
	// 
	// Verifica si una posición en la cortina es válida.
	//
	bool ValidCurtainPosition(CurtainPositionType p_curtain) const;

	//
	// ValidListPosition
	// 
	// Verifica si una posición en la lista es válida.
	//
	bool ValidListPosition(CurtainPositionType p_curtain, ListPositionType p_lis) const;
	
};

