#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *sig;
};

int main() {
    struct Nodo *head = NULL, *temp, *nuevo;
    int n, valor;
    
    printf("¿Cuántos nodos quieres en la lista simple? ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        printf("Ingresa el valor del nodo %d: ", i+1);
        scanf("%d", &valor);
        
        nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
        nuevo->dato = valor;
        nuevo->sig = NULL;
        
        if(head == NULL) {
            head = nuevo;
        } else {
            temp = head;
            while (temp->sig != NULL) {
                temp = temp->sig;
            }
            temp->sig = nuevo;
        }
        
    }
    
    printf("\nLista simple:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->sig;
    }
    printf("NULL\n");
    //liberar memoria
    temp = head;
    while (temp != NULL) {
        struct Nodo *aux = temp;
        temp = temp->sig;
        free(aux);
    }
    printf("\nMemoria liberada correctamente.\n");
    return 0;
}
