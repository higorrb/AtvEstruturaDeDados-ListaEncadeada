#include <stdio.h>
#include <stdlib.h>

struct lista{
    int numero;
    struct lista * next;
};

typedef struct lista Lista;

Lista * incializarLista(){
    return NULL;
}

Lista * inserirLista(Lista * pL, int numero){
    Lista * novo;
    novo = (Lista *)malloc(sizeof(Lista));
    if(novo == NULL){
        printf("Erro ao alocar memoraia...\n");
    }
    else{
        novo->numero = numero;
        novo->next = pL;
        return novo;
    }
}

Lista * imprimirLista(Lista * pL){
    while(pL != NULL){
        printf("[%d] -> ", pL->numero);
        pL = pL->next;
    }
    printf("\n");
}

Lista * separarLista(Lista * pL, int n){
    Lista * pAux = pL;
    Lista * pL2 = NULL;

    while (pAux != NULL)
    {
        if(pAux->numero == n){
            pL2 = pAux->next;
            pAux->next = NULL;
            return pL2;
        }
        pAux = pAux->next;
    }
    
}

int main(){
    Lista * L;
    Lista * L2;

    L = incializarLista();
    
    L = inserirLista(L, 32);
    L = inserirLista(L, 16);
    L = inserirLista(L, 8);
    L = inserirLista(L, 4);
    L = inserirLista(L, 2);

    imprimirLista(L);

    L2 = separarLista(L ,8);

    imprimirLista(L);
    imprimirLista(L2);
    

    return 0;
}