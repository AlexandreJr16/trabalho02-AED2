#include "../include/avl.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// NODE
typedef struct NodeAVL {
  li chave;
  int altura;
  struct NodeAVL *esq;
  struct NodeAVL *dir;
} NodeAVL;

static NodeAVL *createNodeAVL(li chave) {
  NodeAVL *node = (NodeAVL *)malloc(sizeof(NodeAVL));
  node->chave = chave;
  node->altura = 1;
  node->esq = NULL;
  node->dir = NULL;
  return node;
}

static NodeAVL *destroyNodeAVL(NodeAVL *node) {
  if (!node) {
    return NULL;
  }

  destroyNodeAVL(node->esq);
  destroyNodeAVL(node->dir);
  free(node);

  return NULL;
}

static NodeAVL *insertNode(NodeAVL *node, li chave) {}

static NodeAVL *deleteNode(NodeAVL *node, li chave) {}

static int searchNode(NodeAVL *node, li chave) {}

static int heightNode(NodeAVL *node) {}

static int fatorBalanceamento(NodeAVL *node) {}

static NodeAVL *balancear(NodeAVL *node) {}

static NodeAVL *minNode(NodeAVL *node) {}

static void preOrder(NodeAVL *node) {}

static void inOrder(NodeAVL *node) {}

static void postOrder(NodeAVL *node) {}

static NodeAVL *rotateLeft(NodeAVL *node) {}

static NodeAVL *rotateRight(NodeAVL *node) {}

static NodeAVL *rotateLeftRight(NodeAVL *node) {}

static NodeAVL *rotateRightLeft(NodeAVL *node) {}

// AVL
typedef struct AVL {
  NodeAVL *raiz;
  int tamanho;
} AVL;

AVL *createAVL() {
  AVL *avl = (AVL *)malloc(sizeof(AVL));
  avl->raiz = NULL;
  avl->tamanho = 0;
  return avl;
}

void destroyAVL(AVL *self) {
  self->raiz = destroyNodeAVL(self->raiz);
  free(self);
}

void insertAVL(AVL *self, li chave) {}

void deleteAVL(AVL *self, li chave) {}

int searchAVL(AVL *self, li chave) {}

int heightAVL(AVL *self) {}

int sizeAVL(AVL *self) {}

int isEmptyAVL(AVL *self) {}

void preOrderAVL(AVL *self) {}

void inOrderAVL(AVL *self) {}

void postOrderAVL(AVL *self) {}
