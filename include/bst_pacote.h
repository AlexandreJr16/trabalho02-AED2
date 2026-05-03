#ifndef BST_PACOTE_H
#define BST_PACOTE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Pacote {
  unsigned long id;
  unsigned char *dados;
  size_t tamanho;
} Pacote;

typedef struct BSTPacote BSTPacote;

BSTPacote *createBSTPacote();
void destroyBSTPacote(BSTPacote *self);

int insertBSTPacote(BSTPacote *self, Pacote pacote);

int sizeBSTPacote(BSTPacote *self);
int heightBSTPacote(BSTPacote *self);

void writeInOrderBSTPacote(BSTPacote *self, FILE *output);

#endif
