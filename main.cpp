#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int main(){
    int option;
    int n = 0;

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
        cout << "Escolha uma opcao: ";
        cin >> option;

        switch (option)
        {
        case 1:
            break;
        case 2:
            /* code */
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
            cout << "Encerrando programa...";
            break;
        
        default:
            break;
        }
    } while (option != 9);
}