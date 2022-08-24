#include "Curtain.h"

//
// Curtain
//
// Prop�sito: Inicializa una cortina vac�a.
// Argumentos: No tiene.
// Efecto colateral: La cortina es inicializada en vac�o.
//
Curtain::Curtain()
{
	List_Count = 0;
	for(CurtainPositionType i=1; i<=MAX_LIST; i++)
	   Data[i][0]=0;
}

//
// ~List
//
// Prop�sito: Destruye una cortina.
// Argumentos: No tiene.
// Efecto colateral: Todos los elementos de la cortina son eliminados.
//
Curtain::~Curtain()
{

}

//
// CurtainEmpty
//
// Prop�sito: Verifica si una cortina es vac�a.
// Argumentos: No tiene.
// Retorna: True si la cortina es vac�a, False en cualquier otro caso.
// Efecto colateral: No tiene.
//
bool Curtain::CurtainEmpty() const
{
	return List_Count == 0;
}

//
// CurtainFull
//
// Prop�sito: Verifica si una cortina est� llena.
// Argumentos: No tiene.
// Retorna: True si la cortina est� lena, False en cualquier otro caso.
// Efecto colateral: No tiene.
//
bool Curtain::CurtainFull() const
{
	return List_Count == MAX_LIST;
}

//
// CurtainLength
//
// Prop�sito: Devolver la cantidad de listas almacenados en una cortina.
// Argumentos: No tiene.
// Retorna: Retorna un dato del tipo LengthType con la cantidad de listas almacenados en
// la cortina. Si no hay listas almacenadas retorna 0.
// Efecto colateral: No tiene.
//
CurtainLengthType Curtain::CurtainLength() const
{
	return List_Count;
}

//
// CurtainInsert
//
// Prop�sito: Inserta un lista en una posicion p.
// Argumentos: 
//	a: Lista a insertar (se pasa como un arreglo).
// 	count_a: Cantidad de elementos en a.
// 	p: Posici�n de la cortina en la que se desea insertar la lista.
// Retorna: Retorna True si fue posible insertar la lista, False en cualquier otro caso.
// Precondiciones: La cortina no puede estar llena y la posici�n p tiene que ser una posici�n
// v�lida.
// Efecto colateral: Las listas desde la posici�n p son recorridos hacia el final
// de la cortina para crear espacio para la lista a insertar.
//
bool Curtain::CurtainInsert(ItemType a[], unsigned int count_a, CurtainPositionType p)
{
	if (!ValidCurtainPosition(p) || CurtainFull())
		return false;
	// Mover listas hacia el final de la cortina
	for (CurtainPositionType i = List_Count; i > p; i--)
		for (ListPositionType j = 0; j <= Data[p][0]; j++)
			Data[i + 1][j] = Data[i][j];
	for (ListPositionType j = 1; j <= count_a; j++)
		Data[p][j] = a[j];
	Data[p][0] = count_a;
	List_Count++;
	return true;
}

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
bool Curtain::CurtainUpdate(ItemType a[], unsigned int count_a, CurtainPositionType p)
{
	if (!ValidCurtainPosition(p) || !CurtainEmpty())
		return false;
	for (ListPositionType j = 1; j <= count_a; j++)
		Data[p][j] = a[j];
	Data[p][0] = count_a;
	return true;
}

//
// CurtainAdd
//
// Prop�sito: Adiciona una lista a una cortina.
// Argumentos: 
//	a: Lista (como arreglo) a a�adir a la cortina.
// 	count_a: Cantidad de elementos en a.
// Retorna: Retorna True si fue posible a�adir la lista, False en cualquier otro caso.
// Precondiciones: La cortina no puede estar llena.
// 
bool Curtain::CurtainAdd(ItemType a[], unsigned int count_a)
{
	if (CurtainFull())
		return false;
	List_Count++;
	for (ListPositionType j = 1; j <= count_a; j++)
		Data[List_Count][j] = a[j];
	Data[List_Count][0] = count_a;
	return true;
}

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
bool Curtain::CurtainDelete(CurtainPositionType p)
{
	if (!ValidCurtainPosition(p) || CurtainEmpty())
		return false;
	// Mover listas hacia el inicio de la cortina
	for (CurtainPositionType i = p; i < List_Count; i++)
		for (ListPositionType j = 0; j <= Data[p][0]; j++)
			Data[i][j] = Data[i+1][j];
	List_Count--;
	return true;
}


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
bool Curtain::CurtainSearch(ItemType a[], unsigned int count_a, CurtainPositionType& p) const
{
	bool coinciden_todos = true;
	if (CurtainEmpty())
		return false;
	// Mover listas hacia el inicio de la cortina
	for (CurtainPositionType i = 1; i <= List_Count; i++)
	{
		if (count_a != Data[i][0])
			continue;
		for (ListPositionType j = 1; j <= count_a; j++)
			if (Data[i][j] != a[j])
			{
				coinciden_todos = false;
				break;
			}
		if (coinciden_todos)
		{
			p = i;
			return true;
		}
	}
	p = NULL;
	return false;
}

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
bool Curtain::CurtainObtain(ItemType a[], unsigned int& count_a, CurtainPositionType p) const
{
	if (!ValidCurtainPosition(p) || CurtainEmpty())
		return false;
	for (ListPositionType j = 1; j <= Data[p][0]; j++)
			a[j] = Data[p][j];
	count_a= Data[p][0];
	return true;
}

//
// CurtainFirst
//
// Prop�sito: Devuelve la primera posici�n de una cortina.
// Argumentos: No tiene.
// Retorna: Retorna un dato del tipo CurtainPositionType con la primera posici�n de la cortina. Si 
// la cortina est� vac�a devuelve NULL.
// Efecto colateral: No tiene.
//
CurtainPositionType Curtain::CurtainFirst() const
{
	return 1;
}

//
// CurtainLast
//
// Prop�sito: Devuelve la �ltima posici�n de una cortina.
// Argumentos: No tiene.
// Retorna: Retorna un dato del tipo CurtainPositionType con la �ltima posici�n de la 
// cortina. Si la cortina est� vac�a devuelve NULL.
// Efecto colateral: No tiene.
//
CurtainPositionType Curtain::CurtainLast() const
{
	return List_Count;
}

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
CurtainPositionType Curtain::CurtainNext(CurtainPositionType p) const
{
	if (!ValidCurtainPosition(p))
		return false;
	if (p != MAX_LIST)
	{
		p++;
		return p;
	}
	else
		return NULL;
}

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
CurtainPositionType Curtain::CurtainPrevious(CurtainPositionType p) const
{
	if (!ValidCurtainPosition(p))
		return false;
	if (p != 1)
	{
		p--;
		return p;
	}
	else
		return NULL;
}

//
// ListEmpty
//
// Prop�sito: Verifica si una lista es vac�a en una cortina.
// Argumentos: 
// 	   p: Posici�n de la lista en la cortina
// Retorna: True si la lista es vac�a, False en cualquier otro caso.
// Efecto colateral: No tiene.
//
bool Curtain::ListEmpty(CurtainPositionType p) const
{
	if (!ValidCurtainPosition(p))
		return false;
	return Data[p][0] == 0;
}

//
// ListFull
//
// Prop�sito: Verifica si una lista de la posici�n p de una cortina est� llena.
// Argumentos: 
// 	   p: Posici�n de la lista en la cortina.
// Retorna: True si la lista est� llena, False en cualquier otro caso.
// Efecto colateral: No tiene.
//
bool Curtain::ListFull(CurtainPositionType p) const
{
	if (!ValidCurtainPosition(p))
		return false;
	return Data[p][0] == 0;
}

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
ListLengthType Curtain::ListLength(CurtainPositionType p) const
{
	if (!ValidCurtainPosition(p))
		return false;
	return Data[p][0];
}

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
bool Curtain::ListInsert(ItemType a, ListPositionType p_element, CurtainPositionType p_list)
{
	if (!ValidCurtainPosition(p_list) || !ValidListPosition(p_list, p_element))
		return false;
	if (Data[p_list][0] == MAX_LENGTH)
		return false;
	if (Data[p_list][0] == 0)
	{
		Data[p_list][1] = a;
		Data[p_list][0] = 1;
		return true;
	}
	// Desplazando elementos hacia atr�s de la lista para hacer espacio y insertar el
	// elemento a.
	for (ListPositionType i = Data[p_list][0]; i >= p_element; i--)
		Data[p_list][i + 1] = Data[p_list][i];
	Data[p_list][p_element] = a;
	Data[p_list][0]++;
	return true;
}

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
bool Curtain::ListUpdate(ItemType a, ListPositionType p_element, CurtainPositionType p_list)
{
	if (!ValidCurtainPosition(p_list) || !ValidListPosition(p_list, p_element))
		return false;
	Data[p_list][p_element] = a;
	return true;
}

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
bool Curtain::ListAdd(ItemType a, CurtainPositionType p_list)
{
	if (!ValidCurtainPosition(p_list))
		return false;
	if (ListFull(p_list))
		return false;
	Data[p_list][0]++;
	Data[p_list][Data[p_list][0]] = a;
	return true;
}

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
bool Curtain::ListDelete(ListPositionType p_element, CurtainPositionType p_list)
{
	if (!ValidCurtainPosition(p_list) || !ValidListPosition(p_list, p_element))
		return false;
	if (ListEmpty(p_list))
		return false;
	for (ListPositionType i = p_element; i <= Data[p_list][0] - 1; i++)
		Data[p_list][i] = Data[p_list][i + 1];
	Data[p_list][0]--;
	return true;
}
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
bool Curtain::ListSearch(ItemType a, CurtainPositionType p_list, ListPositionType& p) const
{
	if (!ValidCurtainPosition(p_list))
		return false;
	if (ListEmpty(p_list))
		return false;
	for (ListPositionType i = 1; i <= Data[p_list][0]; i++)
		if (Data[p_list][i] == a)
		{
			p = i;
			return true;
		}
	p = NULL;
	return false;
}

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
bool Curtain::ListObtain(ItemType& a, CurtainPositionType p_list, ListPositionType p_element) const
{
	if (!ValidCurtainPosition(p_list) || !ValidListPosition(p_list, p_element))
		return false;
	a = Data[p_list][p_element];
	return true;
}


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
ListPositionType Curtain::ListFirst(CurtainPositionType p_list) const
{
	if (ListEmpty(p_list))
		return NULL;
	return 1;
}

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
ListPositionType Curtain::ListLast(CurtainPositionType p_list) const
{
	if (ListEmpty(p_list))
		return NULL;
	return Data[p_list][0];
}

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
ListPositionType Curtain::ListNext(CurtainPositionType p_list, ListPositionType p_element) const
{
	if (!ValidCurtainPosition(p_list) || !ValidListPosition(p_list, p_element))
		return false;
	if (p_element == MAX_LENGTH)
		return NULL;
	return p_element + 1;
}

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
ListPositionType Curtain::ListPrevious(CurtainPositionType p_list, ListPositionType p_element) const
{
	if (!ValidCurtainPosition(p_list) || !ValidListPosition(p_list, p_element))
		return false;
	if (p_element == 1)
		return NULL;
	return p_element - 1;
}

//
// ValidCurtainPosition
// 
// Verifica si una posici�n en la cortina es v�lida.
//
bool Curtain::ValidCurtainPosition(CurtainPositionType p_curtain) const
{
	return p_curtain >= 1 && p_curtain <= MAX_LIST;
}

//
// ValidListPosition
// 
// Verifica si una posici�n en la lista es v�lida.
//
bool Curtain::ValidListPosition(CurtainPositionType p_curtain, ListPositionType p_list) const
{
	if (!ValidCurtainPosition(p_curtain))
		return false;
	return p_list >= 1 && p_list <= Data[p_curtain][0];
}
