#include <stdio.h>

void print_matrix(int rows, int cols, const int A[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) printf("%4d", A[i][j]);
        printf("\n");
    }
}
void spiral_print(int rows, int cols, const int A[rows][cols]) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    int first = 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j) { printf(first ? "%d" : " %d", A[top][j]); first = 0; }
        top++;

        for (int i = top; i <= bottom; ++i) printf(" %d", A[i][right]);
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; --j) printf(" %d", A[bottom][j]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) printf(" %d", A[i][left]);
            left++;
        }
    }
    printf("\n");
}

int main(void) {
    const int rows = 5, cols = 4;
    int A[5][4] = {
        { 1,  2,  3,  4},
        {14, 15, 16,  5},
        {13, 20, 17,  6},
        {12, 19, 18,  7},
        {11, 10,  9,  8}
    };

    printf("Matriz de ejemplo (%dx%d):\n", rows, cols);
    print_matrix(rows, cols, A);

    printf("Orden espiral: ");
    spiral_print(rows, cols, A);
    return 0;
}
