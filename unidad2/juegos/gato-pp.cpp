// JUEGO DE GATO EN VERSION PROCEDURAL
#include <iostream>
#include <vector>
using namespace std;

// Variables
char panel[3][3]; // tablero del juego
char jugador; // tomara valores 'X' o 'O'
char ganador; // la letra del quien gano el juego
int movimientosHechos; // Cuenta los movimientos hasta el momento
vector<int> ocupados;

bool encuentraEnVector(vector<int> vec, int elemento)
{
	for (int i = 0; i < vec.size(); i++)
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
	// Primera linea
	panel[0][0] = '1';
	panel[0][1] = '2';
	panel[0][2] = '3';
	// Segunda linea
	panel[1][0] = '4';
	panel[1][1] = '5';
	panel[1][2] = '6';
	// Tercera linea
	panel[2][0] = '7';
	panel[2][1] = '8';
	panel[2][2] = '9';
	jugador = 'X';
	ganador = ' ';
	ocupados.clear();
	movimientosHechos = 0;
}

void dibujaPanel()
{
	system("cls");
	cout << "GATO version 1.0 (procedural)" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << panel[i][j] << " ";
		}
		cout << endl;
	}
}

void leeEntrada()
{
	int posicion = 0;
	bool ocupado = true;

	while (ocupado || (posicion < 1) || (posicion > 9))
	{
		cout << "Jugador " << jugador << " elige una posici�n:";
		cin >> posicion;
		ocupado = encuentraEnVector(ocupados, posicion);
	}

	switch (posicion)
	{
	// Seleccion en la primera linea
	case 1:
		panel[0][0] = jugador;
		break;
	case 2:
		panel[0][1] = jugador;
		break;
	case 3:
		panel[0][2] = jugador;
		break;
	// Seleccion en la segunda linea
	case 4:
		panel[1][0] = jugador;
		break;
	case 5:
		panel[1][1] = jugador;
		break;
	case 6:
		panel[1][2] = jugador;
		break;
	// Seleccion en la tercera linea
	case 7:
		panel[2][0] = jugador;
		break;
	case 8:
		panel[2][1] = jugador;
		break;
	case 9:
		panel[2][2] = jugador;
		break;
	default:
		break;
	}
	movimientosHechos++;
	ocupados.push_back(posicion);
}

void cambiaJugador()
{
	if (jugador == 'X') 
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
	// Ganador por fila completa
	for (int i = 0; i < 3; i++)
	{
		if ((panel[i][0] == panel[i][1]) && (panel[i][1] == panel[i][2]))
		{
			ganador = panel[i][0];
		}
	}
	// Ganador por columna completa
	for (int j = 0; j < 3; j++)
	{
		if ((panel[0][j] == panel[1][j]) && (panel[1][j] == panel[2][j]))
		{
			ganador = panel[0][j];
		}
	}
	// Ganador por diagonal principal
	if ((panel[0][0] == panel[1][1]) && (panel[1][1] == panel[2][2]))
	{
		ganador = panel[0][0];
	}
	// Ganador en la diagonal invertida
	if ((panel[0][2] == panel[1][1]) && (panel[1][1] == panel[2][0]))
	{
		ganador = panel[0][2];
	}
  // Determinamos empate
	if ((ganador == ' ') && (movimientosHechos == 9)) 
	{
		ganador = '=';
	}
}

// Main
int main()
{
	reseteaJuego();
	dibujaPanel();
	while ( ganador == ' ' )
	{
		leeEntrada();
		dibujaPanel();
		decideGanador();
		cambiaJugador();
	}
	if (ganador == '=')
	{
		cout << "Es un empate." << endl;
	}
	else 
	{
		cout << "El jugador " << ganador << " gano la partida." << endl;
	}
	system("pause");
	return 0;
}
