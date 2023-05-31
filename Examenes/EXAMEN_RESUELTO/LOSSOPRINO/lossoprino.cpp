/*
NOMBRE Y APELLIDOS:

Nº USUARIO DOMJUDGE:

*/

#include <iostream>

using namespace std;

const int MAX_PERSONAS = 20;
const int MAX_VEHICULOS = 10;


// Datos de entrada
typedef struct {
	bool ha_bebido[MAX_PERSONAS];   // ha_bebido[i]: La persona i ha bebido
	int capacidad[MAX_VEHICULOS];   // capacidad[v]: Nº de personas que caben en el vehículo v 
	int n_personas;                 // Nº total de personas en el clan
	int n_vehiculos;                // Nº total de vehículos
} tDatos;

typedef struct{
  int borrachos[MAX_VEHICULOS];
  int serenos[MAX_VEHICULOS];
}Marcadores;



/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/

bool puedeAsignarse(const tDatos& datos,int persona, int coche, Marcadores& m,
                    int serenos_restantes, int vehiculos_sin_conductor){
int ocupacion = m.borrachos[coche]+m.serenos[coche];
if(ocupacion == datos.capacidad[coche])return false;
if(datos.ha_bebido[persona] && (datos.capacidad[coche]/2) < (m.borrachos[coche]+1)) return false;
if(datos.ha_bebido[persona] && (ocupacion+1 == datos.capacidad[coche] && m.serenos[coche] == 0))
    return false;
if(!datos.ha_bebido[persona] && m.serenos[coche] > 0 && serenos_restantes == vehiculos_sin_conductor)
    return false;
return true;
}

void asignar(const tDatos& datos,
             int persona,
             int coche,
             Marcadores& m,
             int& serenos, int& coches_sin_conductor){
  if(datos.ha_bebido[persona]){
    m.borrachos[coche]++;
    return;
  }
  serenos--;
  if(m.serenos[coche] == 0)coches_sin_conductor--;
  m.serenos[coche]++;
}


void desasignar(const tDatos& datos,
             int persona,
             int coche,
             Marcadores& m,
             int& serenos, int& coches_sin_conductor){
  if(datos.ha_bebido[persona]){
  m.borrachos[coche]--;
  return;
  }
  serenos++;
  m.serenos[coche]--; 
  if(m.serenos[coche] == 0)coches_sin_conductor++;
}

void encontrar_sols(const tDatos& datos,
                     int& sols, 
                     int p,
                     int vehiculos_sin_conductor,
                     int serenos_restantes,
                     Marcadores& m
){
  if(p == datos.n_personas) 
    sols++;
  else{
    for(int c = 0; c < datos.n_vehiculos; c++){
      if(puedeAsignarse(datos,p,c,m, serenos_restantes, vehiculos_sin_conductor)){
        int nuevosSerenos = serenos_restantes, nuevosVehiculos = vehiculos_sin_conductor;
        asignar(datos,p,c,m,nuevosSerenos,nuevosVehiculos);
        encontrar_sols(datos,sols,p+1,nuevosVehiculos,nuevosSerenos,m);
        desasignar(datos,p,c,m,nuevosSerenos,nuevosVehiculos);
      }
    }
  }
}

int num_asignaciones(const tDatos& datos) {
	// A IMPLEMENTAR
  int sols= 0,num_serenos=0;
  Marcadores m;
  for(int i = 0; i < datos.n_personas; i++){
    if(!datos.ha_bebido[i])num_serenos++;
  }
  for(int i= 0; i<datos.n_vehiculos;i++){
    m.borrachos[i] = 0;
    m.serenos[i] = 0;
  }
  encontrar_sols(datos,sols,0,datos.n_vehiculos,num_serenos,m);
  return sols;
}


bool ejecuta() {
	tDatos datos;
	cin >> datos.n_vehiculos;
	if (datos.n_vehiculos == -1) return false;
	cin >> datos.n_personas;
	for (int v = 0; v < datos.n_vehiculos; v++) {
		int bebe;
		cin >> datos.capacidad[v];
	}
	for (int p = 0; p < datos.n_personas; p++) {
		int bebe;
		cin >> bebe;
		if (bebe == 0) {
			datos.ha_bebido[p] = false;
		}
		else {
			datos.ha_bebido[p] = true;
		}
	}
	cout << num_asignaciones(datos) << endl;
	return true;

}


int main() {
	while (ejecuta());
}