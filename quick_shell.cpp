#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

struct Estatisticas {
    long long comparacoes;
    long long movimentacoes;
    double tempo;
};

void showNumbers(int *A, int n){
    if (n > 100) {
        cout << "== Vetor muito grande para exibir no terminal (N = " << n << ") ==" << endl;
        return;
    }
    cout << "== Conteudo do vetor ==" << endl;
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << "\n==========================" << endl;
}

void generateRandomNumbers(int *Array, int n){
    for(int i = 0; i < n; i++)
        Array[i] = rand();
}

void generateOrderedNumbers(int *Array, int n){
    for(int i = 0; i < n; i++)
        Array[i] = i + 1;
}

void generateInverseOrderedNumbers(int *Array, int n){
    for(int i = 0; i < n; i++)
        Array[i] = n - i;
}

void generateMixedOrder(int *Array, int n){
    for(int i = 0; i < n/2; i++)
        Array[i] = i + 1;
    for(int i = n/2; i < n; i++)
        Array[i] = rand();
}

int* createCopy(int *A, int n){
    int *newArray = new int[n];
    for(int i = 0; i < n; i++)
        newArray[i] = A[i];
    return newArray;
}

Estatisticas selectionSort(int *A, int n){
    long long comparacoes = 0, movimentacoes = 0;
    int Min, temp;

    auto inicio = chrono::high_resolution_clock::now();

    for(int i = 0; i < n - 1; i++){
        Min = i;
        for(int j = i + 1; j < n; j++){
            comparacoes++;
            if(A[j] < A[Min]) Min = j;
        }
        if(Min != i){
            temp = A[Min]; A[Min] = A[i]; A[i] = temp;
            movimentacoes += 3;
        }
    }

    auto fim = chrono::high_resolution_clock::now();
    Estatisticas r;
    r.comparacoes = comparacoes;
    r.movimentacoes = movimentacoes;
    r.tempo = chrono::duration<double, milli>(fim - inicio).count();
    return r;
}

Estatisticas insertionSort(int *A, int n){
    long long comparacoes = 0, movimentacoes = 0;

    auto inicio = chrono::high_resolution_clock::now();

    for(int i = 1; i < n; i++){
        int chave = A[i];
        movimentacoes++; // Atribuicao da chave
        int j = i - 1;

        while(j >= 0){
            comparacoes++;
            if(A[j] > chave){
                A[j + 1] = A[j];
                movimentacoes++;
                j--;
            } else {
                break;
            }
        }
        A[j + 1] = chave;
        movimentacoes++;
    }

    auto fim = chrono::high_resolution_clock::now();
    Estatisticas r;
    r.comparacoes = comparacoes;
    r.movimentacoes = movimentacoes;
    r.tempo = chrono::duration<double, milli>(fim - inicio).count();
    return r;
}

Estatisticas shellSort(int *A, int n){
    long long comparacoes = 0;
    long long movimentacoes = 0;

    auto inicio = chrono::high_resolution_clock::now();

    for(int gap = n / 2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
            int temp = A[i];
            movimentacoes++;
            int j = i;

            while(j >= gap){
                comparacoes++;
                if(A[j - gap] > temp){
                    A[j] = A[j - gap];
                    movimentacoes++;
                    j -= gap;
                } else {
                    break;
                }
            }
            A[j] = temp;
            movimentacoes++;
        }
    }

    auto fim = chrono::high_resolution_clock::now();

    Estatisticas resultado;
    resultado.comparacoes = comparacoes;
    resultado.movimentacoes = movimentacoes;
    resultado.tempo = chrono::duration<double, milli>(fim - inicio).count();

    return resultado;
}

void quickSortRecursivo(int *A, int inicio, int fim,
                        long long &comparacoes,
                        long long &movimentacoes){

    if(inicio >= fim) return;

    int pivo = A[fim];
    int i = inicio - 1;

    for(int j = inicio; j < fim; j++){
        comparacoes++;
        if(A[j] <= pivo){
            i++;
            if(i != j){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                movimentacoes += 3;
            }
        }
    }

    if(i + 1 != fim){
        int temp = A[i + 1];
        A[i + 1] = A[fim];
        A[fim] = temp;
        movimentacoes += 3;
    }

    int posicaoPivo = i + 1;

    quickSortRecursivo(A, inicio, posicaoPivo - 1, comparacoes, movimentacoes);
    quickSortRecursivo(A, posicaoPivo + 1, fim, comparacoes, movimentacoes);
}

Estatisticas quickSort(int *A, int n){
    long long comparacoes = 0;
    long long movimentacoes = 0;

    auto inicio = chrono::high_resolution_clock::now();

    if(n > 1){
        quickSortRecursivo(A, 0, n - 1, comparacoes, movimentacoes);
    }

    auto fim = chrono::high_resolution_clock::now();

    Estatisticas resultado;
    resultado.comparacoes = comparacoes;
    resultado.movimentacoes = movimentacoes;
    resultado.tempo = chrono::duration<double, milli>(fim - inicio).count();

    return resultado;
}

void heapify(int *A, int n, int i, long long &comparacoes, long long &movimentacoes) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n) {
        comparacoes++;
        if (A[esquerda] > A[maior]) maior = esquerda;
    }

    if (direita < n) {
        comparacoes++;
        if (A[direita] > A[maior]) maior = direita;
    }

    if (maior != i) {
        int temp = A[i];
        A[i] = A[maior];
        A[maior] = temp;
        movimentacoes += 3;

        heapify(A, n, maior, comparacoes, movimentacoes);
    }
}

Estatisticas heapSort(int *A, int n){
    long long comparacoes = 0, movimentacoes = 0;

    auto inicio = chrono::high_resolution_clock::now();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i, comparacoes, movimentacoes);

    for (int i = n - 1; i > 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        movimentacoes += 3;

        heapify(A, i, 0, comparacoes, movimentacoes);
    }

    auto fim = chrono::high_resolution_clock::now();
    Estatisticas r;
    r.comparacoes = comparacoes;
    r.movimentacoes = movimentacoes;
    r.tempo = chrono::duration<double, milli>(fim - inicio).count();
    return r;
}

void exibirEstatisticas(const string& nome, const Estatisticas& r){
    cout << left << setw(18) << nome
         << setw(16) << r.comparacoes
         << setw(18) << r.movimentacoes
         << fixed << setprecision(4) << r.tempo << " ms" << endl;
}

void compararTodos(int *mainArray, int n){
    if(mainArray == nullptr){
        cout << "Nenhum vetor definido" << endl;
        return;
    }

    cout << "\n=== COMPARACAO DE TODOS OS ALGORITMOS ===" << endl;
    cout << "Tamanho do vetor: " << n << endl;
    cout << left << setw(18) << "Algoritmo" << setw(16) << "Comparacoes"
         << setw(18) << "Movimentacoes" << "Tempo" << endl;
    cout << "---------------------------------------------------------------" << endl;

    int* copia = createCopy(mainArray, n);
    Estatisticas selection = selectionSort(copia, n); delete[] copia;

    copia = createCopy(mainArray, n);
    Estatisticas insertion = insertionSort(copia, n); delete[] copia;

    copia = createCopy(mainArray, n);
    Estatisticas shell = shellSort(copia, n); delete[] copia;

    copia = createCopy(mainArray, n);
    Estatisticas quick = quickSort(copia, n); delete[] copia;

    copia = createCopy(mainArray, n);
    Estatisticas heap = heapSort(copia, n); delete[] copia;

    exibirEstatisticas("Selection Sort", selection);
    exibirEstatisticas("Insertion Sort", insertion);
    exibirEstatisticas("Shell Sort", shell);
    exibirEstatisticas("Quick Sort", quick);
    exibirEstatisticas("Heap Sort", heap);
}

int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
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
        cout << "Escolha uma opcao: ";
        cin >> option;

        switch (option)
        {
        case 1:
            if (mainArray != nullptr) {
                delete[] mainArray;
                mainArray = nullptr;
            }
            cout << "Informe o tamanho do array: ";
            cin >> n;
            mainArray = new int[n];

            cout << "Informe o tipo de geracao de dados: " << endl;
            cout << "[1] Dados aleatorios" << endl;
            cout << "[2] Dados previamente ordenados" << endl;
            cout << "[3] Dados em ordem inversa" << endl;
            cout << "[4] Dados parcialmente ordenados" << endl;
            cin >> dataGenerationType;
            switch (dataGenerationType)
            {
            case 1: generateRandomNumbers(mainArray, n); break;
            case 2: generateOrderedNumbers(mainArray, n); break;
            case 3: generateInverseOrderedNumbers(mainArray, n); break;
            case 4: generateMixedOrder(mainArray, n); break;
            default: break;
            }
            break;
        case 2:
            if (mainArray == nullptr) {
                cout << "Nenhum vetor definido" << endl;
                break;
            } 
            showNumbers(mainArray, n);
            break;
        case 3: {
            if (mainArray == nullptr) { cout << "Nenhum vetor definido" << endl; break; }
            int* arrayCopy = createCopy(mainArray, n);
            Estatisticas resultado = selectionSort(arrayCopy, n);
            cout << "=== Ordenacao por Selecao ===" << endl;
            exibirEstatisticas("Selection Sort", resultado);
            showNumbers(arrayCopy, n);
            delete[] arrayCopy;
            break;
        }
        case 4: {
            if (mainArray == nullptr) { cout << "Nenhum vetor definido" << endl; break; }
            int* arrayCopy = createCopy(mainArray, n);
            Estatisticas resultado = insertionSort(arrayCopy, n);
            cout << "=== Ordenacao por Insercao ===" << endl;
            exibirEstatisticas("Insertion Sort", resultado);
            showNumbers(arrayCopy, n);
            delete[] arrayCopy;
            break;
        }
        case 5: {
            if (mainArray == nullptr) { cout << "Nenhum vetor definido" << endl; break; }
            int* arrayCopy = createCopy(mainArray, n);
            Estatisticas resultado = shellSort(arrayCopy, n);
            cout << "=== Ordenacao por Shell ===" << endl;
            exibirEstatisticas("Shell Sort", resultado);
            showNumbers(arrayCopy, n);
            delete[] arrayCopy;
            break;
        }
        case 6: {
            if (mainArray == nullptr) { cout << "Nenhum vetor definido" << endl; break; }
            int* arrayCopy = createCopy(mainArray, n);
            Estatisticas resultado = quickSort(arrayCopy, n);
            cout << "=== Ordenacao por Quick ===" << endl;
            exibirEstatisticas("Quick Sort", resultado);
            showNumbers(arrayCopy, n);
            delete[] arrayCopy;
            break;
        }
        case 7: {
            if (mainArray == nullptr) { cout << "Nenhum vetor definido" << endl; break; }
            int* arrayCopy = createCopy(mainArray, n);
            Estatisticas resultado = heapSort(arrayCopy, n);
            cout << "=== Ordenacao por Heap ===" << endl;
            exibirEstatisticas("Heap Sort", resultado);
            showNumbers(arrayCopy, n);
            delete[] arrayCopy;
            break;
        }
        case 8:
            compararTodos(mainArray, n);
            break;
        case 9:
            cout << "Encerrando programa..." << endl;
            break;
        default:
            break;
        }
    } while (option != 9);

    if (mainArray != nullptr) {
        delete[] mainArray;
    }
    return 0;
}