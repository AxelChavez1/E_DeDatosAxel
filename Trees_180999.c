#include <stdio.h>

#define MAX 31      
#define EMPTY -1   

typedef struct {
    int nodes[MAX];     
    int numElements;    
} ArrayBinaryTree;

static inline int left (int i){ return 2*i + 1; }
static inline int right(int i){ return 2*i + 2; }
static inline int parent(int i){ return (i-1)/2; }

void printArray(const ArrayBinaryTree *t){
    printf("numElements = %d\n[", t->numElements);
    for(int i=0;i<t->numElements;i++){
        if(i) printf(" ");
        printf("%d", t->nodes[i]);
    }
    printf("]\n");
}

void printByLevels(const ArrayBinaryTree *t){
    int start = 0;
    int width = 1;
    int level = 0;
    printf("\n== Niveles ==\n");
    while(start < t->numElements){
        int end = start + width - 1;
        if(end >= t->numElements) end = t->numElements - 1;
        printf("Nivel %d: ", level);
        for(int i=start; i<=end; ++i){
            if(i) printf(" ");
            if(t->nodes[i] == EMPTY) printf("_");
            else printf("%d", t->nodes[i]);
        }
        printf("\n");
        start += width;
        width <<= 1;  
        level++;
    }
    printf("\n");
}

void initFigureTree(ArrayBinaryTree *t){
    for(int i=0;i<MAX;i++) t->nodes[i] = EMPTY;
    
    t->nodes[0] = 7;   
    t->nodes[1] = 4;   
    t->nodes[2] = 9;   
    t->nodes[3] = 2;   
    t->nodes[4] = 6;   
    t->nodes[5] = 8;   
    t->nodes[6] = 10;  
    t->nodes[7] = 1;   
    t->nodes[8] = 3;   
    t->nodes[9] = 5;   
    t->numElements = 10;
}

void makePerfect(ArrayBinaryTree *t){
    t->nodes[10] = 11;  
    t->nodes[11] = 12;  
    t->nodes[12] = 13;  
    t->nodes[13] = 14;  
    t->nodes[14] = 15;  
    t->numElements = 15;
}

void demoIndices(int i){
    printf("Nodo en índice %d: parent=%d, left=%d, right=%d\n",
           i, parent(i), left(i), right(i));
}

int main(void){
    ArrayBinaryTree tree;
    initFigureTree(&tree);

    printf("Arbol de la figura (completo):\n");
    printArray(&tree);
    printByLevels(&tree);
    demoIndices(0);  
    demoIndices(4);  

    makePerfect(&tree);
    printf("Arbol convertido a full/perfecto (15 nodos):\n");
    printArray(&tree);
    printByLevels(&tree);

    return 0;
}
