#define ex5
#include <stdio.h>
#include <locale.h>

#ifdef ex1
/*1 - Escreva um programa que receba dois numeros inteiros e execute as seguintes
    funçoes:
    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
      retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
      eles.
    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
      entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.*/



int main(void)
{
    setlocale(LC_ALL,"");
    int n1, n2, opcao;

    do
    {

        printf("Insira o primeiro número inteiro: \n");
        scanf("%d", &n1);

        printf("Insira o segundo número inteiro: \n");
        scanf("%d", &n2);
        printf("Os números escolhidos foram: %d, %d \n", n1, n2);

        positivos(n1, n2);
        negativos(n1, n2);
        restante(n1, n2);

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

int verifica(int a)
{
    if(a<0)
    {
        return (0);
    }
    if(a==0)
    {
        return (-1);
    }
    else
    {
        return (1);
    }
} // fim verifica

int positivos(int s1, int s2)
{

    int b, x, y, mini, maxi, soma=0;

    x=verifica(s1);
    y=verifica(s2);


    if(x==1 && y==1)
    {

        if(s1>s2)
        {
            maxi=s1;
            mini=s2;
        }
        if(s2>s1)
        {
            maxi=s2;
            mini=s1;
        }

        for(b=mini+1; b<maxi; b++)
        {
            soma+=b;
        }
        printf(" A soma dos números existentes entre eles é: %d \n", soma);
    }
} // fim positivos

int negativos(int m1, int m2)
{

    int b, x, y, mini, maxi, mult=1;

    x=verifica(m1);
    y=verifica(m2);


    if(x==0 && y==0)
    {

        if(m1>m2)
        {
            maxi=m1;
            mini=m2;
        }
        if(m2>m1)
        {
            maxi=m2;
            mini=m1;
        }
        for(b=mini+1; b<maxi; b++)
        {
            mult*=b;
        }
        printf(" A multiplicação dos números existentes entre eles é: %d \n", mult);
    }
}// fim negativos

int restante(int r1, int r2)
{

    int x, y;
    float div;

    x=verifica(r1);
    y=verifica(r2);
    div=r1/r2;

    if(x==1 && y==0 || x==0 && y==1)
    {
        printf("A divisão dos números inseridos é: %d \n", r1/r2);
    }
}



#endif

    #ifdef ex2
/* 2 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao que retorne a soma dos algarismos do resultado de N!.
 O resultado deve ser mostrado na funcao main().
Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6. ----- seperar os numeros com /10, % resto */


int main(void)
{
    setlocale(LC_ALL,"");
    int num,fat,z, opcao;
    do
    {
        printf("Escreva um número aleatório \n");
        scanf("%d",&num);

        for(fat = 1; num > 1; num = num - 1)
        {
            fat = fat * num;
        }

        z= soma(fat);
        printf("\nFatorial calculado: %d", fat);
        printf("\nSoma dos números do fatorial é: %d \n",z);

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
int soma(int num)
{
    int z = 0;
    while (num > 0)
    {
        z += num % 10;
        num /= 10;
    }
    return z;

}
    #endif // ex2

    #ifdef ex3

    /* 3 - Escreva um programa que receba na funcao main() 2 valores inteiro.
    Escreva uma funcao para cada operacoes aritmeticas e passe como parametro os 2 valores recebidos na funcao main().
    Retorne os resultados usando o comando return e imprima os 4 resultados no video na funcao main(). */

int main(void)
{
    setlocale(LC_ALL,"");
    int n1,n2,opcao;
    do
    {
        printf("Digite o primeiro número:\n");
        scanf("%d",&n1);
        printf("Digite o segundo número:\n");
        scanf("%d",&n2);
        soma(n1,n2);
        subtract(n1,n2);
        multiplica(n1,n2);
        divide(n1,n2);

        printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
        scanf("%d",&opcao);
        if(opcao == 2)
        {
            printf("Fim do programa");
        }
    }
    while(opcao==1);
}
soma(int n1,int n2)
{
    int som;
    som= n1+n2;
    printf("A soma dos dois números é: %d\n",som);
    return(som);
}
subtract(int n1,int n2)
{
    int sub;
    sub= n1-n2;
    printf("A subtração dos dois números é: %d\n",sub);
    return(sub);
}

multiplica(int n1, int n2)
{
    int multi;
    multi= n1*n2;
    printf("A multiplicação dos dois números é: %d\n",multi);
    return(multi);
}
divide(int n1, int n2)
{
    float div;
    div= (float)n1/n2;
    printf("A divisão dos dois números é: %.2f\n",div);
    return(div);
}
    #endif // ex3

    #ifdef ex4
    /* 4 - Reescreva o programa do exercicio anterior para receber via teclado n valores. Os n valores nao sao definidos previamente. */



int main(void)
{
    setlocale(LC_ALL,"");
    int n, quant, soma, sub, mult, cont, div, opcao;

    do
    {
        soma=0, sub=0, mult=1, cont=0, div=1;
        do
        {
            printf("Digite a quantidade de números desejada: \n");
            scanf("%d", &quant);
            if(quant<=0)
            {
                printf("Número inválido. \n");
            }
        }
        while(quant<=0);

        do
        {
            printf("Digite um número: \n");
            scanf("%d",&n);
            cont++;

            soma=adicao(n, soma);
            sub=subt(n, sub, cont);
            mult=multiplica(n, mult);
            div=divide(n, div, cont);

        }
        while(cont<quant);

        printf("Soma: %d \n", soma);
        printf("Subtração: %d \n", sub);
        printf("Multiplicação: %d \n", mult);
        printf("Divisão: %0.2f \n",(float)div);

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

adicao(int n, int soma)
{
    int som;
    som = n+soma;
    return(som);
}
subt(int n, int sub, int cont)
{
    int subs;

    if(cont==1)
    {
        subs = n;
        return(subs);
    }
    if(cont>1)
    {
        subs = sub-n;
        return(subs);
    }
}

multiplica(int n, int mult)
{
    int mults;
    mults = n*mult;
    return(mults);
}
divide(int n, int div, int cont)
{
    float divs;
    if(cont==1)
    {
        divs = n;
        return(divs);
    }
    if(cont>1)
    {
        divs = (float)div/n;
        return(divs);
    }

}
    #endif // arrumar a conta de divisao.

    #ifdef ex5
    /*
    5 - Escreva um programa que receba n valores inteiros via teclado na funcao main().
    Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
    As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser mostrado na funcao main(). */

int main(void)
{
    setlocale(LC_ALL,"");

    int n, quant, cont, result, caso, opcao;

    do
    {
        system("cls");
        cont=0, result=0;
        do
        {
            printf("Digite a quantidade de números desejada: \n");
            scanf("%d", &quant);
            if(quant<=0)
            {
                printf("Número inválido. \n");
            }
        }
        while(quant<=0);


        printf("Digite o primeiro número para a conta desejada: \n");
        scanf("%d",&n);
        cont++;

        do
        {

            printf("Selecione a operação aritmética desejada: \n");
            printf("1 - Adição \n");
            printf("2 - Subtração \n");
            printf("3 - Multiplicação \n");
            printf("4 - Divisão \n\n");
            scanf("%d", &caso);

            switch(caso)
            {

            case 1 :
            {
                result=adicao(n, result, cont);
                cont++;
                break;
            }
            case 2 :
            {
                result=subt(n, result, cont);
                cont++;
                break;
            }
            case 3:
            {
                result=multiplica(n, result, cont);
                cont++;
                break;
            }
            case 4:
            {
                result=divide(n, result, cont);
                cont++;
                break;
            }

            default:
            {
                printf("Opção inválida, tente novamente: \n\n");
            }
            }


        }
        while(cont<quant);


        printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
        scanf("%d",&opcao);
        if(opcao == 2)
        {
            printf("Fim do programa.");
        }
    }
    while(opcao==1);
    return 0;
}

adicao(int n, int result, int cont)
{
    int x, y;
    y=result;
    printf("Digite um número: \n");
    scanf("%d", &x);
    if(cont==1)
    {
        result=n+x;
        printf("O resultado é: %d \n\n", result);
        return(result);
    }
    else
    {
        result=y+x;
        printf("O resultado é: %d \n\n", result);
        return(result);
    }
}
subt(int n, int result, int cont)
{
    int x, y;
    y=result;
    printf("Digite um número: \n");
    scanf("%d", &x);
    if(cont==1)
    {
        result=n-x;
        printf("O resultado é: %d \n\n", result);
        return(result);
    }
    else
    {
        result=y-x;
        printf("O resultado é: %d \n\n", result);
        return(result);
    }
}

multiplica(int n, int result, int cont)
{
    int x, y;
    y=result;
    printf("Digite um número: \n");
    scanf("%d", &x);
    if(cont==1)
    {
        result=n*x;
        printf("O resultado acumulado é: %d \n\n", result);
        return(result);
    }
    else
    {
        result=y*x;
        printf("O resultado acumulado é: %d \n\n", result);
        return(result);
    }
}
divide(int n, int result, int cont)
{
    int x, y;
    y=result;
    printf("Digite um número: \n");
    scanf("%d", &x);
    if(cont==1)
    {
        result=n/x;
        printf("O resultado acumulado é: %d \n\n", result);
        return(result);
    }
    else
    {
        result=y/x;
        printf("O resultado acumulado é: %d \n\n", result);
        return(result);
    }
}

    #endif
