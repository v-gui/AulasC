

//poderia ter usado a opcao 3 para as opcoes 5 e 6
//opcao 3 nao mostra o autor
//opcao 2 mostra "buraco" no livro apagado





#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

FILE*Trab;
char livro1[20],livro2[20],livro3[20];
char autor1[20],autor2[20],autor3[20];

int main(void){
setlocale(LC_ALL,"");
int opcao;
do {
        printf("------------------------------------------------------------------------------------------------------------------------\n");
printf("\t\t\t\t                            | Menu |\n");
printf("\t\t\t\t |   1 – Entrada de dados.                                       |\n");
printf("\t\t\t\t |   2 – Lista todos os dados na tela.                           |\n");
printf("\t\t\t\t |   3 – Pesquisa um livro com o nome completo e mostra na tela. |\n");
printf("\t\t\t\t |   4 – Pesquisa autor pela 1° letra e mostra todos na tela.    |\n");
printf("\t\t\t\t |   5 – Altera dados. Pesquisa pelo livro completo.             |\n");
printf("\t\t\t\t |   6 – Exclui dados. Pesquisa pelo livro completo.             |\n");
printf("\t\t\t\t |   7 - Saída.                                                  |\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
scanf("%d",&opcao);

switch(opcao){

    case 1:
            entrada(Trab);
            break;
    case 2:
            lista_dados(Trab);
            break;
    case 3:
            pesquisalivro(Trab);
            break;

    case 4:
            pesquisaautor(Trab);
            break;

    case 5:
            alteradados(Trab);
            break;

    case 6:
            excluirdados(Trab);
            break;

    case 7:
            exit(0);

            }

}while(opcao!=7);
}

void entrada(FILE*Trab){

    Trab = fopen("Trab.txt", "w");

    printf("Digite o nome do 1° livro: \n");
    // dois gets pois o primeiro é automaticamente pulado ?
    gets(livro1);
    gets(livro1);
    printf("Digite o nome do 1° autor : \n");
    gets(autor1);
    printf("Digite o nome do 2° livro: \n");
    gets(livro2);
    printf("Digite o nome do 2° autor : \n");
    gets(autor2);
    printf("Digite o nome do 3° livro: \n");
    gets(livro3);
    printf("Digite o nome do 3° autor : \n");
    gets(autor3);

    salvardados(Trab);
        }

void lista_dados(FILE*Trab){

        lerdados(Trab);

        if(livro1[20]!='0'){
            printf("\t 1° Livro: %s |  Autor: %s\n", livro1, autor1);
            }
        if(livro2[20]!='0'){
            printf("\t 2° Livro: %s |  Autor: %s\n", livro2, autor2);
            }
        if(livro3[20]!='0'){
            printf("\t 3° Livro: %s |  Autor: %s\n", livro3, autor3);
            }
            else {
                printf("\t Nenhum livro cadastrado.\n");
            }

    fclose(Trab);
                }

void pesquisalivro(FILE*Trab){

    char pesquisalivro[20];
    int cont, i=0;

    Trab = fopen("Trab.txt", "r");

        fread(livro1, sizeof(livro1), 1, Trab);
        fread(autor1, sizeof(autor1), 1, Trab);

        fread(livro2, sizeof(livro2), 1, Trab);
        fread(autor2, sizeof(autor2), 1, Trab);

        fread(livro3, sizeof(livro3), 1, Trab);
        fread(autor3, sizeof(autor3), 1, Trab);

        printf("\t Digite o nome completo do livro que voce quer procurar. \n");
        gets(pesquisalivro);
        gets(pesquisalivro);


       for(cont = 0; pesquisalivro[cont] != '\0' ; cont++){

            if (pesquisalivro[cont] != livro1[cont])
        {

            break;
        }
    }

        if(pesquisalivro[cont] == '\0' && livro1[cont] == '\0')
        {
            printf("\tLivro encontrado: %s \n", pesquisalivro);
            i=1;
        }
        // ---------------------------------------------------------------
        for(cont = 0; pesquisalivro[cont] != '\0' ; cont++){

            if (pesquisalivro[cont] != livro2[cont])
        {

            break;
        }
    }

        if(pesquisalivro[cont] == '\0' && livro2[cont] == '\0')
        {
            printf("\tLivro encontrado: %s \n", pesquisalivro);
            i=1;
        }
         // ---------------------------------------------------------------
         for(cont = 0; pesquisalivro[cont] != '\0' ; cont++){

            if (pesquisalivro[cont] != livro3[cont])
        {

            break;
        }
    }

        if(pesquisalivro[cont] == '\0' && livro3[cont] == '\0')
        {
            printf("\tLivro encontrado: %s \n", pesquisalivro);
            i=1;
        }

        if(i == 0){
            printf("O livro procurado não foi encontrado. \n");
        }

        fclose(Trab);
}

void pesquisaautor(FILE*Trab){

    char letra[20];
    int cont, i=0;

    lerdados(Trab);

    printf("\t Digite a primeira letra do nome do autor.\n");
    scanf(" %c",&letra);

            if(letra[0] != autor1[0]){
                        i=0;
        }

            if(letra[0] != autor2[0]){
                       i=0;
        }

            if(letra[0] != autor3[0]){
                        i=0;
        }

            if(letra[0] == autor1[0]){
                printf("\t Autor: %s \n",autor1);
                i=1;
            }
            if(letra[0] == autor2[0]){
                printf("\t Autor: %s \n",autor2);
                i=1;
            }
            if(letra[0] == autor3[0]){
                printf("\t Autor: %s \n",autor3);
                i=1;
            }
            if(i == 0){
                printf("\tNão encontrei este autor no sistema, certifique-se que usou a letra maiscula pois se trata de um nome próprio.\n");
            }

    fclose(Trab);
}

void excluirdados(FILE*Trab){

char excluirdados[20];
int i=0, cont;

       lerdados(Trab);

        printf("\tQual livro você deseja excluir? Digite o nome completo do livro. \n");
        gets(excluirdados);
        gets(excluirdados);


         for(cont = 0; excluirdados[cont] != '\0' ; cont++){

            if (excluirdados[cont] != livro1[cont])
        {

            break;
        }}

        if(excluirdados[cont] == '\0' && livro1[cont] == '\0')
        {
            printf("Dados do 1° livro apagados.\n");

            Trab = fopen("Trab.txt", "w");

        for (int j = 0; j < 20; j++)
        {
            livro1[j] = '*';
        }

        for (int j = 0; j < 20; j++)
        {
            autor1[j] = '*';
        }
            i = 1;
        }
// -------------------------------------------------------------------------
        for(cont = 0; excluirdados[cont] != '\0' ; cont++){

            if (excluirdados[cont] != livro2[cont])
        {

            break;
        }}

        if(excluirdados[cont] == '\0' && livro2[cont] == '\0')
        {
            printf("Dados do 2° livro apagados.\n");

            Trab = fopen("Trab.txt", "w");

        for (int j = 0; j < 20; j++)
        {
            livro2[j] = '*';
        }

        for (int j = 0; j < 20; j++)
        {
            autor2[j] = '*';
        }
            i = 1;
        }

        // ---------------------------------------------------------------
         for(cont = 0; excluirdados[cont] != '\0' ; cont++){

            if (excluirdados[cont] != livro3[cont])
        {

            break;
        }}

        if(excluirdados[cont] == '\0' && livro3[cont] == '\0')
        {
            printf("Dados do 3° livro apagados.\n");

            Trab = fopen("Trab.txt", "w");

        for (int j = 0; j < 20; j++)
        {
            livro3[j] = '*';
        }

        for (int j = 0; j < 20; j++)
        {
            autor3[j] = '*';
        }
            i = 1;
        }

        salvardados(Trab);
}

void alteradados(FILE*Trab){

 char pesquisalivro[20];
    int cont, i=0;

    lerdados(Trab);
        printf("\t Qual nome do livro que voce quer procurar? \n");
        gets(pesquisalivro);
        gets(pesquisalivro);

       for(cont = 0; pesquisalivro[cont] != '\0' ; cont++){

            if (pesquisalivro[cont] != livro1[cont])
        {

            break;
        }
    }

        if(pesquisalivro[cont] == '\0' && livro1[cont] == '\0')
        {
            printf("Livro encontrado: %s \n", pesquisalivro);
            i=1;
            printf("Insira o novo nome do Livro: \n");
            gets(livro1);
            printf("Insira o novo nome do Autor: \n");
            gets(autor1);
            printf("Dados alterados com sucesso! \n\n");
        }
        // ---------------------------------------------------------------
        for(cont = 0; pesquisalivro[cont] != '\0' ; cont++){

            if (pesquisalivro[cont] != livro2[cont])
        {

            break;
        }
    }

        if(pesquisalivro[cont] == '\0' && livro2[cont] == '\0')
        {
            printf("Livro encontrado: %s \n", pesquisalivro);
            i=1;
            printf("Insira o novo nome do Livro: \n");
            gets(livro2);
            printf("Insira o novo nome do Autor: \n");
            gets(autor2);
            printf("Dados alterados com sucesso! \n\n");
        }
         // ---------------------------------------------------------------
         for(cont = 0; pesquisalivro[cont] != '\0' ; cont++){

            if (pesquisalivro[cont] != livro3[cont])
        {

            break;
        }
    }

        if(pesquisalivro[cont] == '\0' && livro3[cont] == '\0')
        {
            printf("Livro encontrado: %s \n", pesquisalivro);
            i=1;
            printf("Insira o novo nome do Livro: \n");
            gets(livro3);
            printf("Insira o novo nome do Autor: \n");
            gets(autor3);
            printf("Dados alterados com sucesso! \n\n");
        }

        if(i == 0){
            printf("O livro procurado não foi encontrado. \n");
        }

    Trab = fopen("Trab.txt", "w");

    salvardados(Trab);
}

void lerdados(FILE*Trab){

        Trab = fopen("Trab.txt", "r");

        fread(&livro1, sizeof(livro1), 1, Trab);
        fread(&autor1, sizeof(autor1), 1, Trab);
        fread(&livro2, sizeof(livro2), 1, Trab);
        fread(&autor2, sizeof(autor2), 1, Trab);
        fread(&livro3, sizeof(livro3), 1, Trab);
        fread(&autor3, sizeof(autor3), 1, Trab);

}


void salvardados(FILE*Trab){

    fwrite(livro1, sizeof(livro1), 1, Trab);
    fwrite(autor1, sizeof(autor1), 1, Trab);
    fwrite(livro2, sizeof(livro2), 1, Trab);
    fwrite(autor2, sizeof(autor2), 1, Trab);
    fwrite(livro3, sizeof(livro3), 1, Trab);
    fwrite(autor3, sizeof(autor3), 1, Trab);


    fclose(Trab);
}

