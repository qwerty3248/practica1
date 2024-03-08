#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;

void PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st,vector< vector<unsigned char>> &matriz){

	//Por ahora la pondra solo la de componente a 0 pero pondra todas las componentes del terreno en funcion de la 
	//orientacion del agente

	matriz[st.fil][st.col] = terreno[0];


}

Action ComportamientoJugador::think(Sensores sensores)
{

	Action accion = actIDLE;//actIDLE es para que no se mueva, actWALK para
				//moverse, actRUN para que corra 
	int a;

	switch (last_action)
	{
	case actWALK:
		//actualizacion en caso de avanzar
		switch (current_state.brujula)
		{
		case norte:
			current_state.fil--;
			break;
		
		case noroeste:
			current_state.col++; current_state.fil--;
			break;

		case este:
			current_state.col++;
			break;

		case sureste:
			current_state.col++; current_state.fil++;
			break;

		case sur:
			current_state.fil++;
			break;

		case suroeste:
			current_state.col--; current_state.fil++;
			break;

		case oeste:
			current_state.col--;
			break;

		case noreste:
			current_state.col--; current_state.fil--;
			break;

		}

		break;
	case actRUN:
		//actualizacion en caso de avanzar
		switch (current_state.brujula)
		{
		case norte:
			current_state.fil--;
			break;
		
		case noroeste:
			current_state.col++; current_state.fil--;
			break;

		case este:
			current_state.col++;
			break;

		case sureste:
			current_state.col++; current_state.fil++;
			break;

		case sur:
			current_state.fil++;
			break;

		case suroeste:
			current_state.col--; current_state.fil++;
			break;

		case oeste:
			current_state.col--;
			break;

		case noreste:
			current_state.col--; current_state.fil--;
			break;

		}		
		break;
	case actTURN_L:
		a = current_state.brujula;
		a = (a+6)%8;
		current_state.brujula = static_cast<Orientacion>(a); 

		break;
	case actTURN_SR:
		a = current_state.brujula;
		a = (a+1)%8;
		current_state.brujula = static_cast<Orientacion>(a);

		break;

	}

	if (sensores.terreno[0] == 'G' and !bien_situado){

		current_state.fil = sensores.posF;
		current_state.col = sensores.posC;
		current_state.brujula = sensores.sentido;
		bien_situado = true;

	}

	if (bien_situado){
		PonerTerrenoEnMatriz(sensores.terreno,current_state,mapaResultado);
	}

	//Decidir nueva accion
	if ((sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G') and sensores.agentes[2] == '_')
	{
		accion = actWALK;

	}
	else if(!girar_derecha){
		accion = actTURN_L;
		girar_derecha = (rand()%2==0);
	}else{
		accion = actTURN_SR;
		girar_derecha = (rand()%2==0);

	}
	
	last_action=accion;

	/*
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
	cout << "  Vida: " << sensores.vida << endl<< endl;*/

	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}
