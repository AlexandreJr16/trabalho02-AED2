#include "../include/bst.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

// NODE
typedef struct NodeBST {
  li chave;
  struct NodeBST *esq;
  struct NodeBST *dir;
} NodeBST;

static NodeBST *createNodeBST(li chave) {
  NodeBST *node = (NodeBST *)malloc(sizeof(NodeBST));

  node->chave = chave;
  node->esq = NULL;
  node->dir = NULL;

  return node;
}

static void destroyNode(NodeBST *node) {
  if (node == NULL)
    return;
  destroyNode(node->esq);
  destroyNode(node->dir);
  free(node);
}

static NodeBST *insertNode(NodeBST *node, li chave, int *inserido) {
  if (node == NULL) {
    *inserido = 1;
    return createNodeBST(chave);
  }

  if (chave < node->chave) {
    node->esq = insertNode(node->esq, chave, inserido);
  } else if (chave > node->chave) {
    node->dir = insertNode(node->dir, chave, inserido);
  }

  return node;
}

static NodeBST *findMin(NodeBST *node) {

  while (node->esq) {
    node = node->esq;
  }
  return node;
}

static NodeBST *deleteNodeBST(NodeBST *node, li chave, int *removido) {

  if (!node)
    return node;

  if (chave < node->chave) {
    node->esq = deleteNodeBST(node->esq, chave, removido);
  } else if (chave > node->chave) {
    node->dir = deleteNodeBST(node->dir, chave, removido);
  } else {
    *removido = 1;
    if (!node->esq) {
      NodeBST *aux = node->dir;
      free(node);
      return aux;
    }
    if (!node->dir) {
      NodeBST *aux = node->esq;
      free(node);
      return aux;
    }
    NodeBST *aux = findMin(node->dir);
    node->chave = aux->chave;
    node->dir = deleteNodeBST(node->dir, aux->chave, removido);
  }

  return node;
}

static int searchNode(NodeBST *node, li chave) {
  while (node) {
    if (node->chave < chave) {
      node = node->dir;
    } else if (node->chave > chave) {
      node = node->esq;
    } else {
      return 1;
    }
  }
  return 0;
}

static int heightNode(NodeBST *node) {

  if (!node) {
    return 0;
  }

  int alt_esq = heightNode(node->esq);
  int alt_dir = heightNode(node->dir);

  if (alt_esq > alt_dir) {
    return alt_esq + 1;
  } else {
    return alt_dir + 1;
  }
}

static void preOrder(NodeBST *node) {
  if (!node)
    return;

  preOrder(node->esq);
  preOrder(node->dir);
}

static void inOrder(NodeBST *node) {
  if (!node) {
    return;
  }
  inOrder(node->esq);
  printf("%li ", node->chave);
  inOrder(node->dir);
}

static void postOrder(NodeBST *node) {
  if (!node)
    return;
  postOrder(node->esq);
  postOrder(node->dir);
  printf("%li ", node->chave);
}

// BST
typedef struct BST {
  NodeBST *raiz;
  li tamanho;
} BST;

BST *createBST() {
  BST *bst = (BST *)malloc(sizeof(BST));

  bst->raiz = NULL;
  bst->tamanho = 0;
  return bst;
}

void destroyBST(BST *bst) {
  destroyNode(bst->raiz);
  free(bst);
}

void insertBST(BST *self, li chave) {
  int inserido = 0;
  self->raiz = insertNode(self->raiz, chave, &inserido);
  self->tamanho += inserido;
}

void deleteBST(BST *self, li chave) {
  int removido = 0;
  self->raiz = deleteNodeBST(self->raiz, chave, &removido);
  self->tamanho -= removido;
}

int searchBST(BST *self, li chave) { return searchNode(self->raiz, chave); }

int heightBST(BST *self) { return heightNode(self->raiz); }

int sizeBST(BST *self) { return self->tamanho; }

int isEmptyBST(BST *self) { return !self->raiz; }

void preOrderBST(BST *self) { preOrder(self->raiz); }

void inOrderBST(BST *self) { inOrder(self->raiz); }

void postOrderBST(BST *self) { postOrder(self->raiz); }
