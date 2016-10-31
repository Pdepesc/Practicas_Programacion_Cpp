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

//Fichero practica2.cpp (quizas mejor incluirlo con #include)
// practica2.cpp
//
#include <stdio.h>

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


// ***************************************************************************************
// MAIN
// ***************************************************************************************
unsigned int uKey;
int main(int argc, char* argv[])
{

	//MODO DE CREAR LAS ENTIDADES
	//Instrucciones: crear funciones a asociar (declarar y definir), asociarlos a la tabla de funciones 
	//				 y, por ultimo, inicializar (new) la nueva entidad con la tabla de funciones y la posicion inicial.
	//funciones
	funcEntity mover1;
	funcEntity mover2;
	funcEntity pintar1;
	funcEntity pintar2;

	funcEntity funciones[] = { mover1, pintar1 };

	//entidades
	TEntity * entidad1 = new TEntity(funciones, 0, 0);
}
