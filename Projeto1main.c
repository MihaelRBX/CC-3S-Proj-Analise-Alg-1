#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPROMISSOS 100
#define MAX_DESCRICAO 100

typedef struct {
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
    float duracao;
    int prioridade;
    char nome[MAX_DESCRICAO];
    char descricao[MAX_DESCRICAO];
    char local[MAX_DESCRICAO];
} Compromisso;

int lerCompromissos(Compromisso compromissos[MAX_COMPROMISSOS], int * numCompromissos){
  FILE * arquivo;
  arquivo = fopen("entrada.csv", "r");
  if(arquivo == NULL){
    printf("Erro ao abrir o arquivo.\n");
    return 0  ;
  }

  *numCompromissos = 0;
  while(fscanf(arquivo, "%d;%d;%d;%d;%d;%f;%d;%[^;];%[^;];%[^\n]\n",
                    &compromissos[*numCompromissos].ano,
                    &compromissos[*numCompromissos].mes,
                    &compromissos[*numCompromissos].dia,
                    &compromissos[*numCompromissos].hora,
                    &compromissos[*numCompromissos].minuto,
                    &compromissos[*numCompromissos].duracao,
                    &compromissos[*numCompromissos].prioridade,
                    compromissos[*numCompromissos].nome,
                    compromissos[*numCompromissos].descricao,
                    compromissos[*numCompromissos].local) != EOF) {
        (*numCompromissos)++;
    }

  fclose(arquivo);
  return 1;
  
}

void exibirMenu() {
    printf("\nMenu:\n");
    printf("1. Adicionar compromisso\n");
    printf("2. Remover compromisso\n");
    printf("3. Ordenar por data\n");
    printf("4. Ordenar por data e horário\n");
    printf("5. Ordenar por data e prioridade\n");
    printf("6. Ordenar por local, prioridade e duração (decrescente)\n");
    printf("0. Sair\n");
  
}

void adicionarCompromisso() {
  
}

void removerCompromisso() {
  
}

void escreverSaida(Compromisso compromissos[MAX_COMPROMISSOS], int numCompromissos) {
    FILE *arquivo;
    arquivo = fopen("saida.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        return;
    }

    for (int i = 0; i < numCompromissos; i++) {
        fprintf(arquivo, "%d;%d;%d;%d;%d;%f;%d;%s;%s;%s\n",
                compromissos[i].ano,
                compromissos[i].mes,
                compromissos[i].dia,
                compromissos[i].hora,
                compromissos[i].minuto,
                compromissos[i].duracao,
                compromissos[i].prioridade,
                compromissos[i].nome,
                compromissos[i].descricao,
                compromissos[i].local);
    }

    fclose(arquivo);
}

int main() {
    Compromisso compromissos[MAX_COMPROMISSOS];
    int numCompromissos = 0;

    if (!lerCompromissos(compromissos, &numCompromissos)) {
        return 1;
    }

    int escolha;
    do {
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarCompromisso(compromissos, &numCompromissos);
                break;
            case 2:
                removerCompromisso(compromissos, &numCompromissos);
                break;
            case 0:
                escreverSaida(compromissos, numCompromissos);
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção inválida. Por favor, escolha novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}
