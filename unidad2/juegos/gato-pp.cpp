#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

char panel[3][3];
vector<int> ocupados;
char jugador;
char ganador;
int movimientosHechos;

bool encuentraEnVector(vector<int> vec, int elemento)
{
  for(int i=0; i < vec.size(); i++)
  {
    if (vec[i] == elemento)
    {
      return true;
    }
  }
  return false;
}

void reseteaJuego()
{
  panel[0][0] = '1';
  panel[0][1] = '2';
  panel[0][2] = '3';
  panel[1][0] = '4';
  panel[1][1] = '5';
  panel[1][2] = '6';
  panel[2][0] = '7';
  panel[2][1] = '8';
  panel[2][2] = '9';
  jugador = 'X';
  ganador = ' ';
  movimientosHechos = 0;
  ocupados.clear();
}

void dibujaPanel()
{
  //system("cls");//windows
  system("clear");//linux
  cout<<"Gato v1.0"<<endl;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << panel[i][j]<<" ";
    }
    cout<<endl;
  }
}

void leeEntrada()
{
  int posicion = 0;
  bool ocupado = true;
  while ((posicion < 1) || (posicion>9) || ocupado)
  {
    cout<<"Jugador '"<<jugador << "' elija su posición: ";
    cin >> posicion;
    ocupado = encuentraEnVector(ocupados, posicion);
    if (ocupado)
    {
      cout << "La posición " << posicion << " ya está ocupada." << endl;
    }
    else
    {
      int i = (posicion - 1) / 3;
      int j = (posicion - 1) % 3;
      panel[i][j] = jugador;
      ocupados.push_back(posicion);
      movimientosHechos++;
    }
    
  }
}

void cambiaJugador()
{
  if(jugador == 'X')
  {
    jugador = 'O';
  }
  else
  {
    jugador = 'X';
  }
}

void decideGanador()
{
  // Fila completa
  for (int i = 0; i < 3; i++)
  {
    if ((panel[i][0] == panel[i][1]) && (panel[i][1] == panel[i][2]))
    {
      ganador = panel[i][0];
    }
  }
  // Columna completa
  for (int j = 0; j < 3; j++)
  {
    if ((panel[0][j] == panel[1][j]) && (panel[1][j] == panel[2][j]))
    {
      ganador = panel[0][j];
    }
  }
  // Diagonal principal
  if ((panel[0][0] == panel[1][1]) && (panel[1][1] == panel[2][2]))
  {
    ganador = panel[1][1];
  }
  // Diagonal invertida
  if ((panel[0][2] == panel[1][1]) && (panel[1][1] == panel[2][0]))
  {
    ganador = panel[1][1];
  }
  if (movimientosHechos == 9)
  {
    ganador = '=';
  }
}

void juegaGato()
{
  reseteaJuego();
  dibujaPanel();
  while( ganador == ' ' )
  {
    leeEntrada();
    dibujaPanel();
    decideGanador();
    cambiaJugador();
  }
  if ( ganador == '=')
  {
    cout << "Fue un empate."<< endl;
  }
  else
  {
    cout << "El jugador '" <<ganador << "' ganó." << endl;
  }
}

int main()
{
  bool otroJuego = true;
  while( otroJuego )
  {
    juegaGato();
    cout << "Volver a jugar (1 = SI, 0 = NO): ";
    cin >> otroJuego;
  }
  return 0;
}
/*
DONE: Impedir la elección de la misma posición dos veces.
DONE: Determinar empate e imprimir cuando suceda.
TODO: Hacer que los símbolos de jugador sean configurables.
*/