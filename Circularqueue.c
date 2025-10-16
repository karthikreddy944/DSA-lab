#include<stdio.h>
#define N 5
int queue[N];
int front=-1,rear=-1;
void insert(){
    int value;
    printf("Enter the value: \n");
    scanf("%d",&value);
    if((front==0 && rear==N-1) || (rear+1)%N==front){
        printf("Queue Overflow\n");
    }
    else{
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%N;
        queue[rear]=value;
        printf("Inserted value:%d\n",value);
    }
}
void delete(){
    if(front==-1){
       printf("Queue Underflow\n");
    }
    else{
        printf("Deleted:%d\n",queue[front]);
        if(front==rear){
            front=rear=-1;
        }else{
        front=(front+1)%N;
        }
    }
}
void display(){
    if(front==-1){
        printf("Queue is empty\n");
    }else{
        int i=front;
        printf("Queue elements are: ");
        while(1){
            printf("%d ",queue[i]);
            if(i==rear){
                break;
            }
            i=(i+1)%N;
        }
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
