#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *p, int sizeArray)
{
	int i, key, j;
	for (i = 1; i < sizeArray; i++) {
		key = *(p + i);
		j = i - 1;
        
		while (j >= 0 && *(p + j) % 2 != 0 &&  key % 2 == 0)  {
			*(p + j + 1) = *(p + j);
			j = j - 1;
		}
		*(p + j + 1) = key;
	}

}

int main(){
    int *p, sizeArray;


    printf("Digite o tamanho do vetor a ser ordenado:");
    scanf("%d", &sizeArray);

    while(sizeArray <= 0){
        printf("Tamanho Invalido.Digite Novamente:\n");
        scanf("%d", &sizeArray);
    }

    p = malloc(sizeof(int) * sizeArray);

    for(int i = 0; i < sizeArray; i++){
        printf("Digite um numero a ser inserido no array:\n");
        scanf("%d", (p + i));
    }

    printf("\nArray Desordenado:\n");
    for(int i = 0; i < sizeArray; i++){
        printf("%d\n", *(p + i));
    }

    insertionSort(p, sizeArray);

    printf("\nArray Ordenado:\n");

    for(int i = 0; i < sizeArray; i++){
        printf("%d\n", *(p + i));
    }

    system("pause");

    free(p);


    return 0;
}