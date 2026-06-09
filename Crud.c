#include <stdio.h>

typedef struct {
    char marca[30];
    char modelo[30];
    char dataManutencao[30];
    float valorManutencao;
    char descricaoManutencao[100];
} Impressora;

Impressora atendidas[999];
int quant = 0;

void menu();
void adicionarManutencao();
void removerManutencao();
void alterarManutencao();
void quantidade();
void listar();

int main() {
    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: adicionarManutencao(); break;
            case 2: removerManutencao();   break;
            case 3: alterarManutencao();   break;
            case 4: quantidade();          break;
            case 5: listar();              break;
        }
    } while (opcao != 0);
}

void menu() {
    printf("\n");
    printf("0 - Digite 0 para sair.\n");
    printf("1 - Digite 1 para adicionar manutencao.\n");
    printf("2 - Digite 2 para remover manutencao.\n");
    printf("3 - Digite 3 para alterar manutencao.\n");
    printf("4 - Digite 4 para mostrar quantidade de manutencoes.\n");
    printf("5 - Digite 5 para listar manutencoes.\n");
    printf("\n");
}

void adicionarManutencao() {
    printf("\n");
    printf("Marca: ");
    scanf("%s", atendidas[quant].marca);
    printf("Modelo: ");
    scanf("%s", atendidas[quant].modelo);
    printf("Data Manutencao: ");
    scanf("%s", atendidas[quant].dataManutencao);
    printf("Valor a ser cobrado: ");
    scanf("%f", &atendidas[quant].valorManutencao);
    printf("Descricao da Manutencao: ");
    scanf(" %[^\n]", atendidas[quant].descricaoManutencao);
    printf("\n");
    quant++;
}

void removerManutencao() {
    if (quant == 0) {
        printf("\nNenhuma manutencao cadastrada.\n");
        return;
    }

    int num;
    // CORRIGIDO: recolocado %d para exibir o intervalo válido de Ids
    printf("\nDigite o Id da manutencao a remover (0 a %d): ", quant - 1);
    scanf("%d", &num);

    if (num < 0 || num >= quant) {
        printf("Id nao encontrado!\n");
        return;
    }

    for (int i = num; i < quant - 1; i++) {
        atendidas[i] = atendidas[i + 1];
    }
    quant--;
    printf("\nManutencao removida com sucesso.\n");
}

void alterarManutencao() {
    if (quant == 0) {
        printf("\nNenhuma manutencao cadastrada.\n");
        return;
    }

    int num;
    printf("\nDigite o Id da manutencao a alterar (0 a %d): ", quant - 1);
    scanf("%d", &num);

    if (num < 0 || num >= quant) {
        printf("Id nao encontrado!\n");
        return;
    }

    printf("Marca: ");
    scanf("%s", atendidas[num].marca);
    printf("Modelo: ");
    scanf("%s", atendidas[num].modelo);
    printf("Data Manutencao: ");
    scanf("%s", atendidas[num].dataManutencao);
    printf("Valor a ser cobrado: ");
    scanf("%f", &atendidas[num].valorManutencao);
    printf("Descricao da Manutencao: ");
    scanf(" %[^\n]", atendidas[num].descricaoManutencao);
    printf("\nManutencao alterada com sucesso.\n");
}

void quantidade() {
    printf("\nNumero de manutencoes realizadas: %d\n", quant);
}

void listar() {
    if (quant == 0) {
        printf("\nNenhuma manutencao cadastrada.\n");
        return;
    }

    printf("\n");
    for (int i = 0; i < quant; i++) {
        printf("Id: %d\n",                        i);
        printf("Marca: %s\n",                     atendidas[i].marca);
        printf("Modelo: %s\n",                    atendidas[i].modelo);
        printf("Data Manutencao: %s\n",           atendidas[i].dataManutencao);
        printf("Valor a ser cobrado: R$ %.2f\n",  atendidas[i].valorManutencao);
        printf("Descricao da Manutencao: %s\n\n", atendidas[i].descricaoManutencao);
    }
}
