#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
if(argc != 3){
  printf("porfavor ponga dinero ingresado, interes por dia. \n");
  return 0;
}
int cuenta;
float dineroInicial = atof(argv[1]), acumulado;
float interes = atof(argv[2]);
for(cuenta = 0; dineroInicial < 1000; dineroInicial += acumulado){
  acumulado = 0;
  acumulado = dineroInicial * interes;
  cuenta++;
}

printf(" con un interes diario de %f en %d dias conseguiras %f € \n", 
        interes,
        cuenta,
        dineroInicial);
return 0;
}