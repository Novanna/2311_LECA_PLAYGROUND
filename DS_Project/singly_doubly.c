#include 
#include// Struktur node untuk doubly linked liststruct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Fungsi untuk menambah node baru di depan linked list
void insertFront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = *head_ref;

    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;

    *head_ref = new_node;
}

// Fungsi untuk menambah node baru di belakang linked list
void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

// Fungsi untuk menambah node baru di tengah linked list setelah prev_node
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

// Fungsi untuk menghapus node di depan linked list
void deleteFront(struct Node** head_ref) {
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;
    *head_ref = temp->next;

    if (*head_ref != NULL)
        (*head_ref)->prev = NULL;

    free(temp);
}

// Fungsi untuk menghapus node di belakang linked list
void deleteEnd(struct Node** head_ref) {
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head_ref = NULL;

    free(temp);
}

// Fungsi untuk menghapus node di tengah linked list yang ditunjuk oleh prev_node
void deleteNode(struct Node** head_ref, struct Node* del_node) {
    if (*head_ref == NULL || del_node == NULL)
        return;

    if (*head_ref == del_node)
        *head_ref = del_node->next;

    if (del_node->next != NULL)
        del_node->next->prev = del_node->prev;

    if (del_node->prev != NULL)
        del_node->prev->next = del_node->next;

    free(del_node);
}

// Fungsi untuk menampilkan linked list dari depan ke belakang
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL");
}

// Fungsi untuk menampilkan linked list dari belakang ke depan
void printReverse(struct Node* node) {
    if (node == NULL)
        return;

    while (node->next != NULL)
        node = node->next;

    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->prev;
    }
    printf("NULL");
}

int main() {
    struct Node* head = NULL;

    // Insert beberapa node
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);

    // Tampilkan linked list dari depan ke belakang
    printf("Linked list dari depan ke belakang: ");
    printList(head);

    // Tampilkan linked list dari belakang ke depan
    printf("Linked list dari belakang ke depan: ");
    printReverse(head);

    // Delete node pertama
    deleteFront(&head);
    printf("Linked list setelah menghapus node pertama: ");
    printList(head);

    // Delete node terakhir
    deleteEnd(&head);
    printf("Linked list setelah menghapus node terakhir: ");
    printList(head);

    // Insert node di depan
    insertFront(&head, 4);
    printf("Linked list setelah menambah node di depan: ");
    printList(head);

    // Insert node di tengah
    insertAfter(head->next, 5);
    printf("Linked list setelah menambah node di tengah: ");
    printList(head);

    // Delete node di tengah
    deleteNode(&head, head->next);
    printf("Linked list setelah menghapus node di tengah: ");
    printList(head);

    return 0;
}
