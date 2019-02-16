/*
AUTOR: Ezequiel Arceo May
PROPÓSITO: Mostrar el efecto del alcance de las variables.
USO: ejecute, no requiere datos de entrada
*/
#include <iostream>                     // Lee desde y escribe hacia la consola
#include <string>                       // Permite trabajar con cadenas en forma simple

using namespace std;                    // Usa el espacio de nombres estándar

int numeroExterno;                      // numeroExterno es accesible en todo el programa, incluso en otros archivos

int main() {                            // TODO programa en C++ se ejecuta dentro de la función principal llamada main
  /* Uso de una variable declarada DENTRO de la función */
  int numeroInterno = 1;                // numeroInterno solo es accesible en el cuerpo de la función donde se definió
  cout << "numeroInterno = " 
  << numeroInterno << endl;             // Imprime la variable numero en la consola

  /* Uso de una variable declarada FUERA de la función */
  numeroExterno = 2;                    // Asigna un valor a la variable 'numeroExterno' que ha sido declarada fuera/arriba de la función
  cout << "numeroExterno = " 
  << numeroExterno << endl;             // Imprime la variable otroNumero en la consola

  // system("pause");                      // Detiene temporalmente la ejecusión del programa, para que alcancemos a leer consola
  return 0;                             // Valor de retorno, en main 0 significa NO HUBO PROBLEMA
}

