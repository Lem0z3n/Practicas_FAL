#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habr� vectores de m�s de un mill�n de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aqu� la precondici�n de la funci�n.
  
   P = {0 <= i < i: a[i] < a[i+1]}

*/

 
int misterio(const int a[], int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
   int prev = a[0], resul = a[0], reps = 1, maxReps=1;
   bool found;
   for(int i=1; i<n; i++){
      if(a[i] == prev){
         reps++;
      }else{
         reps = 1;
         prev = a[i];
      }
      if(reps > maxReps){
         resul = a[i];
         maxReps = reps;
      }
   }
   return resul;
} 

/* COMPLEJIDAD:
   -- Determina justificadamente el orden de complejidad en el peor caso 
   -- de este algoritmo, indicando claramente cu�l es el tama�o del problema

   la complejidad de este algoritmo es n
*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA. NO MODIFICAR */

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
		   cout << misterio(a, n) << endl;
	   }
   }
   while (n != -1);
}