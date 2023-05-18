#define ex2
#include <stdio.h>
#include <locale.h>

#ifdef ex1

 /* 1 - Escreva um programa que receba via teclado um tempo em segundos e converta para horas, minutos e segundos.*/

    int main(void)
    {
    setlocale(LC_ALL,"");
    int hora,min,seg,s,opcao;
    do{
    printf("Digite a quantidade de segundos que deseja converter para horas, minutos e segundos.\n");

    scanf("%d",&s);

    hora= s/3600;
    min= (s%3600/60);
    seg=(s%60);

    printf("%d hr, %d min e %d segundos.\n",hora,min,seg);

    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }
    }while(opcao==1);

    return 0;
    }
#endif

#ifdef ex2

/* 2 - Escreva um programa que receba dados via teclado para variaveis do tipo short,long, int, float, double e um char e imprima-os no video no seguinte  formato:
   10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
              short               long                int
                   float               double              char*/
#include <stdio.h>

int main(void) {
    setlocale(LC_ALL,"");
    short s;
    long l;
    int i,opcao;
    float f;
    double d;
    char c;

    do{
    printf("Digite um valor do tipo short: ");
    scanf("%hd", &s);
    printf("Digite um valor do tipo long: ");
    scanf("%ld", &l);
    printf("Digite um valor do tipo int: ");
    scanf("%d", &i);
    printf("Digite um valor do tipo float: ");
    scanf("%f", &f);
    printf("Digite um valor do tipo double: ");
    scanf("%lf", &d);
    printf("Digite um valor do tipo char: ");
    scanf(" %c", &c);
    printf("10        20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");
    printf("%-9c %-19hd %-20ld%-20d%\n","",s,l,i);
    printf("%-14c %-19.1f %-19.1lf %-20c\n","",f,d,c);

    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }
    }while(opcao==1);

    return 0;
}

#endif // ex2 Não completo

#ifdef ex3

/* 3 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via teclado. */


    int main(void){
   setlocale(LC_ALL,"");

    int num,lim,res,opcao;

    do{
    printf("Selecione um número para efetuar a conta. \n");
    scanf("%d",&num);
    printf("Selecione o limite para o parametro da conta. \n");
    scanf("%d",&lim);

    res+=num;

    while(res< lim)
    {
    res+=num;
    }

    printf("O menor múltiplo de %d maior que %d é: %d\n", num, lim, res);

    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }
    }while(opcao==1);

    return 0;
    }
#endif

#ifdef ex4

/* 4 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma variável auxiliar. */
    int main(void){
    setlocale(LC_ALL,"");
    int a,b,opcao;

    do{
    printf("Insira o valor de A: \n");
    scanf("%d",& a);
    printf("Insira o valor de B: \n");
    scanf("%d",& b);

    a=a+b;
    b = a-b;
    a=a-b;

    printf("O valor de A é %d\nO valor de B é %d", a, b);

    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }
    }while(opcao==1);

    return 0;
    }
#endif //

#ifdef ex5
/* 5 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar outro número formado pelos dígitos invertidos do número lido.
    Ex:   NúmeroLido = 123 // NúmeroGerado = 321 */

    int main(void){
    setlocale(LC_ALL,"");
    int a, b, c, n1,opcao;
    do{
    do{
    printf("Insira o número desejado para inversão:\n");
    scanf("%d", &n1);

    if(n1<100 || n1>999){
    printf("Dados inválidos, tente novamente.\n");
    }
    } while(n1<100 || n1>999);

    = n1/100;
    b = n1/10%10;
    c = n1%10;

    printf("O número inverso é: %d%d%d\n", c, b, a);

    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }
    }while(opcao==1);

    return 0;
    }

#endif // ex5
