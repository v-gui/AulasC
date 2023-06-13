#define ex4
#include <stdio.h>
#include <locale.h>

/*OBS.: Todos os programa devem ser finalizados pelo usuario.*/

#ifdef ex1
/*1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Fa�a uma
    funcao para compara-las usando ponteiros e retorne como resultado se
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
    Imprima o resultado na funcao main(). Declare os vetores como variavel global*/


char a[10], b[10];

int main (void)
{
    setlocale(LC_ALL,"");
    int x,opcao;
    do
    {
        printf("Digite uma string de at� 10 caracteres. \n");
        gets(a);
        printf("Primeira string: %s \n\n", a);
        printf("Digite outra string de at� 10 caracteres. \n");
        gets(b);
        printf("Segunda string: %s \n\n", b);
        x=verifica();
        if(x==0)
        {
            printf("As strings s�o diferentes. \n");
        }
        else
        {
            printf("As strings s�o iguais. \n");
        }
        return 0;


        printf("---------------------------------------------------------\n");
        printf("Deseja fazer outra conta? 1 para Sim e 2 para N�o \n");
        scanf("%d",&opcao);
        if(opcao == 2)
        {
            printf("Fim do programa\n");
        }
    }
    while(opcao == 1);

    return 0;
}
int verifica(int x)
{
    int *pa, *pb;
    pa = &a;
    pb = &b;
    int k;
    for(k=0; pa[k]!= '\0' || pb[k]!='\0'; k++)
    {
        if(pa[k]!=pb[k])
        {
            return (0);
        }
    }
    return (1);
}
#endif // ex1

#ifdef ex2
/*2 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/
char bancodeletras[] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};
int opcao;
int pesquisaletra(char *pletra)
{
    char *ppesquisa = bancodeletras;
    while(*ppesquisa != '\0')
    {
        if(*ppesquisa == *pletra)
        {
            return 1;
        }
        ppesquisa++;
    }
    return 0; // A letra não foi encontrada
}

int main()
{
    setlocale(LC_ALL,"");
    char letra;
    int resultado;
    char *pletra = &letra;
do{
    printf("Digite uma letra: ");
    scanf(" %c",pletra);

    resultado = pesquisaletra(pletra);
    if(resultado)
    {
        printf("A letra foi encontrada. \n");
    }
    else
    {
        printf("A letra não foi encontrada. \n");
    }

    printf("---------------------------------------------------------\n");
    printf("Deseja digitar outra letra? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa\n");
           }
    }while(opcao == 1);
    return 0;
}

#endif // ex2

#ifdef ex3
/*3 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char */



int main (void)
{
    setlocale(LC_ALL,"");

    char *pc,c;
    int *pi,i,opcao;
    long *pl,l;
    float *pfl,fl;
    double *pdb,db;
    unsigned *pu,u;
    unsigned char *puc,uc;
    unsigned long *pul,ul;
    do{

    printf("Digite o char.\n");
    scanf(" %c",&c);
    printf("Digite o int.\n");
    scanf("%d",&i);
    printf("Digite o long.\n");
    scanf("%ld",&l);
    printf("Digite o float.\n");
    scanf("%f",&fl);
    printf("Digite o double.\n");
    scanf("%lf",&db);
    printf("Digite o unsigned .\n");
    scanf("%u",&u);
    printf("Digite o unsigned char.\n");
    getchar();
    scanf("%c",&uc);
    printf("Digite o unsigned long.\n");
    scanf("%lu",&ul);

    pc = &c;
    pi = &i;
    pl = &l;
    pfl = &fl;
    pdb = &db;
    pu = &u;
    puc = &uc;
    pul = &ul;

    printf("        10        20        30        40        50        60\n");
    printf("123456789012345678901234567890123456789012345678901234567890\n");
    printf("%-4s %-19d %-19ld %u \n","",*pi,*pl,*pu);
    printf("%-14s %-19.2f %-19.2lf %c \n\n","",*pfl,*pdb,*pc);
    printf("%-9s %-19lu %c \n","",*pul,*puc);


    printf("---------------------------------------------------------\n");
    printf("Deseja fazer outra conta? 1 para Sim e 2 para N�o \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa\n");
           }
    }while(opcao == 1);

    return 0;

}

#endif // ex3

#ifdef ex4


/*4 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.*/

  int main(void){
   setlocale(LC_ALL,"");
   int num=0, n ,cont, opcao;
   int *pnum, *pn;
   pnum = &num;
   pn = &n;

   do{
        n=0, num=0;
        system("cls");
   printf("Quando o numero digitado for negativo o programa deve parar e \ncalcular a media dos valores positivos digitados.\n\n");
   for(cont=0;*pn>=0;cont++){
   printf("Digite um número: \n");
   scanf("%d", pn);

    if(*pn>=0){
    *pnum+=*pn;}

   else {cont--;}
   }

    printf("A média dos valores positivos é: %d\n\n", *pnum/cont);

    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d", &opcao);
    if(opcao == 2){
    printf("Fim do programa.");
           }
    }while(opcao == 1);

   return 0;
    }


#endif // ex4

#ifdef ex5


/*5 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    	estrutura: dia, mes e ano*/

struct data{
int dia, mes, ano;
};

int main (void){
setlocale(LC_ALL,"");

struct data x[2];
int meses, dias, anos, dnv, i;
int *pm, *pd, *pa;
struct data *px;

px = &x[0];
pm = &meses;
pd = &dias;
pa = &anos;

do{
dias=0;
printf("Insira as datas desejadas para calcular o n�mero de dias entre elas.\n");
printf("Digite a primeira data: \n");

printf("Digite o dia: ");
scanf("%d", &(px+0)->dia);
printf("Digite o m�s: ");
scanf("%d", &(px+0)->mes);
printf("Digite o ano: ");
scanf("%d", &(px+0)->ano);
printf("\n");

printf("Digite a segunda data: \n");

printf("Digite o dia: ");
scanf("%d", &(px+1)->dia);
printf("Digite o m�s: ");
scanf("%d", &(px+1)->mes);
printf("Digite o ano: ");
scanf("%d", &(px+1)->ano);
printf("\n");

    if(px[0].ano>=px[1].ano){
    *pa = px[0].ano - px[1].ano;
      for (i=px[0].ano;i>=px[1].ano;i--){
        if ((i%4==0 && i%100!=0) || i%400==0) {
            (*pd)++;
        }}}

    else{
        *pa = px[1].ano - px[0].ano;
        for (i=px[1].ano;i>=px[0].ano;i--){
        if ((i%4==0 && i%100!=0) || i%400==0) {
            (*pd)++;
        }}}

    if(x[0].mes>x[1].mes){
    *pm = px[0].mes - px[1].mes;
    }

    else{
    *pm = px[1].mes-px[0].mes;
    }

for(i=*pm;i>0;i--){
    if(i==4 || i==6 || i==9 || i==11){
        *pd+=30;
    }
    else if(i==2){
    *pd+=28;
    }
    else{
    *pd+=31;
    }
}
    *pd+= px[0].dia - px[1].dia;
    *pd += *pa * 365;

 printf("Existem %d dias entre as datas inseridas. \n\n", *pd);

printf("Deseja fazer o c�lculo novamente?\n Digite 1 para Sim e 2 para N�o. \n");
scanf("%d",& dnv);
system("cls");
}while(dnv==1);

return(0);
}

#endif // ex5

#ifdef ex6


/*6 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop.
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep*/


struct pessoa
{
    char nome[50], end[50], cidade[20], estado[20], cep[10];
};
struct pessoa x[4];
int i=0;
int main (void){
setlocale(LC_ALL,"");
int opcao;

struct pessoa *px;

px = &x;


do{
            printf("\t\tMENU:\n");
            printf("\t1- Inserir dados de uma pessoa.\n");
            printf("\t2- Imprime todos os dados salvos.\n");
            printf("\t3- Sair.\n");
            printf("\n\tOp��o: ");
            scanf("%d", &opcao);
            printf("----------------------------------------------------\n");
switch(opcao)
        {
        case 1: recebe(px);
                break;

        case 2: imprime(px);
                break;

        case 3: printf("Saindo do programa...\n");
                return(0);

        default: printf("Op��o inv�lida, tente novamente: \n");
        }
}while(opcao!=3);
}

recebe(struct pessoa px[]){
                if(i<4){
                printf("Entre com os seguintes dados: \n\n");
                printf("Nome completo: \n");
                getchar();
                gets(px[i].nome);
                printf("Endere�o: \n");
                gets(px[i].end);
                printf("Cidade: \n");
                gets(px[i].cidade);
                printf("Estado: \n");
                gets(px[i].estado);
                printf("CEP: \n");
                gets(px[i].cep);
                i++;}
                else{
                printf("Todos os dados j� est�o completos. \n");
                printf("----------------------------------------------------\n");
                }
}
imprime(struct pessoa px[]){
int j;
if(i>0){
for(j = 0; j < i ; j++){
                printf("Dados da pessoa: %d\n", j+1);
                printf("Nome:  %s\n",px[j].nome);
                printf("Endere�o: %s\n",px[j].end);
                printf("Cidade: %s\n",px[j].cidade);
                printf("Estado: %s\n",px[j].estado);
                printf("CEP: %s\n",px[j].cep);
                printf("----------------------------------------------------\n");
                }
      }
if(i==0){
    printf("      Ainda n�o h� nenhum dado informado.\n");
    printf("----------------------------------------------------\n");
}
}


#endif // ex6
