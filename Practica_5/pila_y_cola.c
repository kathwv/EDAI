#include <stdio.h>
#include <stdlib.h>

#define MAX 5

//pila
typedef struct {
    int datos[MAX];
    int tope;
} Pila;

void inicializarPila(Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacía\n");
}

int pilaLlena(Pila *p) {
    return p->tope == MAX - 1;
}

int pilaVacia(Pila *p) {
    return p->tope == -1;
}

void push(Pila *p, int valor) {
    if (pilaLlena(p)) {
        printf("Error: La pila está llena\n");
    } else {
        p->tope++;
        p->datos[p->tope] = valor;
        printf("Elemento %d insertado en la pila\n", valor);
    }
}

int pop(Pila *p) {
    if (pilaVacia(p)) {
        printf("Error: La pila está vacía\n");
        return -1;
    } else {
        int valor = p->datos[p->tope];
        p->tope--;
        printf("Elemento %d extraído de la pila\n", valor);
        return valor;
    }
}

void mostrarPila(Pila *p) {
    if (pilaVacia(p)) {
        printf("Pila vacía\n");
    } else {
        printf("Estado de la pila: ");
        for (int i = 0; i <= p->tope; i++) {
            printf("%d ", p->datos[i]);
        }
        printf("\n");
    }
}

//cola
typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;

void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf("Cola inicializada vacía\n");
}

int colaLlena(Cola *c) {
    return c->final == MAX - 1;
}

int colaVacia(Cola *c) {
    return c->frente > c->final;
}

void enqueue(Cola *c, int valor) {
    if (colaLlena(c)) {
        printf("Error: La cola está llena\n");
    } else {
        c->final++;
        c->datos[c->final] = valor;
        printf("Elemento %d insertado en la cola\n", valor);
    }
}

int dequeue(Cola *c) {
    if (colaVacia(c)) {
        printf("Error: La cola está vacía\n");
        return -1;
    } else {
        int valor = c->datos[c->frente];
        c->frente++;
        printf("Elemento %d extraído de la cola\n", valor);
        return valor;
    }
}

void mostrarCola(Cola *c) {
    if (colaVacia(c)) {
        printf("Cola vacía\n");
    } else {
        printf("Estado de la cola: ");
        for (int i = c->frente; i <= c->final; i++) {
            printf("%d ", c->datos[i]);
        }
        printf("\n");
    }
}

//main 
int main() {
    Pila pila; 
    Cola cola;
    int n, valor;
    int salidaPila[MAX], salidaCola[MAX];
    int countPila = 0, countCola = 0;
    
    //1. inicializar pila
    inicializarPila(&pila);
    
    //2. insertar en la pila
    printf("¿Cuántos elementos quiere apilar? (máximo %d): ", MAX);
    scanf("%d", &n);
    
    if (n > MAX) {
    printf("No puede apilar más de %d elementos. Se ajustará a %d.\n", MAX, MAX);
    n = MAX;
    }
    for (int i = 0; i < n; i++) {
        printf("Ingrese elemento %d: ", i+1);
        scanf("%d", &valor);
        push(&pila, valor);
        mostrarPila(&pila);
    }
    
    //3. extraer elementos de la pila
   printf("¿Cuántos elementos quiere desapilar?: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
         int extraido = pop(&pila);
    if (extraido != -1) {
        salidaPila[countPila++] = extraido;
        }
        mostrarPila(&pila);
    }          
    
    //4. inicializar cola
    inicializarCola(&cola);
    
    //5. insertar elementos en la cola
    printf("¿Cuántos elementos quiere encolar? (máximo %d): ", MAX);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Ingrese elemento %d: ", i+1);
        scanf("%d", &valor);
        enqueue(&cola, valor);
        mostrarCola(&cola);
    }
    
    //6. extraer elementos de la cola
     printf("¿Cuántos elementos quiere desencolar?: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
       int extraido = dequeue(&cola);
    if (extraido != -1) {
        salidaCola[countCola++] = extraido;
    }
    mostrarCola(&cola);
}
    
    //7. comparación
   printf("\n--- Comparación ---\n");
    printf("Pila → LIFO (último en entrar, primero en salir)\n");
    printf("Cola → FIFO (primero en entrar, primero en salir)\n");
    
    return 0;
    
}
