#ifndef SORTING_ALGORITHMS_h
#define SORTING_ALGORITHMS_h

void swap(int *a, int *b);
void swap_char(char *a, char *b);

void bubbleSort(int *vet, int n);
void insertionSort(int *vet, int n);
void merge(int *vet, int inicio, int meio, int fim);
void mergeSort(int *vet, int inicio, int fim);
void quickSort(int *vetor, int inicio, int fim);

void bubbleSort_c(char *vet, int n);
void insertionSort_c(char *vet, int n);
void merge_c(char *vet, int inicio, int meio, int fim);
void mergeSort_c(char *vet, int inicio, int fim);
void quickSort_c(char *vetor, int inicio, int fim);
void quickSortStrings(char *arr[], int inicio, int fim);

#endif

