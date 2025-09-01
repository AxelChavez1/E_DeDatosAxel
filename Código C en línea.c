#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    int i, j;

    // Pide al usuario el tamaño de las matrices
    printf("Ingresa el numero de filas: ");
    scanf("%d", &rows);
    printf("Ingresa el numero de columnas: ");
    scanf("%d", &cols);

    // Reservamos memoria dinámicamente para las tres matrices
    // Usamos un solo bloque de memoria y un puntero
    int *A = (int*) malloc(rows * cols * sizeof(int));
    int *B = (int*) malloc(rows * cols * sizeof(int));
    int *C = (int*) malloc(rows * cols * sizeof(int));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Error al reservar memoria.\n");
        return 1; // salimos si no hay memoria suficiente
    }

    // Llenamos la matriz A con los datos ingresados
    printf("\n--- Llenar matriz A ---\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", (A + i*cols + j)); 
            // Aplicamos la aritmética de punteros
        }
    }

    // Llenamos la matriz B con los datos ingresados
    printf("\n--- Llenar matriz B ---\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", (B + i*cols + j));
        }
    }

    // Aquí alculamos la suma C = A + B
    printf("\n--- Calculando C = A + B ---\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            *(C + i*cols + j) = *(A + i*cols + j) + *(B + i*cols + j);
        }
    }

    // Mostramos el resultado obtenido 
    printf("\n--- Matriz Resultante C ---\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", *(C + i*cols + j));
        }
        printf("\n");
    }

    // Liberamos la memoria
    free(A);
    free(B);
    free(C);

    return 0;
}
