#define ex1
#include "stdio.h"
#include <locale.h>

#ifdef ex1
/*1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video, em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int, unsigned long
            10        20        30        40        50        60        70
    1234\567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long */

struct estrutura
{
    char c;
    int i;
    long l;
    float fl;
    double db;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
};

void recebe(struct estrutura y[]);
void imprime(struct estrutura y[]);

int main(void)
{
    setlocale(LC_ALL,"");
    int opcao;
    do
    {
        struct estrutura y[8];
        recebe(y);
        imprime(y);
    printf("---------------------------------------------------------\n");
    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa\n");
           }
    }while(opcao==1);
    return 0;
}
void recebe(struct estrutura y[])
{


        printf("Digite o char.\n");
        scanf(" %c", &y[0].c);
        printf("Digite o int.\n");
        scanf("%d", &y[0].i);
        printf("Digite o long.\n");
        scanf("%ld", &y[0].l);
        printf("Digite o float.\n");
        scanf("%f", &y[0].fl);
        printf("Digite o double.\n");
        scanf("%lf", &y[0].db);
        printf("Digite o unsigned char.\n");

        scanf(" %c", &y[0].uc);
        printf("Digite o unsigned int.\n");
        scanf("%u", &y[0].ui);
        printf("Digite o unsigned long.\n");
        scanf("%lu",&y[0].ul);
    }
    void imprime(struct estrutura y[])
    {

        printf("        10        20        30        40        50        60        70\n");
        printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
        printf("%-4c %-8c %-9d %-19ld %-19.2f %.2lf \n","",y[0].c,y[0].i,y[0].l,y[0].fl,y[0].db);
        printf("%-10c %-19c %-19u %lu \n\n","",y[0].uc,y[0].ui,y[0].ul);

    }

#endif

#ifdef ex2
/*2 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de estruturas de 4 elementos.
Receba os dados pelo teclado em uma funcao e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Faça um menu com uma opcao para saida do programa. estrutura: nome, end, cidade, estado, cep */

   struct pessoa{
        char nome[50], end[50], cidade[20], estado[20], cep[10];
        };
  int i=0;
int main (void){
setlocale(LC_ALL,"");
int opcao;
struct pessoa x[4];

do{
            printf("\t\tMENU:\n");
            printf("\t1- Inserir dados de uma pessoa.\n");
            printf("\t2- Imprime todos os dados salvos.\n");
            printf("\t3- Sair.\n");
            printf("\n\tOpção: ");
            scanf("%d", &opcao);
            printf("----------------------------------------------------\n");
switch(opcao)
        {
        case 1: recebe(x);
                break;

        case 2: imprime(x);
                break;

        case 3: printf("Saindo do programa...\n");
                return(0);

        default: printf("Opção inválida, tente novamente: \n");
        }
}while(opcao!=3);
}

void recebe(struct pessoa x[]){
                if(i<4){
                printf("Entre com os seguintes dados: \n\n");
                printf("Nome completo: \n");
                getchar();
                gets(x[i].nome);
                printf("Endereço: \n");
                gets(x[i].end);
                printf("Cidade: \n");
                gets(x[i].cidade);
                printf("Estado: \n");
                gets(x[i].estado);
                printf("CEP: \n");
                gets(x[i].cep);
                i++;}
                else{
                printf("Todos os dados já estão completos. \n");
                printf("----------------------------------------------------\n");
                }
}
void imprime(struct pessoa x[]){
int j;
if(i>0){
for(j = 0; j < i ; j++){
                printf("Dados da pessoa: %d\n", j+1);
                printf("Nome:  %s\n",x[j].nome);
                printf("Endereço: %s\n",x[j].end);
                printf("Cidade: %s\n",x[j].cidade);
                printf("Estado: %s\n",x[j].estado);
                printf("CEP: %s\n",x[j].cep);
                printf("----------------------------------------------------\n");
                }
      }
if(i==0){
    printf("      Ainda não há nenhum dado informado.\n");
    printf("----------------------------------------------------\n");
}
}


#endif // ex2

#ifdef ex3
/*3 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faça um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados
    3 - calcula o IMC de todas as pessoas.
    4 - sair                              ||  Calculo do IMC = peso/(altura*altura). estrutura: nome, peso, altura */


        struct imc{
        float peso;
        float altura;
        char nome[20];
        };



        int main (void){
        setlocale(LC_ALL,"");
        struct imc ideal[4];
        int opcao,i=0,j;
        float imcresu;
        do{
            printf("\t\tMENU:\n");
            printf("\t1- Receber todos os dados.\n");
            printf("\t2- Imprime todos os dados.\n");
            printf("\t3- Calcula o IMC de todas as pessoas.\n");
            printf("\t4- Sair.\n");
            scanf("%d", &opcao);


        switch(opcao)
        {
        case 1: printf("Entre com os dados para o calculo do IMC. \n");
                printf("Altura em metros.\n");
                scanf("%f",&ideal[i].altura);
                printf("Peso em kg\n");
                scanf("%f",&ideal[i].peso);
                printf("Nome por extenso\n");
                getchar();
                gets(ideal[i].nome);
                i++;
                break;

        case 2: for(j = 0; j < i ; j++){
                printf("Altura = %.2fm\n",ideal[j].altura);
                printf("Peso = %.2fkg\n",ideal[j].peso);
                printf("Nome = %s\n",ideal[j].nome);
                printf("---------------------\n");
                }
                break;
        case 3: for(j = 0; j < i ; j++){
                imcresu=ideal[j].peso/(ideal[j].altura*ideal[j].altura);
                printf("Resultado do IMC é: %.2f\n",imcresu);
                }
                break;

        case 4: return(0);
        }

        }while(opcao!=4);

        }


#endif // ex3

#ifdef ex4
/*4 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias
    entre elas e mostre o resultado no video na funcao main().
    Utilize vetor de estruturas.
                estrutura: dia, mes, ano */

struct data{
int dia, mes, ano;
};

int main (void){
setlocale(LC_ALL,"");

struct data x[2];
int meses, dias, anos, dnv, i;

do{
dias=0;
printf("Insira as datas desejadas para calcular o número de dias entre elas.\n");
printf("Digite a primeira data: \n");

printf("Digite o dia: \n");
scanf("%d", &x[0].dia);
printf("Digite o mês: \n");
scanf("%d", &x[0].mes);
printf("Digite o ano: \n");
scanf("%d", &x[0].ano);
printf("\n");

printf("Digite a segunda data: \n");

printf("Digite o dia: \n");
scanf("%d", &x[1].dia);
printf("Digite o mês: \n");
scanf("%d", &x[1].mes);
printf("Digite o ano: \n");
scanf("%d", &x[1].ano);
printf("\n");

    if(x[0].ano>=x[1].ano){
    anos = x[0].ano - x[1].ano;
      for (i=x[0].ano;i>=x[1].ano;i--){
        if ((i%4==0 && i%100!=0) || i%400==0) {
            dias++;
        }}}

    else{
        anos = x[1].ano - x[0].ano;
        for (i=x[1].ano;i>=x[0].ano;i--){
        if ((i%4==0 && i%100!=0) || i%400==0) {
            dias++;
        }}}

    if(x[0].mes>x[1].mes){
    meses = x[0].mes - x[1].mes;
    }

    else{
    meses = x[1].mes-x[0].mes;
    }

for(i=meses;i>0;i--){
    if(i==4 || i==6 || i==9 || i==11){
        dias+=30;
    }
    else if(i==2){
    dias+=28;
    }
    else{
    dias+=31;
    }
}
    dias+= x[0].dia - x[1].dia;
    dias+= anos*365;

 printf(" Existem %d dias entre as datas inseridas. \n", dias);

printf("Deseja fazer o cálculo novamente?\n Digite 1 para Sim e 2 para Não. \n");
scanf("%d",& dnv);
system("cls");
}while(dnv==1);

return(0);
}

#endif // ex4
