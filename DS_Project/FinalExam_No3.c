#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node untuk binary search tree
typedef struct Node {
    char *word;
    int frequency;
    struct Node *left, *right;
} Node;

// fungsi untuk membuat node baru
Node* createNode(char *word) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->word = strdup(word);
    newNode->frequency = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// fungsi untuk memasukkan kata ke dalam binary search tree
Node* insert(Node *root, char *word) {
    // tree kosong, buat node baru
    if (root == NULL) return createNode(word);

    // kata sudah ada, naikkan frekuensinya
    int cmp = strcmp(word, root->word);
    if (cmp == 0) {
        root->frequency++;
    } 
    // jika kata lebih kecil, move ke subtree kiri
    else if (cmp < 0) {
        root->left = insert(root->left, word);
    } 
    // jika kata lebih besar, move ke subtree kanan
    else {
        root->right = insert(root->right, word);
    }
    return root;
}

// fungsi untuk mencari kata yang paling sering disebutkan
void findMostFrequent(Node *root, char **mostFrequentWord, int *maxFrequency) {
    if (root == NULL) return;

    // mencari di subtree kiri
    findMostFrequent(root->left, mostFrequentWord, maxFrequency);

    // update kata yang paling sering disebutkan jika perlu
    if (root->frequency > *maxFrequency) {
        *maxFrequency = root->frequency;
        *mostFrequentWord = root->word;
    }

    // mencari di subtree kanan
    findMostFrequent(root->right, mostFrequentWord, maxFrequency);
}

// fungsi untuk membebaskan memori dari tree
void freeTree(Node *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root->word);
    free(root);
}

int main() {
    Node *root = NULL;
    char word[100];
    char *mostFrequentWord = NULL;
    int maxFrequency = 0;

    printf("Enter words (type 'exit' to finish):\n");

    while (1) {
        printf("Word: ");
        scanf("%s", word);

        // jika pengguna mengetik 'exit', maka proses input berakhir
        if (strcmp(word, "exit") == 0) {
            break;
        }

        // masukkan kata ke dalam binary search tree
        root = insert(root, word);
    }

    // mencari kata yang paling sering disebutkan
    findMostFrequent(root, &mostFrequentWord, &maxFrequency);

    if (mostFrequentWord != NULL) {
        printf("Most frequent word: %s, Frequency: %d\n", mostFrequentWord, maxFrequency);
    } else {
        printf("No words found.\n");
    }

    // Bebaskan memori tree
    freeTree(root);

    return 0;
}
