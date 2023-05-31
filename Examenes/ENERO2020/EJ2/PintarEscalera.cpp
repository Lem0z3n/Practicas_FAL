#include <iostream>
using namespace std;

const int MAX_ESCALONES = 10;
const int MAX_COLORES = 5;

typedef struct{
int cantidad;
int precio
}tPintura;
typedef struct{
int nEscalones, nColores;
int tamEscalones [MAX_ESCALONES];
tPintura pinturas[MAX_COLORES];
}tEntrada;



void ejecuta_caso() {
        tEntrada entrada;
        cin >> entrada.num_pacientes >> entrada.num_hospitales;
        for (int h = 0; h < entrada.num_hospitales; h++) {
                cin >> entrada.capacidad[h];
    }
        for (int p = 0; p < entrada.num_pacientes; p++) {
                for (int h = 0; h < entrada.num_hospitales; h++) {
                        cin >> entrada.distancia[p][h];
                }
        }
        cout <<min_distancias(entrada) << endl;
}

int main() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
                ejecuta_caso();
        }
}