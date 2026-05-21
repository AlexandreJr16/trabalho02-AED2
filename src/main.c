#include "../include/question.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_menu() {
  printf("\nMenu\n");
  printf("1. Questão 1\n");
  printf("2. Questão 2\n");
  printf("3. Questão 3\n");
  printf("4. Questão 4\n");
  printf("5. Todos\n");
  printf("0. Sair\n");
}
int main() {
  srand((unsigned int)time(NULL));

  print_menu();
  int n;
  scanf("%d%*c", &n);

  while (n != 0) {
    switch (n) {

    case 1:
      printf(" Questão 1 \n");
      run_questao1();
      break;

    case 2:
      printf("\n Questão 2 \n");
      run_questao2();
      break;

    case 3:
      printf("\n Questão 3 \n");
      run_questao3();
      break;

    case 4:
      printf("\n Questão 4 \n");
      run_questao4();
      break;
    case 5:
      printf("\nTodos\n");
      run_questao1();
      run_questao2();
      run_questao3();
      run_questao4();
      break;
    case 0:
      printf("\nSair\n");
      return 0;
      break;

    default:
      printf("\n Questão invalida \n");
      break;
    }
    print_menu();
    scanf("%d%*c", &n);
    system("clear");
  }

  return 0;
}
