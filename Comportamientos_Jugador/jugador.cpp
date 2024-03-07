#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;

Action ComportamientoJugador::think(Sensores sensores)
{

	Action accion = actWALK;//actIDLE es para que no se mueva, actWALK para
				//moverse, actRUN para que corra 
	int a;

	switch (last_action)
	{
	case actWALK:
		//actualizacion en caso de avanzar, la brujula se queda igual
		break;
	case actRUN:
		//actualizacion en caso de avanzar, la brujula se queda igual
		break;
	case actTURN_L:
		a = current_state.brujula;
		a = (a+6)%8;
		current_state.brujula = static_cast<Orientacion>(a); //giramos la camara a izquierda

		break;
	case actTURN_SR:
		a = current_state.brujula;
		a = (a+1)%8;
		current_state.brujula = static_cast<Orientacion>(a);

		break;

	}



	// Mostrar el valor de los sensores
	cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC;
	switch (sensores.sentido)
	{
		case norte:	  cout << " Norte\n";	break;
		case noreste: cout << " Noreste\n";	break;
		case este:    cout << " Este\n";	break;
		case sureste: cout << " Sureste\n";	break;
		case sur:     cout << " Sur\n";	break;
		case suroeste:cout << " Suroeste\n";	break;
		case oeste:   cout << " Oeste\n";	break;
		case noroeste:cout << " Noroeste\n";	break;
	}
	cout << "Terreno: ";
	for (int i=0; i<sensores.terreno.size(); i++)
		cout << sensores.terreno[i];

	cout << "  Agentes: ";
	for (int i=0; i<sensores.agentes.size(); i++)
		cout << sensores.agentes[i];

	cout << "\nColision: " << sensores.colision;
	cout << "  Reset: " << sensores.reset;
	cout << "  Vida: " << sensores.vida << endl<< endl;

	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}
