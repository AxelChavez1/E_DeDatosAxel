#include <stdio.h>
#define CAP 5 

int enqueue(int q[], int *rear, int *count, int x) {
    if (*count == CAP) return 0;              
    q[*rear] = x;                              
    *rear = (*rear + 1) % CAP;                
    (*count)++;                               
    return 1;
}

int dequeue(int q[], int *front, int *count, int *out) {
    if (*count == 0) return 0;                 
    *out = q[*front];                         
    *front = (*front + 1) % CAP;           
    (*count)--;                                
    return 1;
}

void printQueue(const int q[], int front, int count) {
    if (count == 0) {
        printf("Cola: [vacia]\n");
        return;
    }
    printf("Cola: [");
    for (int i = 0; i < count; i++) {
        int idx = (front + i) % CAP;
        printf("%d", q[idx]);
        if (i < count - 1) printf(" ");
    }
    printf("]\n");
}

int main(void) {
    int queue[CAP];     
    int front = 0;      
    int rear  = 0;     
    int count = 0;      

    int opcion;

    do {
        printf("\n--- COLA DE ENTEROS (capacidad %d) ---\n", CAP);
        printf("1) Enqueue (encolar)\n");
        printf("2) Dequeue (desencolar)\n");
        printf("0) Salir\n");
        printf("Elige una opcion: ");
        if (scanf("%d", &opcion) != 1) {
            
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            opcion = -1;
        }

        switch (opcion) {
            case 1: {
                int x;
                printf("Ingresa el entero a encolar: ");
                if (scanf("%d", &x) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {}
                    printf("Entrada invalida.\n");
                } else {
                    if (enqueue(queue, &rear, &count, x))
                        printf("OK: %d encolado.\n", x);
                    else
                        printf("La cola esta llena. No se pudo encolar.\n");
                }
                printQueue(queue, front, count);   
                break;
            }
            case 2: {
                int val;
                if (dequeue(queue, &front, &count, &val))
                    printf("OK: se desencolo %d.\n", val);
                else
                    printf("La cola esta vacia. No se puede desencolar.\n");
                printQueue(queue, front, count);
                break;
            }
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida.\n");
                printQueue(queue, front, count);
        }
    } while (opcion != 0);

    return 0;
}
