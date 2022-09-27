#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  char p;
  struct no *proximo;
}No;

typedef struct{
  No *topo;
}Pilha;

void criar_pilha(Pilha *p){
  p->topo = NULL;
}

void empilhar(Pilha *p, char letra){
  No *novo = malloc(sizeof(No));

  if (novo){
    novo->p = letra;
    novo->proximo = p->topo;
    p->topo = novo;
  }
  else{
    printf("Erro ao alocar memoria\n");
  }

}

No* desempilhar(Pilha *p){
  if(p->topo){
    No *remover = p->topo;
    p->topo = remover->proximo;
    return remover;
  }

  return NULL;
}

void imprimir(char p){
  printf("%c\n", p);
}

void imprimir_pilha(Pilha *p){
  No *aux = p->topo;
  while(aux){
    imprimir(aux->p);
    aux = aux->proximo;
  }

}

void main(){
    No *remover;
    Pilha p;
    char letra, temp;
    int numberOpen, numberClosed, tempOpen, tempClosed;
    numberClosed = 0;
    numberOpen = 0;
    tempClosed = 0;
    tempOpen = 0;

    criar_pilha(&p);

    printf("Digite sua expressão: (letra por letra)\n");
    do{
        scanf("%c", &letra);
        fflush(stdin);

        if(letra == 'x'){
            break;
        }

        empilhar(&p, letra);
    }while(letra != 'x');

    printf("Sua expressão em pilha:\n");
    imprimir_pilha(&p);

    remover = desempilhar(&p);

    if(remover->p == '('){
        printf("Condição violada\n");
        free(remover);
        remover = desempilhar(&p);
        while(remover){
          free(remover);
          remover = desempilhar(&p);
        }        
        getchar();
        return;
    }

    if(remover){
         while(remover){
            if(remover->p == ')'){
                tempClosed++;
                numberClosed++;
            }  

            if(remover->p == '('){
                tempOpen++;
                numberOpen++;
            }

            if(tempOpen == 1 && tempClosed == 0){
                printf("\nCondição violada\n");
                free(remover);
                remover = desempilhar(&p);
                 while(remover){
                    free(remover);
                    remover = desempilhar(&p);
                 }
                getchar();
                return;
            }
            
            free(remover);
            remover = desempilhar(&p);
        }
    }
    else{
        printf("\nVocê não digitou nada\n");
        getchar();
        return;
    }

    if(numberClosed != numberOpen){
        printf("\nCondição violada\n");
        free(remover);
        getchar();
        return;
    }

    
    printf("\nPassou nas condições\n");

    printf("Pressione qualquer tecla para continuar");
    getchar();
    return;


}