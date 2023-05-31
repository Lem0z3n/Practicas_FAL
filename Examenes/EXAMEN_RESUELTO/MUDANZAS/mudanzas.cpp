
#include <iostream>
using namespace std;

const int MAX_OBJS = 20;

// Lista con los objetos a portar 
typedef struct {
	int tamanios[MAX_OBJS];  // Array en cuyas primeras posiciones se guardan
	                         // los tamaños de los objetos
	int n_objetos;           // Numero de objetos
} tObjetos;



/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos
Generalizacion:
  voy llenando las cajas con los posibles objetos cada caja que no quepa mas suma 1 a la sol.
    --int tam_Act E/S
    --bool Empaquetado[MAX_OBJS] E/S
    --int numCajas S
    --int minCajas S
    --int objetosPorEmpaquetar


(2) ¿Cómo son las soluciones parciales de este problema?

Todos los objetos metidos en cajas.

(3) ¿Cuándo una solución parcial es viable?

El tamaño de los objetos no supera la caja 

(4) ¿Cuándo una solución parcial es una solución final al problema?

cuando es la minima sol parcial

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

viendo si recolocando objetos elimino cajas.

(6) Análisis de casos

(6.1) Caso(s) base
todos los objetos empaquetados
  if(cajasAct < minCajas) minCajas = cajas;

(6.2) Caso(s) recursivos

for(int i = objActual; i < n_objetos; i++){
  comprobarSiCabe
    meterEnCaja
    minnumerocajas
    sacarDeCaja
  
}

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/
typedef struct{
  int numCajas;
  int minCajas;
  bool empaquetado[MAX_OBJS];
}tMarcadores;

bool entraEnCaja(const tObjetos& objetos, int objeto, int capacidad_restante){
  if(objetos.tamanios[objeto] > capacidad_restante)return false;
  return true;
}

void meterEnCaja(const tObjetos& objetos, int objeto, int& capacidad_restante, tMarcadores& m){
  capacidad_restante -= objetos.tamanios[objeto];
  if(capacidad_restante == 0)m.numCajas++;
  m.empaquetado[objeto] = true;
}

void sacarDeCaja(const tObjetos& objetos, int objeto, int capacidad_caja, int& capacidad_restante, tMarcadores& m){
  capacidad_restante += objetos.tamanios[objeto];
  if(capacidad_restante == capacidad_caja)m.numCajas++;
  m.empaquetado[objeto] = false;
}

void nuevaCaja(const tObjetos& objetos,int capacidad_caja,
                   int objeto,
                   int& capacidad_restante, tMarcadores& m ){
  m.numCajas++;
  capacidad_restante = capacidad_caja;
  m.empaquetado[objeto] = true;
}

void encuentra_min(const tObjetos& objetos, int capacidad_caja,
                   int capacidad_restante, int objetos_por_empaquetar,
                   int objetoAct, int objetosTotales,
                   tMarcadores& m)
{
  if(objetos_por_empaquetar == 0)
    if(m.numCajas < m.minCajas)
      m.minCajas  = m.numCajas;
  for(int i = objetoAct; i < objetosTotales; i++){
    if(entraEnCaja(objetos,i,capacidad_restante)){
      meterEnCaja(objetos,i,capacidad_restante,m);
      encuentra_min(objetos,capacidad_caja,capacidad_restante,objetos_por_empaquetar,objetoAct+1,objetosTotales,m);
      sacarDeCaja(objetos,i,capacidad_caja,capacidad_restante,m);
    }
    else nuevaCaja(objetos,capacidad_caja,i,capacidad_restante,m);
  }
}


int min_numero_de_cajas(const tObjetos& objetos, int capacidad_caja) {
	// A IMPLEMENTAR
	tMarcadores m;
  m.minCajas = 0;
  m.numCajas = 0;
  for(int i = 0; i < objetos.n_objetos;i++){
    m.empaquetado[i] = false;
  }
  encuentra_min(objetos,capacidad_caja,capacidad_caja,objetos.n_objetos,0,objetos.n_objetos,m);
  return m.minCajas;
}

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

bool ejecuta_caso() {
	int capacidad;
	cin >> capacidad;
	if (capacidad != -1) {
		tObjetos objetos;
		cin >> objetos.n_objetos;
		for (int i = 0; i < objetos.n_objetos; i++) {
			cin >> objetos.tamanios[i];
		}
		cout << min_numero_de_cajas(objetos,capacidad) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (ejecuta_caso());
}
