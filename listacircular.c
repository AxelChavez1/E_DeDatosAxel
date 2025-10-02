#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

static Node* head = NULL;
static Node* tail = NULL;
static int    size_ = 0;

static void flush_input(void){
    int c; while((c=getchar())!='\n' && c!=EOF){}
}

int  isEmpty(void)        { return head == NULL; }
int  getSize(void)        { return size_; }
Node* getHead(void)       { return head; }
Node* getTail(void)       { return tail; }

void addFront(int value){
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n){ puts("Error: sin memoria."); return; }
    n->data = value;
    if(isEmpty()){
        head = tail = n;
        n->next = n;                
    } else {
        n->next = head;
        head    = n;
        tail->next = head;           
    }
    size_++;
}

void addEnd(int value){
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n){ puts("Error: sin memoria."); return; }
    n->data = value;
    if(isEmpty()){
        head = tail = n;
        n->next = n;
    } else {
        n->next    = head;
        tail->next = n;
        tail       = n;
    }
    size_++;
}

void addAt(int pos, int value){
    if(pos < 0 || pos > size_){ puts("Posición inválida."); return; }
    if(pos == 0){ addFront(value); return; }
    if(pos == size_){ addEnd(value); return; }
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n){ puts("Error: sin memoria."); return; }
    n->data = value;
    Node* cur = head;
    for(int i=0;i<pos-1;i++) cur = cur->next;   
    n->next    = cur->next;
    cur->next  = n;
    size_++;
}

void removeFront(void){
    if(isEmpty()){ puts("Lista vacía."); return; }
    Node* tmp = head;
    if(head == tail){                 
        head = tail = NULL;
    } else {
        head = head->next;
        tail->next = head;
    }
    printf("Eliminado: %d\n", tmp->data);
    free(tmp);
    size_--;
}

void removeEnd(void){
    if(isEmpty()){ puts("Lista vacía."); return; }
    if(head == tail){
        printf("Eliminado: %d\n", head->data);
        free(head);
        head = tail = NULL;
        size_--;
        return;
    }
    Node* cur = head;
    while(cur->next != tail) cur = cur->next;  
    printf("Eliminado: %d\n", tail->data);
    free(tail);
    tail = cur;
    tail->next = head;
    size_--;
}

void removeAt(int pos){
    if(pos < 0 || pos >= size_){ puts("Posición inválida."); return; }
    if(pos == 0){ removeFront(); return; }
    if(pos == size_-1){ removeEnd(); return; }
    Node* cur = head;
    for(int i=0;i<pos-1;i++) cur = cur->next;  
    Node* del = cur->next;
    cur->next = del->next;
    printf("Eliminado: %d\n", del->data);
    free(del);
    size_--;
}

int search(int value){
    if(isEmpty()) return -1;
    Node* cur = head;
    for(int i=0;i<size_;i++){
        if(cur->data == value) return i;
        cur = cur->next;
    }
    return -1;
}

void traverse(void (*fn)(int)){
    if(isEmpty() || !fn) return;
    Node* cur = head;
    for(int i=0;i<size_;i++){
        fn(cur->data);
        cur = cur->next;
    }
}

void display(void){
    if(isEmpty()){ puts("[lista vacía]"); return; }
    Node* cur = head;
    for(int i=0;i<size_;i++){
        printf("%d", cur->data);
        if(i+1<size_) printf(" -> ");
        cur = cur->next;
    }
    printf("  (circular)\n");
}

void clear(void){
    while(!isEmpty()) removeFront();
}

static void print_cb(int x){ printf("%d ", x); }

int main(void){
    int op, val, pos;
    do{
        printf("\n=== Lista Circular ===\n");
        printf("1) Add Front\n2) Add End\n3) Add At\n");
        printf("4) Remove Front\n5) Remove End\n6) Remove At\n");
        printf("7) Search\n8) Traverse\n9) Display\n");
        printf("10) Size\n11) IsEmpty\n12) GetHead/GetTail\n");
        printf("13) Clear\n0) Salir\n");
        printf("Opción: ");
        if(scanf("%d",&op)!=1){ flush_input(); continue; }

        switch(op){
            case 1:
                printf("Valor: "); if(scanf("%d",&val)==1) addFront(val); else flush_input();
                break;
            case 2:
                printf("Valor: "); if(scanf("%d",&val)==1) addEnd(val); else flush_input();
                break;
            case 3:
                printf("Posición (0..%d): ", getSize());
                if(scanf("%d",&pos)!=1){ flush_input(); break; }
                printf("Valor: "); if(scanf("%d",&val)!=1){ flush_input(); break; }
                addAt(pos,val);
                break;
            case 4: removeFront(); break;
            case 5: removeEnd();   break;
            case 6:
                printf("Posición (0..%d-1): ", getSize());
                if(scanf("%d",&pos)==1) removeAt(pos); else flush_input();
                break;
            case 7:
                printf("Valor a buscar: ");
                if(scanf("%d",&val)==1){
                    int idx = search(val);
                    if(idx==-1) puts("No encontrado.");
                    else printf("Encontrado en índice %d.\n", idx);
                } else flush_input();
                break;
            case 8:
                printf("Traverse: ");
                traverse(print_cb);
                printf("\n");
                break;
            case 9:  display(); break;
            case 10: printf("Size = %d\n", getSize()); break;
            case 11: printf("IsEmpty = %s\n", isEmpty()? "true":"false"); break;
            case 12:
                if(isEmpty()) puts("Head = NULL, Tail = NULL");
                else printf("Head = %d, Tail = %d\n", getHead()->data, getTail()->data);
                break;
            case 13: clear(); puts("Lista limpiada."); break;
            case 0:  break;
            default: puts("Opción inválida.");
        }
    }while(op!=0);

    clear();
    return 0;
}
