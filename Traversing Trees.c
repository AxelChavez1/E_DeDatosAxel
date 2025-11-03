#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node* new_node(int key) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

Node* bst_insert(Node* root, int key) {
    if (root == NULL) return new_node(key);
    if (key < root->key)      root->left  = bst_insert(root->left, key);
    else if (key > root->key) root->right = bst_insert(root->right, key);
    return root;
}

void preorder(Node* root) {
    if (root) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

void free_tree(Node* root) {
    if (root) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main(void) {
    int values[] = {40, 20, 60, 10, 30, 50, 70};
    size_t n = sizeof(values)/sizeof(values[0]);

    Node* root = NULL;
    for (size_t i = 0; i < n; ++i) {
        root = bst_insert(root, values[i]);
    }

    printf("Pre-order:   ");
    preorder(root);
    printf("\n");

    printf("In-order:    ");
    inorder(root);
    printf("\n");

    printf("Post-order:  ");
    postorder(root);
    printf("\n");

    free_tree(root);
    return 0;
}
