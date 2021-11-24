#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct celula{
    int numero;
    struct celula *prox;
} celula;

bool validacaoDeNumeroPrimo(int numero){
    if(numero != 2 && numero%2 == 0){
        return false;
    }
    else if(numero != 3 && numero%3 == 0){
        return false;
    }
    else if(numero != 5 && numero%5 == 0){
        return false;
    }
    else if(numero != 7 && numero%7 == 0){ //sera q precisa?
        return false;
    }
    else{ return true; }
}

//insere numero 'x' em lista->prox->numero
void insereNaLista(celula *l, int x){
    
    celula *nova;
    nova = malloc(sizeof(celula));
    
    l->prox = nova;
    nova->prox = NULL;
    nova->numero = x;
    }

void getListaDeDivisores(celula *lista, int num){

    if(num != 1){
        
        if(num%2 == 0){
            insereNaLista(lista, 2);
            getListaDeDivisores(lista->prox, num/2);
        }
        else if(num%3 == 0){
            insereNaLista(lista, 3);
            getListaDeDivisores(lista->prox, num/3);
        }
        else if(num%5 == 0){
            insereNaLista(lista, 5);
            getListaDeDivisores(lista->prox, num/5);
        }
        else if(num%7 == 0){
            insereNaLista(lista, 7);
            getListaDeDivisores(lista->prox, num/7);
        }
    }
    else{  
        return;  
    }
}

void imprimirLista(celula *lista){
    for(lista->prox; lista != NULL; lista = lista->prox){
        printf("%d ", lista->numero);
    }
}

int main(){

    int numero;
    scanf("%d", &numero);

    celula *listaDosDivisores;
    listaDosDivisores = malloc(sizeof(celula)); //cabeca
    listaDosDivisores->prox = NULL;

    if(!validacaoDeNumeroPrimo(numero)){
        printf("O número não é primo!\n");
        printf("Divisores: ");
        getListaDeDivisores(listaDosDivisores, numero);
        imprimirLista(listaDosDivisores->prox);
    }
    else{ printf("O número é primo!"); }
    

    printf("\n");
    return 0;
}