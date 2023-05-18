#include <stdio.h>
#include <locale.h>
#define ex5

#ifdef ex1
/*1 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o decomponha em dois outros vetores. Um tera´ as componentes de ordem impar
    e o outro tera´ as componentes de ordem par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.  */



    int main(void){
    setlocale(LC_ALL,"");
    int A[10],B[5],C[5],cont=0,x=0,y=0,opcao;
    do{
    system("cls");

    printf("Digite os 10 números inteiros: \n");

    for(cont=0;cont<10;cont++){
        scanf("%d",& A[cont]);
    }
    for(cont=0;cont<10;cont++){

        if(cont%2==0){
            B[x]=A[cont];
        x++;
        }

        else{
        C[y]=A[cont];
        y++;
        }

    }
    // Exibição números:
    for(cont=0;cont<x;cont++){

    printf("Os números do vetor B são %d  \n",B[cont]);
    }
    for(cont=0;cont<y;cont++){

    printf("Os números do vetor C são %d  \n",C[cont]);

    }
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
/*2 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o decomponha em dois outros vetores. Um tera´ as componentes de valor impar e o outro tera´ as componentes de valor par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}. */

    int main(void){
    setlocale(LC_ALL,"");
    int A[10],B[10],C[10],cont=0,x=0,y=0,opcao;
    do{
    system("cls");
    printf("Digite os 10 números inteiros: \n");

    for(cont=0;cont<10;cont++){
        scanf("%d",& A[cont]);
    }
    for(cont=0;cont<10;cont++){

    if(A[cont]% 2== 0){
        B[x]=A[cont];
        x++;
        }

        else{
        C[y]=A[cont];
        y++;
        }

    }
    // Exibição números:
    for(cont=0;cont<x;cont++){

    printf("Os números pares do vetor A que estão no vetor B são %d  \n",B[cont]);
    }
    for(cont=0;cont<y;cont++){

    printf("Os números ímpares  do vetor A que estão no vetor C são %d  \n",C[cont]);

    }
    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }
    }while(opcao==1);

    return 0;
    }
#endif

#ifdef ex3
/*3 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa que recebe os dados via teclado para esses 2 vetores.
Usando o operador adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o resultado em um 3. vetor.
Imprima na tela o indice, os valores e o resultado dos 6 elementos dos vetores.  */

    int main(void){
    setlocale(LC_ALL,"");
    int A[2][3],B[2][3],S[2][3],opcao;
    do{
        system("cls");
    // VETOR A
    for(int x=0;x<2;x++){
    for(int y=0;y<3;y++){
    printf("Digite o número: Vetor A [%d] [%d] \n",x,y);
    scanf("%d",&A[x][y]);
    }
    }
    // VETOR B
    for(int x=0;x<2;x++){
    for(int y=0;y<3;y++){
        printf("Digite o número: Vetor B [%d] [%d] \n",x,y);
    scanf("%d",&B[x][y]);
    }
    }
    // soma dos vetores
    for(int x=0;x<2;x++){
    for(int y=0;y<3;y++){
       S[x][y]= (A[x][y]+B[x][y]);
        }}

    // mostrar os vetores:
    printf("Vetor A:\n");
    for(int x=0; x<2; x++){
    for(int y=0;y<3;y++){
    printf("Vetor A [%d] [%d]: %d \n", x,y,A[x][y]);
    }
    }
    printf("Vetor B:\n");
    for(int x=0; x<2; x++){
    for(int y=0;y<3;y++){
    printf("Vetor B [%d] [%d]: %d \n", x,y,B[x][y]);
    }
    }
    printf("Vetor S:\n");
    for(int x=0; x<2; x++){
    for(int y=0;y<3;y++){
    printf("Vetor S [%d] [%d]: %d \n", x,y,S[x][y]);
    }
    }
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
/* Escreva um programa para receber via teclado em vetores 3 int, 3 long, 3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
*/

    int main(void){
    setlocale(LC_ALL,"");
    int vetorint[3],opcao;
    long vetorlong[3];
    unsigned vetorunsigned[3];
    float vetorfloat[3];
    double vetordouble[3];


    do{
        system("cls");
    for(int x=0;x<3;x++){
    printf("Digite o valor do int %d:\n", x+1);
    scanf("%d",&vetorint[x]);
    }
    for(int x=0;x<3;x++){
    printf("Digite o valor do long %d:\n", x+1);
    scanf("%ld",&vetorlong[x]);
    }
    for(int x=0;x<3;x++){
    printf("Digite o valor do unsigned %d:\n", x+1);
    scanf("%u",&vetorunsigned[x]);
    }
    for(int x=0;x<3;x++){
    printf("Digite o valor do float %d:\n", x+1);
    scanf("%f",&vetorfloat[x]);
    }
    for(int x=0;x<3;x++){
    printf("Digite o valor do double %d:\n", x+1);
    scanf("%lf",&vetordouble[x]);
    }
    printf("        10        20        30        40        50 \n");
    printf("12345678901234567890123456789012345678901234567890 \n");
    printf("%-3c %-19d %-19ld %-20u \n", "" , vetorint[0], vetorlong[0], vetorunsigned[0]);
    printf("%-12c %-19.1f %-19.1lf  \n", "" , vetorfloat[0], vetordouble[0]);
    printf("%-3c %-19d %-19ld %-20u \n", "", vetorint[1], vetorlong[1], vetorunsigned[1]);
    printf("%-12c %-19.1f %-19.1lf  \n", "", vetorfloat[1], vetordouble[1]);
    printf("%-3c %-19d %-19ld %-20u \n", "", vetorint[2], vetorlong[2], vetorunsigned[2]);
    printf("%-12c %-19.1f %-19.1lf  \n", "", vetorfloat[2], vetordouble[2]);

    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }
    }while(opcao==1);

    return 0;
    }


#endif

#ifdef ex5
/*5  Receba via teclado 10 valores inteiros e ordene por ordem crescente assim que sao digitados. Guarde-os em um vetor. Mostre ao final os valores ordenados.//vetor 5 elementos sem ser via teclado pra pegar a manha. */


    void ordenar(int arr[], int n) {
    int cont, chave, x,opcao;
    for (cont = 1; cont < n; cont++) {
        chave = arr[cont];
        x = cont - 1;

        // Move os elementos do vetor que são maiores que a chave para uma posição à frente
        while (x >= 0 && arr[x] > chave) {
            arr[x + 1] = arr[x];
            x = x - 1;
        }
        arr[x + 1] = chave;
    }
    }

    int main(void) {
    int vetor[10],opcao;
    setlocale(LC_ALL,"");
    do{
        system("cls");
    printf("Digite 10 valores inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);

        // Ordenar os valores
        ordenar(vetor, i + 1);
    }

    printf("Valores ordenados:\n");
    for (int cont = 0; cont < 10; cont++) {
        printf("%d ", vetor[cont]);
    }
    printf("\n");

    printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
    scanf("%d",&opcao);
    if(opcao == 2){
    printf("Fim do programa");
           }

    }while(opcao==1);
    return 0;
    }

#endif









