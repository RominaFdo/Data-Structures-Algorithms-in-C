#include <stdio.h>
#include <string.h>
#define N 32

void push(char x);
void pop();
char peek();

char b[N];
int top = -1;

int main() {

    char a[32];

    printf("Enter brackets combination: ");
    // Use fgets to prevent buffer overflow
    fgets(a, sizeof(a), stdin);

    int i = 0;
    while (a[i] != '\0') {
        if (a[i] == '(' || a[i] == '[' || a[i] == '{') {
            push(a[i]);
        } else {
            char p = peek();
            if ((p == '(' && a[i] == ')') || (p == '{' && a[i] == '}') || (p == '[' && a[i] == ']')) {
                pop();
            }
        }
        i++;
    }

    if (top == -1)
        printf("Balanced\n");
    else
        printf("Not balanced\n");
    return 0;
}

void push(char x) {
    if (top == N - 1) {
        printf("Array is full\n");
        return;
    } else {
        top++;
        b[top] = x;
    }
}

void pop() {
    if (top == -1) {
        // No need to print message here, handled elsewhere
        return;
    } else {
        top--;
    }
}

char peek() {
    if (top == -1) {
        // No need to print message here, handled elsewhere
        return '\0';
    }
    return b[top];
}
