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


  return 0;
}
