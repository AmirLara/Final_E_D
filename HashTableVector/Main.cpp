#include "HashTableVector.h"
#pragma warning(disable: 4996 6387 4996 3692)
#pragma warning(suppress : 4996)
int main(int argc, char* argv[])
{
	HashTable HT;

	//Declaración de datos a almacenar
	InformationType datos = { "Amir",178,70,20}, datos2 = {"Vale", 163,60,20};
	KeyType llave = datos.suma,llave2=datos2.suma;
	InformationType info;
	//Agrega un nuevo nodo.
	HT.HashTableAdd(llave, datos);
	//Trata de modificar un nodo inexistente por lo que regresa false.
	HT.HashTableInformationUpdate(llave2,datos2);
	//Modifica los datos del nodo.
	HT.HashTableInformationUpdate(llave, datos2);
	//Trata de buscar un nodo inexistente por lo que regresa false.
	HT.HashTableFind(llave2, info);
	//Encuentra una nodo y obtiene sus datos.
	HT.HashTableFind(llave, info);
	//Trata de borrar un nodo inexistente por lo que regresa false.
	HT.HashTableDelete(llave2);

	//Consigue los datos del nodo seleccionado.
	HT.HashTableFind(llave, info);
	//Comprueba si la lista está vacía, como no lo esta regresa false.
	HT.HashTableEmpty();
	//Regresa el primer nodo.
	HT.HashTableFirstNode();
	//Agregamos un nuevo nodo
	HT.HashTableAdd(llave2, datos2);
	//Nos regresa el número de nodos en el arreglo.
	HT.HashTableCount();
	//Borramos nodos.
	HT.HashTableDelete(llave);
	HT.HashTableDelete(llave2);
	//Nos devuelve NULL ya que el arreglo está vacío.
	HT.HashTableFirstNode();

}