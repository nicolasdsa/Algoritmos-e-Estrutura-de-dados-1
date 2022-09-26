#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freeLista(void *lista){
    void *aux = *(void **)lista;
    while (aux != NULL){
        void* pessoa = aux;
        aux = *(void **)(aux + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**));
        free(pessoa);
    }
}

void criarLista(void *lista){
    *(void **)lista = NULL; // Inicio da lista
    *(void **)(lista+(sizeof(void **))) = NULL; // Final da lista
}

void criarBuffer(void *pBuffer){
    ((int*)pBuffer)[0] = 0;
    ((int*)pBuffer)[1] = 0;
    ((int*)pBuffer)[2] = 0;
}

void criarPessoa(void* pBuffer, void* lista)
{
    void *pessoaCriada = malloc((sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void **) + sizeof(void **));  // ponteiro para um ponteiro

    *(void **)(pessoaCriada + (sizeof(char) * 11) + (sizeof(int) * 2)) = NULL; // Valor ele ainda não sabe quem vem antes
    *(void **)(pessoaCriada + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void **)) = NULL; // Valor ou quem vem depois


    printf("Nome (dez caracteres):\n");
    scanf("%s", (char*)pessoaCriada);

    printf("Idade:\n");
    scanf("%d", (int*)(pessoaCriada + (sizeof(char) * 11)));

    printf("Telefone:\n");
    scanf("%d", (int*)(pessoaCriada + (sizeof(char) * 11) + (sizeof(int))));

    if(((int*)pBuffer)[0] != 0){
        void* pessoaNaLista = *(void **)lista;

        while (pessoaNaLista != NULL){

            //| nome | idade | telefone | anterior | posterior |
            if(strcmp((char *)pessoaCriada, (char *)pessoaNaLista) > 0 ){
                if(*(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**) + pessoaNaLista) == NULL) /* Ve se é o ultimo */ {
                    *(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + pessoaCriada) = pessoaNaLista; /* Pessoa criada aponta pra anterior dela */
                    *(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**) + pessoaNaLista) = pessoaCriada; /*Pessoa posterior aponta pra pessoa criada */
                    *(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**) + pessoaCriada) = NULL; /* Pessoa criada posterior pra nulo */
                    *(void **)((sizeof(void **)) + lista) = pessoaCriada; // Adiciona no fim 
                    ((int*)pBuffer)[0]++; // Soma o tamanho da lista 
                    return;
                }
                else if(strcmp((char *)(*(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**) + pessoaNaLista)), (char *)pessoaCriada) > 0){
                    void* temp = *(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**) + pessoaNaLista); /* temp depois da pessoa inserida */
                    *(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + pessoaCriada) = pessoaNaLista;  // Ver quem ta antes da pessoa criada
                    *(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**) + pessoaCriada) = *(void **)(pessoaNaLista + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**)); // Pessoa criada o posterior é tal pessoa
                    *(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**) + pessoaNaLista) = pessoaCriada; // anterior a ela apontando pra pessoa que criei
                    *(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + temp) = pessoaCriada;
                    ((int*)pBuffer)[0]++;  // pessoal posterior aponta pra pessoa criada
                    return;

                }
            }
            else{
                *(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + pessoaNaLista) = pessoaCriada; // Pessoa anterior é a pessoa criada     
                *(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**) + pessoaCriada) = pessoaNaLista; //  Pessoa proxima é a pessoa existente
                *(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + pessoaCriada) = NULL; // Pessoa anterior a pessoa criada é nulo
                *(void **)lista = pessoaCriada; // Primeiro da lista é ele
                ((int*)pBuffer)[0]++;
                return;
            }
            pessoaNaLista = *(void **)((sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**) + pessoaNaLista);
        }
    }
    else{
        *(void **)lista = pessoaCriada; // Primeiro da lista pessoa criada
        *(void **)(lista+(sizeof(void **))) = pessoaCriada; // Ultimo da lista da pessoa criada
        ((int*)pBuffer)[0] += 1;
        return;        
    }

}

void pesquisarNome(void* pessoas, void* lista){
    char *pessoaBuscada = malloc((sizeof(char) * 11));
    printf("Nome da pessoa: ");
    scanf("%s", pessoaBuscada);

    void *aux = *(void **)lista;

    while (aux != NULL){   
        if(strcmp(pessoaBuscada, (char*)aux) == 0){
            printf("\nNome: %s\nIdade: %d\nTelefone: %d\n", (char*)aux, *(int *)(aux + (sizeof(char) * 11)), *(int*)(aux + (sizeof(char) * 11) + (sizeof(int))));
            free(pessoaBuscada);
            return;
        }

        aux = *(void **)(aux + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**));
    }   

    printf("Infelizmente não foi encontrado uma pessoa com esse nome\n");
    free(pessoaBuscada);
}

void mostrarTodos(void* pessoas, void* lista){
    void *aux = *(void **)lista;
    while (aux != NULL){   
        printf("\nNome: %s\nIdade: %d\nTelefone: %d", (char*)aux, *(int *)(aux + (sizeof(char) * 11)), *(int*)(aux + (sizeof(char) * 11) + (sizeof(int))));
        aux = *(void **)(aux + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**));
    }

    printf("\n");
}

void excluirPessoa(void* pBuffer, void* lista){
    char *nomeExcluido = malloc((sizeof(char) * 11));
    printf("Digite o nome da pessoa a ser removida: ");
    scanf("%s", nomeExcluido);

    void *aux = *(void **)lista;
    while( aux != NULL ){
        if(strcmp(aux, nomeExcluido) == 0){
            if(((int*)pBuffer)[0] == 1){
                *(void **)lista = NULL; // Primeiro elemento é igual a nulo
                *(void **)(lista + (sizeof(void **))) = NULL; // Ultimo elemento é igual a nulo
                ((int*)pBuffer)[0]--;
                free(aux);
                free(nomeExcluido);
                return;
            }
            else if(*(void**)(aux + (sizeof(char) * 11) + (sizeof(int) * 2)) == NULL) /* se  da cabeça */{
                void *temp = aux;
                *(void **)lista = *(void **)(aux + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**)); /* primeiro da lista é igual o segundo */
                *(void **)(*(void **)(aux + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**)) + (sizeof(char) * 11) + (sizeof(int) * 2)) = NULL; // Pessoa anterior do segunda lista é igual a nulo
                ((int*)pBuffer)[0]--;
                free(temp);
                free(nomeExcluido);
                return;
            }
            else if(*(void**)(aux + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**)) == NULL){
                void *temp = aux;
                *(void **)(lista + (sizeof(void **))) = *(void **)(aux+(sizeof(char) * 11) + (sizeof(int) * 2)); /* Anterior ao ultimo da lista é a nova cauda */
                *(void **)(*(void **)(aux + (sizeof(char) * 11) + (sizeof(int) * 2)) + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**)) = NULL; /* Posterior a nova cauda é igual a nulo */
                ((int*)pBuffer)[0]--;
                free(temp);
                free(nomeExcluido);
                return;
            }

            void *temp = aux;
            *(void **)(*(void **)(aux + (sizeof(char) * 11) + (sizeof(int) * 2)) + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**)) = *(void **)(aux+(sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**)); /* Quem vem antes da pessoa a ser excluida agora aponta pra posterior a ela */
            *(void **)(*(void **)(aux + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**)) + (sizeof(char) * 11) + (sizeof(int) * 2)) = *(void **)(aux+(sizeof(char) * 11) + (sizeof(int) * 2));  /* Quem vem depois aponta pra pessoa anterior a pessoa a ser excluida */
            free(temp);
            free(nomeExcluido);
            ((int*)pBuffer)[0]--;
            return;
        }

        aux = *(void **)(aux+(sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void**));
    }

    printf("Não existe na lista alguém com esse nome.\n");
    free(nomeExcluido);
}

void Menu(void *lista, void *pBuffer){

    do{
        printf("1 - Criar pessoa na agenda\n2 - Excluir pessoa da agenda\n3 - Pesquisar por nome\n4 - Mostrar todas as pessoas\n5 - Encerrar\n");
        scanf("%d", &((int*)pBuffer)[1]);
        switch(((int*)pBuffer)[1]){
            case 1:
                criarPessoa(pBuffer, lista);
                break;
            case 2:
                excluirPessoa(pBuffer, lista);
                break;
            case 3:
                pesquisarNome(pBuffer, lista);
                break;
            case 4:
                mostrarTodos(pBuffer, lista);
            case 5:
                break;
            default:
                printf("Opção invalida. Digite novamente\n");
        }
    }while(((int*)pBuffer)[1] != 5);
    
    freeLista(lista);
    return;
}

int main(){
    void *lista = malloc(sizeof(void *) * 2);

    criarLista(lista);

    void* pBuffer = malloc(sizeof(int) * 3);

    if(!pBuffer || !lista)
    {
        printf("Erro na memoria\n");
        return 0;
    }

    criarBuffer(pBuffer);    

    Menu(pBuffer, lista);

    free(lista);
    free(pBuffer);

    return 1;
}
  
