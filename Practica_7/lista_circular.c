#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

//inserta al inicio en lista circular
void insertarInicioCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->siguiente = *cabeza;
    } else {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
        (*ultimo)->siguiente = *cabeza;
    }
}

//recorre lista 
void recorrerCircular(struct Nodo *cabeza) {
    if (cabeza == NULL) return;
    struct Nodo *actual = cabeza;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("(cabeza)\n");
}

//elimina un nodo circular
void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL) return;

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = *ultimo;

    do {
        if (actual->dato == valor) {
            if (actual == *cabeza) {
                *cabeza = actual->siguiente;
                (*ultimo)->siguiente = *cabeza;
            } else if (actual == *ultimo) {
                *ultimo = anterior;
                (*ultimo)->siguiente = *cabeza;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            printf("Nodo eliminado.\n");
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    printf("Valor no encontrado.\n");
}

//libera memoria 
void liberarCircular(struct Nodo *cabeza) {
    if (cabeza == NULL) return;
    struct Nodo *actual = cabeza->siguiente;
    while (actual != cabeza) {
        struct Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    free(cabeza);
    printf("Memoria liberada correctamente.\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int n, valor;

    printf("¿Cuántos valores desea insertar en lista circular? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarInicioCircular(&cabeza, &ultimo, valor);
        recorrerCircular(cabeza);
    }

    printf("\nLista circular actual: ");
    recorrerCircular(cabeza);

    printf("¿Qué valor quiere eliminar? ");
    scanf("%d", &valor);
    eliminarCircular(&cabeza, &ultimo, valor);

    printf("Lista después de eliminar: ");
    recorrerCircular(cabeza);

    liberarCircular(cabeza);
    return 0;
}
