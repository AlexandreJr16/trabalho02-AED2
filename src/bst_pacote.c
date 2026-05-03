#include "../include/bst_pacote.h"
#include <stdlib.h>
#include <string.h>

typedef struct NodeBSTPacote {
  Pacote pacote;
  struct NodeBSTPacote *esq;
  struct NodeBSTPacote *dir;
} NodeBSTPacote;

static NodeBSTPacote *createNode(Pacote pacote) {
  NodeBSTPacote *node = (NodeBSTPacote *)malloc(sizeof(NodeBSTPacote));
  node->pacote = pacote;
  node->esq = NULL;
  node->dir = NULL;
  return node;
}

static void destroyNode(NodeBSTPacote *node) {
  if (!node)
    return;
  destroyNode(node->esq);
  destroyNode(node->dir);
  free(node);
}

static NodeBSTPacote *insertNode(NodeBSTPacote *node, Pacote pacote,
                                 int *inserido) {
  if (!node) {
    *inserido = 1;
    return createNode(pacote);
  }

  if (pacote.id < node->pacote.id)
    node->esq = insertNode(node->esq, pacote, inserido);
  else if (pacote.id > node->pacote.id)
    node->dir = insertNode(node->dir, pacote, inserido);

  return node;
}

static int heightNode(NodeBSTPacote *node) {
  if (!node)
    return 0;
  int esq = heightNode(node->esq);
  int dir = heightNode(node->dir);
  return (esq > dir ? esq : dir) + 1;
}

static void writeInOrder(NodeBSTPacote *node, FILE *output) {
  if (!node)
    return;
  writeInOrder(node->esq, output);
  fwrite(node->pacote.dados, 1, node->pacote.tamanho, output);
  writeInOrder(node->dir, output);
}

typedef struct BSTPacote {
  NodeBSTPacote *raiz;
  int tamanho;
} BSTPacote;

BSTPacote *createBSTPacote() {
  BSTPacote *bst = (BSTPacote *)malloc(sizeof(BSTPacote));
  bst->raiz = NULL;
  bst->tamanho = 0;
  return bst;
}

void destroyBSTPacote(BSTPacote *self) {
  destroyNode(self->raiz);
  free(self);
}

int insertBSTPacote(BSTPacote *self, Pacote pacote) {
  int inserido = 0;
  self->raiz = insertNode(self->raiz, pacote, &inserido);
  self->tamanho += inserido;
  return inserido;
}

int sizeBSTPacote(BSTPacote *self) { return self->tamanho; }

int heightBSTPacote(BSTPacote *self) { return heightNode(self->raiz); }

void writeInOrderBSTPacote(BSTPacote *self, FILE *output) {
  writeInOrder(self->raiz, output);
}
