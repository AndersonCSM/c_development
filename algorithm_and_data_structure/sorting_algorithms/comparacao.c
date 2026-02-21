#include <stdio.h>
#include <stdlib.h> // Para rand(), srand()
#include <time.h>   // Para time(), clock_t, clock(), CLOCKS_PER_SEC
#include <string.h> // Para memcpy()
#include<locale.h>


// --- Funcoes Utilitarias ---
void printArrayInfo(const char* prefix, int arr[], int size) {
    printf("%s (primeiros elementos se N > 10): ", prefix);
    int limit = size < 10 ? size : 10;
    for (int i = 0; i < limit; i++) {
        printf("%d ", arr[i]);
    }
    if (size > 10) printf("...");
    printf("\n");
}

void copia_array(int dest[], int src[], int size) {
    memcpy(dest, src, size * sizeof(int));
}

// --- Implementacao do Quicksort (Lomuto) ---
void troca_lomuto(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_lomuto(int arr[], int low, int high, int pivot_mode) {
    int pivot_idx;
    if (pivot_mode == 1) {
        pivot_idx = low;
    } else if (pivot_mode == 2) {
        pivot_idx = high;
    } else if (pivot_mode == 3) {
        pivot_idx = low + (high - low) / 2;
    } else {
        // printf("Lomuto: Estrategia de pivo '%d' invalida. Usando 3 (meio).\n", pivot_mode);
        pivot_idx = low + (high - low) / 2;
    }
    troca_lomuto(&arr[pivot_idx], &arr[high]);
    int pivot_value = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot_value) {
            i++;
            troca_lomuto(&arr[i], &arr[j]);
        }
    }
    troca_lomuto(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort_lomuto(int arr[], int low, int high, int pivot_mode) {
    if (low < high) {
        int pi = partition_lomuto(arr, low, high, pivot_mode);
        quickSort_lomuto(arr, low, pi - 1, pivot_mode);
        quickSort_lomuto(arr, pi + 1, high, pivot_mode);
    }
}

// --- Implementacao do Quicksort (Hoare) ---
void troca_hoare(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_hoare(int arr[], int first, int last_exclusive, int* i_ptr, int pivot_mode) {
    int i = first;
    int j = last_exclusive - 1;
    int pivot_val;
    if (first >= last_exclusive -1) {
        *i_ptr = first;
        return last_exclusive - 1;
    }
    int pivot_idx_choice;
    if (pivot_mode == 1) {
        pivot_idx_choice = first;
    } else if (pivot_mode == 2) {
        pivot_idx_choice = j;
    } else if (pivot_mode == 3) {
        pivot_idx_choice = first + (j - first) / 2;
    } else {
        // printf("Hoare: Estrategia de pivo '%d' invalida. Usando 3 (meio).\n", pivot_mode);
        pivot_idx_choice = first + (j - first) / 2;
    }
    pivot_val = arr[pivot_idx_choice];
    while (i <= j) {
        while (i < last_exclusive && arr[i] < pivot_val) {
            i++;
        }
        while (j >= first && arr[j] > pivot_val) {
            j--;
        }
        if (i <= j) {
            troca_hoare(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    *i_ptr = i;
    return j;
}

void quickSort_hoare(int arr[], int first, int last_exclusive, int pivot_mode) {
    if (first < last_exclusive - 1) {
        int i_after_partition;
        int j_after_partition;
        j_after_partition = partition_hoare(arr, first, last_exclusive, &i_after_partition, pivot_mode);
        quickSort_hoare(arr, first, j_after_partition + 1, pivot_mode);
        quickSort_hoare(arr, i_after_partition, last_exclusive, pivot_mode);
    }
}

// --- Funcoes para Gerar Arrays de Teste ---
void gerar_array_ordenado(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = i;
}
void gerar_array_ordenado_reverso(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = n - 1 - i;
}
void gerar_array_elementos_iguais(int arr[], int n, int valor) {
    for (int i = 0; i < n; i++) arr[i] = valor;
}
void gerar_array_aleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % (n * 2);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int N = 1000000; // Tamanho dos arrays de teste (aumentado para melhor visualiza��o do tempo)

    int* original = malloc(N * sizeof(int));
    int* copia_teste = malloc(N * sizeof(int));

    if (original == NULL || copia_teste == NULL) {
        printf("Falha ao alocar memoria.\n");
        free(original);
        free(copia_teste);
        return 1;
    }

    printf("Comparando Quicksort (Lomuto vs Hoare) com N = %d\n", N);
    printf("Usando Piv� no Meio (modo 3) como padr�o para os primeiros testes.\n");
    printf("------------------------------------------------------------------\n");

    clock_t inicio_tempo, fim_tempo;
    double tempo_decorrido;
    int pivot_mode_default = 3;

    // --- Cen�rios de Teste ---
    // 1. Array Ordenado
    gerar_array_ordenado(original, N);
    printArrayInfo("Original Ordenado", original, N);

    copia_array(copia_teste, original, N);
    inicio_tempo = clock();
    quickSort_lomuto(copia_teste, 0, N - 1, pivot_mode_default);
    fim_tempo = clock();
    tempo_decorrido = ((double)(fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
    printf("Lomuto (Ordenado, Piv� Meio): Tempo: %f segundos\n", tempo_decorrido);

    copia_array(copia_teste, original, N);
    inicio_tempo = clock();
    quickSort_hoare(copia_teste, 0, N, pivot_mode_default);
    fim_tempo = clock();
    tempo_decorrido = ((double)(fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
    printf("Hoare  (Ordenado, Piv� Meio): Tempo: %f segundos\n", tempo_decorrido);
    printf("------------------------------------------------------------------\n");

    // 2. Array Ordenado Reverso
    gerar_array_ordenado_reverso(original, N);
    printArrayInfo("Original Reverso", original, N);

    copia_array(copia_teste, original, N);
    inicio_tempo = clock();
    quickSort_lomuto(copia_teste, 0, N - 1, pivot_mode_default);
    fim_tempo = clock();
    tempo_decorrido = ((double)(fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
    printf("Lomuto (Reverso, Piv� Meio): Tempo: %f segundos\n", tempo_decorrido);

    copia_array(copia_teste, original, N);
    inicio_tempo = clock();
    quickSort_hoare(copia_teste, 0, N, pivot_mode_default);
    fim_tempo = clock();
    tempo_decorrido = ((double)(fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
    printf("Hoare  (Reverso, Piv� Meio): Tempo: %f segundos\n", tempo_decorrido);
    printf("------------------------------------------------------------------\n");

    // 3. Array Aleat�rio
    gerar_array_aleatorio(original, N);
    printArrayInfo("Original Aleatorio", original, N);

    copia_array(copia_teste, original, N);
    inicio_tempo = clock();
    quickSort_lomuto(copia_teste, 0, N - 1, pivot_mode_default);
    fim_tempo = clock();
    tempo_decorrido = ((double)(fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
    printf("Lomuto (Aleatorio, Piv� Meio): Tempo: %f segundos\n", tempo_decorrido);

    copia_array(copia_teste, original, N);
    inicio_tempo = clock();
    quickSort_hoare(copia_teste, 0, N, pivot_mode_default);
    fim_tempo = clock();
    tempo_decorrido = ((double)(fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
    printf("Hoare  (Aleatorio, Piv� Meio): Tempo: %f segundos\n", tempo_decorrido);
    printf("------------------------------------------------------------------\n");

    // 4. Array com Elementos Iguais
    gerar_array_elementos_iguais(original, N, 7);
    printArrayInfo("Original Iguais", original, N);

    copia_array(copia_teste, original, N);
    inicio_tempo = clock();
    quickSort_lomuto(copia_teste, 0, N - 1, pivot_mode_default);
    fim_tempo = clock();
    tempo_decorrido = ((double)(fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
    printf("Lomuto (Iguais, Piv� Meio): Tempo: %f segundos\n", tempo_decorrido);

    copia_array(copia_teste, original, N);
    inicio_tempo = clock();
    quickSort_hoare(copia_teste, 0, N, pivot_mode_default);
    fim_tempo = clock();
    tempo_decorrido = ((double)(fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
    printf("Hoare  (Iguais, Piv� Meio): Tempo: %f segundos\n", tempo_decorrido);
    printf("------------------------------------------------------------------\n");

    // Teste Adicional: Pior caso para piv� no in�cio (Array Ordenado)
    printf("Testando Pior Caso com Piv� no In�cio (modo 1):\n");
    gerar_array_ordenado(original, N);
    printArrayInfo("Original Ordenado", original, N);

    copia_array(copia_teste, original, N);
    inicio_tempo = clock();
    quickSort_lomuto(copia_teste, 0, N - 1, 1);
    fim_tempo = clock();
    tempo_decorrido = ((double)(fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
    printf("Lomuto (Ordenado, Piv� Inicio): Tempo: %f segundos\n", tempo_decorrido);

    copia_array(copia_teste, original, N);
    inicio_tempo = clock();
    quickSort_hoare(copia_teste, 0, N, 1);
    fim_tempo = clock();
    tempo_decorrido = ((double)(fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
    printf("Hoare  (Ordenado, Piv� Inicio): Tempo: %f segundos\n", tempo_decorrido);
    printf("------------------------------------------------------------------\n");

    free(original);
    free(copia_teste);

    return 0;
}
