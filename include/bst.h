#ifndef BST_H
#define BST_H

typedef long int li;

typedef struct BST BST;

BST *createBST();
void destroyBST(BST *self);

void insertBST(BST *self, li chave);
void deleteBST(BST *self, li chave);

int searchBST(BST *self, li chave);

int heightBST(BST *self);
int sizeBST(BST *self);
int isEmptyBST(BST *self);

void preOrderBST(BST *self);
void inOrderBST(BST *self);
void postOrderBST(BST *self);

#endif