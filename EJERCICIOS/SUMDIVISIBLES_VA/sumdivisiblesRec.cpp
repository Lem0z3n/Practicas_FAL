#include <iostream>

using namespace std;

bool sumdivisible_aux( unsigned long long n, int& sum, int& size);

bool es_sumdivisible( unsigned long long n){
	int sum = 0, size = 1;
	return sumdivisible_aux(n,sum,size);
}
bool sumdivisible_aux( unsigned long long n, int& sum, int& size) {
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



void sumdivMochila(unsigned long long & n, int k, int i, long& count, bool hay_mejor){
  if(k == 0) {
    count++;
    hay_mejor = true;
  }
  else{
    for(int a = 0; a < 10; a++){
    unsigned long long  sumParc =n*10+a;
    if (es_sumdivisible(sumParc)) sumdivMochila(sumParc,k-1,0,count,hay_mejor);
    }
  }
}

long sumdivisibles(int n, int k){
  long count=0;
  unsigned long long longN = n;
  sumdivMochila(longN,k-1, 1 ,count, false);
  return count;
}



int main() {
	int n,k;
	do {
		cin >> n;
		if (n > 0) {
      cin >> k;
			printf("%d \n", sumdivisibles(n,k));				
		}
	} while (n > 0);
}