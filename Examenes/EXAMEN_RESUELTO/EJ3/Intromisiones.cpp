/*
NOMBRE Y APELLIDOS: 

IMPORTANTE: Si no se a�ade el nombre y apellidos,
el ejercicio no se corregir� (puntuar� como 0).

*/

#include <iostream>
using namespace std;


/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del dise�o del algoritmo. No 
se tendr� en cuenta la codificaci�n del algoritmo, a menos que
est� acompa�ada del dise�o sistem�tico del mismo.
*/


/*
(1) En caso de utilizar una generalizacion, 
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.


(2) An�lisis de casos:

(2.1) Casos base


(2.2) Casos recursivos

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n 
del algoritmo. Describe de manera clara y concisa c�mo se lleva a 
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.



(4)Determina justificadamente la complejidad del algoritmo

(4.1) Determinaci�n de las ecuaciones de recurrencia para la generalizaci�n

(4.2) Resoluci�n utilizando los patrones vistos en clase

(4.3) Determinaci�n justificada de la complejidad del algoritmo final.



*/
int entrometido(int a[], int b[], int n, int sumA, int sumB, int i, int j){
  if(j-i < 1){
    sumA += a[i];
    sumB += b[i];
  }
  else if(j-i < 2){
    sumA += a[i];
    sumA += a[j];
    sumB += b[i];
    sumB += b[j];
  }
  else{
    
    int auxJ = j/2;
    int auxI = ;
    entrometido(a,b,sumA,sumB,n,i,auxJ);
    entrometido(a,b,sumA,sumB,n,auxI,j);
  }
}
// El vector 'a' tiene 'n' elmenentos. El vector 'b' n+1
int intruso(int a[], int n, int b[]) {
   // A IMPLEMENTAR
  
}

/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el c�digo que sigue no se corregir�n (puntuar�n 0).

const int NMAX = 10000; // El vector 'a' no tendr� m�s de 10000 de elementos

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		int a[NMAX];
		int b[NMAX + 1];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i <= n; i++) {
			cin >> b[i];
		}
		cout << intruso(a, n, b) << endl;
        return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}