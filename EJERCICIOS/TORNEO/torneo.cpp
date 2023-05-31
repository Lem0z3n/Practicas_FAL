
#include <iostream>

using namespace std;


/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.

entrada int max = max(a[]); sirve para saber el poder más grande de la cola
entrada int i = a[i] = max(a[]) la posicion del soldado mas poderoso
entrada/salida int contTorneos cuantos torneos mas puedo formar.
entrada/salida int tamTorneo; cuantos participantes tiene el torneo.
entrada int torneo[]; array del torneo
salida int poder = sum(torneo); poder total del torneo.
salida int sinTorneo; numero de contricantes aun sin torneo

(2) An�lisis de casos:

(2.1) Casos base
    if(poder > max)
        
        contTorneos--;
        

(2.2) Casos recursivos



(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.




(4) An�lisis de la complejidad del algoritmo

*/
bool addaTorneo(int& poderTotal, int poderPart, int max){
    poderTotal = poderTotal + poderPart;
    if(poderTotal < max){
        return true;
    } else { 
        poderTotal = poderTotal - poderPart;
        return false;
    }
}
int getTorneos(int enemigos[], int poderAcumulado, int max, int& torneosRes, int& pos, int fin){
    if(pos == fin){
        torneosRes--;
        return pos; //si llego al final de los contrincantes
    }
    if(!addaTorneo(poderAcumulado, enemigos[pos], max) && torneosRes > 0){
        torneosRes--;
        poderAcumulado = 0;
        getTorneos(enemigos, poderAcumulado, max, torneosRes, pos, fin);
    }
    else if(torneosRes != 0){
        pos++;
        getTorneos(enemigos, poderAcumulado, max, torneosRes, pos, fin);
    }
    else //si me he quedado sin torneos  
        return pos;
    return pos;
    }



int min_poder(int enemigos[], int n, int max_duelos) {
	// Punto de entrada al algoritmo: a implementar
    int max = enemigos[0];
    int maxPos;
    for(int i = 1; i < n; i++){
        if(max <= enemigos[i]){
            max = enemigos[i];
            maxPos = i;
        }
    }
    int poderAcumuluado = 0, primeraMitad, segundaMitad, pos = 0, torneosRes;
    torneosRes = max_duelos-1; //quito el duelo del maximo
    primeraMitad = getTorneos(enemigos, poderAcumuluado, max, torneosRes, pos, maxPos);
    pos++; //salto la posicion del maximo
    segundaMitad = getTorneos(enemigos, poderAcumuluado, max, torneosRes, pos, n);
    int maxPosFin = maxPos;
    while(primeraMitad != maxPos || segundaMitad != n){ 
        if (maxPosFin == n-1){ //modificar el valor de max si la primera aproximacion es erronea.
            maxPos--;
            max =max+ enemigos[maxPos];
        }else{
            maxPosFin++;
            max =max+ enemigos[maxPosFin++];
        }
        primeraMitad = getTorneos(enemigos, poderAcumuluado, max, torneosRes, pos, maxPos);
        segundaMitad = getTorneos(enemigos, poderAcumuluado, max, torneosRes, pos, n);
    }
    return max;
}


const int MAX_ENEMIGOS = 1000;
bool ejecuta_caso() {
	int enemigos[MAX_ENEMIGOS];
	int num_enemigos;
	cin >> num_enemigos;
	if (num_enemigos == -1) {
		return false;
	}
	else {
		int max_torneos;
		cin >> max_torneos;
		for (int i = 0; i < num_enemigos; i++) {
			cin >> enemigos[i];
		}
		cout << min_poder(enemigos, num_enemigos, max_torneos) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}
