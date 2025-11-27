#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *sig;
    
};

int main() {
    struct Nodo *head = NULL, *temp, *nuevo;
    int n, valor;
    
    printf("¿Cuántos nodos quieres en la lista cicular? ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        printf("Ingresa el valor del nodo %d: ", i+1);
        scanf("%d", &valor);
        
        nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
        nuevo->dato = valor;
        nuevo->sig = NULL;
        
        if(head == NULL) {
            head = nuevo;
            head->sig = head; //primer nodo apunta a si mismo
        } else {
            temp=head;
            while (temp->sig != head) {
                temp = temp->sig;
            }
            temp->sig = nuevo;
            nuevo->sig = head;  // ultimo apunta al primero
        } 
    }
    printf("\nLista circular:\n");
    temp=head;
    if(head != NULL) {
        do {
            printf("%d -> ", temp->dato);
            temp = temp->sig;
        } while (temp != head);
    }
    printf("(regresa al inicio)\n");
    
    //liberar memoria
    if(head != NULL) {
        temp= head->sig;
        while (temp != head) {
            struct Nodo *aux = temp;
            temp = temp->sig;
            free(aux);
        }
        free(head);
    }
    printf("\nMemoria liberada exitosamente.\n");
    return 0;
}
