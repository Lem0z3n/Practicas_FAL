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
est� acompa�ada de la especificaci�n y el dise�o sistem�tico
del mismo.
*/


/*
   vcs: vector de valores cal�ricos.
   vns: vector de valores nutricionales.
   n: N�mero de chuches.
   u: Umbral cal�rico
*/
/*
PRECONDICION DE LA FUNCION: 
  ---Escribe aqu� la precondici�n de la funci�n.
  
*/
int mejor_cajita(int vcs[], int vns[], int n, int u);
/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'

*/

/*
DISE�O DEL ALGORITMO:

Paso 1. Variables
 maxNut, nut, cal, i, vcs, vcn, n, u
Paso 2. Invariante
 maxNut >= nut && cal <= u && i < n
Paso 3. Inicializaci�n
     
  int maxNut=0, nut=0, cal= 0;

Paso 4. Condici�n del bucle, y c�digo tras el bucle.
	i<n;
  return maxNut;
Paso 5. Cuerpo del bucle

if( (cal + vcs[i]) <= u ) {
      cal += vcs[i];
      nut += vns[i];
    }
    else {
      cal = 0;
      if(nut > maxNut) maxNut = nut;
      nut = 0;
    }

Paso 6. Justificaci�n de que el algoritmo siempre termina.
 0 < n <= MAX_CHUCHES && i <= n 
Paso 7. Complejidad:
O(n)

*/
int mejor_cajita(int vcs[], int vns[], int n, int u) {
	// A IMPLEMENTAR: Devolver el mayor valor nutricionales
	// que puede conseguirse sin superar el umbral cal�rico.
	// Recuerda: vcs[n]: vector de valores cal�ricos,
	//           vns[n]: vector de valores nutricionales,
	//           u: umbral cal�rico
	//           Debe devolverse el m�ximo valor nutricional 
	//           que puede conseguirse.
  int maxNut=0, nut=0, cal= 0;
  for(int i = 0; i < n; i++){
    if( (cal + vcs[i]) <= u ) {
      cal += vcs[i];
      nut += vns[i];
    }
    else {
      cal = 0;
      nut = 0;
      i--;
    }
     if(nut > maxNut) maxNut = nut;
  }
 return maxNut;
}

/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el c�digo que sigue no se corregir�n (puntuar�n 0).

const static int MAX_CHUCHES = 1000000;

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) return false; 
	else {
		static int calorias[MAX_CHUCHES];
		static int nutricionales[MAX_CHUCHES];
		for (int i = 0; i < n; i++) {
			cin >> calorias[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> nutricionales[i];
		}
		int umbral;
		cin >> umbral;
		cout << mejor_cajita(calorias, nutricionales, n, umbral) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}