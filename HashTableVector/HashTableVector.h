#pragma once

#include <string>
#include <vector>

using namespace std;

//
// HashTable.h:
//
// Este ADT implementa una Tabla Hash con un arreglo de apuntadores a información, si existe colisión.
// en cada elemento del arreglo se crea una vector con los elementos que van en esa posición.
// El tipo de elementos a almacenar puede redefinirlo el usuario con el tipo ItemType.
// La máxima cantidad de elementos por lista está limitada por la memoria disponible.
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
// aquí termina


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
	// Propósito: Inicializa una tabla hash vacía.
	// Argumentos: No tiene.
	// Efecto colateral: La tabla es inicializada en vacío.
	//
	HashTable();

	//
	// ~HashTable:
	//
	// Propósito: Destruye una tabla hash.
	// Argumentos: No tiene.
	// Efecto colateral: Todos los elementos de la lista son eliminados.
	//
	~HashTable();

	//
	// HashTableCount:
	//
	// Propósito: Devuelve la cantidad de elementos almacenados en la tabla.
	// Argumentos: No tiene.
	// Efecto colateral: No tiene.
	//
	LengthType HashTableCount();

	//
	// HashTableKey:
	//
	// Propósito: Devuelve la llave de la tabla del nodo dado.
	// Argumentos: Nodo del cual se desea saber la llave.
	// Efecto colateral: No tiene.
	//
	KeyType HashTableKey(HashTableNode node) const;

	//
	// HashTableAdd:
	//
	// Propósito: Añade a la tabla un nodo.
	// Argumentos: Llave y contenido del nodo a añadir.
	// Efecto colateral: No tiene.
	// Retorna: True si el nodo puede ser añadido.
	//
	bool HashTableAdd(const KeyType key, InformationType information);

	//
	// HashTableInformationUpdate:
	//
	// Propósito: Actualiza la información a la tabla un nodo.
	// Argumentos: Llave y contenido a actualizar.
	// Efecto colateral: No tiene.
	// Retorna: True si el nodo puede ser actualizado, es importante que la llave no cambie.
	//
	bool HashTableInformationUpdate(const KeyType key, InformationType new_information);

	//
	// HashTableFind:
	//
	// Propósito: Devuelve la información de un nodo.
	// Argumentos: Llave y contenido para devolver.
	// Efecto colateral: No tiene.
	// Retorna: True si el nodo puede ser encontrado en la tabla y tiene información.
	//
	bool HashTableFind(const KeyType key, InformationType& information) const;

	//
	// HashTableDelete:
	//
	// Propósito: Borra un nodo de la tabla.
	// Argumentos: Llave del nodo a eliminar.
	// Efecto colateral: No tiene.
	// Retorna: True si el nodo puede ser borrado y si en la llave proporcionada existe información.
	//
	bool HashTableDelete(const KeyType key);

	//
	// HashTableEmpty:
	//
	// Propósito: Devuelve true si una tabla hash no tiene elementos.
	// Efecto colateral: No tiene.
	// Retorna: True si la tabla es vacía.
	//
	bool HashTableEmpty() const;

	//
	// HashTableFirstNode:
	//
	// Propósito: Devuelve el primer nodo con información de la tabla Hash.
	// Efecto colateral: No tiene.
	// Retorna: Devuelve el primer nodo con información de la tabla hash si no devuelve NULL.
	//
	HashTableNode HashTableFirstNode() const;

	//
	// HashTableNextNode:
	//
	// Propósito: Devuelve el nodo siguiente al nodo actual con información de la tabla Hash .
	// Efecto colateral: No tiene.
	// Retorna: Devuelve el nodo siguiente con información de la tabla hash si no devuelve NULL.
	//
	HashTableNode HashTableNextNode(HashTableNode actual_node) const;


private:
	LengthType Data_Count;
	HashTableNode Data[MAX_HASH+1][MAX_HASH+1];
	PositionType Hash_Function(KeyType key) const;

};

