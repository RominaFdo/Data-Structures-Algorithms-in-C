#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct node{
    char ele;
    struct node* next;
};
struct node * top = NULL;

int count = 0;
void push(char a){
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp ->ele = a;
    temp ->next = NULL;
    if (top == NULL){
        top = temp;
        return;
    }
    else{
        temp->next = top;
        top = temp;
    }
}

char pop(){
    if (top == NULL){
        printf("Underflow \n");
        return '\0';
    }
    else{
        struct node*ptr = top;
        char n= ptr->ele;
        top  = top->next;
        free(ptr);
        return n;
    }

}
bool palindrome(char *a){
    int i = 0;
    while (a[i] != '\0'){
        push(a[i]);
        i++;
    }
    int l = i;
    for (i=0; i<l; i++){
        if(a[i] != pop()){
            return false;
        }
    }
    return true;

}
int main() {
    char b[] = "ABBCCCBBBA";
    if (palindrome(b)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
    return 0;
}