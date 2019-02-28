/*
AUTOR: Ezequiel Arceo May
PROPÓSITO: Factorizar un número entero en sus factores primos
(un número primo es aquel que solo es divisible entre 1 y sí mismo)
USO: ejecute, inserte los datos requeridos
*/
#include <iostream>                     // Lee desde y escribe hacia la consola
#include <string>                       // Permite trabajar con cadenas en forma simple
#include <vector>

using namespace std;                    // Usa el espacio de nombres estándar

void imprimeVectorInt(vector<int> vec){
  for (int i = 0; i < vec.size(); i++) 
  {
    cout << vec[i] << endl;
  }
}

int main() {                            // TODO programa en C++ se ejecuta dentro de la función principal llamada main
  vector<int> factores;
  vector<int> primos = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
  int indice = 0;
  int divisor = 1;
  int numero;
  int cociente;
  
  cout << "Inserte un entero: ";
  cin >> numero;
  cociente = numero;
  cout << "Su entero es: " << numero << endl;
  while ( cociente != 1 )
  {
    divisor = primos[indice];
    cout << cociente << " es divisible entre " << divisor << " ?";
    if ( cociente % divisor == 0 ) 
    {
      factores.push_back(divisor);
      cout << " => SI" << endl;
      cociente = cociente / divisor;
    }
    else
    {
      indice = indice + 1;
      cout << " => NO" << endl;
    }
  }
  cout << "Los factores primos del número " << numero << " son: " << endl;
  imprimeVectorInt(factores);
  //system("pause");                      // Detiene temporalmente la ejecusión del programa, para que alcancemos a leer la consola
  return 0;                             // Valor de retorno, en main 0 significa NO HUBO PROBLEMA
}

