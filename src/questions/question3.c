#include "../../include/bst.h"
#include "../../include/question.h"
#include "../../include/utils.h"
#include "../../include/vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000
#define EXECUCOES 15

void run_questao3() {
  li range = N * 100L;

  clock_t inicio, fim;
  double tempo_gasto;
  double *temposVetor = (double *)malloc(sizeof(double) * EXECUCOES * 2);
  double *temposBST = (double *)malloc(sizeof(double) * EXECUCOES * 2);

  Vector *vetor = createVector(N);
  li valor = 0;
  li max_incremento = (range / N) * 2;
  if (max_incremento < 2)
    max_incremento = 2;

  for (li i = 0; i < N; i++) {
    valor += genRandomNumber(1, max_incremento);
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

  for (li i = 0; i < EXECUCOES; i++) {
    li posicao = genRandomNumber(0, N - 1);
    li elemento = getElementAtVector(vetor, posicao);

    inicio = clock();
    binarySearchVector(vetor, elemento);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    temposVetor[i] = tempo_gasto;

    inicio = clock();
    searchBST(bst, elemento);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    temposBST[i] = tempo_gasto;
  }

  li valor_max = getElementAtVector(vetor, N - 1);
  for (li i = 0; i < EXECUCOES; i++) {
    li elemento = genRandomNumber(0, valor_max + (range / 10));

    inicio = clock();
    binarySearchVector(vetor, elemento);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    temposVetor[i + EXECUCOES] = tempo_gasto;

    inicio = clock();
    searchBST(bst, elemento);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    temposBST[i + EXECUCOES] = tempo_gasto;
  }

  fprintf(stdout,
          "\n================ BUSCA BINARIA NO VETOR (%d exec) "
          "================\n",
          EXECUCOES * 2);
  showResults(temposVetor, EXECUCOES * 2, NULL);

  fprintf(stdout,
          "\n=================== BUSCA NA BST (%d exec) "
          "======================\n",
          EXECUCOES * 2);
  showResults(temposBST, EXECUCOES * 2, NULL);
  fprintf(stdout,
          "============================================================\n");

  free(temposVetor);
  free(temposBST);
  destroyVector(vetor);
  destroyBST(bst);
}
