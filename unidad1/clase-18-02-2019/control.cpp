/*
AUTOR: Ezequiel Arceo May
PROPÓSITO: Mostrar el uso de sentencias de control.
USO: ejecute, no requiere datos de entrada
*/
#include <iostream>                     // Lee desde y escribe hacia la consola
#include <string>                       // Permite trabajar con cadenas en forma simple

using namespace std;                    // Usa el espacio de nombres estándar

int main() {                            // TODO programa en C++ se ejecuta dentro de la función principal llamada main
  int numero = 2;
  cout << "numero = " << numero << endl;

  cout << "[INFO] Probamos la sentencia 'if'" << endl;
  if (numero > 0){
    cout << "El número es mayor que 0" << endl;
  }

  cout << "[INFO] Probamos la sentencia 'if/else'" << endl;
  if (numero > 0){
    cout << "El número es mayor que 0" << endl;
  }
  else{
    cout << "El número NO es mayor que 0" << endl;
  }


  cout << "[INFO] Probamos la sentencia 'switch/case'" << endl;
  switch (numero) {
    case 1:
      cout << "Dijiste 1, fallaste." << endl;
      break;                                  // Deja de hace comparaciones y se sale del switch.
    case 2:
      cout << "El número es 2, bingo." << endl;
      break;
    default:
      cout << "Fallaste." << endl;
      break;
  }

  system("pause");                      // Detiene temporalmente la ejecusión del programa, para que alcancemos a leer la consola
  return 0;                             // Valor de retorno, en main 0 significa NO HUBO PROBLEMA
}

