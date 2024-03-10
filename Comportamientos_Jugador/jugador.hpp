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
      girar_derecha=true;
      girar_45_grados = true;
      bien_situado = false;
      bikini=false;
      zapatillas=false;
      //visitados = {false};
      numGiros = 0;
      tamanioMapa = size;
      last_action = actIDLE;
      contador_visitados_otra = 0;
      /*for (int i = 0;i < 3 ; i++){
        for (int j = 0; j < tamanioMapa; j++ ){
          mapaResultado[i][j] = 'P';
          mapaResultado[tamanioMapa-i-1][j] = 'P';
          mapaResultado[j][i] = 'P';
          mapaResultado[j][tamanioMapa-i-1] = 'P';
        }
      }*/
      

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
  bool girar_derecha, bien_situado,bikini,zapatillas,recargando,girar_45_grados;
  //bool visitados[MAX+1][MAX+1];
  int contador_visitados_otra;
  const int bateria_baja = 2000;
  const int bateria_muy_baja = 500;
  const int bateriaRecarga = 4500;
  const int vidaBaja = 1000;
  const int factorVidaBateria = 3;
  int numGiros;
  int tamanioMapa;
};
#endif
