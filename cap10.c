#define ex4
#include "stdio.h"
#include <locale.h>
#include <stdlib.h>
#include <string.h>


//OBS.: Todos os programas devem ser finalizados pelo usuario.

#ifdef ex1

/* 1 - Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
    Receba via teclado diversos caracteres (um por vezes) e escreva-os
    nesse arquivo. O caracter '0' finaliza a entrada de dados. Abra o arquivo
    "arq.txt", leia e imprima na tela todos os caracteres armazenados no
    arquivo (um por vezes). */

int main (void){
setlocale(LC_ALL,"");

    FILE *pont;
    char ent;
    int cont,z,dnv;
do{
    cont=0;
    z=0;

    if((pont=fopen("arq.txt","w"))==NULL)
    {
        printf("Erro de abertura de arquivo. \n");
        exit(0);
    }
    printf("Digite um caracter por vez, e digite 0 para finalizar a entrada de dados. \n");
    for(z=0;;z++)
    {
      scanf("%c",&ent);
      getchar();
      printf("entrada: %c\n",ent);
      if(ent=='0')
        break;
      putc(ent,pont);
      cont++;
    }
    printf("\n");
    printf("Todos os caracteres: ");
    fclose(pont);
    if((pont=fopen("arq.txt","r"))==NULL)
    {
        printf("Erro de abertura de arquivo. \n");
        exit(0);
    }
    z=0;
   while(z!=cont)
    {
        putchar(getc(pont));
        z++;
    }
    printf("\n");
    fclose(pont);

    printf("\nDigite 1 para sair ou 2 para continuar\n");
    scanf("%d",&dnv);
    getchar();
    system("cls");

}while(dnv!=1);
}

#endif

#ifdef ex2

/*2 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
    dados. Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na
    funcao main(). Utilize ponteiros para passar o vetor de estrutura para
    as funcoes. Sempre que o programa for encerrado, os contatos devem ser
    escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
    do arquivo.
    O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)
    1 - inserir contato
    2 - listar todos os contatos
    3 - pesquisar um contato pelo nome
    4 - listar os contatos cujo nome inicia com uma letra digitada
    5 - imprimir os aniversariantes do mês.
    6 - altera contato
    7 - exclui contato
    8 - saida */

#define cont_max 4

struct Contato {
    char nome[50];
    char telefone[15];
    int dia_aniversario;
    int mes_aniversario;
};

void listarContatos(struct Contato *agenda) {
    printf("Lista de contatos:\n");
    printf("\n----------------------------------------------\n");
    for (int i = 0; i < cont_max; i++) {
        if (agenda[i].nome[0] != '\0') {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Aniversário: %d/%d\n", agenda[i].dia_aniversario, agenda[i].mes_aniversario);
            printf("\n----------------------------------------------\n");
        }
    }
}

void pesquisarContato(struct Contato *agenda, char *nome) {
    int encontrado = 0;
    printf("Pesquisando contato por nome: %s\n", nome);
    for (int i = 0; i < cont_max; i++) {
        int j = 0;
        while (agenda[i].nome[j] != '\0' && nome[j] != '\0' && agenda[i].nome[j] == nome[j]) {
            j++;
        }
        if (agenda[i].nome[j] == '\0' && nome[j] == '\0') {
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Aniversário: %d/%d\n", agenda[i].dia_aniversario, agenda[i].mes_aniversario);
            printf("\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

void listarPorLetra(struct Contato *agenda, char letra) {
    printf("Listando contatos com nome iniciado por: %c\n", letra);
    int encontrado = 0;
    for (int i = 0; i < cont_max; i++) {
        if (agenda[i].nome[0] != '\0' && agenda[i].nome[0] == letra) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Aniversário: %d/%d\n", agenda[i].dia_aniversario, agenda[i].mes_aniversario);
            printf("\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum contato encontrado com nome iniciado por: %c\n", letra);
    }
}

void listarAniversariantes(struct Contato *agenda, int mes) {
    printf("\n----------------------------------------------\n");
    printf("Listando aniversariantes do mês: %d\n\n", mes);
    int encontrado = 0;
    for (int i = 0; i < cont_max; i++) {
        if (agenda[i].nome[0] != '\0' && agenda[i].mes_aniversario == mes) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Aniversário: %d/%d\n", agenda[i].dia_aniversario, agenda[i].mes_aniversario);
            printf("\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum aniversariante encontrado no mês: %d\n", mes);
    }
}

void inserirContato(struct Contato *agenda) {
    int posicao = -1;
    for (int i = 0; i < cont_max; i++) {
        if (agenda[i].nome[0] == '\0') {
            posicao = i;
            break;
        }
    }
    if (posicao != -1) {
        printf("Inserir novo contato na posição: %d\n", posicao + 1);
        printf("Nome: ");
        scanf("%s", agenda[posicao].nome);
        printf("Telefone: ");
        scanf("%s", agenda[posicao].telefone);
        printf("Dia do aniversário: ");
        scanf("%d", &agenda[posicao].dia_aniversario);
        printf("Mês do aniversário: ");
        scanf("%d", &agenda[posicao].mes_aniversario);
        printf("Contato inserido com sucesso.\n");
    } else {
        printf("Agenda de contatos está cheia. Não é possível inserir mais contatos.\n");
    }
}

void alterarContato(struct Contato *agenda, char *nome) {
    int encontrado = 0;
    printf("Alterar contato com nome: %s\n", nome);
    for (int i = 0; i < cont_max; i++) {
        int j = 0;
        while (agenda[i].nome[j] != '\0' && nome[j] != '\0' && agenda[i].nome[j] == nome[j]) {
            j++;
        }
        if (agenda[i].nome[j] == '\0' && nome[j] == '\0') {
            printf("Contato encontrado. Insira os novos dados:\n");
            printf("Nome: ");
            scanf("%s", agenda[i].nome);
            printf("Telefone: ");
            scanf("%s", agenda[i].telefone);
            printf("Dia do aniversário: ");
            scanf("%d", &agenda[i].dia_aniversario);
            printf("Mês do aniversário: ");
            scanf("%d", &agenda[i].mes_aniversario);
            printf("Contato alterado com sucesso.\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

void excluirContato(struct Contato *agenda, char *nome) {
    int encontrado = 0;
    printf("Excluir contato com nome: %s\n", nome);
    for (int i = 0; i < cont_max; i++) {
        int j = 0;
        while (agenda[i].nome[j] != '\0' && nome[j] != '\0' && agenda[i].nome[j] == nome[j]) {
            j++;
        }
        if (agenda[i].nome[j] == '\0' && nome[j] == '\0') {
            printf("Contato encontrado. Deseja realmente excluir? (s/n): ");
            char opcao;
            scanf(" %c", &opcao);
            if (opcao == 's' || opcao == 'S') {
                agenda[i].nome[0] = '\0';
                agenda[i].telefone[0] = '\0';
                agenda[i].dia_aniversario = 0;
                agenda[i].mes_aniversario = 0;
                printf("Contato excluído com sucesso.\n");
            } else {
                printf("Operação de exclusão cancelada.\n");
            }
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

int main() {
    setlocale(LC_ALL,"");
    struct Contato agenda[cont_max] = {0};

    FILE *arquivo;
    arquivo = fopen("contatos.txt", "r");
    if (arquivo != NULL) {
        fread(agenda, sizeof(struct Contato), cont_max, arquivo);
        fclose(arquivo);
    }

    int opcao;
    char nome[50];
    char letra;
    int mes;

    do {
        printf("Selecione uma opção:\n");
        printf("1 - Inserir contato\n");
        printf("2 - Listar todos os contatos\n");
        printf("3 - Pesquisar um contato pelo nome\n");
        printf("4 - Listar os contatos cujo nome inicia com uma letra digitada\n");
        printf("5 - Imprimir os aniversariantes do mês\n");
        printf("6 - Alterar contato\n");
        printf("7 - Excluir contato\n");
        printf("8 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirContato(agenda);
                break;
            case 2:
                listarContatos(agenda);
                break;
            case 3:
                printf("Digite o nome a ser pesquisado: ");
                scanf("%s", nome);
                pesquisarContato(agenda, nome);
                break;
            case 4:
                printf("Digite a letra inicial: ");
                scanf(" %c", &letra);
                listarPorLetra(agenda, letra);
                break;
            case 5:
                printf("Digite o mês: ");
                scanf("%d", &mes);
                listarAniversariantes(agenda, mes);
                break;
            case 6:
                printf("Digite o nome do contato a ser alterado: ");
                scanf("%s", nome);
                alterarContato(agenda, nome);
                break;
            case 7:
                printf("Digite o nome do contato a ser excluído: ");
                scanf("%s", nome);
                excluirContato(agenda, nome);
                break;
            case 8:
                sair();
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        printf("\n");
    } while (opcao != 8);

    return 0;
}

#endif // ex2

#ifdef ex3

/*3 - Escreva um programa para controle de um cadastro de clientes. Para cada
    registro sera' armazenado nome, email e celular numa estrutura de dados.
    A unica estrutura de dados e' uma variavel LOCAL na funcao main().
    Escreva os registros direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros para
    passar parametros para as funcoes.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui registros
    2 - listar todos os registros
    3 - pesquisar registro pelo nome
    4 - altera registro
    5 - exclui registro
    6 - saida */

struct Cliente {
    char nome[50];
    char email[50];
    char celular[20];
};

int main() {
    struct Cliente clientes;
    struct Cliente *pclientes = &clientes;
    setlocale(LC_ALL,"");
    int opcao;

    do {
        printf("|----------------------------------------------|\n");
        printf("|          Selecione uma opção:                |\n");
        printf("|      1 - Incluir registro                    |\n");
        printf("|      2 - Listar todos os registros           |\n");
        printf("|      3 - Pesquisar registro pelo nome        |\n");
        printf("|      4 - Alterar registro                    |\n");
        printf("|      5 - Excluir registro                    |\n");
        printf("|      6 - Sair                                |\n");
        printf("|          Opção:                              |\n");
        printf("|----------------------------------------------|\n");
        scanf("%d", &opcao);


        switch (opcao) {
            case 1:
                incluirRegistro(pclientes);
                break;
            case 2:
                listarRegistros(pclientes);
                break;
            case 3:
                pesquisarRegistro(pclientes);
                break;
            case 4:
                alterarRegistro(pclientes);
                break;
            case 5:
                excluirRegistro(pclientes);
                break;
            case 6:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        printf("\n");
    } while (opcao != 6);

}

void incluirRegistro(struct Cliente *pclientes) {

    FILE *arquivo = fopen("clientes.dat", "r+");
    if (arquivo == NULL) {
        arquivo = fopen("clientes.dat", "w");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo de clientes.\n");
            return 1;
        }
    }

    printf("Incluir novo registro\n");
    printf("Nome: ");
    scanf("%s", pclientes->nome);
    printf("Email: ");
    scanf("%s", pclientes->email);
    printf("Celular: ");
    scanf("%s", pclientes->celular);

    fwrite(pclientes, sizeof(struct Cliente), 1, arquivo);

    printf("Registro incluído com sucesso.\n");

    fclose(arquivo);

    return;
}

void listarRegistros(struct Cliente *pclientes) {
    FILE *arquivo = fopen("clientes.dat", "r+");

    printf("Listar todos os registros\n");

    fseek(arquivo, 0, SEEK_SET);
    if (pclientes->nome != '\0' && pclientes->nome[0] != '*')
            {
    while (fread(pclientes, sizeof(struct Cliente), 1, arquivo) == 1) {
        printf("\n-----------------------------------\n");
        printf("Nome: %s\n", pclientes->nome);
        printf("Email: %s\n", pclientes->email);
        printf("Celular: %s\n", pclientes->celular);
        printf("\n");
    }}
}

void pesquisarRegistro(struct Cliente *pclientes) {

    FILE *arquivo = fopen("clientes.dat", "r+");
    char nome[50];
    printf("Digite o nome a ser pesquisado: ");
    scanf("%s", nome);
    printf("Pesquisar registro pelo nome: %s\n", pclientes->nome);

    int encontrado = 0;



    fseek(arquivo, 0, SEEK_SET);
    while (fread(pclientes, sizeof(struct Cliente), 1, arquivo) == 1) {
        int i = 0;
        while (pclientes->nome[i] != '\0' && nome[i] != '\0' && pclientes->nome[i] == nome[i]) {
            i++;
        }
        if (pclientes->nome[i] == '\0' && nome[i] == '\0') {
            printf("\n-----------------------------------\n");
            printf("Nome: %s\n", pclientes->nome);
            printf("Email: %s\n", pclientes->email);
            printf("Celular: %s\n", pclientes->celular);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Registro não encontrado.\n");
    }
}

void alterarRegistro(struct Cliente *pclientes) {
    FILE *arquivo = fopen("clientes.dat", "r+");
    char xnome[50];
    printf("Digite o nome do registro a ser alterado: ");
    scanf("%s", xnome);
    printf("Alterar registro com nome: %s\n", pclientes->nome);

    int encontrado = 0;



    fseek(arquivo, 0, SEEK_SET);
    while (fread(pclientes, sizeof(struct Cliente), 1, arquivo) == 1) {
        int i = 0;
        while (pclientes->nome[i] != '\0' && xnome[i] != '\0' && pclientes->nome[i] == xnome[i]) {
            i++;
        }
        if (pclientes->nome[i] == '\0' && xnome[i] == '\0') {
            printf("\n-----------------------------------\n");
            printf("Registro encontrado. Insira os novos dados:\n");
            printf("Nome: ");
            scanf("%s", pclientes->nome);
            printf("Email: ");
            scanf("%s", pclientes->email);
            printf("Celular: ");
            scanf("%s", pclientes->celular);

            fseek(arquivo, -sizeof(struct Cliente), SEEK_CUR);
            fwrite(pclientes, sizeof(struct Cliente), 1, arquivo);
            printf("Registro alterado com sucesso.\n");

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Registro não encontrado.\n");
    }
    fclose(arquivo);
}

void excluirRegistro(struct Cliente *pclientes) {

    FILE *arquivo = fopen("clientes.dat", "r+");
    char xnome[50];
    printf("Digite o nome do registro a ser excluído: ");
    scanf("%s", xnome);
    printf("Excluir registro com nome: %s\n", xnome);

    int encontrado = 0;

 int i;
    for (i = 0; i < sizeof(xnome); i++)
    {
        if (xnome[i] == '\n')
        {
            xnome[i] = '\0';
            break;
        }
    }

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    else
    {
        while (fread(pclientes, sizeof(struct Cliente), 1, arquivo) == 1)
        {
            int j;
            int match = 1;

            for(j = 0; xnome[j] != '\0'; j++)
            {
                if (xnome[j] != pclientes->nome[j])
                {
                    match = 0;
                    break;
                }
            }
            if(match && pclientes->nome[j] == '\0')
            {
                encontrado = 1;

                printf("~~~~~~~~~~~~~~~~\n");
                pclientes->nome[0] = '*';

                fseek(arquivo, -sizeof(struct Cliente), SEEK_CUR);
                fwrite(pclientes, sizeof(struct Cliente), 1, arquivo);
                break;
            }
        }

        if (!encontrado)
        {
            printf("Registro não encontrado.\n");
        }

        fclose(arquivo);
    }
}

void sair(){

    FILE *arquivo = fopen("clientes.dat", "r+");

        fclose(arquivo);

        printf("Encerrando o programa.\n");

    return 0;
}


#endif // ex3

#ifdef ex4

/*4 - Escreva um programa para o controle de mercadorias em uma dispensa
    domestica. Para cada produto sera' armazenado um codigo numerico, nome
    do produto e quantidade atual numa estrutura de dados. A unica estrutura
    de dados deve ser declarada como variavel LOCAL na funcao main(). Escreva
    os itens das mercadorias direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui produtos
    2 - listar todos os produtos
    3 - pesquisar uma mercadoria pela descrição
    4 - listar os produtos não disponíveis.
    5 - alterar a quantidade atual
    6 - altera produtos
    7 - exclui produtos
    8 - saida */

FILE*qwe;

struct Produto
{
    int codigo;
    char nome[50];
    int qtd;
};
int cont;

int main(void)
{
    setlocale(LC_ALL,"");
    struct Produto produtos;
    struct Produto *pproduto = &produtos;
    int opcao;

    do
    {
        printf("------------------------------------------------------------------------------------\n");
        printf("\n-- Menu de Opções --\n");
        printf("1 - Incluir produtos\n");
        printf("2 - Listar todos os produtos\n");
        printf("3 - Pesquisar uma mercadoria pela descrição\n");
        printf("4 - Listar os produtos não disponíveis\n");
        printf("5 - Alterar a quantidade atual\n");
        printf("6 - Alterar produto\n");
        printf("7 - Excluir produto\n");
        printf("8 - Sair\n");
        printf("------------------------------------------------------------------------------------\n");
        printf("Digite a opção desejada: ");
        scanf("%d",&opcao);
        getchar();
        switch(opcao)
        {

        case 1:
            entrada(pproduto);
            break;

        case 2:
            listar_dados(pproduto);
            break;

        case 3:
            pesquisar_nome(pproduto);
            break;

        case 4:
            listar_zerados(pproduto);
            break;

        case 5:
            alterar_qtd(pproduto);
            break;

        case 6:
            alterar_dados(pproduto);
            break;

        case 7:
            excluir_dados(pproduto);
            break;

        case 8:
            printf("Fechando o programa! ");
            exit(0);
        }

    }
    while(opcao!=8);
}

void entrada(struct Produto *pproduto)
{

    FILE *qwe;

    qwe = fopen("prod.txt", "a");

    printf("Digite o código do produto: ");
    scanf("%d", &pproduto->codigo);
    getchar();
    printf("Digite o nome do produto: ");
    gets(pproduto->nome);
    printf("Digite a quantidade: ");
    scanf("%d", &pproduto->qtd);

    printf("\n");

    fwrite(pproduto, sizeof(struct Produto), 1, qwe);

    printf("Produto registrado com sucesso! \n");
    cont++;
    fclose(qwe);

    return;
}

void listar_dados(struct Produto *pproduto)
{

    FILE *qwe;

    qwe=fopen("prod.txt","r");

    int conteudo;

    if (qwe == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    else
    {
        conteudo=fread(pproduto, sizeof(struct Produto), 1, qwe);
        fseek(qwe, 0, 0);

        if(conteudo == 0)
        {
            printf("Não possui dados!, insira-os primeiro! \n");
            return;
        }

        while(1)
        {

            conteudo=fread(pproduto, sizeof(struct Produto), 1, qwe);

            if(conteudo == 0)
            {
                break;
            }

            if (pproduto->nome != '\0' && pproduto->nome[0] != '*')
            {
                printf("~~~~~~~~~~~~~~~~\n");
                printf("Código: %d\nNome: %s\nQuantidade: %d\n", pproduto->codigo, pproduto->nome, pproduto->qtd);

            }
        }
    }
}


int pesquisar_nome(struct Produto *pproduto)
{

    FILE*qwe;
    int encontrado = 0;
    char pesquisa[30];
    qwe = fopen("prod.txt", "r");

    printf("Digite o nome do produto que você deseja procurar: \n");
    fgets(pesquisa, sizeof(pesquisa), stdin);

    int i;
    for (i = 0; i < sizeof(pesquisa); i++)
    {
        if (pesquisa[i] == '\n')
        {
            pesquisa[i] = '\0';
            break;
        }
    }

    if (qwe == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }
    else
    {
        while (fread(pproduto, sizeof(struct Produto), 1, qwe) == 1)
        {
            int j;
            int match = 1;

            for(j=0; pesquisa[j] != '\0'; j++)
            {
                if (pesquisa[j] != pproduto->nome[j])
                {
                    match = 0;
                    break;
                }
            }
            if(match && pproduto->nome[j] == '\0')
            {
                printf("~~~~~~~~~~~~~~~~\n");
                printf("\tProduto encontrado! \n");
                printf("Código: %d\n", pproduto->codigo);
                printf("Nome: %s\n", pproduto->nome);
                printf("Quantidade Atual: %d\n", pproduto->qtd);
                encontrado = 1;

            }
        }

        if (!encontrado)
        {
            printf("Nenhum produto encontrado com esse nome.\n");
        }

        fclose(qwe);
    }
}

void alterar_qtd(struct Produto *pproduto)
{
    FILE *qwe;
    int encontrado = 0;
    char pesquisa[30];
    qwe = fopen("prod.txt", "r+");

    printf("Digite o nome do produto que você quer alterar a quantidade: \n");
    fgets(pesquisa, sizeof(pesquisa), stdin);

    int i;
    for (i = 0; i < sizeof(pesquisa); i++)
    {
        if (pesquisa[i] == '\n')
        {
            pesquisa[i] = '\0';
            break;
        }
    }

    if (qwe == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    else
    {
        while (fread(pproduto, sizeof(struct Produto), 1, qwe) == 1)
        {
            int j;
            int match = 1;

            for(j = 0; pesquisa[j] != '\0'; j++)
            {
                if (pesquisa[j] != pproduto->nome[j])
                {
                    match = 0;
                    break;
                }
            }
            if(match && pproduto->nome[j] == '\0')
            {
                printf("~~~~~~~~~~~~~~~~\n");
                printf("Produto encontrado! \n");
                printf("Quantidade Atual: %d\n", pproduto->qtd);

                encontrado = 1;

                printf("~~~~~~~~~~~~~~~~\n");
                printf("Digite a nova quantidade: ");
                scanf("%d", &(pproduto->qtd));

                fseek(qwe, -sizeof(struct Produto), SEEK_CUR);
                fwrite(pproduto, sizeof(struct Produto), 1, qwe);
                break;
            }
        }

        if (!encontrado)
        {
            printf("Nenhum produto encontrado com esse nome.\n");
        }

        fclose(qwe);
    }
}


void alterar_dados(struct Produto *pproduto)
{
    FILE *qwe;
    int encontrado = 0;
    char pesquisa[30];
    qwe = fopen("prod.txt", "r+");

    printf("Digite o nome do produto que você quer alterar: \n");
    fgets(pesquisa, sizeof(pesquisa), stdin);

    int i;
    for (i = 0; i < sizeof(pesquisa); i++)
    {
        if (pesquisa[i] == '\n')
        {
            pesquisa[i] = '\0';
            break;
        }
    }

    if (qwe == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    else
    {
        while (fread(pproduto, sizeof(struct Produto), 1, qwe) == 1)
        {
            int j;
            int match = 1;

            for(j = 0; pesquisa[j] != '\0'; j++)
            {
                if (pesquisa[j] != pproduto->nome[j])
                {
                    match = 0;
                    break;
                }
            }
            if(match && pproduto->nome[j] == '\0')
            {
                encontrado = 1;

                // Solicitar novos dados
                printf("~~~~~~~~~~~~~~~~\n");
                printf("Digite o novo código: ");
                scanf("%d", &(pproduto->codigo));
                getchar();
                printf("Digite o nome do novo produto: ");
                gets(pproduto->nome);
                printf("Digite a quantidade: ");
                scanf("%d", &(pproduto->qtd));
                printf("\n");

                // Atualizar a quantidade no arquivo
                fseek(qwe, -sizeof(struct Produto), SEEK_CUR);
                fwrite(pproduto, sizeof(struct Produto), 1, qwe);
                break;
            }
        }

        if (!encontrado)
        {
            printf("Nenhum produto encontrado com esse nome.\n");
        }

        fclose(qwe);
    }
}

void excluir_dados(struct Produto *pproduto){

 FILE *qwe = fopen("prod.txt", "r+");

    char xnome[50];
    printf("Digite o nome do produto a ser excluído: ");
    scanf("%s", xnome);
    printf("Excluir produto com nome: %s\n", xnome);

    int encontrado = 0;

 int i;
    for (i = 0; i < sizeof(xnome); i++)
    {
        if (xnome[i] == '\n')
        {
            xnome[i] = '\0';
            break;
        }
    }

    if (qwe == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    else
    {
        while (fread(pproduto, sizeof(struct Produto), 1, qwe) == 1)
        {
            int j;
            int match = 1;

            for(j = 0; xnome[j] != '\0'; j++)
            {
                if (xnome[j] != pproduto->nome[j])
                {
                    match = 0;
                    break;
                }
            }
            if(match && pproduto->nome[j] == '\0')
            {
                encontrado = 1;

                printf("~~~~~~~~~~~~~~~~\n");
                pproduto->nome[0] = '*';

                fseek(qwe, -sizeof(struct Produto), SEEK_CUR);
                fwrite(pproduto, sizeof(struct Produto), 1, qwe);
                break;
            }
        }

        if (!encontrado)
        {
            printf("Registro não encontrado.\n");
        }

        fclose(qwe);
    }
}

void listar_zerados(struct Produto *pproduto){

 FILE *qwe;

    qwe=fopen("prod.txt","r");

    int conteudo;
    int encontrado = 0;

    if (qwe == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    else
    {
        conteudo=fread(pproduto, sizeof(struct Produto), 1, qwe);
        fseek(qwe, 0, 0);

        if(conteudo == 0)
        {
            printf("Não possui dados!, insira-os primeiro! \n");
            return;
        }

        while(1)
        {
            conteudo=fread(pproduto, sizeof(struct Produto), 1, qwe);

            if(conteudo == 0)
            {
                break;
            }

            if (pproduto->qtd == 0) {
            printf("\n");
            printf("Código: %d\n", pproduto->codigo);
            printf("Nome: %s\n", pproduto->nome);
            printf("Quantidade Atual: %d\n\n", pproduto->qtd);
            encontrado = 1;
        }
        }
    }
if (!encontrado) {
    printf("Nenhum produto indisponível encontrado.\n");
    }
}


#endif // ex4
