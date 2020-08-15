#include <iostream>
#include <ctime>

using namespace std;

/*
 * Imprimir el arreglo.
 */
void print(int arrayN[], int n) {
    cout << "[";
    for(int i = 0; i <= n; i++) {
        if(i <= n - 1) {
            cout << arrayN[i] << ", ";
        } else {
            cout << arrayN[i];
        }
    }
    cout << "]" << endl;
}

/*
 * Ordenamiento Mezcla.
 */
void mezcla(int arrayN[], int extIzq, int extDer, int length) {
    //! Criterio de paro.
    if(extIzq >= extDer) {
        return;
    }

    //! Divide y venceras.
    int medio = (extIzq + extDer) / 2;
    mezcla(arrayN, extIzq, medio, length);
    mezcla(arrayN, medio + 1, extDer, length);

    //! Intercalación.
    int i = extIzq, j = medio + 1, x, temp[length];

    for(x = extIzq; x <= extDer; x++) {
        temp[x] = arrayN[x];
    }
    x = extIzq;

    //! Mezcla.
    while(i <= medio and j <= extDer) {
        while(i <= medio and temp[i] <= temp[j]) {
            arrayN[x] = temp[i];
            i++;
            x++;
        }

        if(i <= medio) {
            while(j <= extDer and temp[j] <= temp[i]) {
                arrayN[x] = temp[j];
                j++;
                x++;
            }
        }
    }

    while(i <= medio) {
        arrayN[x] = temp[i];
        i++;
        x++;
    }

    while(j <= extDer) {
        arrayN[x] = temp[j];
        j++;
        x++;
    }
}

/*
 * Main.
 */
int main() {
    srand(time(0));
    int arrayNum[10];
    int length = (sizeof(arrayNum) / sizeof(*arrayNum));

    for(int i = 0; i < length; i++) {
        arrayNum[i] = 1 + rand() % 100;
    }

    cout << "Ordenamiento Mezcla" << endl << endl;
    cout << "-Longitud del arreglo: " << length << endl;

    cout << "-Arreglo original: ";
    print(arrayNum, length - 1);

    cout << "-Arreglo ordenado: ";
    mezcla(arrayNum, 0, length - 1, length - 1);
    print(arrayNum, length - 1);
    return 0;
}
