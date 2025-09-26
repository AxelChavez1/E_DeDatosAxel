#include <stdio.h>
#define MAXN 10000  

int es_abridor(char c) { return c=='(' || c=='[' || c=='{'; }
int es_cerrador(char c) { return c==')' || c==']' || c=='}'; }

int hace_par(char o, char c) {
    return (o=='(' && c==')') || (o=='[' && c==']') || (o=='{' && c=='}');
}

int main(void) {
    char s[MAXN+5];
    if (!fgets(s, sizeof(s), stdin)) return 0;

    int stack[MAXN];   
    int top = -1;     

    for (int i = 0; s[i] && s[i] != '\n'; ++i) {
        char c = s[i];

        if (es_abridor(c)) {
            if (top == MAXN - 1) {  
                printf("ERROR %d\n", i);
                return 0;
            }
            stack[++top] = i;   
        } else if (es_cerrador(c)) {
            if (top == -1) {        
                printf("ERROR %d\n", i);
                return 0;
            }
            int j = stack[top]; 
            if (!hace_par(s[j], c)) {
                printf("ERROR %d\n", i);  
                return 0;
            }
            --top;                  
        }
        
    }

    if (top != -1) {
        
        printf("ERROR %d\n", stack[0]);
    } else {
        printf("OK\n");
    }
    return 0;
}
