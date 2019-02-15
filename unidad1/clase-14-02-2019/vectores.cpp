/*
AUTOR: Ezequiel Arceo May
PROPÓSITO: colecta un número indefinifo de números decimales
de la consola, los imprime, y calcula el promedio
USO: ejecuta e inserta (escribe) números cada vez que se
le solicite. Escribe un número negativo para salir.
*/
#include <iostream>										// Lee desde y escribe hacia la consola
#include <vector>											// Permite hacer colecciones de datos de un mismo tipo

using namespace std;									// Usa el espacio de nombres est�ndar

int main() {
	/* Definición de variables */
	vector<float> calificaciones;				// Define un vector vacio de enteros
	float calificacion = 0;							// Guarda el último número introducido
	float suma = 0;											// Variable para guardar la suma de enteros en el vector
	float promedio;											// Declaro una variable para el promedio
	bool pide_otro = true;							// Variable para determinar si pido otro número al usuario

	/* Pide números al usuario hasta que inserta -1.
	Si el número insertado no es -1, se guarda en el vector
	*/
	cout << "[INFO] Ingrese un número negativo para salir" << endl;
	while ( pide_otro ) {															// Para iterar una cantidad indefinido de veces se usa while
		cout << "Ingrese una calificacion: ";						// Dá instrucciones al usuario
		cin >> calificacion;														// Leo información de la consola
		if ( calificacion > 0.0 ) {
			// Esto se ejecuta si calificacion > 0.0 
			pide_otro = true;
			calificaciones.push_back(calificacion);				// Inserta el número al final del vector
		}else{
		// Esto se ejecuta si calificacion < 0.0 
			pide_otro = false;
		}
	}

	/* Imprime los elementos del vector */
	for (int i = 0; i < calificaciones.size(); i++) {	// 
		cout << "La calificacion en la posicion " << i << " es " << calificaciones[i] << endl;
		suma = suma + calificaciones[i];								// Añade a "suma" el valor de "calificaciones" en la posición i
	}

	/* Calcula el promedio y lo imprime en pantalla */
	if ( calificaciones.size() != 0 ) {								// Compruebo que el vector no está vacio, para evitar división entre cero
		promedio = suma / calificaciones.size();
		cout << "El promedio es: " << promedio << endl;
	}
	system("pause");
}