#include <stdio.h>
#define N 10
int stack[N];
int top=-1;
void push(){
    int x;
    printf("ENTER THE NUMBER FOR PUSH OPERATION:");
    scanf("%d",&x);
    if(top==N-1){
        printf("Overflow");
    }
    else{
        top++;
        stack[top]=x;
    }
}
void pop(){
    int y;
    if(top==-1){
        printf("Underflow");
    }
    else{
        y=stack[top];
        top--;
        printf("%d\n",y);
    }
}
void display(){
    int i;
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
}
}
void main(){
    int chart;
    do{
        printf("Enter the number=1:push 2:pop 3:display=");
        scanf("%d",&chart);
        switch(chart)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;
        default:
            printf("Invalid Input\n");
    }
  }while(chart!=0);
}
