#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esquerdo, *direito;
    short altura;
}No;

No* novoNo(int x){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = x;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    }
    else
        printf("erro ao alocar\n");
    return novo;
}

short maior(short a, short b){
    return (a > b)? a: b;
}

short alturaDoNo(No *no){
    if(no == NULL)
        return -1;
    else
        return no->altura;
}

No* inserir(No *raiz, int x){
    if(raiz == NULL)
        return novoNo(x);
    else{ 
        if(x < raiz->valor)
            raiz->esquerdo = inserir(raiz->esquerdo, x);
        else if(x > raiz->valor)
            raiz->direito = inserir(raiz->direito, x);
        else
            printf("O elemento já existe.\n");
    }

    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    return raiz;
}

No* rotacao(No *raiz, int x){
    
    if(raiz->valor == x) {
    No *y, *f;

    printf("Raiz->valor: \n%d\n", raiz->valor);
    printf("Raiz->direito: \n%d\n", raiz->direito->valor);
    printf("Raiz->esquerdo: \n%d\n", raiz->esquerdo->valor);


    y = raiz->direito;
    printf("\nY = %d\n", y);
    f = y->esquerdo;
    printf("\nF = %d\n", f );

    y->direito = raiz;
    printf("\nY->direito = %d\n", y->direito);
    raiz->esquerdo = f;
    printf("\nRaiz->direito = %d\n", raiz->esquerdo);

    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    }
    else{
        if(x < raiz->valor)
            raiz->esquerdo = rotacao(raiz->esquerdo, x);
        else
            raiz->direito = rotacao(raiz->direito, x);
    }

    return raiz;
}

void limpar(No *raiz){
    if(raiz){
        limpar(raiz->esquerdo);
        limpar(raiz->direito);
        free(raiz);
        raiz = NULL; 
    }
}

void imprimir(No *raiz, int nivel){
    int i;
    if(raiz){
        imprimir(raiz->direito, nivel + 1);
        printf("\n");

        for(i = 0; i < nivel; i++)
            printf("\t");

        printf("%d", raiz->valor);
        imprimir(raiz->esquerdo, nivel + 1);
    }
}


 int main(){
    int opcao, valor;
    No *raiz = NULL;

    do{
        printf("\n1)Inserir\n2)Rotacao\n3)Imprimir\n0)Sair\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 0:
            break;
        case 1:
            printf("Valor a ser inserido:");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;
        case 2:
            printf("Valor a ser rotado:");
            scanf("%d", &valor);
            rotacao(raiz, valor);
            break;
        case 3:
            imprimir(raiz, 1);
            break;
        default:
            printf("Favor digitar uma opcao valida");
        }

    }while(opcao != 0);

    limpar(raiz);

    return 0;
} 

    