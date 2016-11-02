//Autor: Paris de Perez
//Practica_3.cpp

#include <stdio.h>
#include "consola.h"

/*
4.	Funciones 2: Dado la estructura “TEntity” declarada en el fichero “practica2.cpp” de la sesión 3.
•	Realizar un programa que mueva y pinte por pantalla “n” instancias de “TEntity”.
Para ello se tiene que tener en cuenta :
•	Usar los operadores “new” y “delete” para crear entidades.
•	Las entidades se inicializan con :
	i.Tabla a funciones que tiene que tener dos funciones :
		1.	Función de movimiento : calcula la posición de la entidad.
		2.	Función de pintado : pinta la entidad.
	ii.Posición inicial en la pantalla.
•	Las entidades creadas se meterán en una tabla que será la que se use para acceder a las mismas y proceder a llamar a su pintado y movimiento.
•	Para pintar las entidades en consola se puede utilizar los ficheros de la sesión : “console.cpp” y “console, h”.
•	Se realizan, por lo menos 4 tipos diferentes de entidades : cada tipo de entidad se diferencia de otra en que pinta o se mueve de manera diferente.
*/

struct TEntity;
typedef void(*funcEntity)(TEntity *);


// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	int m_ix;
	int m_iy;
	funcEntity *m_funcs;
	TEntity(funcEntity *funcs, int x, int y)
	{
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;
	}
};

//Funciones de las entidades
//Mueve en diagonal (abajo y derecha)
void mover1(TEntity * entidad)
{
	entidad->m_ix += 1;
	entidad->m_iy += 1;
}
//Mueve en vertical
void mover2(TEntity * entidad)
{
	entidad->m_ix += 0;
	entidad->m_iy += 1;
}
//Mueve en horizontal
void mover3(TEntity * entidad)
{
	entidad->m_ix += 1;
	entidad->m_iy += 0;
}
//No mueve
void mover4(TEntity * entidad)
{
	entidad->m_ix += 0;
	entidad->m_iy += 0;
}

//Pinta el caracter '*'
void pintar1(TEntity * entidad)
{
	gotoxy(entidad->m_ix, entidad->m_iy);
	printf("*");
}
//Pinta el caracter '/'
void pintar2(TEntity * entidad)
{
	gotoxy(entidad->m_ix, entidad->m_iy);
	printf("/");
}
//Pinta el caracter '+'
void pintar3(TEntity * entidad)
{
	gotoxy(entidad->m_ix, entidad->m_iy);
	printf("+");
}
//Pinta el caracter '-'
void pintar4(TEntity * entidad)
{
	gotoxy(entidad->m_ix, entidad->m_iy);
	printf("-");
}


// ***************************************************************************************
// MAIN
// ***************************************************************************************
unsigned int uKey;
int main(int argc, char* argv[])
{
	//Entidades con movimiento distinto
	//Entidad tipo 1: se mueve en diagonal y se pinta con un '*'
	funcEntity funciones[] = { &mover1, &pintar1 };
	TEntity * pTEntityTipo1 = new TEntity(funciones, 3, 0);
	//Entidad tipo 2: se mueve en vertical y se pinta con un '*'
	funcEntity funciones2[] = { &mover2, &pintar1 };
	TEntity * pTEntityTipo2 = new TEntity(funciones2, 1, 0);
	//Entidad tipo 3: se mueve en horizontal y se pinta con un '*'
	funcEntity funciones3[] = { &mover3, &pintar1 };
	TEntity * pTEntityTipo3 = new TEntity(funciones3, 2, 0);
	//Entidad tipo 4: no se mueve y se pinta con un '*'
	funcEntity funciones4[] = { &mover4, &pintar1 };
	TEntity * pTEntityTipo4 = new TEntity(funciones4, 0, 0);

	//Entidades con distinta funcion de pintado
	//Entidad tipo 5: se mueve en diagonal y se pinta con un '*'
	funcEntity funciones5[] = { &mover1, &pintar1 };
	TEntity * pTEntityTipo5 = new TEntity(funciones5, 0, 13);
	//Entidad tipo 6: se mueve en vertical y se pinta con un '/'
	funcEntity funciones6[] = { &mover2, &pintar2 };
	TEntity * pTEntityTipo6 = new TEntity(funciones6, 0, 12);
	//Entidad tipo 7: se mueve en horizontal y se pinta con un '+'
	funcEntity funciones7[] = { &mover3, &pintar3 };
	TEntity * pTEntityTipo7 = new TEntity(funciones7, 0, 11);
	//Entidad tipo 8: no se mueve y se pinta con un '-'
	funcEntity funciones8[] = { &mover4, &pintar4 };
	TEntity * pTEntityTipo8 = new TEntity(funciones8, 0, 10);

	//tabla de entidades
	TEntity * tabla[] = { pTEntityTipo1, pTEntityTipo2, pTEntityTipo3, pTEntityTipo4, pTEntityTipo5, pTEntityTipo6, pTEntityTipo7, pTEntityTipo8};

	while(true){
		clear();
		for (int i = 0; i < 8; i++)
		{

			(tabla[i]->m_funcs[1])(tabla[i]);
			//Mover la entidad
			(tabla[i]->m_funcs[0])(tabla[i]);
			//Pintar la entidad
		}
		Sleep(10000);
	}
}