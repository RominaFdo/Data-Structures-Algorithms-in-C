#include <stdio.h>
#define satckSize 100

int stack[satckSize];
int top = -1;
void push(int n);
void display();
void DecToBin(int a);

int main(){
    int decimalNo;
    printf("Enter Decimal Number to convert in to Binary :");
    scanf("%d", &decimalNo);
    DecToBin(decimalNo);
    return 0;
}

void push(int n){
    if(top == satckSize-1){
        printf("Satck overflow\n");
        return;
    }
    top++;
    stack[top] = n;

};

void display(){
    for(int i= top; i>=0; i--){
        printf("%d", stack[i]);
    }
};

void DecToBin(int a){
    do{
        push(a%2);
        a = a/2;
    }while(a!=0);

    display();
}