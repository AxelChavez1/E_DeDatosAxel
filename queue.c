#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *front = NULL;  
Node *rear  = NULL;  

void enqueue(int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) { /* ..node created!!! */ }
    if (newNode == NULL) {
        printf("Error: sin memoria.\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        
        front = rear = newNode;
    } else {
        
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue(int *out) {
    if (front == NULL) {
        return 0; 
    }
    Node *aux = front;
    if (out) *out = aux->data;
    front = front->next;
    if (front == NULL) rear = NULL; 
    free(aux);
    return 1;
}

void print_queue(void) {
    Node *aux = front;
    if (aux == NULL) {
        printf("[cola vacía]\n");
        return;
    }
    while (aux != NULL) {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

int main(void) {
    int op;
    for (;;) {
        printf("\n--- QUEUE ---\n");
        printf("1) Enqueue (encolar)\n");
        printf("2) Dequeue (desencolar)\n");
        printf("3) Imprimir cola\n");
        printf("0) Salir\n");
        printf("Opción: ");
        if (scanf("%d", &op) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }

        if (op == 0) break;

        if (op == 1) {
            int x;
            printf("Dato entero a encolar: ");
            if (scanf("%d", &x) == 1) {
                enqueue(x);
                printf("Encolado: %d\n", x);
            } else {
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {}
                printf("Entrada inválida.\n");
            }
        } else if (op == 2) {
            int y;
            if (dequeue(&y)) {
                printf("Desencolado: %d\n", y);
            } else {
                printf("Cola vacía.\n");
            }
        } else if (op == 3) {
            print_queue();
        } else {
            printf("Opción inválida.\n");
        }
        
    }
    int tmp;
    while (dequeue(&tmp)) {}

    return 0;
}
