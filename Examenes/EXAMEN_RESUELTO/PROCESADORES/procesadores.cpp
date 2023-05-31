/*
NOMBRE Y APELLIDOS: 

IMPORTANTE: Si no se añade el nombre y apellidos,
el ejercicio no se corregirá (puntuará como 0).

*/
#include <iostream>

using namespace std;


const int MAX_PROCESOS = 100; 

// Tipo para codificar los datos de entrada
// al problema
typedef struct {
	int t_procesamiento;  // Tiempo de procesamiento 'T' de los procesadores.
	                      // Cada procesador permite utizar, como máximo,
						  // 'T' unidades de tiempo.
	int t_procesos[MAX_PROCESOS];  // Unidades de tiempo requeridas por cada proceso. 
	int b_procesos[MAX_PROCESOS];  // Beneficio reportado por cada proceso.
	int n;                         // Número de procesos 'N' (n <= MAX_PROCESOS).
} tEntrada;

typedef struct 
{
  int max_beneficio;
  int beneficio_Act;
  int beneficio_restante;
  int procesamientoReal;
  int procesRestante[2];
  int procesoActual;
  bool procesosHechos[MAX_PROCESOS];
}Solucion;



/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del diseño del algoritmo. No 
se tendrá en cuenta la codificación del algoritmo, a menos que
esté acompañada del diseño sistemático del mismo.
*/


/*
(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Si estás utilizando algún criterio de poda adicional, explica detalladamente
    el criterio utilizado

(7) Análisis de casos

(7.1) Caso(s) base


(7.2) Caso(s) recursivos

(8) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.




*/
void encuentra_beneficio(const tEntrada& entrada, Solucion& sol){

for(int i = sol.procesoActual ; i < entrada.n; i++){
   if(!sol.procesosHechos[i] || sol.procesRestante == 0){
    if(sol.beneficio_Act > sol.max_beneficio) sol.max_beneficio = sol.beneficio_Act;  
    return;
  }else if(sol.procesRestante[0] - entrada.t_procesos[i] >= 0 ||
          sol.procesRestante[1] - entrada.t_procesos[i] >= 0){
    int eleccion;
    (sol.procesRestante[0] - entrada.t_procesos[i] >= 0)? eleccion = 0 : eleccion = 1;  
    sol.procesRestante[eleccion] -= entrada.t_procesos[i];
    sol.beneficio_Act += entrada.b_procesos[i];
    sol.beneficio_restante -= entrada.b_procesos[i];
    sol.procesosHechos[i] = false;
    //si no me queda tiempo de procesamiento vuelvo.
    if(sol.beneficio_Act + sol.beneficio_restante > sol.max_beneficio){
      //poda que establece que solo siga buscando si las posibles soluciones restantes 
      //son mejores que las que tengo.
      sol.procesoActual++;
      encuentra_beneficio(entrada,sol);
      sol.procesoActual--;
   }
    //quito el resultado de la solucion para poder explorar la siguiente solucion
    if(sol.beneficio_Act > sol.max_beneficio) sol.max_beneficio = sol.beneficio_Act;
    sol.beneficio_restante += entrada.b_procesos[i];
    sol.procesRestante[eleccion] += entrada.t_procesos[i];
    sol.beneficio_Act -= entrada.b_procesos[i]; 
    sol.procesosHechos[i] = true; 
  }
 }
}


int max_beneficio(const tEntrada& entrada) {
	// A IMPLEMENTAR: Debe devolver el beneficio máximo
	// que puede conseguirse
  Solucion solucion;
  solucion.max_beneficio=0;
  solucion.beneficio_Act = 0;
  solucion.procesamientoReal = entrada.t_procesamiento * 2;
  solucion.procesRestante[0] = entrada.t_procesamiento;
  solucion.procesRestante[1] = entrada.t_procesamiento;
  solucion.procesoActual = 0;
  solucion.beneficio_restante = 0;
  for(int i = 0; i < entrada.n;i++){   
    solucion.procesosHechos[i] = true;
    solucion.beneficio_restante += entrada.b_procesos[i];
  }
  encuentra_beneficio(entrada,solucion);
  return solucion.max_beneficio;
}


/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el código que sigue no se corregirán (puntuarán 0).

bool ejecuta_caso() {
	int t_procesamiento;
	int n_procesos;
	cin >> t_procesamiento >> n_procesos;
	if (t_procesamiento == 0 && n_procesos == 0) {
		return false;
	}
	else {
		tEntrada entrada;
		entrada.n = n_procesos;
		entrada.t_procesamiento = t_procesamiento;
		for (int p = 0; p < n_procesos; p++) {
			cin >> entrada.t_procesos[p];
		}
		for (int p = 0; p < n_procesos; p++) {
			cin >> entrada.b_procesos[p];
		}
		cout << max_beneficio(entrada) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}



