#include "HashTableVector.h"

#pragma warning(disable: 4996 6387 4996 3692)
#pragma warning(suppress : 4996)

//
// HashTable:
//
// Propósito: Inicializa una tabla hash vacía.
// Argumentos: No tiene.
// Efecto colateral: La tabla es inicializada en vacío.
//
HashTable::HashTable()
{
	Data_Count = 0;
}

//
// ~HashTable:
//
// Propósito: Destruye una tabla hash.
// Argumentos: No tiene.
// Efecto colateral: Todos los elementos de la lista son eliminados.
//
HashTable::~HashTable()
{
}

//
// HashTableCount:
//
// Propósito: Devuelve la cantidad de elementos almacenados en la tabla.
// Argumentos: No tiene.
// Efecto colateral: No tiene.
//
LengthType HashTable::HashTableCount()
{
	return Data_Count;
}

//
// HashTableKey:
//
// Propósito: Devuelve la llave de la tabla del nodo dado.
// Argumentos: Nodo del cual se desea saber la llave.
// Efecto colateral: No tiene.
//
KeyType HashTable::HashTableKey(HashTableNode node)const
{
	return node.element.Key;
}

//
// HashTableAdd:
//
// Propósito: Añade a la tabla un nodo.
// Argumentos: Llave y contenido del nodo a añadir.
// Efecto colateral: No tiene.
// Retorna: True si el nodo puede ser añadido.
//
bool HashTable::HashTableAdd(const KeyType key, InformationType information)
{
	HashTableNode new_node;
	PositionType p;
	

	new_node.element.Information = information;
	new_node.element.Key = key;
	p = Hash_Function(new_node.element.Key);
	Data_Count++;
	if (Data[p][0].element.Information.suma == MAX_HASH)
	{
		return false;
	}
	Data_Count++;
	if (Data[p] == 1)
		Data_[p][0] = Data_Count;
	else
		Data[p][Data[p][0]] = new_node;
	return true;
}

//
// HashTableInformationUpdate:
//
// Propósito: Actualiza la información a la tabla un nodo.
// Argumentos: Llave y contenido a actualizar.
// Efecto colateral: No tiene.
// Retorna: True si el nodo puede ser actualizado, es importante que la llave no cambie.
//
bool HashTable::HashTableInformationUpdate(const KeyType key, InformationType new_information)
{
	PositionType p;
	p = Hash_Function(key);

	if (Data[p].empty())
		return false;
	for (unsigned int i = 0; i < Data[p].size(); i++)
	{
		if (Data[p][i].element.Key) == key)
		{
			Data[p][i].element.Information = new_information; 
			return true; 
		}
	}
	return false;
}


//
// HashTableFind:
//
// Propósito: Devuelve la información de un nodo.
// Argumentos: Llave y contenido para devolver.
// Efecto colateral: No tiene.
// Retorna: True si el nodo puede ser encontrado en la tabla y tiene información.
//
bool HashTable::HashTableFind(const KeyType key, InformationType& information) const
{

	PositionType p;
	p = Hash_Function(key);
	if (Data[p].empty())
		return false;

	for (unsigned int i = 0; i < Data[p].size(); i++)
	{
		if (Data[p][i].element.Key) == key)
		{
			information= Data[p][i].element.Information;
			return true;
		}

	}
	return false;
}

//
// HashTableDelete:
//
// Propósito: Borra un nodo de la tabla.
// Argumentos: Llave del nodo a eliminar.
// Efecto colateral: No tiene.
// Retorna: True si el nodo puede ser borrado y si en la llave proporcionada existe información.
//
bool HashTable::HashTableDelete(const KeyType key)
{
	PositionType p;
	p = Hash_Function(key);

	if (Data[p].empty())
		return false;
	
	for (auto i = begin(Data[p]); i != Data[p].end(); i++)
	{
		if (Data[p][i].element.Key) == key)
		{
			Data_Count[p]--;
			Data[p].erase(i); 
			return true;
		}
	}
	return false;
}

//
// HashTableEmpty:
//
// Propósito: Devuelve true si una tabla hash no tiene elementos.
// Efecto colateral: No tiene.
// Retorna: True si la tabla es vacía.
//
bool HashTable::HashTableEmpty() const
{
	return !Data_Count;
}

//
// HashTableFirstNode:
//
// Propósito: Devuelve el primer nodo con información de la tabla Hash.
// Efecto colateral: No tiene.
// Retorna: Devuelve el primer nodo con información de la tabla hash si no devuelve NULL.
//
HashTableNode HashTable::HashTableFirstNode() const
{
	HashTableNode vec;
	vec.element.Information = {0};

	if (Data_Count == 0)
		return vec;
	for (PositionType i = 0; i < MAX_HASH; i++)
	{
		if (!Data[i].empty())
		{
			return Data[i][0];
		}

	}
	return vec; 
}

//
// HashTableNextNode:
//
// Propósito: Devuelve el nodo siguiente al nodo actual con información de la tabla Hash .
// Efecto colateral: No tiene.
// Retorna: Devuelve el nodo siguiente con información de la tabla hash si no devuelve NULL.
//
HashTableNode HashTable::HashTableNextNode(HashTableNode actual_node) const
{
	HashTableNode vec;
	vec.element.Information = { 0 };
	
	if (Data_Count == 0)
		return vec;

	PositionType p;
	p = Hash_Function(actual_node.element.Key);

	for (PositionType i = p; i < MAX_HASH; i++)
	{
		if (!Data[i].empty())
		{
			if (Data[i].size() != 1)
			{
				for (unsigned int j = 0; j < Data[i].size(); j++)
				{
					if (strcmp(Data[i][j].element.Key, actual_node.element.Key) == 0)
					{
						return Data[i][j + 1];

					}
				}
			}
			else
				return Data[i][0]; 
		}
			
	}
	return vec;

}


PositionType HashTable::Hash_Function(const KeyType key)const
{
	return key % MAX_HASH;
}