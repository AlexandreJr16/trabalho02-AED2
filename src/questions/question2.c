#include "../../include/bst_pacote.h"
#include "../../include/question.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_PACOTE 1024
#define JANELA 5
#define PERCENT_DUPLICATAS 5

#define INPUT_PATH "assets/input.jpg"
#define OUTPUT_PATH "assets/output.jpg"

void run_questao2() {
  FILE *fp = fopen(INPUT_PATH, "rb");
  if (!fp) {
    printf("Erro: nao foi possivel abrir %s\n", INPUT_PATH);
    return;
  }

  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  unsigned char *buffer = (unsigned char *)malloc(file_size);
  fread(buffer, 1, file_size, fp);
  fclose(fp);

  long num_pacotes = (file_size + TAMANHO_PACOTE - 1) / TAMANHO_PACOTE;
  long num_duplicatas = num_pacotes * PERCENT_DUPLICATAS / 100;
  if (num_duplicatas < 1)
    num_duplicatas = 1;
  long total = num_pacotes + num_duplicatas;

  Pacote *pacotes = (Pacote *)malloc(sizeof(Pacote) * total);

  for (long i = 0; i < num_pacotes; i++) {
    pacotes[i].id = i;
    pacotes[i].dados = buffer + i * TAMANHO_PACOTE;
    long restante = file_size - i * TAMANHO_PACOTE;
    pacotes[i].tamanho =
        restante < TAMANHO_PACOTE ? (size_t)restante : TAMANHO_PACOTE;
  }

  for (long i = num_pacotes - 1; i > 0; i--) {
    long min = (i - JANELA > 0) ? i - JANELA : 0;
    long j = min + (rand() % (i - min + 1));
    Pacote tmp = pacotes[i];
    pacotes[i] = pacotes[j];
    pacotes[j] = tmp;
  }

  for (long i = 0; i < num_duplicatas; i++) {
    long idx = rand() % num_pacotes;
    pacotes[num_pacotes + i] = pacotes[idx];
  }

  printf("\n=== Simulacao de Recebimento de Pacotes ===\n");
  printf("Arquivo de entrada: %s (%ld bytes)\n", INPUT_PATH, file_size);
  printf("Total de pacotes: %ld\n", num_pacotes);
  printf("Tamanho do pacote: %d bytes\n", TAMANHO_PACOTE);
  printf("Janela de desordem (W): %d\n", JANELA);
  printf("Duplicatas adicionadas: %ld (%.2f%%)\n", num_duplicatas,
         (double)num_duplicatas / num_pacotes * 100);

  BSTPacote *bst = createBSTPacote();
  int duplicatas_detectadas = 0;

  for (long i = 0; i < total; i++) {
    int inserido = insertBSTPacote(bst, pacotes[i]);
    if (!inserido)
      duplicatas_detectadas++;
  }

  printf("\nPacotes inseridos: %d\n", sizeBSTPacote(bst));
  printf("Duplicatas detectadas: %d\n", duplicatas_detectadas);
  printf("Altura da BST: %d\n", heightBSTPacote(bst));

  FILE *out = fopen(OUTPUT_PATH, "wb");
  if (!out) {
    printf("Erro: nao foi possivel criar %s\n", OUTPUT_PATH);
    free(pacotes);
    free(buffer);
    destroyBSTPacote(bst);
    return;
  }

  writeInOrderBSTPacote(bst, out);
  fclose(out);

  FILE *check = fopen(OUTPUT_PATH, "rb");
  fseek(check, 0, SEEK_END);
  long out_size = ftell(check);
  fseek(check, 0, SEEK_SET);

  unsigned char *out_buffer = (unsigned char *)malloc(out_size);
  fread(out_buffer, 1, out_size, check);
  fclose(check);

  int ok = (out_size == file_size) && (memcmp(buffer, out_buffer, file_size) == 0);

  printf("\nReconstruindo arquivo...\n");
  printf("Arquivo de saida: %s (%ld bytes)\n", OUTPUT_PATH, out_size);
  printf("Verificacao: %s\n", ok ? "OK (arquivos identicos)" : "FALHA");

  free(out_buffer);
  free(pacotes);
  free(buffer);
  destroyBSTPacote(bst);
}
