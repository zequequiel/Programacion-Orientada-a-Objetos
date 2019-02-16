/*
AUTOR: Ezequiel Arceo May
PROPÓSITO: Mostrar el uso de operadores aritméticos y de comparación.
USO: ejecute, no requiere datos de entrada
*/
#include <iostream>                     // Lee desde y escribe hacia la consola
#include <string>                       // Permite trabajar con cadenas en forma simple

using namespace std;                    // Usa el espacio de nombres estándar

int main() {                            // TODO programa en C++ se ejecuta dentro de la función principal llamada main
  int a = 7;
  int b = 2;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "[INFO] Trabajamos con Operadores Aritméticos" << endl;
  // Suma
  cout << "a + b = " << a + b << endl;
  // Resta
  cout << "a - b = " << a - b << endl;
  // Multiplicación
  cout << "a * b = " << a * b << endl;
  // División (entera)
  cout << "a / b = " << a / b << endl;
  cout << "7.0 / 2 = " << 7.0 / 2 << endl;
  // Módulo
  cout << "a % b = " << a % b << endl;

  cout << "[INFO] Trabajamos con Operadores de Comparación" << endl;
  // Menor o igual que
  cout << "a <= b = " << (a <= b) << endl;
  // Mayor que
  cout << "a > b = " << (a > b) << endl;
  // Mayor o igual que
  cout << "a  >=  b = " << (a >= b) << endl;
  // Igual
  cout << "a == b = " << (a ==  b) << endl;
  // No igual
  cout << "a != b = " << (a !=  b) << endl;
  system("pause");                      // Detiene temporalmente la ejecusión del programa, para que alcancemos a leer la consola
  return 0;                             // Valor de retorno, en main 0 significa NO HUBO PROBLEMA
}

