/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:

Guillermo Lemonnier

Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo:


*/

#include<iostream>

using namespace std;


/* Representacion de los personajes */
typedef enum {PRINCESA,CABALLERO,DRAGON} tPersonaje;

/*
(1) ESPECIFICACION:
P= n >= 0 && paraTodo n > i >= 0: 0 <= a[i] <= 2;
fun es_divertida(tPersonaje a, int n) return (bool resul)

q = (diversion(inicio, medio, fin, personajes, protagonista, nCaballeros, nDragones, ePrincesa))
  
(2) GENERALIZACION (EN CASO DE QUE PROCEDA), Y SU ESPECIFICACION

P= n >= 0 && paraTodo n > i >= 0: 0 <= a[i] <= 2;
fun diversion(ininicio,in medio,in fin,in personajes,in protagonista,inout nCaballeros,inout nDragones,inout ePrincesa)
q = comprueba(protagonista,nCaballeros,nDragones,ePrincesa)

(3) DISE�O
caso base fin - inicio <= 1
	cuentaPersonajes(personajes[inicio],nDragones,nCaballeros, ePrincesa)
	if(fin != inicio)
		cuentaPersonajes(personajes[fin],nDragones,nCaballeros, ePrincesa)
		return true
caso recursivo
	int mitad = (posProta) / 2;
	if(!diversion(inicio, mitad, posProta, personajes, nuevProta, nDragones, nCaballeros, ePrincesa))
		return false;
	dragones = nDragones; //me guardo los dragones de la mitad inferior.
	princesa = ePrincesa;
	caballeros = nCaballeros; //importante para las llamadas recursivas siguientes.
	ePrincesa = false;
	nDragones = 0;
	nCaballeros = 0;
	posProta += 2; // lo devuelvo a la posicion inicial para calcular la mitad
	mitad = (fin + posProta) / 2;
	nuevProta = personajes[mitad];
	if(!diversion(posProta, mitad, fin, personajes, nuevProta, nDragones, nCaballeros, ePrincesa))
		return false;
	caballerosFin = nCaballeros;
	nCaballeros = nCaballeros + caballeros;
	nDragones = nDragones + dragones;
	princesa = princesa || ePrincesa;
	return comprueba(protagonista, dragones, caballerosFin, princesa);

(4) TERMINACI�N: 

(5) IMPLEMENTACION POR INMERSION DEL ALGORITMO, SI PROCEDE:

(6) DETERMINACION DEL COSTE DEL ALGORITMO EN EL PEOR CASO:
T(0) = C0
T(n) = 2T(n/2) + w(n), w(n) => O(1)

O(n^log2 2) = O(n)

*/
void cuentaPersonajes(tPersonaje personaje, int& nDragones, int& nCaballeros, bool& ePrincesa){
	switch (personaje)
		{
		case PRINCESA:
		 	ePrincesa = true;
			break;
		
		case CABALLERO:
			nCaballeros++;
			break;
		case DRAGON:
			nDragones++;
			break;
		}
}

bool comprueba(tPersonaje protagonista, int& nDragones, int& nCaballeros, bool ePrincesa){
	bool res = false;
	switch (protagonista){
	case PRINCESA:
		if(nDragones == nCaballeros) 
			res = true;
		if(nDragones < nCaballeros && !ePrincesa)
			res = true;
	break;
	case CABALLERO:
		if(nDragones > nCaballeros)
			res = true;
	break;
	case DRAGON:
		if(nDragones < nCaballeros && ePrincesa)
			res = true;
	break;
	}
	return res;
}

bool diversion(int inicio, int posProta, int fin, tPersonaje personajes[], tPersonaje protagonista, int& nDragones, int& nCaballeros, bool& ePrincesa){
if(fin - inicio < 1){
	cuentaPersonajes(personajes[inicio], nDragones, nCaballeros, ePrincesa);
	return true;
	}
if(fin - inicio == 1){
	if(protagonista != PRINCESA)
		return false;
	cuentaPersonajes(personajes[inicio], nDragones, nCaballeros, ePrincesa);
	cuentaPersonajes(personajes[fin], nDragones, nCaballeros, ePrincesa);
	return true;
}
bool princesa;
int dragones, caballeros, caballerosFin;
posProta--; //lo pongo en la posicion anterior
int mitad = (posProta + inicio) / 2;
tPersonaje nuevProta = personajes[mitad];
if(!diversion(inicio, mitad, posProta, personajes, nuevProta, nDragones, nCaballeros, ePrincesa))
	return false;
if(mitad != inicio && mitad != posProta && inicio != posProta)
 cuentaPersonajes(nuevProta, nDragones, nCaballeros, ePrincesa);
dragones = nDragones; //me guardo los dragones de la mitad inferior.
princesa = ePrincesa;
caballeros = nCaballeros; //importante para las llamadas recursivas siguientes.
ePrincesa = false;
nDragones = 0;
nCaballeros = 0;
posProta += 2; // lo devuelvo a la posicion inicial para calcular la mitad
mitad = (fin + posProta) / 2;
nuevProta = personajes[mitad];
if(!diversion(posProta, mitad, fin, personajes, nuevProta, nDragones, nCaballeros, ePrincesa))
	return false;
if(mitad != fin && mitad != posProta)
	cuentaPersonajes(nuevProta, nDragones, nCaballeros, ePrincesa); //hay que contar los protas recursivos
caballerosFin = nCaballeros;
nCaballeros = nCaballeros + caballeros;
nDragones = nDragones + dragones;
princesa = princesa || ePrincesa;
return comprueba(protagonista, dragones, caballerosFin, princesa);
}


bool es_divertida(tPersonaje personajes[], int n) {
	if(n < 2) return true;
	int dragones = 0, caballeros = 0;
	bool princesa = false;
	int i = 0, j = n-1, mitad = (j-i)/2;

	tPersonaje protagonista = personajes[mitad];
	return diversion(i, mitad,j,personajes,protagonista,dragones,caballeros,princesa);
}

// NO MODIFICAR NADA A PARTIR DE AQUI

const int MAX_TAM = 1000000;
const int REPS = 500;

bool ejecuta_caso() {
  int n;
  cin >> n;
  if (n== -1) {
    return false;
  }
  else {
    static tPersonaje personajes[MAX_TAM];
	for (int i = 0; i < n; i++) {
		int p;
	    cin >> p;
		personajes[i] = tPersonaje(p);
     }
	
	if(n == MAX_TAM) {
	 for (int i=0; i < REPS; i++) {
	   es_divertida(personajes,n);
	 }
	}
	if (es_divertida(personajes,n)) {
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

