#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define constants for node colors
#define RED 0
#define BLACK 1

// struct for the file metadata
typedef struct FileMetadata {
    char file_id[37];
    char file_name[50];
    int file_size;
    time_t uploaded_at;
    time_t last_update;
    char owner_id[37];
    char access_type[10];
} FileMetadata;

// struct for the Red-black Tree node
typedef struct RBNode {
    FileMetadata data;
    int color;
    struct RBNode *left, *right, *parent;
} RBNode;

// Root of the Red-black Tree
RBNode* root = NULL;

// generate a simple UUID 
// simple implementation -> using random numbers
void generateUUID(char* uuid) {
    sprintf(uuid, "%08x-%04x-%04x-%04x-%012x",
            rand(), rand() % 0xFFFF, rand() % 0xFFFF, rand() % 0xFFFF, rand());
}

// create a new RBNode
RBNode* createNode(FileMetadata data) {
    RBNode* newNode = (RBNode*)malloc(sizeof(RBNode));
    newNode->data = data;
    newNode->color = RED;  // new nodes initially red
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// do left rotation
void leftRotate(RBNode** root, RBNode* x) {
    RBNode* y = x->right;
    x->right = y->left;
    if (y->left != NULL) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL) *root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// do right rotation
void rightRotate(RBNode** root, RBNode* y) {
    RBNode* x = y->left;
    y->left = x->right;
    if (x->right != NULL) x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL) *root = x;
    else if (y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}

// FUNCTION MENU 1: Insert File
// fix violations after insertion
void fixInsert(RBNode** root, RBNode* z) {
    while (z != *root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBNode* y = z->parent->parent->right;
            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            RBNode* y = z->parent->parent->left;
            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

// insert a node into the Red-Black Tree
void insert(RBNode** root, FileMetadata data) {
    RBNode* z = createNode(data);
    RBNode* y = NULL;
    RBNode* x = *root;

    while (x != NULL) {
        y = x;
        if (strcmp(z->data.file_name, x->data.file_name) < 0) x = x->left;
        else if (strcmp(z->data.file_name, x->data.file_name) > 0) x = x->right;
        else {
            // Update existing file
            x->data.file_size = z->data.file_size;
            x->data.last_update = time(NULL);
            strcpy(x->data.access_type, z->data.access_type);
            free(z);
            return;
        }
    }

    z->parent = y;
    if (y == NULL) *root = z;
    else if (strcmp(z->data.file_name, y->data.file_name) < 0) y->left = z;
    else y->right = z;

    fixInsert(root, z);
}

// FUNCTION MENU 5: View All Files
// do in-order traversal to view files
void inOrderView(RBNode* root) {
    if (root == NULL) return;
    inOrderView(root->left);
    printf("|%s|%s|%d|%s|%s|%s|%s|\n",
           root->data.file_id, root->data.file_name, root->data.file_size,
           ctime(&root->data.uploaded_at), root->data.owner_id, root->data.access_type,
           ctime(&root->data.last_update));
    inOrderView(root->right);
}

// find a node by file_name
RBNode* findNode(RBNode* root, char* file_name) {
    while (root != NULL && strcmp(file_name, root->data.file_name) != 0) {
        if (strcmp(file_name, root->data.file_name) < 0) root = root->left;
        else root = root->right;
    }
    return root;
}

// FUNCTION MENU 2: Delete File
// find the minimum node in a subtree
RBNode* minimum(RBNode* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// replace one subtree as a child of its parent with another subtree
void rbTransplant(RBNode** root, RBNode* u, RBNode* v) {
    if (u->parent == NULL)
        *root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v != NULL)
        v->parent = u->parent;
}

// fix violations after deletion
void fixDelete(RBNode** root, RBNode* x) {
    while (x != *root && x->color == BLACK) {
        if (x == x->parent->left) {
            RBNode* w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(root, x->parent);
                w = x->parent->right;
            }
            if ((w->left == NULL || w->left->color == BLACK) &&
                (w->right == NULL || w->right->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right == NULL || w->right->color == BLACK) {
                    if (w->left != NULL) w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->right != NULL) w->right->color = BLACK;
                leftRotate(root, x->parent);
                x = *root;
            }
        } else {
            RBNode* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(root, x->parent);
                w = x->parent->left;
            }
            if ((w->right == NULL || w->right->color == BLACK) &&
                (w->left == NULL || w->left->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left == NULL || w->left->color == BLACK) {
                    if (w->right != NULL) w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->left != NULL) w->left->color = BLACK;
                rightRotate(root, x->parent);
                x = *root;
            }
        }
    }
    if (x != NULL) x->color = BLACK;
}


// delete a node by file_name
void deleteNode(RBNode** root, char* file_name) {
    RBNode* z = findNode(*root, file_name);
    if (z == NULL) {
        printf(">> File not found!\n");
        return;
    }

    RBNode* y = z;
    RBNode* x;
    int y_original_color = y->color;

    if (z->left == NULL) {
        x = z->right;
        rbTransplant(root, z, z->right);
    } else if (z->right == NULL) {
        x = z->left;
        rbTransplant(root, z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            if (x != NULL) x->parent = y;
        } else {
            rbTransplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rbTransplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    free(z);

    if (y_original_color == BLACK && x != NULL) {
        fixDelete(root, x);
    }
}

// FUNCTION MENU 3: View File by Name
void viewFileByName(RBNode* root, char* file_name) {
    RBNode* node = findNode(root, file_name);
    if (node == NULL) {
        printf(">> File not found!\n");
        return;
    }
    printf("|%s|%s|%d|%s|%s|%s|\n",
           node->data.file_id, node->data.file_name, node->data.file_size,
           ctime(&node->data.uploaded_at), node->data.owner_id, node->data.access_type);

}

// Main function: file system operations
int main() {
    char user_name[50];
    char user_id[37];
    printf("==================================\n");
    printf("> Username: ");
    scanf("%s", user_name);
    printf("\n==================================\n");
    printf(">> Hallo, %s!\n>> here's your user_id = ",user_name);
    generateUUID(user_id);
    printf("%s\n", user_id);

    int choice;
    char file_name[30];
    int file_size;
    char access_type[10];
    FileMetadata data;

    while (1) {
        printf("\n==================================");
        printf("\nHOME PAGE - CLOUD FILE SYSTEM\nMenu:\n");
        printf("1. Insert File\n");
        printf("2. Delete File\n");
        printf("3. View File by Name\n");
        printf("4. View All Files\n");
        printf("5. Exit\n");
        printf("==================================\n");
        printf("> Enter your choice: ");
        scanf("%d", &choice);
        printf("==================================\n");

        switch (choice) {
            case 1:
                printf("\n==================================\n");
                printf("Menu: Insert File\n");
                printf("> Enter File Name: ");
                scanf("%s", file_name);
                printf("> Enter File Size: ");
                scanf("%d", &file_size);
                printf("> Enter Access Type (public/private): ");
                scanf("%s", access_type);

                // generate random file_id
                generateUUID(data.file_id);
                strcpy(data.file_name, file_name);
                data.file_size = file_size;
                data.uploaded_at = time(NULL);
                data.last_update = data.uploaded_at;
                strcpy(data.owner_id, user_id);
                strcpy(data.access_type, access_type);

                insert(&root, data);
                break;

            case 2:
                printf("\n==================================\n");
                printf("Menu: Delete File\n");
                printf("> Enter File Name to Delete: ");
                scanf("%s", file_name);
                deleteNode(&root, file_name);
                printf(">> %s succesfully delete!", file_name);
                break;

            case 3:
                printf("\n==================================\n");
                printf("Menu: View File by Name\n");
                printf("> Enter File Name to View: ");
                scanf("%s", file_name);
                printf(">> Look up file name: %s\n",file_name);
                printf("|%s|%s|%s|%s|%s|%s|%s|\n","FILE_ID", "FILE_NAME","FILE_SIZE","UPLOADED_AT", "OWNER_ID", "ACCESS_TYPE","LAST_UPDATE");
                viewFileByName(root, file_name);
                break;

            case 4:
                printf("\n==================================\n");
                printf(">> Metadata Schema: FILE_DATA_CENTER\n");
                printf("|%s|%s|%s|%s|%s|%s|%s|\n","FILE_ID", "FILE_NAME","FILE_SIZE","UPLOADED_AT", "OWNER_ID", "ACCESS_TYPE","LAST_UPDATE");
                inOrderView(root);
                break;

            case 5:
                exit(0);

            default:
                printf(">> What can i help?\n");
        }
    }
    return 0;
}
