#pragma once

#include <string>
#include <vector>

using namespace std;

//
// HashTable.h:
//
// Este ADT implementa una Tabla Hash con un arreglo de apuntadores a informaci�n, si existe colisi�n.
// en cada elemento del arreglo se crea una vector con los elementos que van en esa posici�n.
// El tipo de elementos a almacenar puede redefinirlo el usuario con el tipo ItemType.
// La m�xima cantidad de elementos por lista est� limitada por la memoria disponible.
// Tiene cada elemento de la lista una referencia al siguiente y al anterior.
//


typedef unsigned int PositionType;
typedef unsigned int LengthType;
const LengthType MAX_HASH = 100;
const unsigned int MAX_KEY_LENGHT = 300;


// Unico que puede cambiar el usuario
typedef unsigned int KeyType; //para este ejemplo la llave es el nombre y apellidos
typedef struct
{
	string nombre;
	unsigned int estatura;
	unsigned int peso;
	unsigned int edad;
	unsigned int suma= estatura + peso + edad;
} InformationType;
// aqu� termina


struct ElementType
{
	InformationType Information;
	KeyType Key = Information.suma;
};

struct HashTableNode
{
	ElementType element;

};


class HashTable
{
public:

	//
	// HashTable:
	//
	// Prop�sito: Inicializa una tabla hash vac�a.
	// Argumentos: No tiene.
	// Efecto colateral: La tabla es inicializada en vac�o.
	//
	HashTable();

	//
	// ~HashTable:
	//
	// Prop�sito: Destruye una tabla hash.
	// Argumentos: No tiene.
	// Efecto colateral: Todos los elementos de la lista son eliminados.
	//
	~HashTable();

	//
	// HashTableCount:
	//
	// Prop�sito: Devuelve la cantidad de elementos almacenados en la tabla.
	// Argumentos: No tiene.
	// Efecto colateral: No tiene.
	//
	LengthType HashTableCount();

	//
	// HashTableKey:
	//
	// Prop�sito: Devuelve la llave de la tabla del nodo dado.
	// Argumentos: Nodo del cual se desea saber la llave.
	// Efecto colateral: No tiene.
	//
	KeyType HashTableKey(HashTableNode node) const;

	//
	// HashTableAdd:
	//
	// Prop�sito: A�ade a la tabla un nodo.
	// Argumentos: Llave y contenido del nodo a a�adir.
	// Efecto colateral: No tiene.
	// Retorna: True si el nodo puede ser a�adido.
	//
	bool HashTableAdd(const KeyType key, InformationType information);

	//
	// HashTableInformationUpdate:
	//
	// Prop�sito: Actualiza la informaci�n a la tabla un nodo.
	// Argumentos: Llave y contenido a actualizar.
	// Efecto colateral: No tiene.
	// Retorna: True si el nodo puede ser actualizado, es importante que la llave no cambie.
	//
	bool HashTableInformationUpdate(const KeyType key, InformationType new_information);

	//
	// HashTableFind:
	//
	// Prop�sito: Devuelve la informaci�n de un nodo.
	// Argumentos: Llave y contenido para devolver.
	// Efecto colateral: No tiene.
	// Retorna: True si el nodo puede ser encontrado en la tabla y tiene informaci�n.
	//
	bool HashTableFind(const KeyType key, InformationType& information) const;

	//
	// HashTableDelete:
	//
	// Prop�sito: Borra un nodo de la tabla.
	// Argumentos: Llave del nodo a eliminar.
	// Efecto colateral: No tiene.
	// Retorna: True si el nodo puede ser borrado y si en la llave proporcionada existe informaci�n.
	//
	bool HashTableDelete(const KeyType key);

	//
	// HashTableEmpty:
	//
	// Prop�sito: Devuelve true si una tabla hash no tiene elementos.
	// Efecto colateral: No tiene.
	// Retorna: True si la tabla es vac�a.
	//
	bool HashTableEmpty() const;

	//
	// HashTableFirstNode:
	//
	// Prop�sito: Devuelve el primer nodo con informaci�n de la tabla Hash.
	// Efecto colateral: No tiene.
	// Retorna: Devuelve el primer nodo con informaci�n de la tabla hash si no devuelve NULL.
	//
	HashTableNode HashTableFirstNode() const;

	//
	// HashTableNextNode:
	//
	// Prop�sito: Devuelve el nodo siguiente al nodo actual con informaci�n de la tabla Hash .
	// Efecto colateral: No tiene.
	// Retorna: Devuelve el nodo siguiente con informaci�n de la tabla hash si no devuelve NULL.
	//
	HashTableNode HashTableNextNode(HashTableNode actual_node) const;


private:
	LengthType Data_Count;
	HashTableNode Data[MAX_HASH+1][MAX_HASH+1];
	PositionType Hash_Function(KeyType key) const;

};

