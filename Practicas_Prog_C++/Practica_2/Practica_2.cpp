//Autor: Paris de Perez
//Practica_2.cpp

#include <stdio.h>
#include <string.h>

//Dado un entero obtener por separado cada uno de los bytes que lo forman utilizando para ello “casting” y aritmética de punteros
void printBytes(int * i)
{
	//Convertimos el puntero a puntero a caracter en vez de puntero a entero, de modo que podamos leer byte a byte
	char * bytes = reinterpret_cast<char *>(i);
	//Interpretamos el contenido apuntado por el puntero como numeros hexadecimales de la misma longitud que un char (un byte)
	//y recorremos la memoria (leemos 4 bytes)
	printf("%#hhX - ", *bytes);
	printf("%#hhX - ", *(bytes + 1));
	printf("%#hhX - ", *(bytes + 2));
	printf("%#hhX\n", *(bytes + 3));
}

char * getBytes(int * i)
{
	//Convertimos el puntero a puntero a caracter en vez de puntero a entero, de modo que podamos leer byte a byte
	char * aux = reinterpret_cast<char *>(i);
	//Interpretamos el contenido apuntado por el puntero como numeros hexadecimales de la misma longitud que un char (un byte)
	//y recorremos la memoria (leemos 4 bytes)
	char bytes[] = { *aux, *(aux + 1), *(aux + 2), *(aux + 3) };
	return bytes;
}


//Dada la tabla de enteros “int tabla[]={1, 3, 2, 5, 3, 0xFFFFFFFF, 2}” obtener el entero mayor usando puntero y aritmética de punteros
int getMayorInt(const int * tabla)
{
	int aux = 0;
	int aux2 = 0;
	for (int i = 0; i < 7; i++)
	{
		aux2 = *(tabla + i);
		if (aux2 > aux)
			aux = aux2;
	}
	return aux;
}

//Como el apartado anterior pero en lugar de obtener el entero mayor obtener el byte mayor(usar casting)
char getMayorByte(const int * tabla)
{
	int aux = 0;
	unsigned char aux2 = 0;
	unsigned char aux3 = 0;
	for (int i = 0; i < 7; i++)
	{
		aux = *(tabla + i);
		char * bytes = getBytes(&aux);
		for (int i = 0; i < 4; i++)
		{
			aux3 = *(bytes + i);
			if (aux3 > aux2)
				aux2 = aux3;
		}
	}
	return aux2;
}

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


void main()
{
	int i = 0xA3C21F3B;
	printf("%#X: %i\n", i, i);
	printBytes(&i);
	i = 0x3241ADf6;
	printf("%#X: %i\n", i, i);
	printBytes(&i);

	printf("-------------------\n");

	int tabla[] = { 1, 3, 2, 5, 3, 0xFFFFFFFF, 2 };
	printf("mayor int: %i\n", getMayorInt(tabla));
	printf("mayor byte: %hhX\n", getMayorByte(tabla));

	printf("-------------------\n");

	char cadena[] = "Cadena a revertir";
	printf("%s\n", cadena);
	char * inversa = getReverseString(cadena, strlen(cadena));
	printf("%s\n", inversa);

	scanf_s("");
}