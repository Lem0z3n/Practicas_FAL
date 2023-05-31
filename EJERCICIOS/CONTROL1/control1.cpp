#include <iostream>
#include <cmath>

using namespace std;

//GUILLERMO LEMONNIER Y JORGE MARINAS

int diametro(int a[], int n){
  int diam = 0, max = a[0], min = a[0];
  for(int i = 1; i < n; i++){
    if(a[i] < min)min = a[i];
    if(a[i] > max)max = a[i];
  }
  diam = abs(max - min);
  return diam;
}

const int TMAX = 1000000;


bool ejecuta_caso(){
  static  int a[TMAX];
  int n;
  cin >> n;

  if( n == -1 || n > TMAX)
   return false;
  else {
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    cout << diametro(a, n) << endl;
    return true;
  }
}

int main(){
  while(ejecuta_caso());
}