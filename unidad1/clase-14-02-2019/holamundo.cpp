/*
AUTOR: Ezequiel Arceo May
PROPÓSITO: imprimir mis datos personales en la consola
USO: ejecute, no requiere datos de entrada
*/
#include <iostream>											// Lee desde y escribe hacia la consola
#include <string>												// Permite trabajar con cadenas en forma simple

using namespace std;										// Usa el espacio de nombres estándar


int main() { 														// TODO programa en C++ se ejecuta dentro de la función principal llamada main
	/* Definición de variables (las cuales almacenarán datos) */	
	string nombre = "Ezequiel Arceo May";	// Variable de tipo cadena de caracteres
	int edad = 33;												// Variable de tipo entero
	float estatura = 1.58;								// Variable de tipo flotante (decimal)

	/* Impresión de datos en consola */
	cout << "\t[INFO] Mis datos\n";											// \t significa TAB y \n significa SALTO DE LÍNEA (lo que usualmente conocemos como ENTER)
	cout << "Mi nombre es: " << nombre << endl;					// endl también significa SALTO DE LÍNEA
	cout << "Mi edad es: " << edad << endl;
	cout << "Mido: " << estatura << " metros." << endl;
	system("pause");																		// Detener temporalmente la ejecusión del programa, para que alcancemos a leer consola
	return 0;																						// Valor de retorno, en main 0 significa NO HUBO PROBLEMA
}

