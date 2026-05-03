#include "../include/utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

li genRandomNumber(li min, li max) {
  return (li)((((li)rand() << 30) | ((li)rand() << 15) | (li)rand()) %
              (max - min + 1)) +
         min;
}

double getMedia(double *tempos, li quantidade) {
  double sum = 0;
  for (li i = 0; i < quantidade; i++) {
    sum += tempos[i];
  }
  return sum / quantidade;
}

double getDesvioPadrao(double *tempos, li quantidade) {
  double media = getMedia(tempos, quantidade);
  double soma_quadrados = 0;
  for (li i = 0; i < quantidade; i++) {
    double diff = tempos[i] - media;
    soma_quadrados += diff * diff;
  }
  return sqrt(soma_quadrados / quantidade);
}

void showResults(double *tempos, li quantidade, FILE *output) {
  if (output == NULL)
    output = stdout;

  fprintf(output, "Tempos em segundos:\n");
  for (li i = 0; i < quantidade; i++) {
    fprintf(output, "Exec [%2ld]: %10.6f s\n", i + 1, tempos[i]);
  }
  double media = getMedia(tempos, quantidade);
  double desvio = getDesvioPadrao(tempos, quantidade);
  fprintf(output, "Média:         %10.6f s\n", media);
  fprintf(output, "Desvio padrão: %10.6f s\n", desvio);
}