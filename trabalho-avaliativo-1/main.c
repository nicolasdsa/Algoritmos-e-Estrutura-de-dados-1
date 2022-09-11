#include<stdio.h>
#include <stdlib.h>


int adicionarPessoa(void *ptr){
  
  printf("Digite seu nome:\n");
  scanf("%s", (char *) (ptr + sizeof(int) * 2));

  printf("%s", (char *) (ptr + sizeof(int) * 2));


  printf("Digite sua idade:");
  scanf("%d", (int *) (ptr + sizeof(char) * 10 + sizeof(int) * 3));

  printf("%i\n", *(int *) (ptr + sizeof(char) * 10 + sizeof(int) * 3));

  printf("Digite seu telefone");
  scanf("%d", (int *) (ptr + sizeof(char) * 10 + sizeof(int) * 4));

  printf("%i\n", *(int *) (ptr + sizeof(char) * 10 + sizeof(int) * 4));
  return 0;
}

int main(){
  void *ptr;

  ptr = malloc(sizeof(int) * 2 +sizeof(char) * 10 + sizeof(int) * 3);

  *((int *) ptr) = 0; // Contador i
  *((int *) ptr + sizeof(int)) = 0; // Escolha do menu

  /*printf("%d\n",  *((int *) ptr));
  printf("%d\n", *((int *) ptr + sizeof(int)));

   *((int *) ptr) =+ 1;
  *((int *) ptr + sizeof(int)) =+ 1; */

  adicionarPessoa(ptr);
  
  free(ptr);
}
  
  
