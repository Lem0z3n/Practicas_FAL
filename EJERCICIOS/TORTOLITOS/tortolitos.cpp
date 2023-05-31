
#include <iostream>
using namespace std;

const unsigned int MAX_CLIENTES = 10; // maximo numero de clientes
  // Representaci�n de la matriz de afinidades
typedef struct {
	unsigned int n_clientes;                              // numero de clientes. 
	unsigned int afinidades[MAX_CLIENTES][MAX_CLIENTES];  // la matriz se almacena en las 'n_clientes' primeras filas,
	                                                      // 'n_clientes' primeras columnas	                                                      
} tMatrizAfinidad;

typedef struct{
  unsigned int parejas[MAX_CLIENTES];
  bool emparejados[MAX_CLIENTES];
  unsigned int max_afinidad; 
  unsigned int n_parejas;
}tSolucion;
						 
/*

(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos

(2) �C�mo son las soluciones parciales de este problema?

(3) �Cu�ndo una soluci�n parcial es viable?

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?

(6) An�lisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.



*/
bool viable(tSolucion& sol, int afinidad, int soltero, int chica){
  if(sol.emparejados[chica]) return false;
  sol.parejas[sol.n_parejas] = afinidad;
  sol.emparejados[soltero] = true;
  sol.emparejados[chica] = true;
  sol.n_parejas++;
  return true;
}

void checkSol(tSolucion& sol){
  int solPar = 0; 
  for(int i = 0; i < sol.n_parejas; i++){
    solPar += sol.parejas[i];
  }
  if(solPar > sol.max_afinidad) sol.max_afinidad = solPar;
}


void encuentra_maxima(const tMatrizAfinidad& as, tSolucion& sol, int soltero){
if(!sol.emparejados[soltero]){
  for(int i = soltero+1; i < as.n_clientes; i++){
    int afinidadInicial = as.afinidades[soltero][i];
    if(afinidadInicial > 0 && as.afinidades[i][soltero] >0){
      int afinidadPar = afinidadInicial + as.afinidades[i][soltero];
      if(viable(sol,afinidadPar,soltero,i)){
        encuentra_maxima(as,sol,soltero+1);
        sol.emparejados[soltero] = false;
        sol.emparejados[i] = false;
        sol.parejas[soltero] = 0;
        sol.n_parejas--;
      }
    }
  }
}
else if(soltero != as.n_clientes-1)
  encuentra_maxima(as,sol,soltero+1);
else 
  checkSol(sol) ;
}

int maxima_afinidad(const tMatrizAfinidad& as) {
	// Punto de entrada al algoritmo: as representa la matriz de afinidades 
	// (ver definici�n de tMatrizAfinidad). Una vez finalizado el algoritmo,
	// deber� devolverse el valor pedido. Pueden definirse todas las 
	// funciones auxiliares que se considere oportuno.
  tSolucion sol;
  sol.max_afinidad = 0;
  for(int i = 0; i < as.n_clientes; i++){
    sol.emparejados[i] = false;
  }
  sol.n_parejas = 0;
  encuentra_maxima(as,sol,0);
  return sol.max_afinidad;
}


void ejecuta_caso() {
	tMatrizAfinidad as;
	cin >> as.n_clientes;
	for (unsigned int i = 0; i < as.n_clientes; i++) {
		for (unsigned int j = 0; j < as.n_clientes; j++) {
			cin >> as.afinidades[i][j];
		}
	}
	cout << maxima_afinidad(as) << endl;
}


int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (unsigned int i = 0; i < num_casos; i++) {
		ejecuta_caso();
	}
}