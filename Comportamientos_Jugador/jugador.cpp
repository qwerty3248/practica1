#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
#include <stack>
#include <queue>
//#include <cmath>
using namespace std;

/*
#define PI 3.1415926535
inline int rotar_fil(const int & fil, const int & col , float a) {
	return -round(col*sin(a)-fil*cos(a));
}
inline int rotar_col(const int & fil, const int & col , float a) {
	return round(col*cos(a)+fil*sin(a));
}*/



void PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st,vector< vector<unsigned char>> &matriz, Sensores sensores){
	bool nivel_3 = (sensores.nivel == 3);
	//Por ahora la pondra solo la de componente a 0 pero pondra todas las componentes del terreno en funcion de la 
	//orientacion del agente
	matriz[st.fil][st.col] = terreno[0];
	//cout << st.fil << " "<< st.col <<endl;

	//aqui vamos a poner la como se llena dependiendo de la orientacion

	switch(st.brujula){

		case norte:
			matriz[st.fil-1][st.col-1] = terreno[1];
			matriz[st.fil-1][st.col] = terreno[2];
			matriz[st.fil-1][st.col+1] = terreno[3];
			matriz[st.fil-2][st.col-2] = terreno[4];
			matriz[st.fil-2][st.col-1] = terreno[5];
			matriz[st.fil-2][st.col] = terreno[6];
			matriz[st.fil-2][st.col+1] = terreno[7];
			matriz[st.fil-2][st.col+2] = terreno[8];
			matriz[st.fil-3][st.col-3] = terreno[9];
			matriz[st.fil-3][st.col-2] = terreno[10];
			matriz[st.fil-3][st.col-1] = terreno[11];
			matriz[st.fil-3][st.col] = terreno[12];
			matriz[st.fil-3][st.col+1] = terreno[13];
			matriz[st.fil-3][st.col+2] = terreno[14];
			matriz[st.fil-3][st.col+3] = terreno[15];
			if (!nivel_3){

			}
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
			matriz[st.fil-1][st.col+3] = terreno[11];
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
			matriz[st.fil+1][st.col-3] = terreno[14];
			matriz[st.fil][st.col-3] = terreno[15];
			break;


	}
	/*
	if (st.brujula%2){
		int n = 0;
		for (int i = 0; i >-4 ;i--){
			int fil = i, nextfil = i;
			int col = 0, nextcol = 0;
			while (fil <= 0)
			{
				if (col == -i){
					nextfil++;
				}else if (fil == i){
					nextcol++;
				}
				int nfil = st.fil+rotar_fil(fil,col,-PI/4*(st.brujula-1));
				int ncol = st.col+rotar_col(fil,col,-PI/4*(st.brujula-1));

				if (0 < nfil && nfil < matriz.size() && 0 <= ncol && ncol < matriz[0].size()){
					matriz[nfil][ncol]=terreno[n];
				}
				fil = nextfil;
				col = nextcol;
				n++;
			}
			
		}
	}*/

}
Action BuscarCasillaInteres(Sensores sensores,const bool zapatillas,const bool bikini,const bool bien_situado, bool &girar_derecha,const int BATERIA_MINIMA,const int BATERIA_BAJA ,const int POCOS_CICLOS){
	Action  accion = actIDLE;
	//prioridades a la hora de buscar casilla  de la mas a la menos prioritaria
	bool encontre_casilla_interes = false, peligro = false;
	//int aleat_giro; esto no se va a usar
	int pos_casilla_a_ir =  -1; //a -1 porque  es el unico valor que ya no esta dentro del rango del sensor
	//bool frente = (pos_casilla_a_ir == 2) || (pos_casilla_a_ir == 6) || (pos_casilla_a_ir == 12) || (pos_casilla_a_ir == 7) || (pos_casilla_a_ir == 5) || (pos_casilla_a_ir == 10) || (pos_casilla_a_ir == 11) || (pos_casilla_a_ir == 14) || (pos_casilla_a_ir == 13);
	//bool derecha = (pos_casilla_a_ir == 3) || (pos_casilla_a_ir == 8) || (pos_casilla_a_ir == 15);
	//bool izquierda = (pos_casilla_a_ir == 1) || (pos_casilla_a_ir == 9) || (pos_casilla_a_ir == 4);
	//Si estamos al limite de bateria y NO nos quedan pocos ciclos pues buscamos una casilla de recarga
	if (sensores.bateria <= BATERIA_MINIMA && !(sensores.vida < POCOS_CICLOS)){
		for (int i = 0; i < sensores.terreno.size() && !encontre_casilla_interes; i++){
			if (sensores.terreno[i] == 'X'){
				pos_casilla_a_ir = i;
				encontre_casilla_interes=true;
			}
		}
	}
	//Zapatillas 
	if (!zapatillas && !encontre_casilla_interes){
		for (int i = 0; i < sensores.terreno.size() && !encontre_casilla_interes; i++){
			if (sensores.terreno[i] == 'D'){
				pos_casilla_a_ir = i;
				encontre_casilla_interes=true;
				//cout<<"Encontre casilla zapas en "<<i<<endl;
			}
		}
	}

	//Bikini
	if (!bikini && !encontre_casilla_interes){
		for (int i = 0; i < sensores.terreno.size() && !encontre_casilla_interes; i++){
			if (sensores.terreno[i] == 'K'){
				pos_casilla_a_ir = i;
				encontre_casilla_interes=true;
				//cout<<"Encontre casilla bikini en "<<i<<endl;
			}
		}
	}
	//Situarse corerctamente, G
	if (!bien_situado && !encontre_casilla_interes){
		for (int i = 0; i < sensores.terreno.size() && !encontre_casilla_interes; i++){
			if (sensores.terreno[i] == 'G'){
				pos_casilla_a_ir = i;
				encontre_casilla_interes=true;
				//cout<<"Encontre casilla interes G en "<<i<<endl;
			}
			//cout << sensores.terreno[i]<<endl;
		}
	}

	//Si tenemos la bateria baja
	if (sensores.bateria < BATERIA_BAJA && !encontre_casilla_interes && !(sensores.vida <  POCOS_CICLOS)) {
		for (int i = 0; i < sensores.terreno.size() && !encontre_casilla_interes; i++){
			if (sensores.terreno[i] == 'X'){
				pos_casilla_a_ir = i;
				encontre_casilla_interes=true;
			}
		}
	}

	//Si no tenemos los items de bikini o zapatillas buscar una casilla que gaste menos ya que gasta mucha energia
	if ((!zapatillas && sensores.terreno[0] == 'B') || (!bikini && sensores.terreno[0] == 'A') && !encontre_casilla_interes) {
		for (int i = 0; i < sensores.terreno.size() && !encontre_casilla_interes; i++){
			if (sensores.terreno[i] == 'S' || sensores.terreno[i] == 'T'){
				pos_casilla_a_ir = i;
				encontre_casilla_interes=true;
			}
		}
	}	
	//Le daremos más prioridad porque no quiero que robotin muera =(
	//Si podemos porque tenemos bateria suficiente y tenemos los sensores activados, las esquivamos para que no nos maten y perder los sensores activados
	if (bien_situado && (sensores.bateria > BATERIA_BAJA)) {
		for (int i = 0; i < sensores.terreno.size() && !encontre_casilla_interes; i++){
			if (sensores.terreno[i] == 'l' || sensores.terreno[i] == 'a'){
				pos_casilla_a_ir = i;
				encontre_casilla_interes=true;
				peligro = true;
			}
		}
	}	

	//Si llegamos a encontrar una casilla de interes vemos que accion deseada hacer para llegar a ella 
	if (encontre_casilla_interes){
		//Ahora hay que ver por los sensores donde esta, si hay que girar a la derecha a la izquierda o hacia el frente
		//cout << "Encontre esta a true "<<endl;
		if ((pos_casilla_a_ir == 2) || (pos_casilla_a_ir == 6) || (pos_casilla_a_ir == 12) || (pos_casilla_a_ir == 7) || (pos_casilla_a_ir == 5) || (pos_casilla_a_ir == 10) || (pos_casilla_a_ir == 11) || (pos_casilla_a_ir == 14) || (pos_casilla_a_ir == 13)){
			//Si hay peligro giramos para no morir
			//cout << "Pa lante"<<endl;
			if (peligro){
				//cout << "Peligro"<<endl;
				if (girar_derecha){
					accion = actTURN_SR;
					girar_derecha = (rand()%2 == 0);
				}else{
					accion = actTURN_L;
					girar_derecha = (rand()%2 == 0);
				}
			}else{
				accion = actWALK;//Si no hay peligro podemos avanzar
			}

		}else if ((pos_casilla_a_ir == 3) || (pos_casilla_a_ir == 8) || (pos_casilla_a_ir == 15)){
			//cout << "Derecha "<<endl;
			if (peligro){
				accion = actTURN_L;
			}else{
				accion = actTURN_SR;//Si no hay peligro hacemos la accion correspondiente
			}			

		}else if ((pos_casilla_a_ir == 1) || (pos_casilla_a_ir == 9) || (pos_casilla_a_ir == 4)){
			//cout << "Izquierda "<<endl;
			if (peligro) {
				accion = actTURN_SR;
			}else{
				accion = actTURN_L;//Lo mismo aqui
			}

		}


	}
	//cout << accion<<endl;


	return accion;

}
Action RealizarAccion(Sensores sensores,const bool zapatillas,const bool bikini,const bool bien_situado, bool &girar_derecha,const int BATERIA_MINIMA,const int BATERIA_BAJA ,const int POCOS_CICLOS, const int BATERIA_A_RECARGAR,int &numGiros){
	Action accion=actIDLE;
	//Cuando voy a avanzar, puede ir cambiando si consigo items por ejemplo, el bikini o las zapatillas
	bool avanzo_si = sensores.terreno[2] == 'T' || sensores.terreno[2] == 'S';
	//Condicion que debe cumplirse siempre, que no haya colision, ni un muro ni un precipicio
	bool siempre_cumplir = (!sensores.colision) && sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' ;
	//Si tenemos poca bateria y estamos en una casilla de carga nos quedaremos en ella
	if ((sensores.terreno[0] == 'X') && ((sensores.bateria < BATERIA_BAJA) or (sensores.bateria+10 < BATERIA_A_RECARGAR))){//El +10 es lo que recarga 
		return accion; //Nos quedamos en el sitio si estamos en la x y tenemos la bateria baja o no hemos recargado lo suficiente
	}
	//Tenemos algun movimiento de interes ??
	accion = BuscarCasillaInteres(sensores,zapatillas,bikini,bien_situado,girar_derecha,BATERIA_MINIMA,BATERIA_BAJA,POCOS_CICLOS);
	//cout << accion<<endl;
	if (accion != actIDLE){
		if (accion == actWALK){
			if (siempre_cumplir){
				return accion;//Si cumple lo fundamental entonces va hacia delante
			}
		}else{
			return accion;//Si no es andar hacia delante, gira que es posible siempre
		}
	}

	if (sensores.bateria > BATERIA_MINIMA){
		if (bikini){
			avanzo_si = avanzo_si || sensores.terreno[2] == 'A' /*|| sensores.terreno[2] == 'K'*/; //Ahora podre caminar por agua sin que gaste mucha energia
		}
	}

	//Repetimos lo mismo para las zapatillas
	if (sensores.bateria > BATERIA_MINIMA){
		if (zapatillas){
		avanzo_si = avanzo_si || sensores.terreno[2] == 'B' /*|| sensores.terreno[2] == 'D'*/; //Ahora podre caminar por bosque sin que gaste mucha energia
		}
	}

	//Ahora vamos por si entramos a una casa
	if (numGiros > 30 ){ // si hemos girado más de 50 seguro que estamos atrapadados en una casa o en un sitio sin items lleno de agua o de bosque
		avanzo_si = avanzo_si || sensores.terreno[2] == 'B' ||  sensores.terreno[2] == 'A';
	}

	//una vez que tenemos la posible condicion de avanzar y la elemental que es que no sea ni pared ni precipicio ni colision y no haya ningun agente delante
	if (avanzo_si && siempre_cumplir){
		accion = actWALK; //Vamos hacia adelante
		if (numGiros >= 0){//Evitar negativo
			numGiros--;//Cuando avanzemos  decrementamos los giros disponibles
		}// si giramos mucho puede que estemos en un sitio cerrado o no tengamos items
	}else{//Si no se puede giramos aleatoriamente y actualizamos girar_derecha
		if (girar_derecha){
			accion = actTURN_SR;
			girar_derecha = (rand()%2 == 0);
		}else{
			accion = actTURN_L;
			girar_derecha = (rand()%2 == 0);
		}
		numGiros++;//SI hemos girado da igual para donde incrementamos 1 los giros
	}

	return accion;
	
}
Action ComportamientoJugador::think(Sensores sensores)
{



	Action accion = actIDLE;//actIDLE es para que no se mueva, actWALK para
				//moverse, actRUN para que corra

	if (sensores.reset){
		bikini=false;
		zapatillas=false;
		current_state.brujula=norte;
		bien_situado=false;
		current_state.fil = 99;
		current_state.col = 99;
	}
	int a;
	// Mostrar el valor de los sensores
	
	switch (last_action) //ultima accion
	{
	case actWALK:
		//actualizacion en caso de avanzar
		switch (current_state.brujula)
		{
		case norte:
			if (!sensores.colision){
				current_state.fil--;
			}
			break;

		case noroeste:
			if (!sensores.colision){
				current_state.col--; current_state.fil--;

			}
			break;

		case este:
			if (!sensores.colision){
				current_state.col++;
			}
			break;

		case sureste:
			if (!sensores.colision){
				current_state.col++; current_state.fil++;
			}
			
			break;

		case sur:
			if (!sensores.colision){
				current_state.fil++;
			}
			
			break;

		case suroeste:
			if (!sensores.colision){
				current_state.col--; current_state.fil++;
			}
			break;

		case oeste:
			if (!sensores.colision){
				current_state.col--;
			}
			break;

		case noreste:
			if (!sensores.colision) {
				current_state.col++; current_state.fil--;
			}
			break;

		}

		break;
	case actRUN:
		//actualizacion en caso de avanzar no acabado
		switch (current_state.brujula)
		{
		case norte:
			if (!sensores.colision){
				current_state.fil-=2;
			}
			break;

		case noroeste:
			if (!sensores.colision){
				current_state.col-=2; current_state.fil-=2;
			}
			break;

		case este:
			if (!sensores.colision){
				current_state.col+=2;
			}
			break;

		case sureste:
			if (!sensores.colision){
				current_state.col+=2; current_state.fil+=2;
			}
			break;

		case sur:
			if (!sensores.colision){
				current_state.fil+=2;
			}
			break;

		case suroeste:
			if (!sensores.colision){
				current_state.col-=2; current_state.fil+=2;
			}
			break;

		case oeste:
			if (!sensores.colision){
				current_state.col-=2;
			}
			break;

		case noreste:
			if (!sensores.colision){
				current_state.col+=2; current_state.fil-=2;
			}
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
	//cout << current_state.brujula<<endl;

	if (sensores.nivel == 0){
		bien_situado = true;
		current_state.fil = sensores.posF;
		current_state.col = sensores.posC;
		current_state.brujula = sensores.sentido;
	}	

	if ((sensores.terreno[0] == 'G') and !bien_situado){ //Orientacion

		current_state.fil = sensores.posF;
		current_state.col = sensores.posC;
		current_state.brujula = sensores.sentido;
		bien_situado = true;

	}

	if (bien_situado){
		PonerTerrenoEnMatriz(sensores.terreno,current_state,mapaResultado,sensores);

	}
	
	if (sensores.terreno[0] == 'D'){
		zapatillas = true;
	}
	
	if (sensores.terreno[0] == 'K'){
		bikini = true;
	}
	//Decidir nueva accion
	/*if ((sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or 	sensores.terreno[2] == 'A' or sensores.terreno[2] == 'K' or sensores.terreno[2] == 'D' or sensores.terreno[2] == 'X' or sensores.terreno[2] == 'B') and sensores.agentes[2] == '_')

	{
		accion = actWALK;

	}
	else if(!girar_derecha){
		accion = actTURN_L;
		girar_derecha = (rand()%2==0);
	}else{
		accion = actTURN_SR;
		girar_derecha = (rand()%2==0);

	}*/



	accion = RealizarAccion(sensores,zapatillas,bikini,bien_situado,girar_derecha,BATERIA_MINIMA,BATERIA_BAJA,POCOS_CICLOS,BATERIA_A_RECARGAR,numGiros);
	/*if (accion == actWALK){
		if (numGiros >= 0){
			numGiros--;
		}
	}else{
		numGiros++;
		girar_derecha = (rand()%2 == 0);
	}*/
	last_action=accion;
	//cout <<accion<<endl;
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

	
	return accion;
	
	

}
int ComportamientoJugador::interact(Action accion, int valor){
	return false;
}

