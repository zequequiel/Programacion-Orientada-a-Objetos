/*
AUTOR: Ezequiel Arceo May
PROPÓSITO: calcula el área de formas geométricas
a partir de datos tomados de la consola
USO: ejecute y proporcione los datos solicitados
*/
#include <iostream>                       // Lee desde y escribe hacia la consola
#include <cmath>                          // Libreria de funciones matemáticas

using namespace std;                      // Se usa el espacio de nombres estándar

float areaCirculo(float radio) {
  float area = 0;                         // Defino una variable para guardar el área
  float PI = 3.1415;                      // Defino de la constante PI
  area = PI * radio * radio;              // Calculo el área
  return area;                            // Devuelve el valor área calculada
}

float areaRectangulo(float base, float altura) {
  float area = 0;                         // Defino una variable para guardar el área
  area = base * altura;                   // Calculo el área
  return area;                            // Devuelve el valor área calculada
}

float areaTriangulo(float base, float altura) {
  float area = 0;                          // Defino una variable para guardar el área
  area = base * altura / 2;                // Calculo el área
  return area;                             // Devuelve el valor área calculada
}


int main() {
  float area = 0;
  float radio = 0;                          // Variable flotante para contener un valor de radio
  float base = 0;                           // Variable flotante para contener un valor de base
  float altura = 0;                         // Variable flotante para contener un valor de altura

  cout << "[INFO] Trabajamos con el área un círculo" << endl;
  cout << "Ingrese ell valor del radio: ";  // Pedimos un valor del radio al usuario, 
  cin >> radio;                             // guardamos el valor del radio en la variable "radio"
  area = areaCirculo(radio);                // llamamos a la función que calcula el área
  cout << "El area del circulo de radio " 
  << radio << " es " << area << endl;
  system("pause");


  cout << "[INFO] Trabajamos con el área un rectángulo" << endl;
  cout << "Ingrese del valor de la base: ";   // Pedimos un valor de una base al usuario, 
  cin >> base;                                // guardamos el valor de base la variable "base"
  cout << "Ingrese del valor de la altura: "; // Pedimos un valor de una base al usuario, 
  cin >> altura;                              // guardamos el valor de base la variable "base"
  area = areaRectangulo(base, altura);        // llamamos a la función que calcula el área
  cout << "El area del rectangulo de base " 
  << base << " y altura " << altura << " es " << area << endl;
  system("pause");
  

  cout << "[INFO] Trabajamos con el área un triángulo" << endl;
  cout << "Ingrese del valor de la base: ";     // Pedimos un valor de una base al usuario, 
  cin >> base;                                  // guardamos el valor de base la variable "base"
  cout << "Ingrese del valor de la altura: ";   // Pedimos un valor de una base al usuario, 
  cin >> altura;                                // guardamos el valor de base la variable "base"
  area = areaTriangulo(base, altura);           // llamamos a la función que calcula el área
  cout << "El area del triángulo de base " 
  << base << " y altura " << altura << " es " << area << endl;
  system("pause");

  return 0;
}

