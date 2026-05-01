#ifndef UTILS_H
#define UTILS_H

#include "vetor.h"

#include <stdio.h>

li genRandomNumber(li min, li max);
double getMedia(double *tempos, li quantidade);
double getDesvioPadrao(double *tempos, li quantidade);
void showResults(double *tempos, li quantidade, FILE *output);

#endif