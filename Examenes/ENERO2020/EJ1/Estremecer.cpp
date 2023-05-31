
#include <iostream>

using namespace std;

const int TMAX = 1000;


bool escaleraAsc(int a[], int maxIndex, int& salida){
int anch=1, prev = a[0];
bool esEscalera = true;
salida = anch;
for(int i = 1; i < maxIndex; i++){
  if(a[i] < prev)esEscalera = false;
  if(a[i] == prev) anch++;
  else anch = 1;
  if(anch > salida)salida = anch;
  prev = a[i];
}
return esEscalera;
}

bool escaleraDesc(int a[], int n, int maxIndex, int& salida){
int anch=1, prev = a[maxIndex];
bool esEscalera = true;
salida = anch;
for(int i = maxIndex+1; i < n; i++){
  if(a[i] > prev)esEscalera = false;
  if(a[i] == prev) anch++;
  else anch = 1;
  if(anch > salida)salida = anch;
  prev = a[i];
}
return esEscalera;
}

bool escalera(int a[], int n, int& salida1, int& salida2 ){
  bool out = false;
  int max = a[0], maxIndex = 0;
  for(int i = 1; i < n; i++){
    if(max < a[i]){
      maxIndex = i;
      max = a[i];
    }
  }
  if(maxIndex == n-1)maxIndex = n;
  if(escaleraAsc(a, maxIndex, salida1)){
    if(escaleraDesc(a,n, maxIndex,salida2)){ 
    out = true;
    }}
  if(out && salida1 < salida2){
    int aux = salida1;
    salida1 = salida2;
    salida2 = aux;
  }
  return out;
}


void lee_vector(int a[], int & n) {
        cin >> n;
   for (int i=0; i < n; i++) {
           cin >> a[i];
   }
}

int main() {
   static int a[TMAX];
   int n;
   int sal1=0, sal2=0;
   do {
           lee_vector(a,n);
           if (n>=0) {
                 if (escalera(a,n,sal1,sal2))
           cout << "SI "<< sal1 << endl;
         else
           cout << "NO " << sal1 <<" "<<  sal2 <<  endl;
           }
   }
   while (n != -1);
}
