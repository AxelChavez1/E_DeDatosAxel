#include <stdio.h>
#include <limits.h>

#define CAP 100000

static int heap[CAP + 1];
static int heapSize = 0;

static inline void swap(int *a, int *b){ int t = *a; *a = *b; *b = t; }
static inline int parent(int i){ return i/2; }
static inline int left(int i){ return 2*i; }
static inline int right(int i){ return 2*i+1; }

void showHeap(void){
    printf("Heap(size=%d):", heapSize);
    for(int i = 1; i <= heapSize; ++i) printf(" %d", heap[i]);
    putchar('\n');
}

void reHeapDown(int i){
    for(;;){
        int l = left(i), r = right(i), largest = i;
        if(l <= heapSize && heap[l] > heap[largest]) largest = l;
        if(r <= heapSize && heap[r] > heap[largest]) largest = r;
        if(largest == i) break;
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
}

void insert(int item){
    if(heapSize == CAP){
        fprintf(stderr, "Aviso: heap lleno, %d ignorado\n", item);
        return;
    }
    heap[++heapSize] = item;
    for(int i = heapSize; i > 1 && heap[parent(i)] < heap[i]; i = parent(i))
        swap(&heap[i], &heap[parent(i)]);
}

int removeMax(void){
    if(heapSize == 0) return INT_MIN;
    int maxv = heap[1];
    heap[1] = heap[heapSize--];
    if(heapSize) reHeapDown(1);
    return maxv;
}

void printMapping(void){
    if(!heapSize){ puts("Mapeo: (heap vacío)"); return; }
    puts("Mapeo arreglo↔árbol  [i:valor] -> L[2i] / R[2i+1]");
    for(int i = 1; i <= heapSize; ++i){
        int l = left(i), r = right(i);
        printf(" [%d:%d] -> ", i, heap[i]);
        if(l <= heapSize) printf("L[%d:%d]", l, heap[l]); else printf("L[-:-]");
        printf(" / ");
        if(r <= heapSize) printf("R[%d:%d]\n", r, heap[r]); else printf("R[-:-]\n");
    }
}

int main(void){
    int n, k, x;

    printf("n: ");
    if(scanf("%d", &n) != 1 || n < 0){ fprintf(stderr, "Entrada invalida.\n"); return 1; }

    printf("n enteros:\n");
    for(int i = 0; i < n; ++i){
        if(scanf("%d", &x) != 1){ fprintf(stderr, "Entrada invalida.\n"); return 1; }
        insert(x);
        showHeap();                
    }

    puts("\nMapeo tras inserciones:");
    printMapping();

    printf("\nK (eliminaciones): ");
    if(scanf("%d", &k) != 1 || k < 0){ fprintf(stderr, "Entrada invalida.\n"); return 1; }

    for(int j = 0; j < k; ++j){
        int mx = removeMax();
        if(mx == INT_MIN){ puts("Heap vacio, fin de eliminaciones."); break; }
        printf("removeMax = %d\n", mx);
        showHeap();                 
    }

    puts("\nMapeo final:");
    printMapping();
    return 0;
}
