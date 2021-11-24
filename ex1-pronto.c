#include <stdio.h>
#include <stdbool.h>

void imprimeNumeroPorExtenso(int numero){
    if(numero == 0){
        printf("zero");
    }
    else if(numero == 1){
        printf("um");
    }
    else if(numero == 2){
        printf("dois");
    }
    else if(numero == 3){
        printf("três");
    }
    else if(numero == 4){
        printf("quatro");
    }
    else if(numero == 5){
        printf("cinco");
    }
    else if(numero == 6){
        printf("seis");
    }
    else if(numero == 7){
        printf("sete");
    }
    else if(numero == 8){
        printf("oito");
    }
    else if(numero == 9){
        printf("nove");
    }
    else{ printf("Número inválido"); }
}

bool validaNumero3Digitos(int num){
    int contador = 0;
    while(num%10 > 0){
        contador++;
        if(contador > 3){ return false; }
        num=num/10;
    }
    return true;
}

int contadorDeDigitos(int x){
    int contador = 0;
    while(x%10 != 0){
        ++contador;
        x = x/10;
    }
    return contador;
}

//10^n
int multiplica10_nVezes(int n){
    if (n == 0){ return 1; }
    return multiplica10_nVezes(n-1)*10;
}

void percorreNumeroRecebidoComRecursao(int numero){
    if(numero%10 != 0){
        percorreNumeroRecebidoComRecursao(numero/10);
        if(numero/10 > 0){ printf(" "); }
        imprimeNumeroPorExtenso(numero%10);   
    } 
}

void percorreNumeroRecebidoComLaco(int numero){
    int aux = contadorDeDigitos(numero);

    for(int i = aux-1; i >= 0; i--){      
        imprimeNumeroPorExtenso(numero/multiplica10_nVezes(i));
        if(numero>10){ 
            printf(" "); 
            numero = numero%multiplica10_nVezes(i);
        }
    }
}

int main(){

    int num;
    scanf("%d", &num);

    if(validaNumero3Digitos(num)){

        printf("Resolução por recursão -> \"");
        percorreNumeroRecebidoComRecursao(num);
        printf("\".\n");

        printf("Resolução utilizando laço -> \"");
        percorreNumeroRecebidoComLaco(num);
        printf("\".\n");

    } else{ printf("O número possui mais que três digítos!"); }

    printf("\n");
    return 0;
}