/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:
GUILLERMO LEMONNIER

Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo:


*/


#include <iostream>

using namespace std;

static const int MAX_HOSPITALES = 20;
static const int MAX_PACIENTES = 20;

// Representaci�n de los datos de entrada
typedef struct {
	int distancia[MAX_PACIENTES][MAX_HOSPITALES]; // distancia[p][h] es la distancia que separa al paciente 'p'
	                                              // del hospital 'h'
	int capacidad[MAX_HOSPITALES]; // capacidad[i]: N�mero de pacientes que caben en el hospital i.
	int num_hospitales; // N�mero de hospitales
	int num_pacientes; // N�mero de pacientes;
} tEntrada;

typedef struct{
	int minDist;
	bool haymin;
	int curDist;
	int capacidadRes[MAX_HOSPITALES];
}tSolucion;

/*
(1) �C�mo son las soluciones parciales viables de este problema?
Son la suma de las distancias a los hospitales con capacidad mientras tienen capacidad
(2) �Cu�ndo una soluci�n es final?
Cuand es la mínima solucion.
(3) Dada una soluci�n viable, �c�mo se generan nuevas soluciones viables a partir de ella?
se retrocede hasta el elemento anterior a esta solucion y se busca un indice menor en la matriz
si lo hay.
(4) �C�mo se representar�n las soluciones en este problema? Describe los distintos elementos
    de informaci�n que las componen, indicando si se representan como par�metros de entrada,
	de entrada/salida (estado global), si se representan impl�citamente...
se representan con un entero mayor que 0 de entrada/salida
(5) �Qu� marcadores utiliza el algoritmo? Describe claramente su prop�sito, los elementos
    de informaci�n que los componen, as� como si dichos elementos se representan como par�metros
	de entrada, de entrada/salida (estado global)... 
utiliza las capacidades restantes de los hospitales disponibles entrada/salida,
 si ya se tiene una solucion salida,
 y la solucion actual que se está tratando entrada/salida
(6) Si el algoritmo utiliza generalizaci�n, indica como es la misma, describiendo claramente
    el prop�sito de cada par�metro.
	void gestion(const tEntrada& entrada, tSolucion& sol,int paciente)
	la entrada es de entrada (valga la redundancia), y sirve como los datos del problema
	la salida es de entrada/salida, y carga con los datos que necesito para generar una solucion final
	y el paciente es de entrada y nos dice en que punto del bucle estamos
(7) An�lisis de casos: casos base, casos recursivos
caso base = paciente == entrada.numpacientes
caso recursivo 
			for hospital in hospitales
			if(viable)
				gestion(entrada,sol,paciente+1)
(8) Si el algoritmo utiliza una generalizaci�n, describe c�mo se implementa el algoritmo
    en t�rminos de la misma (inmersi�n)
if(paciente == entrada.num_pacientes){
		if(!sol.haymin || sol.curDist < sol.minDist){
			sol.haymin = true;  primero busca una solucion parcial contra la que comparar el resto
			sol.minDist = sol.curDist;
		}
	}
	else{
		for(int hos = 0; hos< entrada.num_hospitales; hos++){
			if(sol.capacidadRes[hos]>0 &&(!sol.haymin || //necesito que el hospital tenga capacidad
			sol.curDist + entrada.distancia[paciente][hos] < sol.minDist)){ 
				//y si al sumarle esto va a ser peor que la sol que ya 
				tengo para que sumar esto o el resto
			sol.curDist += entrada.distancia[paciente][hos];
			sol.capacidadRes[hos]--; 
			gestion(entrada,sol,paciente+1); //voy buscando todas las soluciones parciales que son coherentes
			sol.capacidadRes[hos]++;
			sol.curDist -= entrada.distancia[paciente][hos];
*/
void gestion(const tEntrada& entrada, tSolucion& sol,int paciente){
	if(paciente == entrada.num_pacientes){
		if(!sol.haymin || sol.curDist < sol.minDist){
			sol.haymin = true;
			sol.minDist = sol.curDist;
		}
	}
	else{
		for(int hos = 0; hos< entrada.num_hospitales; hos++){
			if(sol.capacidadRes[hos]>0 &&(!sol.haymin || //necesito que el hospital tenga capacidad
			sol.curDist + entrada.distancia[paciente][hos] < sol.minDist)){ //y si al sumarle esto va a ser peor que la sol que ya tengo pa que sumar
			sol.curDist += entrada.distancia[paciente][hos];
			sol.capacidadRes[hos]--;
			gestion(entrada,sol,paciente+1);
			sol.capacidadRes[hos]++;
			sol.curDist -= entrada.distancia[paciente][hos];
			}
		}
	}
}


int min_distancias(const tEntrada& entrada) {
	// A IMPLEMENTAR
  tSolucion sol;
	sol.curDist = 0;
	sol.minDist = 0;
	sol.haymin = false;
	for(int i = 0; i < entrada.num_hospitales; i++){
		sol.capacidadRes[i] = entrada.capacidad[i];
	}
	gestion(entrada,sol,0);
	return (sol.minDist*2);
}


/*** A PARTIR DE AQUI NO MODIFICAR EL CODIGO ***/

void ejecuta_caso() {
	tEntrada entrada;
	cin >> entrada.num_pacientes >> entrada.num_hospitales;
	for (int h = 0; h < entrada.num_hospitales; h++) {
		cin >> entrada.capacidad[h];
    }
	for (int p = 0; p < entrada.num_pacientes; p++) {
		for (int h = 0; h < entrada.num_hospitales; h++) {
			cin >> entrada.distancia[p][h];
 		}
	}
	cout <<min_distancias(entrada) << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ejecuta_caso();
	}
}