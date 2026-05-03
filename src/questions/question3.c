#include "../../include/bst.h"
#include "../../include/question.h"
#include "../../include/utils.h"
#include "../../include/vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000
#define BUSCAS 30
#define EXISTENTES 15

void run_questao3() {
  Vector *vetor = createVector(N);

  li valor = 0;
  for (li i = 0; i < N; i++) {
    valor += genRandomNumber(1, 100);
    setElementAtVector(vetor, i, valor);
  }

  li *indices = (li *)malloc(sizeof(li) * N);
  for (li i = 0; i < N; i++)
    indices[i] = i;
  for (li i = N - 1; i > 0; i--) {
    li j = genRandomNumber(0, i);
    li tmp = indices[i];
    indices[i] = indices[j];
    indices[j] = tmp;
  }

  BST *bst = createBST();
  for (li i = 0; i < N; i++) {
    insertBST(bst, getElementAtVector(vetor, indices[i]));
  }
  free(indices);

  li alvos[BUSCAS];
  li valor_max = getElementAtVector(vetor, N - 1);

  for (int i = 0; i < EXISTENTES; i++) {
    alvos[i] = getElementAtVector(vetor, genRandomNumber(0, N - 1));
  }
  for (int i = EXISTENTES; i < BUSCAS; i++) {
    alvos[i] = valor_max + genRandomNumber(1, 1000000);
  }

  double tempos_vetor[BUSCAS];
  double tempos_bst[BUSCAS];
  struct timespec inicio, fim;

  for (int i = 0; i < BUSCAS; i++) {
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    binarySearchVector(vetor, alvos[i]);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempos_vetor[i] = (fim.tv_sec - inicio.tv_sec) +
                      (fim.tv_nsec - inicio.tv_nsec) / 1e9;

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    searchBST(bst, alvos[i]);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempos_bst[i] = (fim.tv_sec - inicio.tv_sec) +
                    (fim.tv_nsec - inicio.tv_nsec) / 1e9;
  }

  printf("\n--- Busca no Vetor (Binary Search) ---\n");
  showResults(tempos_vetor, BUSCAS, NULL);

  printf("\n--- Busca na BST ---\n");
  showResults(tempos_bst, BUSCAS, NULL);

  destroyVector(vetor);
  destroyBST(bst);
}
