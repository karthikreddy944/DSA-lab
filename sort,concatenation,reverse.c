#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void sortList(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* i;
    struct Node* j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    printf("List reversed.\n");
}


struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL)
        return head2;
    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}


int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int choice, data;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert in List 1\n");
        printf("2. Insert in List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate (List1 + List2)\n");
        printf("8. Display Concatenated List\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertEnd(&head1, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertEnd(&head2, data);
            break;
        case 3:
            printf("List 1: ");
            display(head1);
            break;
        case 4:
            printf("List 2: ");
            display(head2);
            break;
        case 5:
            sortList(&head1);
            break;
        case 6:
            reverseList(&head1);
            break;
        case 7:
            head1 = concatenate(head1, head2);
            printf("Lists concatenated successfully.\n");
            break;
        case 8:
            printf("Concatenated List: ");
            display(head1);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
