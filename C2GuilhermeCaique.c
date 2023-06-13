#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

FILE*Trab;

struct livro
{
    char livro[30];
    char autor[30];
    int qtd;
    float preco;
};

int main(void)
{
    setlocale(LC_ALL,"");
    struct livro livraria;
    struct livro *plivraria = &livraria;
    int opcao;
    do
    {
        printf("------------------------------------------------------------------------------------\n");
        printf("\t\t\t---- Menu de Opções ----\n");
        printf("\t1 - Incluir Livros: \n");
        printf("\t2 - Listar todos os Livros: \n");
        printf("\t3 - Pesquisar um livro (Pelo nome completo)\n");
        printf("\t4 - Pesquisar autor (Pelo nome completo)\n");
        printf("\t5 - Pesquisar livro por faixa de preço: \n");
        printf("\t6 - Alterar a quantidade (Entrada e saída, pesquisado pelo nome completo)\n");
        printf("\t7 - Alterar o preço do livro: (Pesquisa nome completo) \n");
        printf("\t8 - Alterar dados: (Pesquisa nome completo) \n");
        printf("\t9 - Excluir dados: (Pesquisa nome completo) \n");
        printf("\t10 - Sair\n\n");
        printf("------------------------------------------------------------------------------------\n");
        scanf("%d",&opcao);
        getchar();
        switch(opcao)
        {

        case 1:
            entrada(plivraria);
            break;

        case 2:
            listar_dados(plivraria);
            break;

        case 3:
            pesquisar_livro(plivraria);
            break;

        case 4:
            pesquisar_autor(plivraria);
            break;

        case 5:
            pesquisar_preco(plivraria);
            break;

        case 6:
            alterar_qtd(plivraria);
            break;

        case 7:
            alterar_preco(plivraria);
            break;

        case 8:
            alterar_dados(plivraria);
            break;

        case 9:
            excluir_dados(plivraria);
            break;

        case 10:
            printf("Fechando o programa! ");
            exit(0);

        }

    }
    while(opcao!=10);
}

void entrada(struct livro *livraria)
{

    FILE *Trab;

    Trab = fopen("data.txt", "a");

    printf("Digite o nome do livro: ");
    gets(livraria->livro);
    printf("Digite o nome do autor: ");
    gets(livraria->autor);
    printf("Digite a quantidade: ");
    scanf("%d", &livraria->qtd);
    printf("Preço do livro: ");
    scanf("%f", &livraria->preco);
    printf("\n");

    fwrite(livraria, sizeof(struct livro), 1, Trab);

    printf("Itens registrados com sucesso! \n");

    fclose(Trab);

    return;
}

void listar_dados(struct livro *livraria)
{

    FILE *Trab;

    Trab=fopen("data.txt","r");

    int conteudo;

    if (Trab == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    else
    {
        conteudo=fread(livraria, sizeof(struct livro), 1, Trab);
        fseek(Trab, 0, 0);

        if(conteudo == 0)
        {
            printf("Não possui dados!, insira-os primeiro! \n");
            return;
        }

        while(1)
        {

            conteudo=fread(livraria, sizeof(struct livro), 1, Trab);

            if(conteudo == 0)
            {
                break;
            }

            if (livraria->livro != '\0' && livraria->livro[0] != '*')
            {
                printf("~~~~~~~~~~~~~~~~\n");
                printf("Livro: %s\nAutor: %s\nQuantidade: %d\nPreço: R$ %.2f\n", livraria->livro, livraria->autor, livraria->qtd, livraria->preco);

            }
        }
    }
}


int pesquisar_livro(struct livro *livraria)
{

    FILE*Trab;
    int encontrado = 0;
    char pesquisaLivro[30];
    Trab = fopen("data.txt", "r");

    printf("Digite o nome completo do livro que voce quer procurar: \n");
    fgets(pesquisaLivro, sizeof(pesquisaLivro), stdin);

    // Remover a quebra de linha do final da string
    int i;
    for (i = 0; i < sizeof(pesquisaLivro); i++)
    {
        if (pesquisaLivro[i] == '\n')
        {
            pesquisaLivro[i] = '\0';
            break;
        }
    }

    if (Trab == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }
    else
    {
        while (fread(livraria, sizeof(struct livro), 1, Trab) == 1)
        {
            int j;
            int match = 1;

            for(j=0; pesquisaLivro[j] != '\0'; j++)
            {
                if (pesquisaLivro[j] != livraria->livro[j])
                {
                    match = 0;
                    break;
                }
            }
            if(match && livraria->livro[j] == '\0')
            {
                printf("~~~~~~~~~~~~~~~~\n");
                printf("\tLivro encontrado! \n");
                printf("Livro: %s\n", livraria->livro);
                printf("Autor: %s\n", livraria->autor);
                printf("Quantidade Atual: %d\n", livraria->qtd);
                printf("Preço do Livro: %.2f\n", livraria->preco);
                encontrado = 1;

            }
        }

        if (!encontrado)
        {
            printf("Nenhum livro encontrado com esse nome.\n");
        }

        fclose(Trab);
    }
}

void pesquisar_autor(struct livro *livraria)
{

    FILE*Trab;
    int encontrado = 0;
    char pesquisaAutor[30];
    Trab = fopen("data.txt", "r");

    printf("Digite o nome completo do autor que voce quer procurar: \n");
    fgets(pesquisaAutor, sizeof(pesquisaAutor), stdin);

    // Remover a quebra de linha do final da string
    int i;
    for (i = 0; i < sizeof(pesquisaAutor); i++)
    {
        if (pesquisaAutor[i] == '\n')
        {
            pesquisaAutor[i] = '\0';
            break;
        }
    }

    if (Trab == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }
    else
    {
        while (fread(livraria, sizeof(struct livro), 1, Trab) == 1)
        {
            int j;
            int match = 1;

            for(j=0; pesquisaAutor[j] != '\0'; j++)
            {
                if (pesquisaAutor[j] != livraria->autor[j])
                {
                    match = 0;
                    break;
                }
            }
            if(match && livraria->autor[j] == '\0')
            {
                printf("~~~~~~~~~~~~~~~~\n");
                printf("\tAutor encontrado! \n");
                printf("Livro: %s\n", livraria->livro);
                printf("Autor: %s\n", livraria->autor);
                printf("Quantidade Atual: %d\n", livraria->qtd);
                printf("Preço do Livro: %.2f\n", livraria->preco);
                encontrado = 1;

            }
        }

        if (!encontrado)
        {
            printf("Nenhum autor encontrado com esse nome.\n");
        }

        fclose(Trab);
    }
}

void pesquisar_preco(struct livro *livraria)
{

    FILE *Trab;
    float preco_min,preco_max;
    int conteudo = 0;
    Trab = fopen("data.txt","r");

    if (Trab == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    else
    {
        printf("Digite o valor minimo do preco do livro que deseja pesquisar: R$ ");
        scanf("%f", &preco_min);

        printf("Digite o valor maximo do preco do livro que deseja pesquisar: R$ ");
        scanf("%f", &preco_max);
        conteudo=fread(livraria, sizeof(struct livro), 1, Trab);
        fseek(Trab,0,0);
        if(conteudo ==0)
        {
            printf("Não possui dados!, insira-os primeiro! \n");
            return;
        }

        while(1)
        {
            conteudo=fread(livraria, sizeof(struct livro), 1, Trab);

            if(conteudo == 0)
            {
                break;
            }


            if (livraria->preco>=preco_min && livraria->preco<=preco_max)
            {
                printf("~~~~~~~~~~~~~~~~\n");
                printf("\tLivro encontrado! \n");
                printf("Livro: %s\n", livraria->livro);
                printf("Autor: %s\n", livraria->autor);
                printf("Quantidade Atual: %d\n", livraria->qtd);
                printf("Preço do Livro: %.2f\n", livraria->preco);
                conteudo = 1;
            }
        }
    }
}

void alterar_qtd(struct livro *livraria)
{
    FILE *Trab;
    int encontrado = 0;
    char pesquisaLivro[30];
    Trab = fopen("data.txt", "r+");

    printf("Digite o nome completo do livro que você quer alterar a quantidade: \n");
    fgets(pesquisaLivro, sizeof(pesquisaLivro), stdin);

    int i;
    for (i = 0; i < sizeof(pesquisaLivro); i++)
    {
        if (pesquisaLivro[i] == '\n')
        {
            pesquisaLivro[i] = '\0';
            break;
        }
    }

    if (Trab == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    else
    {
        while (fread(livraria, sizeof(struct livro), 1, Trab) == 1)
        {
            int j;
            int match = 1;

            for(j = 0; pesquisaLivro[j] != '\0'; j++)
            {
                if (pesquisaLivro[j] != livraria->livro[j])
                {
                    match = 0;
                    break;
                }
            }
            if(match && livraria->livro[j] == '\0')
            {
                printf("~~~~~~~~~~~~~~~~\n");
                printf("Livro encontrado! \n");
                printf("Quantidade Atual: %d\n", livraria->qtd);

                encontrado = 1;

                // Solicitar nova quantidade
                printf("~~~~~~~~~~~~~~~~\n");
                printf("Digite a nova quantidade: ");
                scanf("%d", &(livraria->qtd));

                // Atualizar a quantidade no arquivo
                fseek(Trab, -sizeof(struct livro), SEEK_CUR);
                fwrite(livraria, sizeof(struct livro), 1, Trab);
                break;
            }
        }

        if (!encontrado)
        {
            printf("Nenhum livro encontrado com esse nome.\n");
        }

        fclose(Trab);
    }
}

void alterar_preco(struct livro *livraria)
{
    FILE *Trab;
    int encontrado = 0;
    char pesquisaLivro[30];
    Trab = fopen("data.txt", "r+");

    printf("Digite o nome completo do livro que você quer alterar o preço: \n");
    fgets(pesquisaLivro, sizeof(pesquisaLivro), stdin);

    int i;
    for (i = 0; i < sizeof(pesquisaLivro); i++)
    {
        if (pesquisaLivro[i] == '\n')
        {
            pesquisaLivro[i] = '\0';
            break;
        }
    }

    if (Trab == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    else
    {
        while (fread(livraria, sizeof(struct livro), 1, Trab) == 1)
        {
            int j;
            int match = 1;

            for(j = 0; pesquisaLivro[j] != '\0'; j++)
            {
                if (pesquisaLivro[j] != livraria->livro[j])
                {
                    match = 0;
                    break;
                }
            }
            if(match && livraria->livro[j] == '\0')
            {
                printf("~~~~~~~~~~~~~~~~\n");
                printf("Livro encontrado! \n");
                printf("Preço do Livro: %.2f\n", livraria->preco);
                encontrado = 1;

                // Solicitar novo preço
                printf("~~~~~~~~~~~~~~~~\n");
                printf("Digite o novo preço: ");
                scanf("%f", &(livraria->preco));

                // Atualizar a quantidade no arquivo
                fseek(Trab, -sizeof(struct livro), SEEK_CUR);
                fwrite(livraria, sizeof(struct livro), 1, Trab);
                break;
            }
        }

        if (!encontrado)
        {
            printf("Nenhum livro encontrado com esse nome.\n");
        }

        fclose(Trab);
    }
}

void alterar_dados(struct livro *livraria)
{
    FILE *Trab;
    int encontrado = 0;
    char pesquisaLivro[30];
    Trab = fopen("data.txt", "r+");

    printf("Digite o nome completo do livro que você quer alterar: \n");
    fgets(pesquisaLivro, sizeof(pesquisaLivro), stdin);

    int i;
    for (i = 0; i < sizeof(pesquisaLivro); i++)
    {
        if (pesquisaLivro[i] == '\n')
        {
            pesquisaLivro[i] = '\0';
            break;
        }
    }

    if (Trab == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    else
    {
        while (fread(livraria, sizeof(struct livro), 1, Trab) == 1)
        {
            int j;
            int match = 1;

            for(j = 0; pesquisaLivro[j] != '\0'; j++)
            {
                if (pesquisaLivro[j] != livraria->livro[j])
                {
                    match = 0;
                    break;
                }
            }
            if(match && livraria->livro[j] == '\0')
            {
                encontrado = 1;

                // Solicitar novos dados
                printf("~~~~~~~~~~~~~~~~\n");
                printf("Digite o nome do novo livro: ");
                gets(livraria->livro);
                printf("Digite o nome do novo autor: ");
                gets(livraria->autor);
                printf("Digite a quantidade: ");
                scanf("%d", &(livraria->qtd));
                printf("Preço do livro: ");
                scanf("%f", &(livraria->preco));
                printf("\n");

                // Atualizar a quantidade no arquivo
                fseek(Trab, -sizeof(struct livro), SEEK_CUR);
                fwrite(livraria, sizeof(struct livro), 1, Trab);
                break;
            }
        }

        if (!encontrado)
        {
            printf("Nenhum livro encontrado com esse nome.\n");
        }

        fclose(Trab);
    }
}

void excluir_dados(struct livro *livraria)
{
    FILE *Trab;
    int encontrado = 0;
    char pesquisaLivro[30];
    Trab = fopen("data.txt", "r+");

    printf("Digite o nome completo do livro que você quer excluir: \n");
    fgets(pesquisaLivro, sizeof(pesquisaLivro), stdin);

    int i;
    for (i = 0; i < sizeof(pesquisaLivro); i++)
    {
        if (pesquisaLivro[i] == '\n')
        {
            pesquisaLivro[i] = '\0';
            break;
        }
    }

    if (Trab == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    else
    {
        while (fread(livraria, sizeof(struct livro), 1, Trab) == 1)
        {
            int j;
            int match = 1;

            for(j = 0; pesquisaLivro[j] != '\0'; j++)
            {
                if (pesquisaLivro[j] != livraria->livro[j])
                {
                    match = 0;
                    break;
                }
            }
            if(match && livraria->livro[j] == '\0')
            {
                encontrado = 1;

                // Excluindo os dados
                printf("~~~~~~~~~~~~~~~~\n");
                livraria->livro[0] = '*';

                // Atualizar a quantidade no arquivo
                fseek(Trab, -sizeof(struct livro), SEEK_CUR);
                fwrite(livraria, sizeof(struct livro), 1, Trab);
                break;
            }
        }

        if (!encontrado)
        {
            printf("Nenhum livro encontrado com esse nome.\n");
        }

        fclose(Trab);
    }
}

