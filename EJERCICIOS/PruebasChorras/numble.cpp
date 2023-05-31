#include <iostream>
#include <cmath>

using namespace std;

string resultado;
const int TMAX = 6;

int operacion(int a, int b, int op){
  int operacion=0;
  switch(op){
    case(0):
      resultado = resultado + to_string(a) + " + " + to_string(b);
      operacion = a+b;
      break;
    case(1):
      resultado = resultado + to_string(a) + " - " + to_string(b);
      operacion =  a-b;
      break;
    case(2):
      resultado = resultado + to_string(b) + " + " + to_string(a);
      operacion = b-a;
      break;
    case(3):
      resultado = resultado + to_string(a) + " * " + to_string(b);
      operacion = a*b;
      break;
    case(4):
      resultado = resultado + to_string(b) + " / " + to_string(a);
      try{
        operacion = b/a;
      } catch(exception e) {
        throw exception_ptr();
      }
      break;
    case(5):
      resultado = resultado + to_string(a) + " / " + to_string(b);
      try{
        operacion = a/b;
      } catch(exception e){
        throw exception_ptr();
      }
      break;
  }
  return operacion;
}


void resultar(int a[], int n){
  int tempRes = 0;
  int usados[TMAX];
  int trabaja[TMAX];
  for(int i = 0; i<TMAX; i++){
    usados[i] = a[i];
    trabaja[i] = a[i];
  }
  int counter = 0;
  int vueltas= 0;
  while(tempRes != n){
    resultado = "";
    if(tempRes != 0) tempRes = 0;
    tempRes = tempRes + a[counter];
    a[counter] = 0;
    trabaja[counter] = tempRes;
    bool cont = true;
    while(cont){     
      int op = rand() % 6; 
      int rNum = rand() % 6;
      int orNum = rand() % 6;
      if(a[rNum] != 0 && (a[orNum] != 0 || orNum == counter)){
        try{
          tempRes = operacion(trabaja[orNum],trabaja[rNum],op);
        } catch(exception& e){
          for(int i = 0; i < 6; i++){
            a[i] = 0;
          }
        }
        resultado = resultado + " ";
        a[rNum] = 0;
        a[orNum] = 0;
        cont = false;
        for(int i = 0; i < TMAX; i++){
          if(a[i] != 0) cont = true;
        }
      }
    }
    vueltas++;
    counter = vueltas % 6;
    cout << vueltas << " " << tempRes << endl;
    a = usados;
  }
  if(tempRes == n)cout << resultado << endl;
}


void getInputs(){
  int a[TMAX];
  int res;
  string aux;
  cout << "Introduzca el resultado deseado.\n";
  getline(cin, aux);
  res = stoi(aux);
  for(int i = 0; i < 6; i++){
    cout << "Introduzca el operando " << i+1 << endl;
    cin >> a[i];
  }
  resultar(a,res);
}

int main(){
 getInputs();
}