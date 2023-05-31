/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:
Guillermo Lemonnier	

Si alguno de los miembros del grupo no ha realizado
la práctica, indicarlo aquí, junto con el motivo:


*/

#include <iostream>

using namespace std;


/*
(1) ESPECIFICACION
P ={ n > 2}
fun min_capacidad(int etapas[], int n, int reportajes_permitidos) return ( int  resul)
Q = {busqueda(etapas,n,sup,inf,repostajes_permitidos)}

(2) GENERALIZACION (EN CASO DE QUE PROCEDA), Y SU ESPECIFICACION

P= {sup > inf && min_capacidad(int etapas[], int n, int repostajes_permitidos)}
fun busqueda(in int etapas[], in int n,in int sup,in int inf,in int repostajes_permitidos)
Q = {min_capacidad(int etapas[], int n, int reportajes_permitidos)} 

(3) DISEÑO (CASOS)
Caso base  factible(m) && !factible(m+1)
	return m
Caso recusivo 
			if(factible(m)) busqueda(m-1)
			else busqueda(m+1)

(4) TERMINACIÓN


(5) IMPLEMENTACION POR INMERSION DEL ALGORITMO, SI PROCEDE
int busqueda( int etapas[], int n, int sup, int inf, int repostajes_permitidos){
	int m = (inf + sup) / 2;
	if(factible(etapas, n, m, repostajes_permitidos)){
		if(!factible(etapas, n, m -1, repostajes_permitidos)){
			return m;
		}else{
			return busqueda(etapas,n, inf, m-1, repostajes_permitidos);
		}
	}
	else {
		return busqueda(etapas,n, m+1, sup, repostajes_permitidos);
	}
}

(6) DETERMINACION DEL COSTE DEL ALGORITMO EN EL PEOR CASO
T(0) = C0

T(N) = w(n)+ 2T(N/2), w(n)=> O(n)

T(n) => O(nlogn)
*/


bool factible(int etapas[],int n, int capacidad , int repostajes_permitidos){

int i = 0;
int suma = 0;

while(i < n){
	if(repostajes_permitidos == -1){
		return false;
	} if (suma + etapas[i] <= capacidad){
		suma = suma + etapas[i];
	}
	else {
		repostajes_permitidos--;
		suma = 0;
		i--;
	}
	i++;
}
return true;
}

void acotar(int etapas[], int n, int repostajes_permitidos, int& inf, int& sup){
	while(!factible(etapas, n, sup, repostajes_permitidos)){
		inf = sup;
		sup *= 2;
	}
}

int busqueda( int etapas[], int n, int sup, int inf, int repostajes_permitidos){
	int m = (inf + sup) / 2;
	if(factible(etapas, n, m, repostajes_permitidos)){
		if(!factible(etapas, n, m -1, repostajes_permitidos)){
			return m;
		}else{
			return busqueda(etapas,n, inf, m-1, repostajes_permitidos);
		}
	}
	else {
		return busqueda(etapas,n, m+1, sup, repostajes_permitidos);
	}
}


int min_capacidad(int etapas[], int n, int repostajes_permitidos) {
	 // A IMPLEMENTAR
	int sup = 2, inf = 0;
	acotar(etapas, n, repostajes_permitidos, inf, sup);
	 return busqueda(etapas,n, sup, inf, repostajes_permitidos);
}


const int MAX_ETAPAS = 100000;


bool ejecuta_caso() {
	static int v[MAX_ETAPAS];
	int n, c;
	cin >> n;
	if (n == -1) return false;
	else {
		cin >> c;
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		cout << min_capacidad(v, n, c) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}

