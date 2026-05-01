#ifndef VETOR_H
#define VETOR_H

typedef long int li;
typedef struct Vector Vector;

// Constructor | Destroyer
Vector *createVector(li tamanho);
void destroyVector(Vector *self);

li linearSearchVector(Vector *self, li target);
li binarySearchVector(Vector *self, li target);
void bubbleSortVector(Vector *self);
void insertionSortVector(Vector *self);
void selectionSortVector(Vector *self);
void quickSortVector(Vector *self);
void mergeSortVector(Vector *self);
void copyVector(Vector *v1, Vector *v2);

li getSizeVector(Vector *self);
li getElementAtVector(Vector *self, li index);
void setElementAtVector(Vector *self, li index, li value);

#endif