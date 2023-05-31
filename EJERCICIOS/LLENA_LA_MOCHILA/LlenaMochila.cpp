#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habr� vectores de m�s de dos millones de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aqu� la precondici�n de la funci�n.
      P = k > 0 && n > 0  para todo i: 0 < i <= n: a[i] > 0
*/

int llena_mochila(const int a[], int n, int k); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
     
    Q = resul = #i : 0 < i < n : (Sum(a[i]) < k) falta especificar que a[i] debe ser seguido.

 */
 

/*
DISE�O DEL ALGORITMO:

Paso 1. Variables
cuenta, pesoAct, maxCuenta, i, j

Paso 2. Invariante
pesoAct < K && i <n && j < i && maxCuenta < cuenta 

Paso 3. Inicializaci�n
cuenta = 0, pesoAct = 0, maxCuenta = 0, j = 0


Paso 4. Condici�n del bucle, y c�digo tras el bucle.
i < n;
while((pesoAct = (pesoAct + a[i])) <= k && i<n)

	
Paso 5. Cuerpo del bucle

 j = i;
    while((pesoAct = (pesoAct + a[i])) <= k && i<n){
      i++;
      cuenta++;
    }
    if(maxCuenta < cuenta) maxCuenta = cuenta;
    i = j+1;
    cuenta = 1;
    pesoAct = a[i];


Paso 6. Justificaci�n de que el algoritmo siempre termina.
 
 si n pertenece a R entonces en algún momento i = n;
 
Paso 7. Complejidad:

Omega(n²).
 
*/

int llena_mochila(const int a[], int n, int k) {
	  // A IMPLEMENTAR!!
    int cuenta=0, pesoAct = 0, maxCuenta= 0, j = 0;
  for(int i = 0; i < n;i++){
    j = i;
    while((pesoAct = (pesoAct + a[i])) <= k && i<n){
      i++;
      cuenta++;
    }  //numeros de objetos analizados, suma de los pesos, peso maximo, posicion en el vector
    if(maxCuenta < cuenta) maxCuenta = cuenta;
    i = j+1;
    cuenta = 1;
    pesoAct = a[i];
  }
  //if(maxCuenta < cuenta) maxCuenta = cuenta;
  return maxCuenta;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int & n) {
	cin >> n; 
   for (int i=0; i < n; i++) {
	   cin >> a[i]; 
   }   
}

int main() {
	static int a[TMAX];
	int n;
    do {
	   lee_vector(a,n);	   
	   if (n>=0) {
		   int k;
		   cin >> k;
		   cout << llena_mochila(a, n, k) << endl;
	   }
   }
   while (n != -1);
}