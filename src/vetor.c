#include "../include/vetor.h"
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
  li *data;
  li tamanho;
} Vector;

Vector *createVector(li tamanho) {
  Vector *vetor = (Vector *)malloc(sizeof(Vector));
  vetor->data = (li *)malloc(sizeof(li) * tamanho);
  vetor->tamanho = tamanho;
  return vetor;
}

void destroyVector(Vector *self) {
  free(self->data);
  free(self);
}

li linearSearchVector(Vector *self, li target) {
  for (li i = 0; i < self->tamanho; i++) {
    if (self->data[i] == target)
      return i;
  }
  return -1;
}

li binarySearchVector(Vector *self, li target) {
  li inicio = 0, fim = self->tamanho - 1, meio;

  while (fim >= inicio) {
    meio = (inicio + fim) / 2;
    if (self->data[meio] > target) {
      fim = meio - 1;
    } else if (self->data[meio] < target) {
      inicio = meio + 1;
    } else {
      return meio;
    }
  }
  return -1;
}

void bubbleSortVector(Vector *self) {
  li aux;
  short int swapped;
  for (li i = 0; i < self->tamanho - 1; i++) {
    swapped = 0;
    for (li j = 0; j < self->tamanho - 1 - i; j++) {
      if (self->data[j] > self->data[j + 1]) {
        aux = self->data[j];
        self->data[j] = self->data[j + 1];
        self->data[j + 1] = aux;
        swapped = 1;
      }
    }
    if (!swapped)
      break;
  }
}

void insertionSortVector(Vector *self) {
  li *v = self->data;
  li i, j, key;
  for (i = 1; i < self->tamanho; i++) {
    key = v[i];
    j = i - 1;
    while (j >= 0 && v[j] > key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}

void selectionSortVector(Vector *self) {
  li *v = self->data;
  for (li i = 0; i < self->tamanho - 1; i++) {
    li menor = i;
    for (li j = i + 1; j < self->tamanho; j++) {
      if (v[j] < v[menor]) {
        menor = j;
      }
    }
    if (menor != i) {
      li aux = v[menor];
      v[menor] = v[i];
      v[i] = aux;
    }
  }
}

static void swap(li v[], li i, li j) {
  li aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

static li partition(li *v, li start, li end) {
  li pivot = v[end];
  li pivotIndex = start;
  for (li i = start; i < end; i++) {
    if (v[i] <= pivot) {
      swap(v, i, pivotIndex);
      pivotIndex++;
    }
  }
  swap(v, pivotIndex, end);
  return pivotIndex;
}

static li partitionOtimization(li v[], li start, li end) {
  li pivotIndex = start + (rand() % (end - start + 1));
  swap(v, pivotIndex, end);
  return partition(v, start, end);
}

static void qSort(li v[], li start, li end) {
  if (start < end) {
    li pivotIndex = partitionOtimization(v, start, end);
    qSort(v, start, pivotIndex - 1);
    qSort(v, pivotIndex + 1, end);
  }
}

void quickSortVector(Vector *self) {
  if (self == NULL)
    return;
  qSort(self->data, 0, self->tamanho - 1);
}

static void intercala(li *v, li start, li meio, li end, li *vAux) {
  li i = start, j = meio + 1, k = start;
  while (i <= meio && j <= end) {
    if (v[i] < v[j]) {
      vAux[k++] = v[i++];
    } else {
      vAux[k++] = v[j++];
    }
  }
  while (i <= meio)
    vAux[k++] = v[i++];
  while (j <= end)
    vAux[k++] = v[j++];
  for (li i = start; i <= end; i++)
    v[i] = vAux[i];
}

static void mSort(li *v, li start, li end, li *vAux) {
  if (start < end) {
    li meio = start + (end - start) / 2;
    mSort(v, start, meio, vAux);
    mSort(v, meio + 1, end, vAux);
    intercala(v, start, meio, end, vAux);
  }
}

void mergeSortVector(Vector *self) {
  if (self == NULL || self->tamanho <= 1)
    return;
  li *vAux = (li *)malloc(sizeof(li) * self->tamanho);
  if (vAux == NULL)
    return;
  mSort(self->data, 0, self->tamanho - 1, vAux);
  free(vAux);
}

void copyVector(Vector *v1, Vector *v2) {
  memcpy(v2->data, v1->data, v1->tamanho * sizeof(li));
}

li getSizeVector(Vector *self) {
  if (self == NULL)
    return 0;
  return self->tamanho;
}

li getElementAtVector(Vector *self, li index) {
  if (self == NULL || index < 0 || index >= self->tamanho)
    return -1;
  return self->data[index];
}

void setElementAtVector(Vector *self, li index, li value) {
  if (self == NULL || index < 0 || index >= self->tamanho)
    return;
  self->data[index] = value;
}