/*
AUTOR: Ezequiel Arceo May
PROPÓSITO: Demostrar la forma correcta de usar tipos de datos,
USO: ejecute, no requiere datos de entrada
*/
#include <iostream>                     // Lee desde y escribe hacia la consola
#include <string>                       // Permite trabajar con cadenas en forma simple

using namespace std;                    // Usa el espacio de nombres estándar

int main() {                            // TODO programa en C++ se ejecuta dentro de la función principal llamada main
  /* Usos correctos de tipos de datos */	
  int numero = 1;                       // Declaración con inicialización de la variable numero
  cout << "numero = " 
  << numero << endl;                    // Imprime la variable numero en la consola

  int otroNumero;                       // declaración de otroNumero, "hay una variable tipo 'int' que se llama 'otroNumero'"
  otroNumero = 2;                       // Asignación de valor a la variable otroNumero
  cout << "otroNumero = " 
  << otroNumero << endl;                // Imprime la variable otroNumero en la consola

  /* Uso incorrecto de tipos de datos */
  /*
  numeroNoDeclarado = 3;                 // Error, intenta asignar un valor a la variable 'numeroNoDeclarado' que no ha sido declarada
  cout << "numeroNoDeclarado = " 
  << numeroNoDeclarado << endl;          // Imprime la variable otroNumero en la consola
  */
 
  // system("pause");                      // Detiene temporalmente la ejecusión del programa, para que alcancemos a leer consola
  return 0;                             // Valor de retorno, en main 0 significa NO HUBO PROBLEMA
}

