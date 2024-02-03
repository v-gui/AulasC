#include <stdio.h>
int stair(int n, int k){
    if(n <=1){
        return 1;
    }
    int maneiras = 0;
    for(int i = 1; i <= n && i <= k; i++){
          maneiras += stair(n-i, k);
    }
    return maneiras;
}
int main (){
    int n, k;
    printf("Coloque o número de degraus: ");
    scanf("%d", &n);
  // Como não há um delimitador no número de passos máximo que a pessoa pode  "pular os degraus", vamos utilizar um scanf para o usuário colocar o número de passos máximo que pode pular.  
    printf("Coloque o número máximo de degraus que a pessoa pode pular: ");
    scanf("%d", &k);
    printf("Maneiras de subir as escadas: %d\n", stair(n, k));
    return 0;
}

// Levando em consideração que a pessoa pode no máximo subir 2 degraus por vez, a resposta é 121.393
// Levando em consideração que a pessoa pode no máximo subir 3 degraus por vez, a resposta é 2.555.757