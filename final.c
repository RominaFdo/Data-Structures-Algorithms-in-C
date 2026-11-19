#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


char br[100];
struct node{
    char symbol;
    struct node* next ; 
};

struct node* top =NULL;

struct node* new(char n){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        return 0;
    }
    else{
        ptr-> symbol = n;
        ptr->next =NULL;
        return ptr;
    }   
}


bool isEmpty(){
    if (top == NULL){
        return true;
    }
    else{
        return false;
    }
}

void push(char b){
    struct node* temp = new(b);

    if(isEmpty()){
        top = temp;
    }

    else{
        temp->next = top;
        top = temp;
    }
}


void pop(){
    if(isEmpty()){
        return;
    }

    else{
        struct node* ptr = top;
        top = top->next;

        free(ptr);
    }
}


int closingBrackets(char *a){
    int count = 0;
    int  i=0;
    while(a[i] != '\0'){
        if(a[i] == '('){
            push(a[i]);
        }
        else{
            if(isEmpty()){
                count ++;
            }
            else{
                pop();
            }
        }
        i++;
    }

    struct node* ptr = top;
    while(ptr!= NULL){
        count++;
        ptr= ptr->next;
    }
    return count;

}

void freemem(struct node* ptr){
    if(ptr->next!= NULL){
        ptr = ptr->next;
    }
    free(ptr);
}


int main(){
    printf("Enetr bracket sequence :");
    scanf("%s" , br);
    int count = closingBrackets(br);
    printf("Number of closing Brackets needed = %d" , count);
    freemem(top);
    return 0;
}