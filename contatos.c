#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100
#define NOME_SIZE 50
#define TELEFONE_SIZE 15

typedef struct {
    char nome[NOME_SIZE];
    char telefone[TELEFONE_SIZE];
} Contato;

Contato contatos[MAX_CONTATOS];
int totalContatos = 0;

void adicionarContato() {
    if (totalContatos >= MAX_CONTATOS) {
        printf("Lista de contatos cheia!\n");
        return;
    }
    printf("Digite o nome do contato: ");
    scanf(" %[^\n]", contatos[totalContatos].nome);
    printf("Digite o telefone do contato: ");
    scanf(" %[^\n]", contatos[totalContatos].telefone);
    totalContatos++;
    printf("Contato adicionado com sucesso!\n");
}

void listarContatos() {
    if (totalContatos == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }
    printf("\nLista de Contatos:\n");
    for (int i = 0; i < totalContatos; i++) {
        printf("Contato %d: %s - %s\n", i + 1, contatos[i].nome, contatos[i].telefone);
    }
}

void removerContato() {
    if (totalContatos == 0) {
        printf("Nenhum contato para remover.\n");
        return;
    }
    listarContatos();
    int index;
    printf("Digite o número do contato a ser removido: ");
    scanf("%d", &index);
    if (index < 1 || index > totalContatos) {
        printf("Número inválido!\n");
        return;
    }
    for (int i = index - 1; i < totalContatos - 1; i++) {
        contatos[i] = contatos[i + 1];
    }
    totalContatos--;
    printf("Contato removido com sucesso!\n");
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Remover Contato\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato();
                break;
            case 2:
                listarContatos();
                break;
            case 3:
                removerContato();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
