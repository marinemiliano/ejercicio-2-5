/*
 ============================================================================
 Name        : ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Ejercicio 2-5:
Debemos generar el pedido de libretas universitarias a la imprenta para los alumnos
al regreso a la presencialidad. De cada persona debemos obtener los siguientes
datos:
número de legajo (4 cifras sin ceros a la derecha),
estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
edad (más de 17),
año de ingreso (validar por favor)
y género ('f' para femenino, 'm' para masculino, 'o' para no binario).
NOTA: El precio por libreta universitaria es de $450.
Se debe informar (solo si corresponde):

a) La cantidad de personas mayores de 60 años.

b) El legajo y edad de la mujer que ingreso hace más tiempo.

c) Cuanto debe abonar la facultad por las libretas sin el descuento

d) Si se solicitan mas de 5 libretas hay un 5% de descuento, si se solicitan más de
10 libretas se hace 10%. Además, por cada alumno mayor de 60 años al valor original
de la libreta se le hace un 25%. Informar los valores si corresponde.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	char respuesta;
	respuesta='s';

	int legajo;
	char estadoCivil;
	int edad;
	char genero;
	int precio;
	int anoIngreso;
	int maximoAnoIngreso;

	int bandera;
	bandera=0;

	precio=450;
	int contadorLibretas;
	contadorLibretas=0;

	int acumuladorPrecio;
	acumuladorPrecio=0;

	int legajoMujer;
	int edadMujer;

	int porcentaje;
	int descuento;


	int contador60;
	contador60=0;
	int porcentaje60;
	porcentaje60 = 0.75;
	int descuento60;

		while(respuesta== 's')
		{
			printf("ingrese legajo de cuatro cifras \n");
			scanf("%d",&legajo);

			while(legajo<1111 || legajo>1999)
			{
				printf("error, reingrese legajo\n");
				scanf("%d",&legajo);
			}

			printf("ingrese estado civil\n");
			fflush(stdin);
			scanf("%c",&estadoCivil);

			while(estadoCivil != 's' && estadoCivil != 'c' && estadoCivil !='v')
			{
				printf("error, reingrese estado civil\n");
				fflush(stdin);
				scanf("%c",&estadoCivil);
			}

			printf("ingrese edad\n");
			scanf("%d",&edad);

			while(edad<17)
			{
				printf("error, reingrese edad\n");
				scanf("%d",&edad);
			}
			if(edad>60)
			{
				contador60++;
			}

			printf("ingrese año de ingreso\n");
			scanf("%d",&anoIngreso);

			while(anoIngreso<1950 || anoIngreso>2022)
			{
				printf("error, reingrese edad\n");
				scanf("%d",&anoIngreso);
			}

			printf("ingrese genero\n");
			fflush(stdin);
			scanf("%c",&genero);

			while(genero !='f' && genero !='m' && genero != 'o')
			{
				printf("error, reingrese genero\n");
				fflush(stdin);
				scanf("%c",&genero);
			}

			contadorLibretas++;
			acumuladorPrecio+=precio;

			printf("desea agregar otro alumno? s");
			fflush(stdin);
			scanf("%c",&respuesta);
		}


		switch(genero)
					{
					case 'f':
					if(anoIngreso>maximoAnoIngreso || bandera == 0)
					{
						maximoAnoIngreso=anoIngreso;
						legajoMujer=legajo;
						edadMujer=edad;
						bandera=1;
					}
					printf("el legajo de la mujer que ingreso hace mas tiempo es %d\n",legajoMujer);
					printf("la edad es %d\n",edadMujer);

						break;

					case 'm':

						break;

					case 'o':

						break;
					}


		if(contadorLibretas<2)
		{
			printf("menos de 2 libretas, no se ingresaron descuentos\n");
		}
		else
		if(contadorLibretas>2 || contadorLibretas<4)
		{
				porcentaje=	0.95;
				descuento= acumuladorPrecio*porcentaje;
				printf("se ingresaron libretas descuento del 5 porciento de %d\n",descuento);
		}
		else
		{
				porcentaje= 0.90;
				descuento= acumuladorPrecio*porcentaje;
				printf("se ingresaron 5 o mas libretas, descuento del 10 porciento es de %d\n",descuento);
		}

		if(genero != 'f')
		{
			printf("no se ingresaron mujeres\n");
		}

		if(contador60 > 0)
		{
			printf("la cantidad de personas mayores a 60 es %d\n",contador60);

			descuento60=precio*porcentaje60;

			printf("a las personas mayores de 60 se le aplica el descuento del 25 porciento igual a %d\n",descuento60);
		}
		else
		{
			printf("no se ingresaron personas mayores a 60 anos\n");
		}


		printf("el precio que debe abonar la facultad por las libretas sin los descuentos es de: %d\n",acumuladorPrecio);


	return 0;
}
