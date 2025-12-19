#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;  
struct Node* rear = NULL;   


void enqueue(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    
    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("\n%d inserted into queue.\n", value);
}


void dequeue() {
    if (front == NULL) {
        printf("\nQueue Underflow! No elements to remove.\n");
        return;
    }

    struct Node* temp = front;
    printf("\nDeleted element: %d\n", front->data);

    front = front->next;

    
    if (front == NULL)
        rear = NULL;

    free(temp);
}


void peek() {
    if (front == NULL) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nFront element: %d\n", front->data);
    }
}


void isEmpty() {
    if (front == NULL)
        printf("\nQueue is empty.\n");
    else
        printf("\nQueue is NOT empty.\n");
}


void display() {
    if (front == NULL) {
        printf("\nQueue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("\nQueue elements (Front -> Rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front)\n");
        printf("4. Check if Empty\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
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

