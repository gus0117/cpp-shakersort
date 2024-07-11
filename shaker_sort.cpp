#include <iostream>

void cambio(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

void shakeSort(int a[], int ocup) {
    int i;
    bool ordenado = false;
    int pri = 0;
    int ult = ocup - 1;

    while(ordenado == false && pri < ult) {
        ordenado = true;
        i = ult;
        
        while(i > pri) {
            if(a[i] < a[i - 1]) {
                cambio(a[i], a[i - 1]);
                ordenado = false;
            }
            i = i - 1;
        }
        pri++;
        
        if (ordenado == false) {
            ordenado = true;
            i = pri;
            while(i < ult) {
                if(a[i] > a[i + 1]) {
                    cambio(a[i], a[i + 1]);
                    ordenado = false;
                }
                i = i + 1;
            }
            ult = ult - 1;
        }
    }
}

void imprimirArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int a[5] = {1,2,3,4,5};
    int ocup = 5;
    
    shakeSort(a, ocup);
    imprimirArray(a, ocup);
    return 0;
}
