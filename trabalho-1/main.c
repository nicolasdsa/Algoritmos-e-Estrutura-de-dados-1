#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Malloc, casting, return, e funções.

int sumTwoNumbers(int *ptr, int searchNumber, int sizeArray){
    int cont, i, j, sum;
      for(i = 0; i < sizeArray; i++){
                for(j = 0; j < sizeArray; j++){
                    sum = *(ptr + i) + *(ptr + j);

                    if(sum == searchNumber){   
                        printf("O resultado da soma desses dois numeros e igual ao numero procurado. Numero 1: %d\nNumero 2: %d\nNumero buscado:%d\n", *(ptr + i), *(ptr + j), searchNumber);

                        for(cont = i; cont < sizeArray - 1; cont++){
                            *(ptr + cont) = *(ptr + cont + 1);
                        }

                        for(cont = j - 1; cont < sizeArray - 2; cont++){
                            *(ptr + cont) = *(ptr + cont + 1);
                        }

                        ptr = (int *) realloc(ptr, _msize(ptr) - sizeof(int) * 2);
             
                        sizeArray -=  2;

                        printf("Novo array:\n");

                        for(i = 0; i < sizeArray; i++){
                            printf("%d\n", *(ptr + i));
                        }
                    return 0;
                }
            }
        }
        printf("Infelizmente nao existe um resultado com a soma de dois numeros igual ao numero procurado.");
        return 0;
}

int searchEqual(int *ptr, int searchNumber, int sizeArray ){
    int i, j;
    for(i = 0; i < sizeArray; i++){

        if(searchNumber == *(ptr + i)){

            for(j = i; j < sizeArray - 1; j++){
                *(ptr + j) = *(ptr + j + 1);
            }

            ptr = (int *) realloc(ptr, _msize(ptr) - sizeof(int));

            sizeArray--;

            printf("Novo Array:\n");

            for(i = 0; i < sizeArray; i++){
                printf("%d\n", *(ptr + i));
            }

            printf("Este numero existe no array e foi removido");
            return 1;
        }

    }

    return 0;
}

int main(){
    int *ptr, sizeArray , searchNumber,  sum;
    int i, j;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &sizeArray);

    ptr = (int *) malloc(sizeArray * sizeof(int));
    
    for(i = 0; i < sizeArray; i++){
        *(ptr + i) = rand();
    }

    for(i = 0; i < sizeArray; i++){
        printf("%d\n", *(ptr + i));
    }

    printf("Digite o numero que gostaria de buscar no array:\n");
    scanf("%d", &searchNumber);
    
    int verify = searchEqual(ptr, searchNumber, sizeArray);

    if(verify == 0){
        sumTwoNumbers(ptr, searchNumber, sizeArray);
    }

    free(ptr);

    system("pause");
    
};