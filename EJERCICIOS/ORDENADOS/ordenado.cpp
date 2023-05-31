#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



bool esta_ordenado(int a[], int n) {
	bool ord = true;
	int i = 0;
	while(ord && i < n-1){
		if(a[i] > a[i+1]){
			ord = false;
		}
		i++;
	}
	return ord;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA - NO MODIFICAR */

const int TMAX = 1000000;  // No se podr�n leer vectores de m�s de un mill�n de elementos

bool ejecuta_caso() {
	static int a[TMAX];
	int n;
	cin >> n;
	if (n == -1 || n > TMAX) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (esta_ordenado(a, n)) cout << "SI" << endl;
		else cout << "NO" << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}