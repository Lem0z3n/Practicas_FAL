/*
N� DE GRUPO: 
NOMBRE Y APELLIDOS DE LOS ESTUDIANTES QUE
HAN REALIZADO LA PRACTICA:

EN CASO DE QUE ALGUNO DE LOS MIEMBROS DEL
GRUPO NO HAYA PARTICIPADO EN LA PRACTICA,
INDICARLO AQUI, EXPLICANDO TAMBI�N EL MOTIVO:

GUILLERMO LEMONNIER JORGE MARINAS

*/

#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habr� vectores de m�s de un mill�n de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aqu� la precondici�n de la funci�n.
  P = { n > 0}

*/
bool divertida(const int a[], int n); 

/*
POSTCONDICION DE LA FUNCION: 
 
  Q: { resul = (  (PARATODO i:0<=i<n:(SUMA j:0<=j<=i:a[j])>=0) && ( (SUMA i:0<=i<n:a[i])=0 ) ) }
   
 */

 
 
 
 bool divertida(const int a[], int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
   bool resul = true;
   int i = 0, suma = 0;
   while(resul && i < n){
     suma = suma + a[i];
      if(suma<0){
         resul = false;
      }
      i++;
   }
   if(suma != 0) resul = false;
	return resul;
} 

/* COMPLEJIDAD:
   -- Determina justificadamente el orden de complejidad en el peor caso 
   -- de este algoritmo, indicando claramente cu�l es el tama�o del problema
   
   la complejidad esta en O(n)

   
*/




/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA. NO MODIFICAR! */

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
		 if (divertida(a,n)) 
           cout << "SI" << endl;
         else  
           cout << "NO" << endl;			 
	   }
   }
   while (n != -1);
}