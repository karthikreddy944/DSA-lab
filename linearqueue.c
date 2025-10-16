#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void insert(){
    int value;
    printf("Enter the value:");
    scanf("%d",&value);
    if(rear==N-1){
        printf("Queue is Overflow\n");
    }
    else if(front==-1 && rear==-1){
        front=0;
        rear=0;
        queue[rear]=value;
    }
    else{
        rear++;
        queue[rear]=value;
    }
}
void delete(){
    if(front==-1 || front>rear){
        printf("Queue Underflow\n");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
}
void display(){
    if(front==-1 || front>rear){
        printf("Queue is empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main(){
    int choice;
    while(1){
        printf("1:Insert\n");
        printf("2:Delete\n");
        printf("3:Display\n");
        printf("4:Exit\n");
        printf("Enter the choice: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
      }
    }
    return 0;
}


