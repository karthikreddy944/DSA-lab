#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL; 


void push(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("\n%d pushed to stack.\n", value);
}


void pop() {
    if (top == NULL) {
        printf("\nStack Underflow! No elements to pop.\n");
        return;
    }

    struct Node* temp = top;
    printf("\nPopped element: %d\n", top->data);
    top = top->next;
    free(temp);
}


void peek() {
    if (top == NULL) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nTop element: %d\n", top->data);
}


void isEmpty() {
    if (top == NULL) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack is NOT empty.\n");
    }
}


void display() {
    if (top == NULL) {
        printf("\nStack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("\nStack elements (Top -> Bottom):\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}


int main() {

    int choice, value;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top)\n");
        printf("4. Check if Empty\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                isEmpty();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}

