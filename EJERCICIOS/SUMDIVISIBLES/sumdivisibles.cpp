
#include <iostream>

using namespace std;


/*
DISEÑO DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de diseño realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada 
-- parámetro (en caso de que utilices una generalización), los casos base, y los 
-- casos recursivos

P: {n > 0}


Q: resul = sumdivisible(int n)
sumdivisible(dk .... d0) = (dk % size == 0) && (d(k/10) % size == 0) ... && d0;  

caso base n < 10 sumdivisibleAux = true, todos los numeros son divisibles entre 1

caso recursivo:
    supongamos r' = sumdivisibleAux(r'/10, size-1) && (r' % size = 0)


ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo diseñado.
-- Escribe y resuelve las ecuaciones de recurrencia.

T(n) = co   n < 10
T(n) = cn + T(n/10)
k = 1 a = 1 b = 10
1 < 10 => O(n¹) = O(n).
*/
bool sumdivisible_aux(int& n, int& sum, int& size);

bool sumdivisible(int n){
	int sum = 0, size = 1;
	return sumdivisible_aux(n,sum,size);
}
bool sumdivisible_aux(int& n, int& sum, int& size) {
	/* IMPLEMENTACION:
	   Esta función será el punto de entrada a tu algoritmo.
	   Puedes implementar, además, las funciones auxiliares
	   que consideres oportuno.
	   -- n: El número cuya sumdivisibilidad debes determinar.
	   -- La función deberá devolver 'true' si n es sumdivisible,
	   -- y 'false' en otro caso
	*/
	if(n < 10){
		sum += n;
		return (sum % size == 0);
	}
	sum += n % 10;
	n /= 10;
	size++;
	if(sumdivisible_aux(n,sum,size))
		return (sum % size == 0);
	return false;
}   


/* CODIGO DE LECTURA Y EJECUCION DE CASOS DE PRUEBA: 
   NO MODIFICAR */

int main() {
	int n;
	do {
		cin >> n;
		if (n > 0) {
			if (sumdivisible(n)) 
				 cout << "SI" << endl;
			else 
                 cout << "NO" << endl;				
		}
	} while (n > 0);
}
	
	