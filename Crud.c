#include <stdio.h>
#include <string.h>

typedef struct { // Estrutura para armazenar os usuários do sistema
    char perfil[30];
    char login[30];
    char email[50];
    char senha[30];
} Usuario;

typedef struct { // Estrutura para armazenar contratos e vendas de impressoras
    char nomeCliente[50];
    char cpfCNPJ[20];
    char numeroTelefone[20];
    char endereco[100];
    char marcaImpressora[15];
    char modeloImpressora[15];
    char status[20];
    char categoria[10];
    float valor;
} Cadastro;

typedef struct { // Estrutura para registrar manutenções realizadas
    char marca[30];
    char modelo[30];
    char dataManutencao[30];
    char descricaoManutencao[100];
    char categoria[10];
} Chamado;

typedef struct { // Estrutura para controle de garantias
    char nome[30];
    char cpfCNPJ[30];
    char marca[30];
    char modelo[30];
    char dataGarantia[30];
} Garantia;

typedef struct { // Estrutura para venda de peças e produtos
    char cpfCNPJ[30];
    char pecaProduto[30];
    float valor;
} Produtos;

Produtos vendidos[100]; // Vetor que armazenam os dados do sistema
int montante = 0; // Contador de registros


Garantia defeitos[100]; // Vetor que armazenam os dados do sistema
int val = 0; // Contador de registros

Chamado atendidas[100]; // Vetor que armazenam os dados do sistema
int quant = 0; // Contador de registros

Cadastro clientes[100]; // Vetor que armazenam os dados do sistema
int num = 0; // Contador de registros

Usuario pessoas[100]; // Vetor que armazenam os dados do sistema
int id = 0; // Contador de registros

int usuarioLogado = -1; //Variavel global que guarda qual usuario esta logado

// Declaração das funções utilizadas no sistema
void telaInicial();
void entrada(int entrar);
void login();
void cadastro();
void menuPrincipal(int idx);
void menuAdmin();
void menuUsuario();
void impressoraAlugada();
void impressoraCliente();
void gerenciarUsuarios();
void relatorios();
void novoContrato();
void alterarContrato();
void encerrarContrato();
void manutencao();
void novaVenda();
void garantiaImpressora();
void manutencaoCliente();
void vendaProdutos();
void listarUsuarios();
void removerUsuarios();
void alterarUsuarios();
void manutencoes();
void receitaTotal();
void totalContratos();
void voltarMenu();

int main() {
    telaInicial();
    // Inicia o sistema exibindo a tela inicial
    return 0;
}
void telaInicial() { // Exibe as opções iniciais do sistema
    int entrar;
    printf("1-Login \n2-Cadastrar\n");
    scanf("%d", &entrar);
    entrada(entrar);
}
void entrada(int entrar) {
    if(entrar == 1) {
        login();
    } else {
        cadastro();
    }

}
void cadastro() { // Realiza o cadastro de novos usuários
    int opcao;

    printf("\n");
    printf("Perfil (Admin/Usuario): \n");
    scanf("%s", pessoas[id].perfil);
    printf("Email: \n");
    scanf("%s", pessoas[id].email);
    printf("Login: \n");
    scanf("%s", pessoas[id].login);
    printf("Senha: \n");
    scanf("%s", pessoas[id].senha);
    id++;
    printf("\n1-Login \n2-Cadastrar\n");
    scanf("%d", &opcao);
    entrada(opcao);
}
void login() { // Verifica login e senha e libera o acesso ao sistema
    char nome[30];
    char pin[30];
    int encontrado = 0;

    printf("Login: \n");
    scanf("%s", nome);
    printf("Senha: \n");
    scanf("%s", pin);
    for(int i = 0; i < id; i++) {
        if(strcmp(nome, pessoas[i].login) == 0 && strcmp(pin, pessoas[i].senha) == 0) {
            encontrado = 1;
            usuarioLogado = i;
            menuPrincipal(i);
            break;
        }
    }
    if(encontrado == 1) {
        printf("Login realizado com sucesso!!!");
    } else {
        printf("Login ou senha incorretos!!!");
        telaInicial();
    }
}
void voltarMenu() { // Retorna para o menu correspondente ao perfil logado
    if(strcmp(pessoas[usuarioLogado].perfil, "Admin") == 0 ||
       strcmp(pessoas[usuarioLogado].perfil, "admin") == 0) {
        menuAdmin();
    } else {
        menuUsuario();
    }
}
void menuPrincipal(int idx) { // Direciona o usuário para o menu correto conforme o perfil
    if(strcmp("admin", pessoas[idx].perfil) == 0 || strcmp("Admin", pessoas[idx].perfil) == 0) {
        menuAdmin();
    } else if(strcmp("usuario", pessoas[idx].perfil) == 0 || strcmp("Usuario", pessoas[idx].perfil) == 0) {
        menuUsuario();
    }
}
void menuAdmin() { // Menu com acesso completo para administradores
    int opcao;

    printf("\n");
    printf("\n1-Impressoras Alugadas");
    printf("\n2-Impressoras de Clientes");
    printf("\n3-Gerenciar Usuarios");
    printf("\n4-Relatorios");
    printf("\n0-Voltar Para Tela Inicial");
    printf("\n");
    scanf("%d", &opcao);

    switch(opcao) {
    case 1:
        impressoraAlugada();
        break;
    case 2:
        impressoraCliente();
        break;
    case 3:
        gerenciarUsuarios();
        break;
    case 4:
        relatorios();
        break;
    default:
        telaInicial();
    }
}
void impressoraAlugada() { // Gerencia contratos de locação de impressoras
    int opcao;

    printf("\n");
    printf("\n1-Novo Contrato");
    printf("\n2-Alterar Contrato");
    printf("\n3-Encerrar Contrato");
    printf("\n4-Manutencao");
    printf("\n0-Voltar Para Menu Admin");
    printf("\n");
    scanf("%d", &opcao);

    switch(opcao) {
    case 1:
        novoContrato();
        break;
    case 2:
        alterarContrato();
        break;
    case 3:
        encerrarContrato();
        break;
    case 4:
        manutencao();
        break;
    default:
        voltarMenu();
    }
}
void impressoraCliente() { // Gerencia vendas, garantias e serviços para clientes
    int opcao;

    printf("\n");
    printf("\n1-Nova Venda");
    printf("\n2-Garantia");
    printf("\n3-Manutencao");
    printf("\n4-Venda Pecas/Produtos");
    printf("\n0-Voltar Para Menu Admin");
    printf("\n");
    scanf("%d", &opcao);

    switch(opcao) {
    case 1:
        novaVenda();
        break;
    case 2:
        garantiaImpressora();
        break;
    case 3:
        manutencaoCliente();
        break;
    case 4:
        vendaProdutos();
        break;
    default:
        voltarMenu();
    }
}
void gerenciarUsuarios() { // Permite listar, alterar e remover usuários
    int opcao;

    printf("\n");
    printf("\n1-Listar Usuarios");
    printf("\n2-Remover Usuarios");
    printf("\n3-Alterar Dados de Usuario");
    printf("\n0-Voltar Para Menu Admin");
    printf("\n");
    scanf("%d", &opcao);

    switch(opcao) {
    case 1:
        listarUsuarios();
        break;
    case 2:
        removerUsuarios();
        break;
    case 3:
        alterarUsuarios();
        break;
    default:
        menuAdmin();
    }
}
void relatorios() { // Exibe relatórios gerenciais do sistema
    int opcao;

    printf("\n");
    printf("\n1-Listar Manutencoes");
    printf("\n2-Exibir Total de Receita");
    printf("\n3-Exibir Total de Contratos");
    printf("\n0-Voltar Para Menu Admin");
    printf("\n");
    scanf("%d", &opcao);

    switch(opcao) {
    case 1:
        manutencoes();
        break;
    case 2:
        receitaTotal();
        break;
    case 3:
        totalContratos();
        break;
    default:
        menuAdmin();
    }
}
void novoContrato() { // Cadastra um novo contrato de aluguel
    printf("\n");
    printf("Nome do Cliente: ");
    scanf(" %[^\n]", clientes[num].nomeCliente);
    printf("CPF ou CNPJ: ");
    scanf("%s", clientes[num].cpfCNPJ);
    printf("Numero de Telefone: ");
    scanf("%s", clientes[num].numeroTelefone);
    printf("Endereco: ");
    scanf(" %[^\n]", clientes[num].endereco);
    printf("Marca da Impressora: ");
    scanf(" %s", clientes[num].marcaImpressora);
    printf("Modelo da Impressora: ");
    scanf(" %s", clientes[num].modeloImpressora);
    strcpy(clientes[num].categoria, "aluguel");
    printf("Valor do Aluguel: ");
    scanf(" %f", &clientes[num].valor);
    strcpy(clientes[num].status, "ativo");
    printf("\n");
    num++;
    impressoraAlugada();
}
void alterarContrato() { // Permite atualizar os dados de um contrato existente
    char busca[20];

    printf("Digite o CPF ou CNPJ desejado: ");
    scanf("%s", busca);
    for(int i = 0; i < num; i++) {
        if(strcmp(busca, clientes[i].cpfCNPJ) == 0) {
            printf("Dados Atuais: \n");
            printf("Nome: %s\n", clientes[i].nomeCliente);
            printf("CPF/CNPJ: %s\n", clientes[i].cpfCNPJ);
            printf("Telefone: %s\n", clientes[i].numeroTelefone);
            printf("Endereco: %s\n", clientes[i].endereco);
            printf("Marca: %s\n", clientes[i].marcaImpressora);
            printf("Modelo: %s\n", clientes[i].modeloImpressora);
            printf("Valor: R$ %.2f\n", clientes[i].valor);
            printf("\n");
            printf("\n");
            printf("Nome do Cliente: ");
            scanf(" %[^\n]", clientes[i].nomeCliente);
            printf("CPF ou CNPJ: ");
            scanf("%s", clientes[i].cpfCNPJ);
            printf("Numero de Telefone: ");
            scanf("%s", clientes[i].numeroTelefone);
            printf("Endereco: ");
            scanf(" %[^\n]", clientes[i].endereco);
            printf("Marca da Impressora: ");
            scanf(" %s", clientes[i].marcaImpressora);
            printf("Modelo da Impressora: ");
            scanf(" %s", clientes[i].modeloImpressora);
            printf("Valor do Aluguel: ");
            scanf(" %f", &clientes[i].valor);
        }
    }
    impressoraAlugada();
}
void encerrarContrato() { // Altera o status do contrato para encerrado
    char busca[20];

    printf("Digite o CPF ou CNPJ desejado: ");
    scanf("%s", busca);
    for(int i = 0; i < num; i++) {
        if(strcmp(busca, clientes[i].cpfCNPJ) == 0) {
            strcpy(clientes[i].status, "Encerrado");
        }
    }
    impressoraAlugada();
}
void manutencao() { // Registra manutenção de impressoras alugadas
    printf("\n");
    printf("Marca: ");
    scanf("%s", atendidas[quant].marca);
    printf("Modelo: ");
    scanf("%s", atendidas[quant].modelo);
    printf("Data Manutencao: ");
    scanf("%s", atendidas[quant].dataManutencao);
    printf("Descricao da Manutencao: ");
    scanf(" %[^\n]", atendidas[quant].descricaoManutencao);
    printf("Categoria(Venda/Alugada): ");
    scanf("%s", atendidas[quant].categoria);
    printf("\n");
    quant++;
    impressoraAlugada();
}
void novaVenda() { // Registra a venda de uma impressora para um cliente
    printf("\n");
    printf("Nome do Cliente: ");
    scanf(" %[^\n]", clientes[num].nomeCliente);
    printf("CPF ou CNPJ: ");
    scanf("%s", clientes[num].cpfCNPJ);
    printf("Numero de Telefone: ");
    scanf("%s", clientes[num].numeroTelefone);
    printf("Endereco: ");
    scanf(" %[^\n]", clientes[num].endereco);
    printf("Marca da Impressora: ");
    scanf(" %s", clientes[num].marcaImpressora);
    printf("Modelo da Impressora: ");
    scanf(" %s", clientes[num].modeloImpressora);
    strcpy(clientes[num].categoria, "venda");
    printf("Valor da Venda: ");
    scanf(" %f", &clientes[num].valor);
    printf("\n");
    num++;
    impressoraCliente();
}
void garantiaImpressora() { // Registra uma solicitação de garantia
    printf("\n");
    printf("Nome do Cliente: ");
    scanf(" %[^\n]", defeitos[val].nome);
    printf("CPF ou CNPJ: ");
    scanf("%s", defeitos[val].cpfCNPJ);
    printf("Marca da Impressora: ");
    scanf(" %s", defeitos[val].marca);
    printf("Modelo da Impressora: ");
    scanf(" %s", defeitos[val].modelo);
    printf("Data da Garantia: ");
    scanf("%s", defeitos[val].dataGarantia);
    val++;
    impressoraCliente();
}
void manutencaoCliente() { // Registra manutenção de impressoras de clientes
    printf("\n");
    printf("Marca: ");
    scanf("%s", atendidas[quant].marca);
    printf("Modelo: ");
    scanf("%s", atendidas[quant].modelo);
    printf("Data Manutencao: ");
    scanf("%s", atendidas[quant].dataManutencao);
    printf("Descricao da Manutencao: ");
    scanf(" %[^\n]", atendidas[quant].descricaoManutencao);
    printf("Categoria(Venda/Alugada): ");
    scanf("%s", atendidas[quant].categoria);
    printf("\n");
    quant++;
    impressoraCliente();
}
void vendaProdutos() { // Registra venda de peças e produtos
    printf("\n");
    printf("CPF ou CNPJ:");
    scanf("%s", vendidos[montante].cpfCNPJ);
    printf("Peca/Produto Vendido:");
    scanf("%s", vendidos[montante].pecaProduto);
    printf("Valor:");
    scanf("%f", &vendidos[montante].valor);
    montante++;
    impressoraCliente();
}
void listarUsuarios() { // Exibe todos os usuários cadastrados
    for(int i = 0; i < id; i++) {
        printf("\n");
        printf("Perfil: %s\n", pessoas[i].perfil);
        printf("Login: %s\n", pessoas[i].login);
        printf("E-mail: %s\n", pessoas[i].email);
        printf("\n");
    }
    gerenciarUsuarios();
}
void alterarUsuarios() { // Atualiza os dados de um usuário
    char busca[20];

    printf("Digite o login desejado: ");
    scanf("%s", busca);
    for(int i = 0; i < id; i++) {
        if(strcmp(busca, pessoas[i].login) == 0) {
            printf("Dados Atuais: \n");
            printf("Perfil: %s\n", pessoas[i].perfil);
            printf("Login: %s\n", pessoas[i].login);
            printf("E-mail: %s\n", pessoas[i].email);
            printf("Senha: %s\n", pessoas[i].senha);
            printf("\n");
            printf("\n");
            printf("Perfil (Admin/Usuario): \n");
            scanf("%s", pessoas[i].perfil);
            printf("Email: \n");
            scanf("%s", pessoas[i].email);
            printf("Login: \n");
            scanf("%s", pessoas[i].login);
            printf("Senha: \n");
            scanf("%s", pessoas[i].senha);
        }
    }
    gerenciarUsuarios();
}
void removerUsuarios() { // Remove um usuário do sistema
    char busca[20];

    printf("Digite o login desejado: ");
    scanf("%s", busca);
    for(int i = 0; i < id; i++) {
        if(strcmp(busca, pessoas[i].login) == 0) {
            for(int j = i; j < id - 1; j++) {
                pessoas[j] = pessoas[j + 1];
            }
            id--;
            break;
        }
    }
    gerenciarUsuarios();
}
void manutencoes() { // Lista todas as manutenções registradas
    for(int i = 0; i < quant; i++) {
        printf("\n");
        printf("Marca: %s\n", atendidas[i].marca);
        printf("Modelo: %s\n", atendidas[i].modelo);
        printf("Data da Manutencao: %s\n", atendidas[i].dataManutencao);
        printf("Descricao da Manutencao: %s\n", atendidas[i].descricaoManutencao);
        printf("Categoria: %s\n", atendidas[i].categoria);
        printf("\n");
    }
    relatorios();
}
void receitaTotal() { // Calcula a receita total de vendas e contratos
    float impressoras = 0;
    float produtos = 0;
    float total = 0;
    for(int i = 0; i < num; i++) {
        impressoras = impressoras + clientes[i].valor;
    }
    for(int j = 0; j < montante; j++) {
        produtos = produtos + vendidos[j].valor;
    }
    total = impressoras + produtos;
    printf("Receita Total: %.2f\n", total);
    relatorios();
}
void totalContratos() { // Conta contratos ativos e encerrados
    int cont = 0;
    int cont2 = 0;
    for(int i = 0; i < num; i++) {
        if(strcmp("aluguel", clientes[i].categoria) == 0) {
            if(strcmp("ativo", clientes[i].status) == 0) {
                cont = cont + 1;
            } else {
                cont2 = cont2 + 1;
            }
        }
    }
    printf("\nTotal contratos em Aberto: %d\n", cont);
    printf("Total contratos Encerrados: %d\n", cont2);
    relatorios();
}
void menuUsuario() { // Menu simplificado para usuários comuns
    int opcao;

    printf("\n");
    printf("\n1-Impressoras Alugadas");
    printf("\n2-Impressoras de Clientes");
    printf("\n0-Voltar Para Menu Inicial");
    printf("\n");
    scanf("%d", &opcao);

    switch(opcao) {
    case 1:
        impressoraAlugada();
        break;
    case 2:
        impressoraCliente();
        break;
    default:
        telaInicial();
    }
}



