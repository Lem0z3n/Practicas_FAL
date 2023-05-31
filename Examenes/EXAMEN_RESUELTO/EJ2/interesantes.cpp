
#include <iostream>
using namespace std;

/*
DISE�O DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de dise�o realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada 
-- par�metro (en caso de que utilices una generalizaci�n), los casos base, y los 
-- casos recursivos

En mi algoritmo utilizo una inmersión llamada interes que acepta un parametro de entrada, n y dos 
de entrada/salida sumMenor y sumMayor. el parámetro n es el número de entrada y los valores sum 
llevan el contenido de la suma de los digitos. también utilizo una variable interna res que simboliza
el resultado de si es interesante.

caso base n < 10
  (sumMenor % n == 0)? res = true : res =false;
    sumMayor += n;
    return res;
caso recursivo 
 int div = n % 10;
  n = n / 10;
  if(sumMenor % div != 0) return false;
  sumMenor += div;
  if(!interes(n,sumMenor,sumMayor)) return false;
  if(sumMayor % div != 0) return false;
  sumMayor += div;
  return true;

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo dise�ado.
-- Escribe y resuelve las ecuaciones de recurrencia.

  T(0) = c
  T(n) =  T(n/10) + w(n) W(n) e O(1)

  a = 1 b = 10 k = 0 a = b^k
  O(logn)


*/

bool interes(unsigned int n, unsigned int& sumMenor, unsigned int& sumMayor){
  bool res;
  if(n < 10){
    (sumMenor % n == 0)? res = true : res =false;
    sumMayor += n;
    return res;
  }
  int div = n % 10;
  if(div == 0) return false;
  n = n / 10;
  if(sumMenor % div != 0) return false;
  sumMenor += div;
  if(!interes(n,sumMenor,sumMayor)) return false;
  if(sumMayor % div != 0) return false;
  sumMayor += div;
  return true;
}

bool es_interesante(unsigned int n) {
	// A IMPLEMENTAR
  unsigned int sum1 = 0, sum2= 0;
  return interes(n,sum1, sum2);
	
}



void ejecuta_caso(){
  unsigned int n;
  cin >> n;
if (es_interesante(n)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; i++) {
		ejecuta_caso();
    }
}