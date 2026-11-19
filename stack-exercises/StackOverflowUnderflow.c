#include <stdio.h>
#include <stdbool.h>

#define stackMaxSize 1
int stack[stackMaxSize];
int top;

bool stackIsEmpty();
bool stackIsFull();
void stackState();
void pushStack();
void stackDisplay();
void popStack();

int main(){
    top = -1;
    stackState();
    pushStack();
    stackState();
    pushStack();
    pushStack();
    stackDisplay();
    popStack();
    stackDisplay();
    return 0;
}


bool stackIsEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}
bool stackIsFull(){
    if(top == stackMaxSize-1){
        return true;
    }
    else{
        return false;
    }
}
void stackState(){
    if(stackIsEmpty()){
        printf("Stack is Empty\n");
    }
    else if(stackIsFull()){
        printf("Stack is Full\n");
    } else{
        printf("Stack is neither Empty nor Full\n");
    }
}
void pushStack(){
    if(stackIsFull()){
        printf("Cannot push. Stack is Full\n");
        return;
    }
    else{
        int a;
        printf("Enter elemnet to push :");
        scanf("%d" , &a);
        top = top+1;
        stack[top] = a;
    }
}
void stackDisplay(){
    for(int i=0; i<=top; i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
void popStack(){
    if(stackIsEmpty()){
        printf("Cannot pop. Stack is Empty\n");
        return;
    }
    else{
        int popped= stack[top];
        printf("Popped %d\n" , popped);
        top = top-1;
    }
}
