#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int data){
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void preOrderTraversal(Node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}

void inOrderTraversal(Node *root) {
  if (root != NULL) {
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
  }
}

void postOrderTraversal(Node *root) {
  if (root != NULL) {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
  }
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    // Gunakan array untuk menyimpan Node yang akan dicetak
    struct Node* queue[100];
    int front = -1, rear = -1;

    // Enqueue root ke dalam queue
    queue[++rear] = root;

    while (front != rear) {
        // Dequeue Node dari queue dan cetak datanya
        struct Node* currentNode = queue[++front];
        printf("%d ", currentNode->data);

        // Enqueue left child jika ada
        if (currentNode->left != NULL)
            queue[++rear] = currentNode->left;

        // Enqueue right child jika ada
        if (currentNode->right != NULL)
            queue[++rear] = currentNode->right;
    }
}


int main() {
  Node *root = createNode(35);

  root->left = createNode(23);
  root->left->left = createNode(15);
  root->left->left->left = createNode(9);
  root->left->left->left->left = createNode(5);
  root->left->right = createNode(26);
  root->left->right->left = createNode(25);
  root->left->right->right = createNode(28);

  root->right = createNode(40);
  root->right->left = createNode(37);
  root->right->right = createNode(45);
  root->right->right->left = createNode(41);
  root->right->left->right = createNode(39);

  printf("### preOrderTraversal\n");
  preOrderTraversal(root);
  printf("--------------------\n");
  printf("### inOrderTraversal\n");
  inOrderTraversal(root);
  printf("--------------------\n");
  printf("### postOrderTraversal\n");
  postOrderTraversal(root);
  printf("--------------------\n");
  printf("### levelOrderTraversal\n");
  levelOrderTraversal(root);


  return 0;
}
