#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include <queue>
#include "comportamientos/comportamiento.hpp"
using namespace std;

struct state
{
  int fil;
  int col;
  Orientacion brujula;
};
const int MAX = 99;

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      // Constructor de la clase
      // Dar el valor inicial a las variables de estado
      current_state.fil=MAX;
      current_state.col=MAX;
      current_state.brujula=norte;
      girar_derecha=false;
      bien_situado = false;
      bikini=false;
      zapatillas=false;
      numGiros = 0;
      last_action = actIDLE;
      
      

    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  // Declarar aquí las variables de estado
  state current_state; 
  //Orientacion brujula;
  Action last_action;
  bool girar_derecha, bien_situado,bikini,zapatillas,recargando;
  //bool visitados[MAX+1][MAX+1];
  int contador_visitados_otra;
  const int BATERIA_BAJA = 2000;
  const int BATERIA_MINIMA = 500;
  const int BATERIA_A_RECARGAR = 4500;
  const int POCOS_CICLOS = 1200;
  int numGiros;
};
#endif
