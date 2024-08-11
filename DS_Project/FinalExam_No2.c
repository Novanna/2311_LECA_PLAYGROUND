#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Struktur data stack
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Fungsi untuk inisialisasi stack
void initStack(Stack *s) {
    s->top = -1;
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Fungsi untuk mengecek apakah stack penuh
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Fungsi untuk menambah elemen ke stack
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Fungsi untuk mengambil elemen dari stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

// Fungsi untuk melihat elemen teratas dari stack tanpa menghapusnya
char peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return '\0';
    }
    return s->items[s->top];
}

// Fungsi untuk menentukan prioritas tiap operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// fungsi untuk mengonversi infix ke postfix
void infixToPostfix(const char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int i = 0, k = 0;
    char token;

    while ((token = infix[i++]) != '\0') {
        if (isalnum(token)) {
            // Jika token adalah operand, tambahkan ke postfix
            postfix[k++] = token;
        } else if (token == '(') {
            // Jika token adalah '(', masukkan ke stack
            push(&s, token);
        } else if (token == ')') {
            // Jika token adalah ')', pop hingga menemukan '('
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); // Menghapus '(' dari stack
        } else {
            // Jika token adalah operator
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(token)) {
                postfix[k++] = pop(&s);
            }
            push(&s, token);
        }
    }

    // Pop semua operator yang tersisa di stack
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0'; // Akhir string postfix
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
