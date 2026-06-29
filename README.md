Sistema de Gestão de Impressoras

Sistema em linguagem C para gerenciamento de impressoras alugadas e impressoras de clientes, desenvolvido como trabalho final da disciplina de Fundamentos de Algoritmos e Programação / Laboratório de Programação.

O projeto foi inspirado no fluxo de atendimento real de uma empresa de assistência técnica de impressoras, separando os dois tipos de operação que existem na prática: equipamentos da própria frota (alugados) e equipamentos de clientes externos (assistência técnica).

Funcionalidades

Acesso ao sistema


Cadastro de usuário no primeiro acesso
Login com validação de credenciais
Dois perfis de acesso: Admin e Usuário


Impressoras Alugadas


Cadastro de novo contrato de aluguel
Alteração de contrato existente
Encerramento de contrato
Registro de manutenção


Impressoras de Clientes


Registro de venda de impressora
Abertura de garantia
Registro de manutenção
Venda de peças e produtos (tinta, toner, etc.)


Gerenciamento de Usuários (exclusivo Admin)


Listagem de usuários cadastrados
Alteração de dados de usuário
Remoção de usuário


Relatórios (exclusivo Admin)


Listagem de manutenções realizadas
Receita total (contratos + vendas)
Total de contratos ativos e encerrados


Estrutura do projeto

O sistema é construído em torno de cinco structs principais:

StructFinalidadeUsuarioDados de login e perfil de acessoCadastroContratos de aluguel e vendas de impressorasChamadoRegistros de manutenção técnicaGarantiaSolicitações de garantiaProdutosVendas de peças e insumos

Cada entidade é armazenada em um vetor estático, com um contador de registros correspondente.

Conceitos aplicados


Modularização com funções e protótipos
Estruturas de dados (struct)
Vetores e contadores de controle
Laços de repetição (for, while, do-while)
Estruturas condicionais (if, switch case)
Manipulação de strings (strcmp, strcpy)
Controle de acesso por perfil de usuário
Persistência de dados em arquivo (fopen, fprintf, fscanf)
