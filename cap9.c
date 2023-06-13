#define ex6
#include <stdio.h>
#include <locale.h>


/*OBS.: Todos os programa devem ser finalizados pelo usuario.*/

#ifdef ex1
/*1 - Escreva um programa que receba n valores via teclado e receba tambem a
    operação a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operações aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.
    As variaveis sao LOCAIS na funcao main(). */

int recebeValor(int *valor,int n)
{
    printf("Digite os valores: \n");
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d",&valor[i]);
    }
}

int operacao(int *valor,int n,char opcao)
{
    int resultado = valor[0];
    int i;
    for(i = 1; i < n; i++)
    {
        switch(opcao)
        {
        case '+':
            resultado += valor[i];
            break;
        case '-':
            resultado -= valor[i];
            break;
        case '*':
            resultado *= valor[i];
            break;
        case '/':
            resultado /= valor[i];
            break;
        }
    }
    return resultado;
}

int main (void)
{
    setlocale(LC_ALL,"");
    int n,opcao;

    do{
    printf("Digite a quantidade de números a serem digitados: \n");
    scanf("%d",&n);

    int valor[n];

    recebeValor(valor,n);

    char opcao;

    printf("Digite a operação a ser executada: ( '+' , '-' , '*' , '/' )\n");
    scanf(" %c",&opcao);

    int resultado = operacao(valor,n,opcao);
    printf("O resultado é:%d \n",resultado);

    printf("---------------------------------------------------------\n");
        printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
        scanf("%d",&opcao);
        getchar();
        if(opcao == 2)
        {
            printf("Fim do programa\n");
        }
    }
    while(opcao == 1);

    return 0;

}
#endif // ex1

#ifdef ex2
/*2 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa
    usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y */



int pesquisaletra(char* pletra,char *bancodeletras)
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
    char bancodeletras[] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};
    char letra;
    int resultado,opcao;
    char *pletra = &letra;

    do{
    printf("Digite uma letra: ");
    scanf("%c",pletra);

    resultado = pesquisaletra(pletra,bancodeletras);
    if(resultado)
    {
        printf("A letra foi encontrada. \n");
    }
    else
    {
        printf("A letra não foi encontrada. \n");
    }

    printf("---------------------------------------------------------\n");
        printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
        scanf("%d",&opcao);
        getchar();
        if(opcao == 2)
        {
            printf("Fim do programa\n");
        }
    }
    while(opcao == 1);

    return 0;
}

#endif // ex2

#ifdef ex3
/*3 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na função main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main(). */

int main (void)
{
    setlocale(LC_ALL,"");

    char a[10], b[10];

    int x,opcao;

    char *pa, *pb;
    /*pa = &a;
     *pb = &b;*/

    do
    {
        recebeString(a,b);

        x=verifica(a,b);
        if(x == 0)
        {
            printf("As strings são diferentes. \n");
        }
        else
        {
            printf("As strings são iguais. \n");
        }

        printf("---------------------------------------------------------\n");
        printf("Deseja fazer outra conta? 1 para Sim e 2 para Não \n");
        scanf("%d",&opcao);
        getchar();
        if(opcao == 2)
        {
            printf("Fim do programa\n");
        }
    }
    while(opcao == 1);

    return 0;
}
int recebeString(char *pa,char *pb)
{
    printf("Digite uma string de 10 até caracteres. \n");
    gets(pa);
    printf("Primeira string: %s \n\n", pa);
    printf("Digite outra string de 10 até caracteres. \n");
    gets(pb);
    printf("Segunda string: %s \n\n", pb);
}
int verifica(char *pa,char *pb)
{
    int i = 0;
    while (pa[i] != '\0' && pb[i] != '\0')
    {
        if(pa[i] != pb[i])
        {
            return 0;
        }
        i++;
    }
    if(pa[i] != pb[i])
    {
        return 0;
    }
    return 1;
}

#endif // ex3

#ifdef ex4


/*4 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato(também numa função).
    estrutura: char, int, long, float, double, unsigned char, unsigned int,
    unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long
*/
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
void recebe(struct estrutura *y)
{

        printf("Digite o char.\n");
        scanf(" %c",&(y->c));
        printf("Digite o int.\n");
        scanf("%d", &(y->i));
        printf("Digite o long.\n");
        scanf("%ld", &(y->l));
        printf("Digite o float.\n");
        scanf("%f", &(y->fl));
        printf("Digite o double.\n");
        scanf("%lf", &(y->db));
        printf("Digite o unsigned char.\n");
        scanf(" %c", &(y->uc));
        printf("Digite o unsigned int.\n");
        scanf("%u", &(y->ui));
        printf("Digite o unsigned long.\n");
        scanf("%lu",&(y->ul));
    }
    void imprime(struct estrutura *y)
    {

        printf("        10        20        30        40        50        60        70\n");
        printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
        printf("%-4c %-8c %-9d %-19ld %-19.2f %.2lf \n","",y->c,y->i,y->l,y->fl,y->db);
        printf("%-10c %-19c %-19u %lu \n\n","",y->uc,y->ui,y->ul);

    }


#endif // ex4

#ifdef ex5


/*5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa função e imprima todos os registros no
    video em outra funcao. Faça um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opção de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
     estutura: nome, end, cidade, estado, cep
*/


struct pessoa
{
    char nome[50], end[50], cidade[20], estado[20], cep[10];
};

int i=0;

int main (void){
setlocale(LC_ALL,"");
int opcao;
struct pessoa x[4];
struct pessoa *px;

px = &x;


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
        case 1: recebe(px);
                break;

        case 2: imprime(px);
                break;

        case 3: printf("Saindo do programa...\n");
                return(0);

        default: printf("Opção inválida, tente novamente: \n");
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
                printf("Todos os dados já estão completos. \n");
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
    printf("      Ainda não há nenhum dado informado.\n");
    printf("----------------------------------------------------\n");
}
}


#endif // ex5

#ifdef ex6


/*6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro sempre usando ponteiros.*/


struct pessoa
{
    char nome[50], end[50], cidade[20], estado[20], cep[10];
};

int i=0;

int main (void){
setlocale(LC_ALL,"");
int opcao;
struct pessoa x[4];
struct pessoa *px;

px = &x;


do{
            printf("\t\tMENU:\n");
            printf("\t1- Inserir dados de uma pessoa.\n");
            printf("\t2- Imprime todos os dados salvos.\n");
            printf("\t3- Procurar dados salvos.\n");
            printf("\t4- Alterar dados de uma pessoa.\n");
            printf("\t5- Excluir dados de uma pessoa.\n");
            printf("\t6- Sair.\n");
            printf("\n\tOpção: ");
            scanf("%d", &opcao);
            printf("----------------------------------------------------\n");
switch(opcao)
        {
        case 1: recebe(px);
                break;

        case 2: imprime(px);
                break;

        case 3: procura(px);
                break;

        case 4: altera(px);
                break;

        case 5: exclui(px);
                break;

        case 6: printf("Saindo do programa...\n");
                return(0);

        default: printf("Opção inválida, tente novamente: \n");
        }
}while(opcao!=6);
}

void recebe(struct pessoa px[]){
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
                printf("Todos os dados já estão completos. \n");
                printf("----------------------------------------------------\n");
                }
}
void imprime(struct pessoa px[]){
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
    printf("      Ainda não há nenhum dado informado.\n");
    printf("----------------------------------------------------\n");
}
}

void procura(struct pessoa px[]) {
    char nome_procurado[50];
    printf("Digite o nome da pessoa que deseja encontrar os dados: \n");
    getchar();
    gets(nome_procurado);

    int j;
    int encontrou = 0;
    for (j = 0; j < i; j++) {
        int k;
        int nome_igual = 1;
        for (k=0; nome_procurado[k] != '\0' || px[j].nome[k] != '\0'; k++) {
            if (nome_procurado[k] != px[j].nome[k]) {
                nome_igual = 0;
                break;
            }
        }

        if (nome_igual && nome_procurado[k] == '\0' && px[j].nome[k] == '\0') {
            printf("Dados da pessoa encontrada:\n");
            printf("Nome:  %s\n", px[j].nome);
            printf("Endereço: %s\n", px[j].end);
            printf("Cidade: %s\n", px[j].cidade);
            printf("Estado: %s\n", px[j].estado);
            printf("CEP: %s\n", px[j].cep);
            printf("----------------------------------------------------\n");
            encontrou = 1;
            break;
        }
        else {
        printf("Pessoa não encontrada.\n");
        printf("----------------------------------------------------\n");
    }
    }


}

void altera(struct pessoa px[]) {
    int pessoa_alterar;
    printf("Deseja alterar os dados de qual pessoa? ");
    scanf("%d", &pessoa_alterar);

    if (pessoa_alterar >= 1 && pessoa_alterar <= i) {
        pessoa_alterar--;

        printf("Entre com os novos dados: \n");
        getchar();
        printf("Nome completo: \n");
        gets(px[pessoa_alterar].nome);
        printf("Endereço: \n");
        gets(px[pessoa_alterar].end);
        printf("Cidade: \n");
        gets(px[pessoa_alterar].cidade);
        printf("Estado: \n");
        gets(px[pessoa_alterar].estado);
        printf("CEP: \n");
        gets(px[pessoa_alterar].cep);
        printf("Dados da pessoa alterados com sucesso.\n");
        printf("----------------------------------------------------\n");
    } else {
        printf("Pessoa inválida.\n");
        printf("----------------------------------------------------\n");
    }
}

void exclui(struct pessoa px[]) {
    int excluir;
    printf("Qual pessoa deseja excluir? ");
    scanf("%d", &excluir);

    if (excluir >= 1 && excluir <= i) {
        excluir--;

        int j;
        for (j = excluir; j< i-1; j++) {
            px[j] = px[j+1];
        }

        i--;
        printf("Dados da pessoa excluídos com sucesso.\n");
        printf("----------------------------------------------------\n");
    } else {
        printf("Pessoa inválida.\n");
        printf("----------------------------------------------------\n");
    }



}
#endif // ex6
