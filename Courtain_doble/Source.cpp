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
	//Comprueba que está vacía por lo que nos devuelve un true
	C1.CurtainEmpty();
	//Comprueba si la cortina está llena, al ser una cortina vacía regresa false.
	C1.CurtainFull();
	//Se trata de insertar una lista en una posición inválida por lo que regresa false.
	C1.CurtainInsert(L1, 3, 2);
	//Se crea una cortina de 3 elementos.
	C1.CurtainAdd(L1,3);
	C1.CurtainAdd(L1, 3);
	C1.CurtainAdd(L1, 3);
	//Se inserta una lista en la posición indicada.
	C1.CurtainInsert(L1, 3,2);
	//Se modifican los datos de una lista en la posición indicada.
	C1.CurtainUpdate(L2, 3, 2);
	//Se trata de modificar los datos en una posición inválida por lo que regresa false.
	C1.CurtainUpdate(L2, 3, 7);
	//Se trata de borrar los datos en una posición inválida por lo que regresa false.
	C1.CurtainDelete(7);
	//Borra los datos de la posición deseada.
	C1.CurtainDelete(1);
	//Busca una lista inexistente por lo que regresa falso y nos da una posición en NULL.
	C1.CurtainSearch(L3,1,a);
	//Busca una lista y nos devuelve su posición,retorna true.
	C1.CurtainSearch(L1, 3, a);
	//
	C1.CurtainObtain(L3,b,3);
	//Regresa la primer posición.
	C1.CurtainFirst();
	//Regresa la ultima posición.
	C1.CurtainLast();
	//Trata de regresar la siguiente posición de una inexistente por lo que regresa false.
	C1.CurtainNext(7);
	//Regresa la siguente posición.
	C1.CurtainNext(2);
	//Regresa la posición anterior.
	C1.CurtainPrevious(2);
	//Regresa false ya que es una posición inválida.
	C1.CurtainPrevious(7);
}