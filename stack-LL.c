
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node*next;
};
struct node*head = NULL;

void push();
int pop();
int peek();
bool isEmpty();
bool isFull();

int main(){
    int choice;

    while(1){
        printf("\n1. Push\n2. Pop\n3. peek\n4. isEmpty\n\n");
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

        default:
            printf("Invalid choice,\n");
            break;
    }
    }
    return 0;
    
}

void push(){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to push to the stack:");
    scanf("%d" , &temp->data);

    if(isEmpty()){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}
int pop(){
    struct node* ptr;
    
    if(isEmpty()){
        printf("Nothing to pop. Empty stack.\n");
        return NULL;
    }
    else{
        ptr = head;
        int val = head->data;
        head = head->next;
        printf("%d is popped out of the stack\n",val);
        free(ptr);
        return val;
    }
}
int peek(){
    if(isEmpty()){
        printf("Nothing to peek. Empty stack.\n");
        return NULL;
    }

    else{
        int x =head->data;
        printf("%d is the top most element of the stack\n",x);
        return x;
    }
}
bool isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}
