#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//bool visitados [100][100] = {false};
//queue<pair<int,pair<int,char>>> pos_visitadas;

void PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st,vector< vector<unsigned char>> &matriz){

	//Por ahora la pondra solo la de componente a 0 pero pondra todas las componentes del terreno en funcion de la 
	//orientacion del agente
	matriz[st.fil][st.col] = terreno[0];

	//aqui vamos a poner la como se llena dependiendo de la orientacion

	 switch(st.brujula){

		case norte:
			matriz[st.fil-1][st.col-1] = terreno[1];
			matriz[st.fil-1][st.col] = terreno[2];
			matriz[st.fil-1][st.col+1] = terreno[3];
			matriz[st.fil-2][st.col-2] = terreno[4];
			matriz[st.fil-2][st.col-1] = terreno[5];
			matriz[st.fil-2][st.col] = terreno[6];
			matriz[st.fil-2][st.col-1] = terreno[7];
			matriz[st.fil-2][st.col+2] = terreno[8];
			matriz[st.fil-3][st.col-3] = terreno[9];
			matriz[st.fil-3][st.col-2] = terreno[10];
			matriz[st.fil-3][st.col-1] = terreno[11];
			matriz[st.fil-3][st.col] = terreno[12];
			matriz[st.fil-3][st.col+1] = terreno[13];
			matriz[st.fil-3][st.col-2] = terreno[14];
			matriz[st.fil-3][st.col+3] = terreno[15];
			break;

		case sur:
			matriz[st.fil+1][st.col+1] = terreno[1];
			matriz[st.fil+1][st.col] = terreno[2];
			matriz[st.fil+1][st.col-1] = terreno[3];
			matriz[st.fil+2][st.col+2] = terreno[4];
			matriz[st.fil+2][st.col+1] = terreno[5];
			matriz[st.fil+2][st.col] = terreno[6];
			matriz[st.fil+2][st.col-1] = terreno[7];
			matriz[st.fil+2][st.col-2] = terreno[8];
			matriz[st.fil+3][st.col+3] = terreno[9];
			matriz[st.fil+3][st.col+2] = terreno[10];
			matriz[st.fil+3][st.col+1] = terreno[11];
			matriz[st.fil+3][st.col] = terreno[12];
			matriz[st.fil+3][st.col-1] = terreno[13];
			matriz[st.fil+3][st.col-2] = terreno[14];
			matriz[st.fil+3][st.col-3] = terreno[15];
			break;		
		case este:
			matriz[st.fil-1][st.col+1] = terreno[1];
			matriz[st.fil][st.col+1] = terreno[2];
			matriz[st.fil+1][st.col+1] = terreno[3];
			matriz[st.fil-2][st.col+2] = terreno[4];
			matriz[st.fil-1][st.col+2] = terreno[5];
			matriz[st.fil][st.col+2] = terreno[6];
			matriz[st.fil+1][st.col+2] = terreno[7];
			matriz[st.fil+2][st.col+2] = terreno[8];
			matriz[st.fil-3][st.col+3] = terreno[9];
			matriz[st.fil-2][st.col+3] = terreno[10];
			matriz[st.fil-1][st.col-3] = terreno[11];
			matriz[st.fil][st.col+3] = terreno[12];
			matriz[st.fil+1][st.col+3] = terreno[13];
			matriz[st.fil+2][st.col+3] = terreno[14];
			matriz[st.fil+3][st.col+3] = terreno[15];
			break;		
		case oeste:
			matriz[st.fil+1][st.col-1] = terreno[1];
			matriz[st.fil][st.col-1] = terreno[2];
			matriz[st.fil-1][st.col-1] = terreno[3];
			matriz[st.fil+2][st.col-2] = terreno[4];
			matriz[st.fil+1][st.col-2] = terreno[5];
			matriz[st.fil][st.col-2] = terreno[6];
			matriz[st.fil-1][st.col-2] = terreno[7];
			matriz[st.fil-2][st.col-2] = terreno[8];
			matriz[st.fil+3][st.col-3] = terreno[9];
			matriz[st.fil+2][st.col-3] = terreno[10];
			matriz[st.fil+1][st.col-3] = terreno[11];
			matriz[st.fil][st.col-3] = terreno[12];
			matriz[st.fil-1][st.col-3] = terreno[13];
			matriz[st.fil-2][st.col-3] = terreno[14];
			matriz[st.fil-3][st.col-3] = terreno[15];
			break;
		case noreste:
			matriz[st.fil-1][st.col] = terreno[1];
			matriz[st.fil-1][st.col+1] = terreno[2];
			matriz[st.fil][st.col+1] = terreno[3];
			matriz[st.fil-2][st.col] = terreno[4];
			matriz[st.fil-2][st.col+1] = terreno[5];
			matriz[st.fil-2][st.col+2] = terreno[6];
			matriz[st.fil-1][st.col+2] = terreno[7];
			matriz[st.fil][st.col+2] = terreno[8];
			matriz[st.fil-3][st.col] = terreno[9];
			matriz[st.fil-3][st.col+1] = terreno[10];
			matriz[st.fil-3][st.col+2] = terreno[11];
			matriz[st.fil-3][st.col+3] = terreno[12];
			matriz[st.fil-2][st.col+3] = terreno[13];
			matriz[st.fil-1][st.col+3] = terreno[14];
			matriz[st.fil][st.col+3] = terreno[15];
			break;
		case noroeste:
			matriz[st.fil][st.col-1] = terreno[1];
			matriz[st.fil-1][st.col-1] = terreno[2];
			matriz[st.fil-1][st.col] = terreno[3];
			matriz[st.fil][st.col-2] = terreno[4];
			matriz[st.fil-1][st.col-2] = terreno[5];
			matriz[st.fil-2][st.col-2] = terreno[6];
			matriz[st.fil-2][st.col-1] = terreno[7];
			matriz[st.fil-2][st.col] = terreno[8];
			matriz[st.fil][st.col-3] = terreno[9];
			matriz[st.fil-1][st.col-3] = terreno[10];
			matriz[st.fil-2][st.col-3] = terreno[11];
			matriz[st.fil-3][st.col-3] = terreno[12];
			matriz[st.fil-3][st.col-2] = terreno[13];
			matriz[st.fil-3][st.col-1] = terreno[14];
			matriz[st.fil-3][st.col] = terreno[15];
			break;
		case sureste:
			matriz[st.fil][st.col+1] = terreno[1];
			matriz[st.fil+1][st.col+1] = terreno[2];
			matriz[st.fil+1][st.col] = terreno[3];
			matriz[st.fil][st.col+2] = terreno[4];
			matriz[st.fil+1][st.col+2] = terreno[5];
			matriz[st.fil+2][st.col+2] = terreno[6];
			matriz[st.fil+2][st.col+1] = terreno[7];
			matriz[st.fil+2][st.col] = terreno[8];
			matriz[st.fil][st.col+3] = terreno[9];
			matriz[st.fil+1][st.col+3] = terreno[10];
			matriz[st.fil+2][st.col+3] = terreno[11];
			matriz[st.fil+3][st.col+3] = terreno[12];
			matriz[st.fil+3][st.col+2] = terreno[13];
			matriz[st.fil+3][st.col+1] = terreno[14];
			matriz[st.fil+3][st.col] = terreno[15];
			break;
		case suroeste:
			matriz[st.fil+1][st.col] = terreno[1];
			matriz[st.fil+1][st.col-1] = terreno[2];
			matriz[st.fil][st.col-1] = terreno[3];
			matriz[st.fil+2][st.col] = terreno[4];
			matriz[st.fil+2][st.col-1] = terreno[5];
			matriz[st.fil+2][st.col-2] = terreno[6];
			matriz[st.fil+1][st.col-2] = terreno[7];
			matriz[st.fil][st.col-2] = terreno[8];
			matriz[st.fil+3][st.col] = terreno[9];
			matriz[st.fil+3][st.col-1] = terreno[10];
			matriz[st.fil+3][st.col-2] = terreno[11];
			matriz[st.fil+3][st.col-3] = terreno[12];
			matriz[st.fil+2][st.col-3] = terreno[13];
			matriz[st.fil][st.col-3] = terreno[14];
			matriz[st.fil][st.col-3] = terreno[15];
			break;

	}


}

Action ComportamientoJugador::think(Sensores sensores)
{

	
	Action accion = actIDLE;//actIDLE es para que no se mueva, actWALK para
				//moverse, actRUN para que corra
	int a;
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
	cout << "  Vida: " << sensores.vida << endl<< endl;//informacion
	
	switch (last_action) //ultima accion
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
		//actualizacion en caso de avanzar no acabado
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
	case actIDLE:
		break;

	}

	if (sensores.terreno[0] == 'G' and !bien_situado){ //Orientacion

		current_state.fil = sensores.posF;
		current_state.col = sensores.posC;
		current_state.brujula = sensores.sentido;
		bien_situado = true;

	}

	if (bien_situado){
		PonerTerrenoEnMatriz(sensores.terreno,current_state,mapaResultado);
		//visitados[current_state.fil][current_state.col]=true;
		//bien_situado = false;
	}

	//Decidir nueva accion
	if ((sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or 	sensores.terreno[2] == 'A' or sensores.terreno[2] == 'K' or sensores.terreno[2] == 'D' or sensores.terreno[2] == 'X' or sensores.terreno[2] == 'B') and sensores.agentes[2] == '_')

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
	state last_state = current_state;

	
	return accion;
	
	

}
int ComportamientoJugador::interact(Action accion, int valor){
	return false;
}

