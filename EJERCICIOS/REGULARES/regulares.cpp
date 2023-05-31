/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:
Guillermo Lemonnier y Jorge Marinas,

Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo:

 jorge marinas no vino
*/

#include<iostream>

using namespace std;



/*
(1) ESPECIFICACION:
P: 0 <= n < tam(a)

Q: resul = es_regular(a,n)

es_regular(a,n)= n < 3 || #min(a) == 1 && max(a) == a[n/2] && 
								 es_regular(a[0]...a[(n/2)-1], n/2) && es_regular(a[(n/2)+1]...a[n], n/2)


caso base: n < 3 
			return true;
case recursivo n>= 3
			if(a[n/2] == max(a)){
				return es_regular(a[0]-a[n/2 - 1], n/2) && es_regular(a[n/2 + 1] - a[n], n/2)
			}


(2) GENERALIZACION (EN CASO DE QUE PROCEDA), Y SU ESPECIFICACION
	P: 0<=i<=j<=n

	void es_regular_aux(int a[], int n, int & max, int & min, int i, int j, bool & res)

	Q: res = es_regular(a[0]-a[n/2 - 1], n/2) && es_regular(a[n/2 + 1] - a[n], n/2) && es_regular(a[])
(3) DISE�O
caso base j - i < 3:
	if(min > minimo(a, j,i)) min = minimo(a,j,i)
	else if (min == minimo(a, j, i)) res =  false
	else res = true
case recursivo j - i >= 3:
	if(max < a[i+j/2]) res = false
	else
		max = a[i+j/2]
		es_regular_aux(a, max, min, i, (i+j/2 - 1), res)
		es_regular_aux(a, max, min, (i+j/2 + 1), j, res)

(4) TERMINACI�N 

n es una cota

(5) IMPLEMENTACION POR INMERSION DEL ALGORITMO, SI PROCEDE


(6) DETERMINACION DEL COSTE DEL ALGORITMO EN EL PEOR CASO

T(n) = c1 n<3

T(n) = c1 + 2T(n/2) n >= 3

a = 2, b = 2, k = 0

a = b^k => O(log n)
*/
const int MAX_TAM = 1000000;

int minimo(int a[],int j,int i){
	int mid = a[i+1];
	if(a[i]<a[j] && a[i] < mid){
		return a[i];
	}else if(a[j] < mid){
		return a[j];
	}else return mid;
}


void es_regular_aux(int a[], int & max, int & min, int i, int j, bool & res){

if((j-i) + 1< 3){
	if((a[i] < max && a[j] < max) || max == MAX_TAM +1){
		if(a[i] < min && (a[i] < a[j] || i ==j)){ 
			min = a[i];
			res = true;
			}
		else if(a[j] < min){	
			min = a[j];
			res = true;
			}
		else if(a[i] == min || a[j] == min){
			res = false;
		}else res = true;
	}
	else res = false;
}
else{
	if(max < a[i+j/2] && max != MAX_TAM +1) res = false;
	else{
		max = a[i+j/2];
		es_regular_aux(a, max, min, i, (i+j/2 - 1), res);
		es_regular_aux(a, max, min, (i+j/2 + 1), j, res);
	}
}
}


bool es_regular(int a[], int n) {
	bool res;
	int  min =MAX_TAM +1, j=n-1, i=0, max = MAX_TAM +1 ;
	es_regular_aux(a,max,min,i,j, res);
	return res;
}


/* A PARTIR DE AQUI, NO MODIFICAR NADA, he movido MAX_TAM para poder usarlo en mi funcion */


const int REPS = 500;

bool ejecuta_caso() {
  int n;
  cin >> n;
  if (n== -1) {
    return false;
  }
  else {
    static int a[MAX_TAM];
	for (int i=0; i< n; i++) {
	  cin >> a[i];
	}
	
	if(n == MAX_TAM) {
	 for (int i=0; i < REPS; i++) {
	   es_regular(a,n);
	 }
	}
	if (es_regular(a,n)) {
	  cout << "SI" << endl;
	}
	else {
	  cout << "NO" << endl;
	}
	return true;
  }
}

int main() {
  while(ejecuta_caso());
  return 0;
}