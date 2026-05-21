#include "../../include/avl.h"
#include "../../include/bst.h"
#include "../../include/question.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000
#define ARVORES 10
#define BUSCAS 30
#define EXISTENTES 15
#define REPETICOES 100000

void run_questao4() {
  li range = N * 100L;
  li *valores = (li *)malloc(sizeof(li) * N);

  clock_t inicio, fim;
  double tempos_criacao_bst[ARVORES];
  double tempos_criacao_avl[ARVORES];
  int alturas_bst[ARVORES];
  int alturas_avl[ARVORES];

  BST *bst = NULL;
  AVL *avl = NULL;

  printf("\n");
  printf("Exec |  Tempo BST  |  Tempo AVL  | Altura BST | Altura AVL\n");
  printf("-----|-------------|-------------|------------|------------\n");

  for (int exec = 0; exec < ARVORES; exec++) {
    for (li i = 0; i < N; i++)
      valores[i] = genRandomNumber(0, range);

    bst = createBST();
    inicio = clock();
    for (li i = 0; i < N; i++)
      insertBST(bst, valores[i]);
    fim = clock();
    tempos_criacao_bst[exec] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    alturas_bst[exec] = heightBST(bst);

    avl = createAVL();
    inicio = clock();
    for (li i = 0; i < N; i++)
      insertAVL(avl, valores[i]);
    fim = clock();
    tempos_criacao_avl[exec] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    alturas_avl[exec] = heightAVL(avl);

    printf(" %2d  | %9.6f s | %9.6f s |    %4d    |    %4d\n",
           exec + 1, tempos_criacao_bst[exec], tempos_criacao_avl[exec],
           alturas_bst[exec], alturas_avl[exec]);

    if (exec < ARVORES - 1) {
      destroyBST(bst);
      destroyAVL(avl);
    }
  }

  printf("-----|-------------|-------------|------------|------------\n");
  printf("Media| %9.6f s | %9.6f s |\n",
         getMedia(tempos_criacao_bst, ARVORES),
         getMedia(tempos_criacao_avl, ARVORES));

  double tempos_busca_bst[BUSCAS];
  double tempos_busca_avl[BUSCAS];

  printf("\nExec | Busca BST   | Busca AVL\n");
  printf("-----|-------------|------------\n");

  for (int i = 0; i < EXISTENTES; i++) {
    li elemento = valores[genRandomNumber(0, N - 1)];

    inicio = clock();
    for (int r = 0; r < REPETICOES; r++)
      searchBST(bst, elemento);
    fim = clock();
    tempos_busca_bst[i] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    inicio = clock();
    for (int r = 0; r < REPETICOES; r++)
      searchAVL(avl, elemento);
    fim = clock();
    tempos_busca_avl[i] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf(" %2d  | %9.6f s | %9.6f s\n", i + 1,
           tempos_busca_bst[i], tempos_busca_avl[i]);
  }

  for (int i = EXISTENTES; i < BUSCAS; i++) {
    li elemento;
    do {
      elemento = genRandomNumber(0, range);
    } while (searchBST(bst, elemento));

    inicio = clock();
    for (int r = 0; r < REPETICOES; r++)
      searchBST(bst, elemento);
    fim = clock();
    tempos_busca_bst[i] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    inicio = clock();
    for (int r = 0; r < REPETICOES; r++)
      searchAVL(avl, elemento);
    fim = clock();
    tempos_busca_avl[i] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf(" %2d  | %9.6f s | %9.6f s\n", i + 1,
           tempos_busca_bst[i], tempos_busca_avl[i]);
  }

  printf("-----|-------------|------------\n");
  printf("Media| %9.6f s | %9.6f s\n",
         getMedia(tempos_busca_bst, BUSCAS),
         getMedia(tempos_busca_avl, BUSCAS));

  free(valores);
  destroyBST(bst);
  destroyAVL(avl);
}
