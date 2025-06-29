#ifndef SORT_H
#define SORT_H

void bubbleSort(int *vetor, int tamanho);

void merge(int * vetor, int left, int h, int right);

void gnomeSort(int *vetor, int tamanho);

void insertionSort(int *vetor, int tamanho);

void quickSort(int * vetor, int left, int right);

void mergeSort(int * vetor, int left, int right);

void bubbleSortChar(char **vetor, int tamanho);

void mergeChar(char **vetor, int left, int h, int right);

void insertionSortChar(char **vetor, int tamanho);

void quickSortChar(char **vetor, int left, int right);

void mergeSortChar(char **vetor, int left, int right);

#endif