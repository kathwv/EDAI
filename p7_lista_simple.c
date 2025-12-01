#include  <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato; 
    struct Nodo *siguiente;
};

//insertar inicio
void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

//recorrer lista
void recorrer(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

//elimina un nodo por valor
void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;
    
    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }
    
    if (actual == NULL) {
        printf("Valor no encontrado.\n");
        return;
    }
    
    if (anterior == NULL) {
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }
    
    free(actual);
    printf("Nodo eliminado.\n");
}

//liberar memoria
void liberar(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        struct Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    printf("Memoria liberada correctamente.\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    int n, valor;
    
    printf("¿Cuántos valores desear insertar?: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }
    
    printf("\nLista actual: ");
    recorrer(cabeza);
    
    printf("¿Qué valor deseas eliminar?: ");
    scanf("%d", &valor);
    eliminar(&cabeza, valor);
    
    printf("Lista después de eliminar: ");
    recorrer(cabeza);
    
    liberar(cabeza);
    return 0;
}
