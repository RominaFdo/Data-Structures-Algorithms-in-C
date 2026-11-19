#include <stdio.h>
#include<stdbool.h>
#include<stdbool.h>

#define n 100
int stack[n];

int top = -1;
int sign = 1;

int cal(char *s){
    int num = 0;
    int res = 0;
    while (*s != '\0'){
        if (*s >= '0' && *s <= '9') {
            num = num *10 + (*s - '0');
        }
        else if(*s == '+'){
            res += sign * num;
            num = 0;
            sign = 1;
        }
        else if (*s == '-') {
            res += sign * num;
            num = 0;
            sign = -1;
        }
        else if (*s == '(') {
            stack[++top] = res;
            stack[++top] = sign;
            res = 0;
            sign = 1;
        } 
        else if (*s == ')') {
            res += sign * num;
            num = 0;
            res *= stack[top--]; // previous sign
            res += stack[top--]; // previous result
        }
        s++;

    }   
    res += sign * num;
    return res;
    
}int main() {
    printf("%d\n", calculate("1 + 1")); // Output: 2
    printf("%d\n", calculate(" 2-1 + 2 ")); // Output: 3
    printf("%d\n", calculate("(1+(4+5+2)-3)+(6+8)")); // Output: 23
    return 0;
}
