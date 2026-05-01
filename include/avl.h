#ifndef AVL_H
#define AVL_H

typedef long int li;

// AVL
typedef struct AVL AVL;

AVL *createAVL();
void destroyAVL(AVL *self);

void insertAVL(AVL *self, li chave);
void deleteAVL(AVL *self, li chave);

int searchAVL(AVL *self, li chave);

int heightAVL(AVL *self);
int sizeAVL(AVL *self);
int isEmptyAVL(AVL *self);

void preOrderAVL(AVL *self);
void inOrderAVL(AVL *self);
void postOrderAVL(AVL *self);

#endif