#include "stdafx.h" //agrega libreria
#include <iostream>
#include <conio.h>
using namespace std;//Permite  dejar de utilizar el std antes del cout ,std es el comonado para estandarizar el cout  que es llamado a partir de la libreria  ionstream
void main()
{
	int a = 2; //denomina la varible como un decimal
	float b = 3.5; //denomina la varible como un flotante
	float c = a + b;
	cout << "El valor de a+b es: " << c << " centimetros." << endl; //el mayor igual imprime el valor en comillas  y asigna lo qu eesta fuera del mayor igual y el endl es fin de linea
	printf("el valor de a+b es: %f \n", c);//el printf imprime el valor en comillas y asigna la varible ....el porcentaje le da  a entender el tipo de valor y el slash n es fin de linea
	system("pause"); //system llama al sistema y pause hace que la ventana negra no desaparesca
}

/*El valor de a+b es: 5.5 centimetros.
el valor de a+b es: 5.500000
Press any key to continue . . .*/