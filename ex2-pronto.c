#include <stdio.h>

void imprimeArvore(int n){
    if(n == 0){ return; }
    imprimeArvore(n-1);
    for(int i = 1; i <= n; i++){
        printf("%d ", n);
    }
    printf("\n");
}

int somaArvore(int n){

    int soma = 0;

    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= i; k++){
            soma = soma + i;
        }
    }
    return soma;
}

void imprimeArvoreESomaDaLinha(int n){
    if(n == 0){ return; }
    imprimeArvoreESomaDaLinha(n-1);
    int num = 0;
    for(int i = 1; i <= n; i++){
        if(i != 1){ printf("+ ");}
        printf("%d ", n);
        num = num + n;
    }
    printf("= (%d)\n", num);
}

int main(){
    
    int num;
    scanf("%d", &num);

    imprimeArvore(num);
    printf("\n");
    printf("Soma total: %d", somaArvore(num));
    printf("\n\n");
    imprimeArvoreESomaDaLinha(num);

    return 0;
}