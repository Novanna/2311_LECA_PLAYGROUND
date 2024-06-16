#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }

    *head_ref = new_node;
}

void insertInMiddle(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = prev_node;
    new_node->next = prev_node->next;

    if (prev_node->next != NULL) {
        prev_node->next->prev = new_node;
    }

    prev_node->next = new_node;
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) {
        return;
    }

    if (*head_ref == del) {
        *head_ref = del->next;
    }

    if (del->next != NULL) {
        del->next->prev = del->prev;
    }

    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    free(del);
}

void printList(struct Node* node) {
    struct Node* last = NULL;
    printf("Doubly Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        last = node;
        node = node->next;
    }
    if (last != NULL) {
        printf("NULL\n");
    }
}

int main() {
    struct Node* head = NULL;

    // Insert di node terakhir
    insertAtEnd(&head, 1);
    printf("List Setelah insert di node terakhir: ");
    printList(head);

    // Insert di node awal
    insertAtBeginning(&head, 2);
    printf("List Setelah insert di node awal: ");
    printList(head);

    // Insert di node tengah
    insertInMiddle(head, 3);
    printf("List Setelah insert di node tengah: ");
    printList(head);

    // Delete di node pertama
    deleteNode(&head, head);
    printf("List Setelah delete di node pertama: ");
    printList(head);

    // Delete di node tengah
    deleteNode(&head, head->next);
    printf("List Setelah delete di node tengah: ");
    printList(head);

    // Delete di node terakhir
    deleteNode(&head, head);
    printf("List Setelah delete di node terakhir: ");
    printList(head);

    return 0;
}
