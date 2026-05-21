#include "../../include/bst.h"
#include "../../include/question.h"
#include "../../include/utils.h"
#include "../../include/vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000
#define EXECUCOES 15
#define REPETICOES 100000

void run_questao3() {
  printf("\n[MEMORIA] Antes de alocar estruturas. Anote a memoria agora.\n");
  printf("Pressione ENTER para continuar...\n");
  getchar();

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

  printf("\n[MEMORIA] Vetor (%d elementos) criado. Anote a memoria agora.\n", N);
  printf("Pressione ENTER para continuar...\n");
  getchar();

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

  printf("\n[MEMORIA] Vetor + BST (%d elementos cada) criados. Anote a memoria agora.\n", N);
  printf("Pressione ENTER para continuar...\n");
  getchar();

  for (li i = 0; i < EXECUCOES; i++) {
    li posicao = genRandomNumber(0, N - 1);
    li elemento = getElementAtVector(vetor, posicao);

    inicio = clock();
    for (int r = 0; r < REPETICOES; r++)
      binarySearchVector(vetor, elemento);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    temposVetor[i] = tempo_gasto;

    inicio = clock();
    for (int r = 0; r < REPETICOES; r++)
      searchBST(bst, elemento);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    temposBST[i] = tempo_gasto;
  }

  for (li i = 0; i < EXECUCOES; i++) {
    li elemento;
    do {
      elemento = genRandomNumber(0, range);
    } while (binarySearchVector(vetor, elemento) != -1);

    inicio = clock();
    for (int r = 0; r < REPETICOES; r++)
      binarySearchVector(vetor, elemento);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    temposVetor[i + EXECUCOES] = tempo_gasto;

    inicio = clock();
    for (int r = 0; r < REPETICOES; r++)
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

  printf("\n[MEMORIA] Apos liberar vetor e BST. Anote a memoria agora.\n");
  printf("Pressione ENTER para continuar...\n");
  getchar();
}
