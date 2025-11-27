#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};


struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


struct Node* createList(struct Node *head, int value) {

    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}


struct Node* insertLeft(struct Node *head, int target, int value) {

    struct Node *temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node %d not found!\n", target);
        return head;
    }

    struct Node *newNode = createNode(value);

    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;

    temp->prev->next = newNode;
    temp->prev = newNode;

    return head;
}


struct Node* deleteNode(struct Node *head, int value) {

    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node %d not found!\n", value);
        return head;
    }

    if (temp == head) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    temp->prev->next = temp->next;

    free(temp);
    return head;
}


void display(struct Node *head) {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node *head = NULL;
    int ch, value, target, n;

    while (1) {
        printf("\n1. Create Node\n2. Insert Left\n3. Delete Node\n4. Display\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = createList(head, value);
                break;

            case 2:
                printf("Insert left of which value? ");
                scanf("%d", &target);
                printf("Enter new value: ");
                scanf("%d", &value);
                head = insertLeft(head, target, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;

            case 4:
                display(head);
                break;

            case 0:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
