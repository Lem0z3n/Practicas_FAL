#include <iostream>
using namespace std;

const unsigned int MAX_NINIOS = 20; // maximo numero de ni�os
                                    // el n�mero de sitios siempre
									// ser� menor o igual que el
									// n�mero de ni�os

  // Representaci�n de la matriz de satisfacciones
typedef struct {
	int n_ninios;	// numero de ni�os.
    int n_sitios;	// numero de sitios
	int sat[MAX_NINIOS][MAX_NINIOS];  // la posici�n i,j representa la satisfaccion
                                      // que siente el ninio i si se le asigna el sitio j											   
} tMatrizSatisfacciones;


/*
(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos

Generalizacion:
    --- supersticion: cuantos asientos cumplen la supersticion. (E/S)
    --- maxSatisfaccion: satisfaccion maxima conseguida hasta ahora (S)
    --- posHermano: posicion del hermano(Entrada)
    --- asiento_dado[]: si hemos dado ya este asiento
    --- 

(2) �C�mo son las soluciones parciales de este problema?
    --sin numeros negativos
    --sin superar la supersticion
    --con el hermano sentado
(3) �Cu�ndo una soluci�n parcial es viable?

    cuando: 
    supersticion < m/3; 
        ninguna comodidad negativa;
        el hermano va;

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?
 cuando es la mayor de todas las soluciones parciales.
(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?
 conservando el sitio del hermano con mas valor y añadiendo el resto

(6) An�lisis de casos

(6.1) Caso(s) base
no quedan sitios por dar: apuntamos la satisfaccion obtenida si la supersticion lo permite y esta el hermano.

(6.2) Caso(s) recursivos
marcamos el sitio 
recursion 
desmarcamos 
(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.



*/
typedef struct{
    bool ninio_sentado[MAX_NINIOS];
    int supersticion;
    int maxSupersticion;
    bool hermanoInvitado;
}tMarcadores;

bool puedeAsignar(const tMatrizSatisfacciones& sats,int h,
                  int ninio, int asiento,
                  tMarcadores m){
int asientoSuper = ninio % sats.n_sitios;
if(sats.sat[ninio][asiento] < 0)return false;
if(m.ninio_sentado[ninio])return false;
if(m.supersticion+1 >= m.maxSupersticion && asiento == asientoSuper)return false;
if(!m.hermanoInvitado && ninio != h && asiento+1 == sats.n_sitios) return false;
return true;
}

void asignar(const tMatrizSatisfacciones& sats,int h,
        int ninio, int asiento,
        int& satisfaccion,
        tMarcadores& m){         
int asientoSuper = ninio % sats.n_sitios;
satisfaccion += sats.sat[ninio][asiento];
if(ninio == h)
  m.hermanoInvitado = true;
if(asiento == asientoSuper)
  m.supersticion++;
m.ninio_sentado[ninio] = true;
}

void desasignar(const tMatrizSatisfacciones& sats,int h,
        int ninio, int asiento,
        int& satisfaccion,
        tMarcadores& m){
int asientoSuper = ninio % sats.n_sitios;
satisfaccion -= sats.sat[ninio][asiento];
if(ninio == h)m.hermanoInvitado = false;
if(asiento == asientoSuper)m.supersticion--;
m.ninio_sentado[ninio] = false;
}

void comprobar(const tMatrizSatisfacciones& sats,
              int asiento, int satisfaccion,
              int& maxSatisfaccion,
              tMarcadores m)
{
              if(m.hermanoInvitado)
                  if(m.supersticion <= m.maxSupersticion)
                      if(satisfaccion > maxSatisfaccion){
                          maxSatisfaccion = satisfaccion;
                      }
          
}

void encuentra_maxima(const tMatrizSatisfacciones& sats, int h,
                     int asiento,
                     int& satisfaccion,
                     int& maxSatisfaccion,
                     tMarcadores& m)
{
  if(asiento == sats.n_sitios) 
          comprobar(sats,asiento,satisfaccion,maxSatisfaccion,m);
  else{
  for(int i = 0; i < sats.n_ninios; i++){
      if(puedeAsignar(sats,h,i,asiento,m)){
          asignar(sats,h,i,asiento,satisfaccion,m);
          encuentra_maxima(sats,h,asiento+1,satisfaccion,maxSatisfaccion,m);
          desasignar(sats,h,i,asiento,satisfaccion,m);
    }
    comprobar(sats,asiento,satisfaccion,maxSatisfaccion,m);
  }
  }
}


int satisfaccion_maxima(const tMatrizSatisfacciones& sats, int h) {
	// A IMPLEMENTAR
    int maxSupersticion = sats.n_sitios / 3;
    tMarcadores m;
    for(int i = 0; i < sats.n_ninios ; i++){
       m.ninio_sentado[i] = false;
    }
    m.supersticion = 0;
    m.hermanoInvitado = false;
    m.maxSupersticion = maxSupersticion;
    int maxSatis=0;
    int satis = 0;
   encuentra_maxima(sats,h,0,satis,maxSatis,m);
   return maxSatis;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */
					
bool ejecuta_caso() {
	tMatrizSatisfacciones sats;
	cin >> sats.n_ninios;
	if (sats.n_ninios != -1) {
	   cin >> sats.n_sitios;
	   int h;
	   cin >> h;
	   for (int sitio=0; sitio < sats.n_sitios; sitio++) {
		   for (int ninio=0; ninio < sats.n_ninios; ninio++) {
			   cin >> sats.sat[ninio][sitio];
		   }
	   }
	   cout << satisfaccion_maxima(sats,h) << endl; 
	   return true;
	}
	else {
		return false; 
	}
}	


int main() {
	while(ejecuta_caso());
}