#include <iostream>
#include <string>
#include <chrono>

using namespace std;

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
    int option;
    int n = 0;
    int dataGenerationType;
    int* mainArray = nullptr;

    do {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "[1] Gerar um conjunto de dados" << endl;
        cout << "[2] Exibir os dados gerados" << endl;
        cout << "[3] Ordenar utilizando Selection Sort" << endl;
        cout << "[4] Ordenar utilizando Insertion Sort" << endl;
        cout << "[5] Ordenar utilizando Shell Sort" << endl;
        cout << "[6] Ordenar utilizando Quick Sort" << endl;
        cout << "[7] Ordenar utilizando Heap Sort" << endl;
        cout << "[8] Executar e comparar todos os algoritmos" << endl;
        cout << "[9] Sair" << endl;
        cout << "Escolha uma opcao: " << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Informe o tamanho do array: ";
            cin >> n;
            mainArray = new int[n];

            cout << "Informe o tipo de geração de dados: " << endl;
            cout << "[1] Dados aleatórios" << endl ;
            cout << "[2] Dados previamente ordenados" << endl ;
            cout << "[3] Dados em ordem inversa" << endl ;
            cout << "[4] Dados parcialmente ordenados" << endl ;
            cin >> dataGenerationType;
            switch (dataGenerationType)
            {
            case 1:
                generateRandomNumbers(mainArray, n);
                break;
            case 2:
                generateOrderedNumbers(mainArray, n);
                break;
            case 3:
                generateInverseOrderedNumbers(mainArray, n);
                break;
            case 4:
                generateMixedOrder(mainArray, n);
                break;
            
            default:
                break;
            }
            break;
        case 2:
            if (mainArray == nullptr) {
                cout << "Nenhum vetor definido" << endl;
                break;
            } 
            cout << "== Conteúdo do vetor ==" << endl;
            showNumbers(mainArray, n);
            cout << "==========================" << endl;
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        case 8:
            /* code */
            break;
        case 9:
            cout << "Encerrando programa..." << endl;
            break;
        
        default:
            break;
        }
    } while (option != 9);
}