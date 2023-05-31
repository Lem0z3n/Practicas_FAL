
#include <iostream>
using namespace std;

/*
DISE�O DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de dise�o realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada 
-- par�metro (en caso de que utilices una generalizaci�n), los casos base, y los 
-- casos recursivos
P= { n > 0}

Q = resul = es_interesante(n)

es_interesante(n) = (sumamensig % dig = 0) && (sumaMassig % dig = 0) && (n < 10 -> es_interesante(n/10))
sumaMassig = dk + .. +d(n+1)
sumaMensig = dn-1 + ... +do

Caso base: n < 10 => resul =  true
caso recursivo n > 10 
    Sea r' = es_interesante(n/10)
    resul = r' && sumamensig % dig = 0 && sumamassig % dig = 0

Generalizacion
P : n > 0

proc es_interesante_aux(in int n, out bool res, out int sumMasSig,  out int sumMenSig)


Caso base n < 10
    res = (sumaMenSig % n) == 0
    sumMasSig = n
    sumMenSig - n
Caso recursivo: n >= 10
    supongamos es_interesante_aux(n/10, 'res, 'sumMasSig,  'sumMenSig)    
    res = res' && ((sumMasSig % (n%10) == 0) && (sumMenSig % (n%10) ==0))
    sumMasSig - n%10
    sumaMenSig + n%10

Inmersion:
    es_interesante_aux(n, res, smssig, smnsig)
    resultado = res
Terminacion n es una cota
ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo dise�ado.
-- Escribe y resuelve las ecuaciones de recurrencia.
    Tamaño de problema: n
    T(n) = co, n <= 9
    T(n) = c1 + T(n/10), n < 9
    T(n) esta en O(log n)

    Tamaño del problema: d, numero de digitos de n
    T(1) = co
    T(d) = c1 + T(d-1), n>1
    O(d) 
*/


void es_interesante_aux(int n, bool& res, int& smsig, int& smnsig){
  if(n < 10){
    res = ((smnsig % n) == 0);
    smsig = n;
  }else{
    smnsig += n%10;
    es_interesante_aux(n/10, res, smsig, smnsig);
    smnsig -= n%10;
    res = res && ((smnsig % (n%10) == 0) && ((smsig % (n%10))==0));
    smsig += n%10;
  }
}


bool es_interesante(unsigned int n) {
	// A IMPLEMENTAR
  bool resul; 
  int smsig= 0, smnsig= 0;
  es_interesante_aux(n, resul, smsig, smnsig);
  return resul;
}

void ejecuta_caso() {
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