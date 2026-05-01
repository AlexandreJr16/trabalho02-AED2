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

static int maxHeight(int a, int b) { return (a > b) ? a : b; }

static int heightNode(NodeAVL *node) {
  if (node == NULL)
    return 0;
  return node->altura;
}

static int fatorBalanceamento(NodeAVL *node) {
  if (node == NULL)
    return 0;
  return heightNode(node->esq) - heightNode(node->dir);
}

static NodeAVL *rotateRight(NodeAVL *node) {
  NodeAVL *aux = node->esq;
  NodeAVL *T2 = aux->dir;

  aux->dir = node;
  node->esq = T2;

  node->altura = maxHeight(heightNode(node->esq), heightNode(node->dir)) + 1;
  aux->altura = maxHeight(heightNode(aux->esq), heightNode(aux->dir)) + 1;

  return aux;
}

static NodeAVL *rotateLeft(NodeAVL *node) {
  NodeAVL *aux = node->dir;
  NodeAVL *T2 = aux->esq;

  aux->esq = node;
  node->dir = T2;

  node->altura = maxHeight(heightNode(node->esq), heightNode(node->dir)) + 1;
  aux->altura = maxHeight(heightNode(aux->esq), heightNode(aux->dir)) + 1;

  return aux;
}

static NodeAVL *rotateLeftRight(NodeAVL *node) {
  node->esq = rotateLeft(node->esq);
  return rotateRight(node);
}

static NodeAVL *rotateRightLeft(NodeAVL *node) {
  node->dir = rotateRight(node->dir);
  return rotateLeft(node);
}

static NodeAVL *balancear(NodeAVL *node) {
  if (node == NULL)
    return NULL;

  node->altura = maxHeight(heightNode(node->esq), heightNode(node->dir)) + 1;

  int balance = fatorBalanceamento(node);

  if (balance > 1 && fatorBalanceamento(node->esq) >= 0)
    return rotateRight(node);

  if (balance > 1 && fatorBalanceamento(node->esq) < 0)
    return rotateLeftRight(node);

  if (balance < -1 && fatorBalanceamento(node->dir) <= 0)
    return rotateLeft(node);

  if (balance < -1 && fatorBalanceamento(node->dir) > 0)
    return rotateRightLeft(node);

  return node;
}

static NodeAVL *insertNode(NodeAVL *node, li chave) {
  if (!node)
    return createNodeAVL(chave);

  if (chave < node->chave)
    node->esq = insertNode(node->esq, chave);
  else if (chave > node->chave)
    node->dir = insertNode(node->dir, chave);
  else
    return node;

  return balancear(node);
}

static NodeAVL *minNode(NodeAVL *node) {
  if (!node) {
    return NULL;
  }
  while (node->esq) {
    node = node->esq;
  }
  return node;
}

static NodeAVL *deleteNode(NodeAVL *node, li chave) {
  if (!node)
    return node;

  if (chave < node->chave)
    node->esq = deleteNode(node->esq, chave);
  else if (chave > node->chave)
    node->dir = deleteNode(node->dir, chave);
  else {
    if (!node->esq || !node->dir) {
      NodeAVL *temp = node->esq ? node->esq : node->dir;

      if (!temp) {
        temp = node;
        node = NULL;
      } else
        *node = *temp;
      free(temp);
    } else {
      NodeAVL *temp = minNode(node->dir);

      node->chave = temp->chave;

      node->dir = deleteNode(node->dir, temp->chave);
    }
  }

  if (!node)
    return node;

  return balancear(node);
}

static int searchNode(NodeAVL *node, li chave) {
  if (!node)
    return 0;
  while (node) {
    if (node->chave > chave) {
      node = node->esq;
    } else if (node->chave < chave) {
      node = node->dir;
    } else {
      return 1;
    }
  }
  return 0;
}

static void preOrder(NodeAVL *node) {
  if (node == NULL)
    return;
  printf("%ld ", node->chave);
  preOrder(node->esq);
  preOrder(node->dir);
}

static void inOrder(NodeAVL *node) {
  if (node == NULL)
    return;
  inOrder(node->esq);
  printf("%ld ", node->chave);
  inOrder(node->dir);
}

static void postOrder(NodeAVL *node) {
  if (node == NULL)
    return;
  postOrder(node->esq);
  postOrder(node->dir);
  printf("%ld ", node->chave);
}

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

void insertAVL(AVL *self, li chave) {
  self->raiz = insertNode(self->raiz, chave);
  self->tamanho++;
}

void deleteAVL(AVL *self, li chave) {
  self->raiz = deleteNode(self->raiz, chave);
  self->tamanho--;
}

int searchAVL(AVL *self, li chave) { return searchNode(self->raiz, chave); }

int heightAVL(AVL *self) { return heightNode(self->raiz); }

int sizeAVL(AVL *self) { return self->tamanho; }

int isEmptyAVL(AVL *self) { return !self->raiz; }

void preOrderAVL(AVL *self) { preOrder(self->raiz); }

void inOrderAVL(AVL *self) { inOrder(self->raiz); }

void postOrderAVL(AVL *self) { postOrder(self->raiz); }
