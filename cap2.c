#define ex3
#include <stdio.h>
#include <locale.h>

#ifdef ex1
/*1 - As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles.}*/

    int main (void){
        setlocale(LC_ALL,"");
        int hr1,hr2,min1,min2,s1,s2,opcao;
        int totalseg1,totalseg2;
        int difhr,difmin,difs;


    do{
    printf("Digite o inicio da ligação em (hr:min:seg) \n");
    scanf("%d:%d:%d",&hr1,&min1,&s1);
    printf("Digite o fim da ligação em (hr:min:seg) \n");
    scanf("%d:%d:%d",&hr2,&min2,&s2);

    totalseg1= hr1*3600 + min1*60 + s1;
    totalseg2= hr2*3600 + min2*60 + s2;

    difs= totalseg2-totalseg1;

    difhr= difs/3600;
    difmin= difs%3600/60;
    difs  %=60;

    printf("%d hr, %d minutos, %d segundos.\n",difhr,difmin,difs);

    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }
    }while(opcao==1);

    return 0;
    }
#endif // ex1

#ifdef ex2
/*
2 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario pensou.
Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o comando if-else.*/ // 7 TENTATIVAS 100% DE CHANCE DE SABER O NUMERO

    int main (void){
    setlocale(LC_ALL,"");
    // a = >, b = <, c = =
    char a;
    int maxi=99,mini=1,n,opcao;
    do{
    printf(" Digite se for o certo (=) Maior(>) ou Menor (<) \n");
    printf(" O seu número é: %d\n", n=(maxi+mini)/2);
    do{
    scanf("%c",&a);
    getchar();
    if(a!='=')
        {
            } if(a=='>'){
                mini=n;
                printf("Errei o seu número  \n");
                printf(" O seu número é: %d\n", n=(maxi+mini)/2);

            }
            if(a=='<'){
                maxi=n;
                printf("Errei o seu número  \n");
                printf(" O seu número é: %d\n", n=(maxi+mini)/2);
            }

            }while(a!='=');

        printf(" Acertei o seu número !! \n \n");

    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }
    }while(opcao==1);

    return 0;
    }



#endif // ex2

#ifdef ex3
/*3 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
    Conte o n. de tentativas e imprima o resultado no video. */

   int main(void){
   setlocale(LC_ALL,"");
    // 1 = >, 2 = <, 3 = =
    char a;
    int maxi,mini,n,opcao, cont, caso,tentativas;
    do{ maxi=99,mini=1, tentativas=0;
    system("cls");
    printf(" Digite se for o certo (=) Maior(>) ou Menor (<) \n");
    printf(" O seu número é: %d\n", n=(maxi+mini)/2);

    for(cont=0; cont<7; cont++){
    // problema com esse cont, corrigir para encerrar o programa quando clicar no 3, botei return 0 mais não funcionou.
    // programa não limpa o numero correto quando reinicia ele.
    printf("Informe sua opção: \n");
    printf("1 - Maior \n");
    printf("2 - Menor \n");
    printf("3 - Número correto \n");
    scanf("%d", &caso);
    tentativas++;

    switch(caso){
   case 1 : {
                mini=n;
                printf("Errei o seu número  \n");
                printf(" O seu número é: %d\n", n=(maxi+mini)/2);
                break;
            }
    case 2 :{
                maxi=n;
                printf("Errei o seu número  \n");
                printf(" O seu número é: %d\n", n=(maxi+mini)/2);
                break;
            }
    case 3: {
                printf("Acertei o seu número em %d tentativas! \n", tentativas);


                break;
           }

    }
    if(caso==3){
        cont=8;
    }
    }printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }
    }while(opcao==1);
    }

#endif // ex3

#ifdef ex4
/* 4 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a media dos valores positivos digitados. */

    int main(void){
    setlocale(LC_ALL,"");
    int num=0, n ,cont, opcao;

    do{ n=0, num=0, cont=0;
       system("cls");
    printf("Quando o numero digitado for negativo o programa deve parar e \ncalcular a media dos valores positivos digitados.\n\n");
    for(cont=0;n>=0;cont++){
    printf("Digite um número: \n");
    scanf("%d", &n);

    if(n>=0){
    num+=n;}

    else {cont--;}
   }

    printf("A média dos valores positivos é: %d\n\n", num/cont);

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
/*5 - Receba via teclado a distancia em km e a quantidade de litros de gasolina consumidos por um carro em um percurso.
    Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela abaixo:
     CONSUMO (km/l) MENSAGEM menor que 8    Venda o carro!  //  entre 8 e 14   Economico! //   maior que 14   Super economico! */

   int main(void){
   setlocale(LC_ALL,"");
   int km, gas, consumo, opcao;

    do{
    do{
    system("cls");
    printf("Insira a distância percorrida em km: \n");
    scanf("%d", &km);

    if(km<=0){
    printf("O valor deve ser maior que Zero. Digite Novamente: \n");
    }

    }while(km<=0);

    do{
    printf("Insira a quantidade de litros de gasolina consumida: \n");
    scanf("%d", &gas);

    if(gas<=0){
    printf("O valor deve ser maior que Zero. Digite Novamente: \n");
    }
    }while(gas<=0);

    consumo = km/gas;

    if(consumo<8){
    printf("VENDA O CARRO!!!\n");
    }

    else if(consumo>=8 && consumo<=14){
    printf("Econômico!\n");
    }
    else {
    printf("SUPER ECONÔMICO!!!\n");
    }

    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d", &opcao);
    if(opcao == 2){
    printf("Fim do programa.");
           }
    }while(opcao == 1);

    return 0;
    }
#endif // ex5
