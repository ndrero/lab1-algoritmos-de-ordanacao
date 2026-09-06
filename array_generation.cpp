#include <string>
#include <iostream>
using namespace std;

typedef int Indice;
typedef int ChaveTipo;

void showNumbers(int *A, int n){
    for(int i = 0; i < n; i++){
        cout << A[i] << endl;
    }
}

void generateRandomNumbers(int *Array, int n){;
    for(int i = 0; i < n; i++)
        Array[i] = rand() % 100; // % 100 para pegar apenas numeros abaixo de 100 para melhor visualização
};

void generateOrderedNumbers(int *Array, int n){
    for(int i = 0; i < n; i++)
        Array[i] = i + 1;
};

void generateInverseOrderedNumbers(int *Array, int n){
    for(int i = 0; i < n; i++)
        Array[i] = n - i;
};

void generateMixedOrder(int *Array, int n){
    for(int i = 0; i < n/2; i++)
        Array[i] = i + 1;
    for(int i = n/2; i < n; i++)
        Array[i] = rand() % 100;
};




int main(){
    srand(time(nullptr));
    int n = 10;
    int* Array = new int[n];
    
    generateMixedOrder(Array, n);
    showNumbers(Array, n);
    return 0;

}