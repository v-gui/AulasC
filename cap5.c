#include <stdio.h>
#include <locale.h>
#define ex1

#ifdef ex1

/*1 - Receba 2 string de ate 10 caracteres via teclado na funcao main().
Faça uma funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
(Declare os vetores como variavel global) */

// Variavel Global.
char f[11],k[11];

int main(void)
{
    setlocale(LC_ALL,"");
    int cont,x,opcao;
    do{
    printf("Digite a string número 1. \n");
    scanf("%s",f);
    printf("Digite a string número 2. \n");
    scanf("%s",k);
    x=comparar();

    if(x == 1)
    {
        printf("As strings são iguais. \n");
    }
    else
    {

        printf("As strings são diferentes. \n");
    }

    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }
    }while(opcao==1);

    return 0;
}
int comparar()
{
    int cont;

    for(cont=0; f[cont]!='\0' || k[cont]!='\0'; cont++)
    {

        if(f[cont]!=k[cont])

            return(0);

    }
    return(1);

}


#endif // ex1

#ifdef ex2

/*2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis globais).
            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4

                         nome3 */

  //Variavel global
char nome1[7],nome2[7],nome3[7],nome4[7],nome5[7];


int main(void)
{
    setlocale(LC_ALL,"");
    int cont,opcao;
    do
    {
        printf("Digite os 5 nomes desejados.\n");
        scanf(" %s", &nome1);
        scanf(" %s", &nome2);
        scanf(" %s", &nome3);
        scanf(" %s", &nome4);
        scanf(" %s", &nome5);

        printf("        10        20        30        40        50\n");
        printf("12345678901234567890123456789012345678901234567890\n");
        printf("%-3s %-40s %-8s \n", nome1,"",nome5);
        printf("%-12s %-20s %-17s \n","",nome2,nome4);
        printf("%-21s %-28s \n","",nome3);
        printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
        scanf("%d",&opcao);
        if(opcao == 2)
        {
            printf("Fim do programa");
        }
    }
    while(opcao==1);

    return 0;
}
#endif // ex2

#ifdef ex3
/* 3 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres para letras maiusculas. */


int main(void)
{
    setlocale(LC_ALL,"");
    char c[11];
    int cont,opcao;
    do
    {
        printf("Digite algo em letra minuscula para converter os caracteres para letras maiusculas.\n");
        scanf("%s",&c);

        for(cont=0; c[cont]!='\0'; cont++)
        {

            if (c[cont] >= 'a' && c[cont] <= 'z')
                c[cont] -= 32;

        }
        printf("%s",c);
        printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
        scanf("%d",&opcao);
        if(opcao == 2)
        {
            printf("Fim do programa");
        }
    }
    while(opcao==1);

    return 0;
}


#endif // ex3

#ifdef ex4

/*4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres para letras minusculas. */

int main(void)
{
    setlocale(LC_ALL,"");
    char c[11];
    int cont,opcao;
    do{
    printf("Digite algo em letra maiusculas para converter os caracteres para letras minuscula.\n");
    scanf("%s",&c);

    for(cont=0; c[cont]!='\0'; cont++)
    {

        if (c[cont] >= 'A' && c[cont] <= 'Z')
            c[cont] += 32;

    }
    printf("%s",c);

    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }
    }while(opcao==1);

    return 0;
}



#endif // ex4

#ifdef ex5

/*5 - Escreva um programa que receba uma string na funcao main(). Faca uma funcao que calcula o comprimento de uma string recebida via teclado.
Mostre o valor do comprimento na funcao main().
(Declare o vetor como variavel global). */
char str[];
int main(void){
setlocale(LC_ALL,"");
int cont,comp;
do{
printf("Digite uma string. \n");
scanf("%s",str);

for(cont=0;str[cont]!='\0';cont++){

comp=cont;
}

printf("O comprimento da string é %d \n", cont);

printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }
    }while(opcao==1);
}

#endif // ex5
