#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

//insertar al final en lista doble circular
void insertarFinalCircular(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if (*inicio == NULL) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *inicio = nuevo;
    } else {
        struct Nodo *ultimo = (*inicio)->anterior;
        nuevo->siguiente = *inicio;
        nuevo->anterior = ultimo;
        ultimo->siguiente = nuevo;
        (*inicio)->anterior = nuevo;
    }
}

//recorrer circular hacia adelante
void recorrerCircularAdelante(struct Nodo *inicio) {
    if (inicio == NULL) return;
    struct Nodo *actual = inicio;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != inicio);
    printf("(inicio)\n");
}

//recorrer hacia atrás
void recorrerCircularAtras(struct Nodo *inicio) {
    if (inicio == NULL) return;
    struct Nodo *actual = inicio->anterior;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->anterior;
    } while (actual != inicio->anterior);
    printf("(fin)\n");
}

//rliminar nodo 
void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) return;

    struct Nodo *actual = *inicio;
    do {
        if (actual->dato == valor) {
            if (actual->siguiente == actual) { 
                free(actual);
                *inicio = NULL;
                printf("Lista vacía.\n");
                return;
            }
            actual->anterior->siguiente = actual->siguiente;
            actual->siguiente->anterior = actual->anterior;
            if (actual == *inicio)
                *inicio = actual->siguiente;
            free(actual);
            printf("Nodo eliminado.\n");
            return;
        }
        actual = actual->siguiente;
    } while (actual != *inicio);

    printf("Valor no encontrado.\n");
}

//liberar memoria
void liberarCircular(struct Nodo *inicio) {
    if (inicio == NULL) return;
    struct Nodo *actual = inicio->siguiente;
    while (actual != inicio) {
        struct Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    free(inicio);
    printf("Memoria liberada correctamente.\n");
}

int main() {
    struct Nodo *inicio = NULL;
    int n, valor;

    printf("¿Cuántos valores deseas insertar en lista doble circular? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarFinalCircular(&inicio, valor);
        recorrerCircularAdelante(inicio);
    }

    printf("\nRecorrido circular hacia adelante: ");
    recorrerCircularAdelante(inicio);
    printf("Recorrido circular hacia atrás: ");
    recorrerCircularAtras(inicio);

    printf("¿Qué valor deseas eliminar? ");
    scanf("%d", &valor);
    eliminarCircular(&inicio, valor);

    printf("Lista después de eliminar: ");
    recorrerCircularAdelante(inicio);

    liberarCircular(inicio);
    return 0;
}
