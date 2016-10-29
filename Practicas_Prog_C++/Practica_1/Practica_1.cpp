//Autor: Paris De Perez
//Practica_1.cpp


#include <stdio.h>

/*
•	Los 8 bits de mayor peso contienen la vida del personaje
•	Los siguientes 8 bits el número de balas.
•	Los siguientes 4 bits el número de compañeros.
•	Le bit 0 el indicador de modo invulnerable.
•	El bit 1 el indicador de balas infinitas
•	El bit 2 el indicador de escudo presente.
•	El bit 3 el indicador de modo “berseker”.
*/

//Mascaras de bits para acceder a los distintos parametros del entero segun el esquema anterior
const unsigned int BM_VIDA = 0xFF000000;
const unsigned int BM_BALAS = 0x00FF0000;
const unsigned int BM_COMP = 0x0000F000;
const unsigned int BM_BERSEKER = 0x00000008;
const unsigned int BM_ESCUDO = 0x00000004;
const unsigned int BM_BALAS_INFINITAS = 0x00000002;
const unsigned int BM_INVULNERABLE = 0x00000001;


//Función que dado el entero anterior retorne el número de balas
unsigned int getBalas(unsigned int ui)
{
	//Aplicamos la mascara de bits correspondiente a las balas para limpiar el resto de datos
	ui &= BM_BALAS;
	//Desplazamos los bits que nos quedan hasta las posiciones de menor de peso del entero
	ui >>= 16;
	//Devolvemos 'i' ya que lo que nos queda en la memoria es un entero (sin signo) cuya estructura es la siguiente: 
	//ceros en los bits del 31 al 8 y ceros o unos en los bits del 7 al 0, correspondientes al número de balas
	// 00000000-00000000-00000000-XXXXXXXX
	return ui;
}


//Función que dado el entero anterior añada un número de balas a las existentes
void sumaBalas(unsigned int * ui, unsigned int balas)
{
	//Obtenemos el numero de balas actual
	unsigned int balasAux = getBalas(*ui);
	//Sumamos las balas nuevas
	balasAux += balas;
	//En este momento tenemos la información relativa a las balas en los últimos 8 bits de la variable balasAux
	//Aunque puede ser que al sumar las balas existentes con las que añadimos se haya sobrepasado el maximo de balas
	//Por ello, devolvemos los bits de las balas a su posicion original (8 bits a la izquierda) y le pasamos de nuevo
	//la máscara de bits para evitar contaminar la información de la vida despues
	balasAux <<= 16;
	balasAux &= BM_BALAS;
	//Ahora sustituimos los bits con la información de las balas viejos por los nuevos
	//Para ello primero ponemos a cero los bits viejos y luego copiamos los nuevos
	*ui &= ~BM_BALAS;
	*ui |= balasAux;
}


//Función que dado el entero anterior retorne si está activo el modo de balas infinitas
bool isBalasInfinitasEnabled(unsigned int ui)
{
	//Aplicamos la mascara de bits para obtener los bits correspondientes al modo de balas infinitas
	ui &= BM_BALAS_INFINITAS;
	//Si tenemos todo ceros está desactivado.
	return ui != 0;
}


//Función que dado el entero anterior active el modo de balas infinitas
void setBalasInfinitasEnabled(unsigned int * ui)
{
	*ui |= BM_BALAS_INFINITAS;
}


//Ejemplo de funcionamiento
void main()
{
	unsigned int personaje = 0xA3AD8600;
	printf("Entero en hexadecimal: %x - balas: %u\n", personaje, getBalas(personaje));
	sumaBalas(&personaje, 5);
	printf("Entero en hexadecimal: %x - balas: %u\n", personaje, getBalas(personaje));
	printf("Entero en hexadecimal: %x - balasInfinitas: %u\n", personaje, isBalasInfinitasEnabled(personaje));
	setBalasInfinitasEnabled(&personaje);
	printf("Entero en hexadecimal: %x - balasInfinitas: %u\n", personaje, isBalasInfinitasEnabled(personaje));
	scanf_s("");
}