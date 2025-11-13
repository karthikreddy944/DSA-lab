#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}


void deleteStart() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from the end.\n");
}


void deletePosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos == 1) {
        deleteStart();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
    printf("Node deleted from position %d.\n", pos);
}


void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- Singly Linked List Deletion Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete from Start\n");
        printf("3. Delete from End\n");
        printf("4. Delete from Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertEnd(data);
            break;
        case 2:
            deleteStart();
            break;
        case 3:
            deleteEnd();
            break;
        case 4:
            printf("Enter position: ");
            scanf("%d", &pos);
            deletePosition(pos);
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
