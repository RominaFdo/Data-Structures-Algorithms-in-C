#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *next;
};

struct node *top = NULL;

char pop();
void push(char data);

int main()
{
    char br[32];                //  ({[]})\0
    printf("Enter brackets combination: ");
    scanf("%s", &br);

    int i = 0;

    while(br[i] != '\0') {      // \0 NUL  
        if ((br[i] == '(' || br[i] == '{' || br[i] == '['))  // || OR  ({[
            push(br[i]);
        else{
            char popped = pop();
            if (!((popped == '(' && br[i] == ')') || (popped == '{' && br[i] == '}') || (popped == '[' && br[i] == ']')))
            {
                printf("Not balanced\n");
                
                return 0;
            }       
               
        }
        i++;
    }

    
    if (top == NULL)
        printf("Balanced\n");
    else
        printf("Not balanced\n");
    return 0;
}

char pop()
{
    if (top == NULL)
    {
        printf("Stack is empty! Nothing to pop!\n");
        return '\0';
    }
    struct node *ptr = top;
    char data = top->data;
    top = top->next;
    free(ptr);
    return data;
}

void push(char data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    if (top == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = top;
    }
    top = temp;
}