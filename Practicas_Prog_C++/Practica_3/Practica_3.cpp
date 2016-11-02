//Autor: Paris de Perez
//Practica_3.cpp

#include <stdio.h>
#include <string.h>

//Tabla de cadenas
char *g_Strings[] =
{
	"",
	"Hola",
	"Adios",
};

//Funcion de la practica 2 que invierte una cadena
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


//Función que, dado un índice a la tabla de cadenas, retorne la cadena de índice dado si existe
char * getStringAtIndex(char * * tabla, unsigned int i)
{
	if (tabla[i] != nullptr)
		return tabla[i];
	else
		return nullptr;
}


//Función que, dado un índice a la tabla de cadenas, retorne la cadena de índice dado, si existe, invertida.
char * getReverseStringAtIndex(char ** tabla, unsigned int i)
{
	char * aux = getStringAtIndex(tabla, i);
	if (aux != nullptr)
		return getReverseString(aux, strlen(aux));
	else
		return nullptr;
}


void main()
{	
	char ** tabla = g_Strings;
	printf("%s\n", getStringAtIndex(tabla, 0));
	printf("%s\n", getStringAtIndex(tabla, 1));
	printf("%s\n", getStringAtIndex(tabla, 2));

	printf("-------------------\n");

	printf("%s\n", getReverseStringAtIndex(tabla, 0));
	printf("%s\n", getReverseStringAtIndex(tabla, 1));
	printf("%s\n", getReverseStringAtIndex(tabla, 2));

	scanf_s("");
}