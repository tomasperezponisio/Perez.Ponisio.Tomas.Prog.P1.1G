#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 5

/**
1. Crear una funci�n llamada aplicarAumento que reciba como par�metro
el precio de un producto y devuelva el valor del producto con un
aumento del 5%. Realizar la llamada desde el main.
**/
int aplicarAumento( int precio );

/**
2. Crear una funci�n que se llame reemplazarCaracteres que reciba
una cadena de caracteres como primer par�metro, un car�cter como
segundo y otro car�cter como tercero, la misma deber� reemplazar cada
ocurrencia del segundo par�metro por el tercero y devolver la cantidad
de veces que se reemplazo ese car�cter en la cadena
**/
int reemplazarCaracteres( char palabra[], char primerLetra, char segundaLetra );

/**
3. Dada la siguiente estructura generar una funci�n que permita
ordenar un array de dicha estructura por tipo. Ante igualdad de tipo
deber� ordenarse por efectividad creciente. Hardcodear datos
y mostrarlos desde el main. *
**/

typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
} eVacuna;

int ordenarVacunas( eVacuna vacunas[], int tam);

int main()
{
    /**
     1. Crear una funci�n llamada aplicarAumento que reciba como par�metro
     el precio de un producto y devuelva el valor del producto con un
     aumento del 5%. Realizar la llamada desde el main.
     **/

    int precio;
    int precioFinal;
    printf("Ingrese precio: ");
    scanf("%d", &precio);

    precioFinal = aplicarAumento(precio);

    printf("Precion final: %d\n", precioFinal);
    printf("----------------------------------------------------------\n");

    /**
    2. Crear una funci�n que se llame reemplazarCaracteres que reciba
    una cadena de caracteres como primer par�metro, un car�cter como
    segundo y otro car�cter como tercero, la misma deber� reemplazar cada
    ocurrencia del segundo par�metro por el tercero y devolver la cantidad
    de veces que se reemplazo ese car�cter en la cadena
    **/

    char palabra[15];
    char primerLetra;
    char segundaLetra;

    printf("Ingrese palabra: ");
    fflush(stdin);
    gets(palabra);
    strlwr(palabra);

    printf("Ingrese la primer letra: ");
    fflush(stdin);
    scanf("%c", &primerLetra);
    primerLetra = tolower(primerLetra);

    printf("Ingrese la segunda: ");
    fflush(stdin);
    scanf("%c", &segundaLetra);
    segundaLetra = tolower(segundaLetra);

    printf("La palabra ingresada es: %s\n", palabra);
    printf("Y la letra %c aparecia %d veces y fue reemplazada por la letra %c\n", primerLetra, reemplazarCaracteres(palabra, primerLetra, segundaLetra), segundaLetra );
    printf("Ahora la palabra es: %s\n", palabra);
    printf("----------------------------------------------------------\n");

    /**
    3. Dada la siguiente estructura generar una funci�n que permita
    ordenar un array de dicha estructura por tipo. Ante igualdad de tipo
    deber� ordenarse por efectividad creciente. Hardcodear datos
    y mostrarlos desde el main. *
    **/
    eVacuna vacunas[TAM] =
    {
        { 100, "Astra", 'a', 95.6 },
        { 101, "Sputnik", 'a', 75.4 },
        { 102, "Oxford", 'c', 85.9 },
        { 103, "Bayer", 'b', 76.8 },
        { 104, "ELEA", 'c', 65.2 },
    };

    printf("\n");
    printf("Desordenados\n");
    printf("\n");
    for (int i = 0; i < TAM; i++ )
    {
        printf( "%d  %-10s     %c     %.2f\n", vacunas[i].id, vacunas[i].nombre, vacunas[i].tipo, vacunas[i].efectividad );
    }

    printf("\n");
    printf("Ordenados\n");
    printf("\n");
    ordenarVacunas(vacunas, TAM);
    for (int i = 0; i < TAM; i++ )
    {
        printf( "%d  %-10s     %c     %.2f\n", vacunas[i].id, vacunas[i].nombre, vacunas[i].tipo, vacunas[i].efectividad );
    }

    return 0;
}

int aplicarAumento( int precio )
{
    int precioFinal;
    int aumento = 5;
    precioFinal = precio + (aumento * precio / 100 );
    return precioFinal;
}

int reemplazarCaracteres( char palabra[], char primerLetra, char segundaLetra )
{
    int contador = 0;
    if (palabra != NULL)
    {
        for (int i = 0; i < strlen(palabra); i++)
        {
            if ( palabra[i] == primerLetra )
            {
                palabra[i] = segundaLetra;
                contador++;
            }
        }
    }
    return contador;
}

int ordenarVacunas( eVacuna vacunas[], int tam)
{
    int todoOk = 0;
    eVacuna auxVacuna;
    if (vacunas != NULL && tam > 0)
    {
        todoOk = 1;
        for ( int i = 0; i < tam - 1 ; i++ )
        {
            for ( int j = i+1; j < tam; j++ )
            {
                if ( vacunas[i].tipo > vacunas[j].tipo  ||
                   ( vacunas[i].tipo == vacunas[j].tipo && vacunas[i].efectividad > vacunas[j].efectividad) )
                {
                    auxVacuna = vacunas[i];
                    vacunas[i] =vacunas[j];
                    vacunas[j] = auxVacuna;
                }
            }
        }
    }
    return todoOk;
}
