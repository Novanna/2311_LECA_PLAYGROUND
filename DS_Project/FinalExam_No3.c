#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Implementasi AVL Tree
   untuk cetak report score siswa berurutan
*/

typedef struct AVLNode {
    int studentID;
    int score;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

// create node baru
AVLNode* createNode(int studentID, int score) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    newNode->studentID = studentID;
    newNode->score = score;
    // node baru diinisiasi dengan tinggi = 1
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// tinggi node
int height(AVLNode *node) {
    return node ? node->height : 0;
}

// faktor keseimbangan
int getBalance(AVLNode *node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// to right rotation
AVLNode* rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

// to left rotation
AVLNode* leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

// insertion di node
AVLNode* insertOrUpdate(AVLNode* node, int studentID, int score) {
    // if tree kosong, create node baru
    if (node == NULL)
        return createNode(studentID, score);

    // compare student id 
    if (studentID < node->studentID)
        node->left = insertOrUpdate(node->left, studentID, score);
    else if (studentID > node->studentID)
        node->right = insertOrUpdate(node->right, studentID, score);
    else // update score jika student id ditemukan
        node->score += score;

    // update tinggi node
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // get info faktor keseimbangan
    int balance = getBalance(node);

    // cek tree balance, rotate jika diperlukan
    // cek balance di subtree kiri
    if (balance > 1 && studentID < node->left->studentID)
        return rightRotate(node);
    // cek balance di subtree kanan kiri
    if (balance > 1 && studentID > node->left->studentID) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // cek balance di subtree kanan
    if (balance < -1 && studentID > node->right->studentID)
        return leftRotate(node);

    // cek balance di subtree kiri kanan
    if (balance < -1 && studentID < node->right->studentID) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// fungsi cetak skor mahasiswa, find by ID
AVLNode* search(AVLNode* root, int studentID) {
    if (root == NULL || root->studentID == studentID)
        return root;

    if (studentID < root->studentID)
        return search(root->left, studentID);
    else
        return search(root->right, studentID);
}

// fungsi cetak semua skor mahasiswa (menggunakan in-order traversal)
void printAllScores(AVLNode* root) {
    if (root == NULL)
        return;

    printAllScores(root->left);
    printf("|%10d|%10d|\n", root->studentID, root->score);
    printAllScores(root->right);
}

// fungsi untuk free memori tree
void freeTree(AVLNode *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// main function
int main() {
    AVLNode* root = NULL;
    int studentID, score;
    char input[20];
    // 1. User perlu input data student
    printf("\n______________________________________________\n");
    printf("Please enter \n> UserID (4 Digit Number) and\n> Score (1-100)\n");
    printf("type 'end' to finish input");
    printf("\n______________________________________________\n");
    while (1) {
        printf("> Student ID: ");
        scanf("%s", input);

        if (strcmp(input, "end") == 0)
            break;

        studentID = atoi(input);

        printf("> Score: ");
        scanf("%d", &score);

        root = insertOrUpdate(root, studentID, score);
    }

    // 2. User bisa pilih action selanjutnya
    int choice;
    while (1) {
        printf("\n______________________________________________");
        printf("\nHai, what can i help?\n");
        printf("1. View Student Score\n");
        printf("2. Report All Student Scores\n");
        printf("3. Exit\n");
        printf("> Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // View Student Score
                printf("\n______________________________________________");
                printf("\n> Enter Student ID to View: ");
                scanf("%d", &studentID);
                AVLNode* node = search(root, studentID);
                if (node)
                    printf(">> Student ID: %d, Score: %d\n", node->studentID, node->score);
                else
                    printf(">> Student ID not found.\n");
                printf("\n______________________________________________");
                break;

            case 2: // Report All Student Scores
                printf("\n______________________________________________");
                printf("\n>> Report All Student Scores \n");
                printf("|%10s|%10s|\n", "UserID  ", "Score  ");
                printf("|%10s|%10s|\n", "==========", "==========");
                printAllScores(root);
                printf("\n______________________________________________");
                break;

            case 3: // Exit
                freeTree(root);
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
