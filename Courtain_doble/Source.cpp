#include "Curtain.h"
#include "List.h"
#include <iostream>

#pragma warning(disable: 6262)

using namespace std;

int main(int argc, char* argv[])
{
	Curtain C1;
	CurtainPositionType a;
	unsigned int b=0;

	//Se crea una lista de 3 elementos
	List L1,L2,L3;
	L1.Add(2);
	L1.Add(3);
	L1.Add(5);
	L2.Add(1);
	L2.Add(2);
	L2.Add(3);
	L3.Add(1);
	//Comprueba que est� vac�a por lo que nos devuelve un true
	C1.CurtainEmpty();
	//Comprueba si la cortina est� llena, al ser una cortina vac�a regresa false.
	C1.CurtainFull();
	//Se trata de insertar una lista en una posici�n inv�lida por lo que regresa false.
	C1.CurtainInsert(L1, 3, 2);
	//Se crea una cortina de 3 elementos.
	C1.CurtainAdd(L1,3);
	C1.CurtainAdd(L1, 3);
	C1.CurtainAdd(L1, 3);
	//Se inserta una lista en la posici�n indicada.
	C1.CurtainInsert(L1, 3,2);
	//Se modifican los datos de una lista en la posici�n indicada.
	C1.CurtainUpdate(L2, 3, 2);
	//Se trata de modificar los datos en una posici�n inv�lida por lo que regresa false.
	C1.CurtainUpdate(L2, 3, 7);
	//Se trata de borrar los datos en una posici�n inv�lida por lo que regresa false.
	C1.CurtainDelete(7);
	//Borra los datos de la posici�n deseada.
	C1.CurtainDelete(1);
	//Busca una lista inexistente por lo que regresa falso y nos da una posici�n en NULL.
	C1.CurtainSearch(L3,1,a);
	//Busca una lista y nos devuelve su posici�n,retorna true.
	C1.CurtainSearch(L1, 3, a);
	//
	C1.CurtainObtain(L3,b,3);
	//Regresa la primer posici�n.
	C1.CurtainFirst();
	//Regresa la ultima posici�n.
	C1.CurtainLast();
	//Trata de regresar la siguiente posici�n de una inexistente por lo que regresa false.
	C1.CurtainNext(7);
	//Regresa la siguente posici�n.
	C1.CurtainNext(2);
	//Regresa la posici�n anterior.
	C1.CurtainPrevious(2);
	//Regresa false ya que es una posici�n inv�lida.
	C1.CurtainPrevious(7);
}