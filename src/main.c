#include "../include/question.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand((unsigned int)time(NULL));

  printf("=== Questão 1 ===\n");
  run_questao1();

  printf("\n=== Questão 2 ===\n");
  run_questao2();

  printf("\n=== Questão 3 ===\n");
  run_questao3();

  printf("\n=== Questão 4 ===\n");
  run_questao4();

  return 0;
}
