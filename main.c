#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int info;
    struct lista *next;
};

typedef struct lista Lista;

Lista *iniciarLista(){
    return NULL;
}

Lista *inserirInicio(Lista *pL, int info){
    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    if(novo != NULL){
        novo->info = info;
        novo->next = pL;
        return novo;
    }
    else
        printf("Erro ao alocar memoria...\n");
}


Lista *inserirFinal(Lista *pL, int info){
    Lista *novo;
    Lista *aux;
    novo = (Lista *)malloc(sizeof(Lista));
    
    if(novo != NULL){
        novo->info = info;
        novo->next = NULL;

        if(pL == NULL){
            pL = novo;
        }
        else{
            aux = pL;
            while(aux->next != NULL){
                aux = aux->next;
            }
            aux->next = novo;
        }
        return pL;
    }
    else{
        printf("erro ao alocar memoria...\n");
    }

}

Lista *inserirMeio(Lista *pL, int info, int anterior){
    Lista *novo;
    Lista *aux;
    novo = (Lista *)malloc(sizeof(Lista));
    if(novo != NULL){
        novo->info = info;
        if (pL == NULL)
        {
            novo->next = NULL;
            pL = novo;
        }
        else{
            aux = pL;
            while (aux->next != NULL && aux->info != anterior)
            {
                aux = aux->next;
            }
            novo->next = aux->next;
            aux->next = novo;
            
        }
    }
    else{
        printf("erro ao aloca memoria...");
    }
    return pL;
}

Lista *inserirOrdenado(Lista *pL, int info){
    Lista *novo, *aux, *anterior = NULL;
    novo = (Lista *)malloc(sizeof(Lista));

    if(novo == NULL){
        printf("erro ao alocar memoria...");
        return pL;
    }
    
    novo->info = info;
    
    if(pL == NULL || pL->info >= info){
        novo->next = pL;
        pL = novo;
        return pL;
    }

    aux = pL;
    while(aux != NULL && aux->info < info){
        anterior = aux;
        aux = aux->next;
    }
    anterior->next = novo;
    novo->next = aux;
    return pL;

}

void imprirmirLista(Lista *pL){
    while(pL != NULL){
        printf("%d -> ", pL->info);
        pL = pL->next;
    }
    printf("\n");
}


int main(){
    int info, count = 0;
    Lista * L;
    
    L = iniciarLista();

    for(int i = 0; i < 5; i++){
    printf("Digiet um numero para adicionar na lista: ");
    scanf("%d", &info);
    count++;
    L= inserirOrdenado(L, info);
    }

    imprirmirLista(L);


    
    L = inserirMeio(L, 50, 0);
    count++;
    imprirmirLista(L);
    L = inserirInicio(L, 10);
    count++;
    imprirmirLista(L);
    L = inserirInicio(L, 20);
    count++;
    imprirmirLista(L);
    L = inserirFinal(L, 30);
    count++;
    imprirmirLista(L);
    L = inserirMeio(L, 40, 10);
    count++;
    imprirmirLista(L);

    printf("Foram inseridos [%d] dados na lista.", count);
    
    return 0;
}