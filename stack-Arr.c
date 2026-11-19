
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 10

int top = -1;

int stack[N];

void push();
int pop();
int peek();
bool isEmpty();
bool isFull();

int main(){
    int choice;

    while(1){
        printf("\n1. Push\n2. Pop\n3. peek\n4. isEmpty\n5. isFull\n\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            push();
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
            isFull();
            break;

        default:
            printf("Invalid choice,\n");
            break;
    }
    }
    return 0;
    
}

void push(){
    if(top == N-1){
        printf("Overflow state.\n");
        return;
    }
    else{
        int data;
        printf("Enter data to push in to the stack:");
        scanf("%d",&data);
        top += 1;
        stack[top] = data;
    }
}
int pop(){
    if (top == -1){
        printf("stack is empty nothing to pop\n");
    }
    else{
        int x = stack[top];
        printf("Poping %d from the stack,\n",x);
        top -=1;
        return x;

    }
    return -1;
}
int peek(){
    int x = stack[top];
    printf("%d is the top most element in the stack.\n",x);
    return x;

}
bool isEmpty(){
    if(top == -1){
        printf("Stack is empty: Undeflow state.\n");
        return true;
    }
    printf("Stack is not empty.\n");
    return false;

}
bool isFull(){
    if (top == N-1){
        printf("Stack is full.\n");
        return true;
    }

    printf("Stack is not full.\n");
    return false;
}