
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cctype> 
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h> 
#include <math.h>
#include <sstream>
#include <random>
using namespace std;

//T_Votante
typedef struct T_Votante { //Se define la estructura para los votantes
	char cedula[10];
	char codelec[7];
	char sexo;
	char fecha[9];
	char numjun[6];
	char nombre[31];
	char papellido[27];
	char sapellido[27];
	T_Votante * PtrSiguiente;
}*PtrT_Votante;

//Funcion para agregar un votante, recibe como parametro la lista de votantes y la LINEA DE TEXTO del padron electoral
//extrae cada uno de los atributos de la linea y los almacena en un nodo de la lista de votantes
void agregarvotante(PtrT_Votante &ListaV, char agregado[118]) {
	PtrT_Votante Aux = new (T_Votante);
	Aux->PtrSiguiente = ListaV;
	ListaV = Aux;

	for (int ce = 0; ce < 9; ce++) {
		ListaV->cedula[ce] = agregado[ce];
	}
	ListaV->cedula[9] = '\0';

	for (int co = 10; co < 16; co++) {
		ListaV->codelec[co - 10] = agregado[co];
	}
	ListaV->codelec[6] = '\0';

	ListaV->sexo = agregado[17];


	for (int fe = 19; fe < 27; fe++) {
		ListaV->fecha[fe - 19] = agregado[fe];
	}
	ListaV->fecha[8] = '\0';

	for (int nu = 28; nu < 33; nu++) {
		ListaV->numjun[nu - 28] = agregado[nu];
	}
	ListaV->numjun[5] = '\0';

	for (int nom = 34; nom < 64; nom++) {
		ListaV->nombre[nom - 34] = agregado[nom];
	}
	ListaV->nombre[30] = '\0';

	for (int pa = 65; pa < 91; pa++) {
		ListaV->papellido[pa - 65] = agregado[pa];
	}
	ListaV->papellido[26] = '\0';

	for (int sa = 92; sa < 118; sa++) {
		ListaV->sapellido[sa - 92] = agregado[sa];
	}
	ListaV->sapellido[26] = '\0';

}



//Funcion para cargar los votantes, se encarga de tomar cada una de las lineas
//directo del archivo de texto y enviarlo a la funci�n encargada de extraer cad uno
// de los datos e incorporarlos en un nodo de la lista.
void CargarVotantes(PtrT_Votante &ListaV) {
	int cont = 1;
	time_t inicio, fin;
	inicio = time(NULL);
	FILE *archivo;
	fopen_s(&archivo, "PADRON_COMPLETO.txt", "r");
	if (NULL == archivo) {
		printf("No se pudo abrir el archivo");
	}
	else {
		char agregado[119];
		while (fgets(agregado, 119, archivo) != NULL) {
			if (cont % 2 != 0) {
				agregarvotante(ListaV, agregado);
			}
			cont++;
		}
		fclose(archivo);
	}

	fin = time(NULL);
	cout << "----------------------------Padron cargado--------------------------------" << endl;
	printf("\nEl cargado del padron ha tardado : %f segundos.\n", difftime(fin, inicio));
	cout << "----------------------------Padron cargado--------------------------------" << endl;
	system("pause");
}


//Funcion para liberar los votantes en estructuras de memoria dinamica de la lista enlazada hasta dejar la lista en NULL

void LiberarVotantes(PtrT_Votante &ListaV) {
	PtrT_Votante Aux = ListaV;
	time_t inicio, fin;

	inicio = time(NULL);

	while (Aux != NULL) {
		ListaV = ListaV->PtrSiguiente;
		delete(Aux);
		//Globalfree(Aux);
		Aux = ListaV;
	}

	fin = time(NULL);

	cout << "----------------------------Padron liberado--------------------------------" << endl;
	printf("\nLa liberacion del padron ha tardado : %f segundos.\n", difftime(fin, inicio));
	cout << "----------------------------Padron liberado--------------------------------" << endl;
	system("pause");
}


//Funci�n para inicializar la lista de votantes
void inicializarvotantes(PtrT_Votante &ListaV) {
	ListaV = NULL;
}

PtrT_Votante BuscarVotante(PtrT_Votante &Lista, char cual[9])
{
	bool encontro = false;
	PtrT_Votante Aux;
	Aux = Lista;

	while ((!encontro == true) && (Aux != NULL))
	{
		if (strncmp(Aux->cedula, cual, 9) == 0)
			encontro = true;
		else
			Aux = Aux->PtrSiguiente;
	}
	return Aux;
}

bool Encontro = false;
PtrT_Votante Aux=Lista

void main() {
	bool realizado = false;
	bool ciclo = true;
	int opcion = 0;
	PtrT_Votante ListaV;
	inicializarvotantes(ListaV);
	cout << "Por favor espere mientras se carga el Padron" << endl;
	CargarVotantes(ListaV);
	char buscado[] = "207550913";
	PtrT_Votante Encontrado = NULL;
	Encontrado = BuscarVotante(ListaV, buscado);
	if (Encontrado != NULL) {
		cout << endl << "Encontre' al Votante!! " << endl << endl;

		cout << "Ce'dula: " << Encontrado->cedula << endl;
		cout << "Nombre: " << Encontrado->nombre << endl;
		cout << "Primer Apellido: " << Encontrado->papellido << endl;
		cout << "Segundo Apellido: " << Encontrado->sapellido << endl;
		cout << "Sexo: " << Encontrado->sexo << endl;
		cout << "Fecha: " << Encontrado->fecha << endl;
		cout << "Co'digo Electoral:  " << Encontrado->codelec << endl;
		cout << "Nu'mero Junta: " << Encontrado->numjun << endl;
	}
	else
		cout << " No se encontro al votante !!! " << endl;

	LiberarVotantes(ListaV);

	cout << "Finalizado" << endl;

	system("pause");


}

/*Por favor espere mientras se carga el Padron
----------------------------Padron cargado--------------------------------

El cargado del padron ha tardado : 25.000000 segundos.
----------------------------Padron cargado--------------------------------
Press any key to continue . . .

Encontre' al Votante!!

Ce'dula: 107490737
Nombre: VICTOR MANUEL
Primer Apellido: GARRO
Segundo Apellido: ABARCA
Sexo: 1
Fecha: 20300204
Co'digo Electoral:  101016
Nu'mero Junta: 00022
----------------------------Padron liberado--------------------------------

La liberacion del padron ha tardado : 0.000000 segundos.
----------------------------Padron liberado--------------------------------
Press any key to continue . . .Por favor espere mientras se carga el Padron
----------------------------Padron cargado--------------------------------

El cargado del padron ha tardado : 25.000000 segundos.
----------------------------Padron cargado--------------------------------
Press any key to continue . . .*/

/*Por favor espere mientras se carga el Padron
----------------------------Padron cargado--------------------------------

El cargado del padron ha tardado : 16.000000 segundos.
----------------------------Padron cargado--------------------------------
Press any key to continue . . .

Encontre' al Votante!!

Ce'dula: 207550813
Nombre: ALFREDO
Primer Apellido: ACU╤A
Segundo Apellido: CHACON
Sexo: 1
Fecha: 20240703
Co'digo Electoral:  206004
Nu'mero Junta: 02390
----------------------------Padron liberado--------------------------------

La liberacion del padron ha tardado : 1.000000 segundos.
----------------------------Padron liberado--------------------------------
Press any key to continue . . .
Finalizado
Press any key to continue . . .*/