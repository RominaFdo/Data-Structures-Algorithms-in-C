#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<stdlib.h>

#define N 100
int top = -1;
int stack[N];

void push(int);
int pop();
int eval(char, int,int);
int main(){
    char a[50];
    char ch;
    int op1,op2,res,x;
    printf("Enter a postfix expression :");
    scanf("%s" , a);

    for (int i=0; a[i] != '\0'; i++){
        ch=a[i];
        if(isdigit(ch)){
            push(ch - '0');
        }
         else if (ch == ' ' || ch == '\n')
            continue;
        else{
            op2 = pop();
            op1 = pop();
            res = eval(ch , op1, op2);
            push(res);
        }
    }
    x = pop();
    printf("evaluated value = %d", x);
    return 0;
}

void push(int n){
    if (top == N-1){
        printf("Full list\n");
        return;
    }
    else{
        top += 1;
        stack[top] = n;
    }
}
int pop(){
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int res = stack[top];
    top--;
    return res;

}
int eval(char ch, int op1,int op2){
    switch(ch){
        case '+': return (op1 + op2);
        case '-': return (op1 - op2);
        case '*' : return (op1*op2);
        case '/' : 
        if (op2 == 0){
             printf("Error: Division by zero\n");
                exit(1);
        }
        else{
            return(op1 / op2);
        }
    }
}