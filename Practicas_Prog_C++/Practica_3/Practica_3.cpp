//Autor: Paris de Perez
//Practica_3.cpp

#include <string.h>

//Dada una cadena de caracteres darle la vuelta
//tam es el valor retornado por la funcion strlen
char * getReverseString(const char * cadena, int tam)
{
	char * out = new char[tam];
	for (int i = 0; i < tam; i++)
	{
		out[tam - i - 1] = cadena[i];
	}
	out[tam] = '\0';
	return out;
}

/*
3.	Funciones 1. Dada una tabla de cadenas
•	Hacer una función que, dado un índice a la tabla de cadenas, retorne la cadena de índice dado si existe.
•	Hacer una función que, dado un índice a la tabla de cadenas, retorne la cadena de índice dado, si existe, invertida.
*/

char * getStringAtIndex(char * * tabla, unsigned int i)
{
	if (tabla[i] != nullptr)
		return tabla[i];
	else
		return nullptr;
}

char * getReverseStringAtIndex(char ** tabla, unsigned int i)
{
	char * aux = getStringAtIndex(tabla, i);
	if (aux != nullptr)
		return getReverseString(aux, strlen(aux));
}