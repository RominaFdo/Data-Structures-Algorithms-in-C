#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head = NULL;
struct node*tail = NULL;

void Display(){
    struct node*ptr = head;
    while (ptr !=NULL){
        printf("%d=>" ,ptr->data);
        ptr = ptr->next;
    }
}
// void DisplayReverse();
void InsertAtBegin(){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to enter into the  node:");
    scanf("%d" , &temp->data);

    if (head == NULL){
        temp->prev = NULL;
        temp->next = NULL;
        head =temp;
        tail = temp;
    }

    else{
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        head = temp;
    }
}

void InsertAtEnd(){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to enter into the  node:");
    scanf("%d" , &temp->data);

    if (head == NULL){
        temp->prev = NULL;
        temp->next = NULL;
        head =temp;
        tail = temp;
    }

    else{
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}
void InsertAtPosition(){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    int pos;
    printf("Enter position to enter data:");
    scanf("%d" , &pos);
    if (pos == 0){
        InsertAtBegin();
        return;
    }
    else{
        struct node*ptr;
        ptr  =head;
        for(int i=0; i<pos; i++){
            if (ptr ==NULL){
                printf("Invalid\n");
                return;
            }
            ptr =ptr->next;
        }
        printf("Enter data to enter into the  node:");
        scanf("%d" , &temp->data);
        temp->next = ptr;
        temp->prev= ptr->prev;
        ptr->prev->next= temp;
        ptr->prev = temp;
        
    }
    
}
void DeleteAtBegin(){
    if (head == NULL){
        printf("Nothing to delete.\n");
        return;
    }
    struct node*ptr;
    ptr = head;
    head = head->next;
    if(head == NULL){
        tail = NULL;
    }
    else{
        head ->prev = NULL;
    }
    free(ptr);
    

}
void DeleteAtEnd(){
    if (tail == NULL){
        printf("Nothing to delete.\n");
        return;
    }
    struct node*ptr;
    ptr = tail;
    tail = tail->prev;
    if(tail == NULL){
        head = NULL;
    }
    else{
        tail->next = NULL;
    }
    free(ptr);
    
    
}
void DeleteAtPosition(){
    printf("Enter position to add data:");
    int pos;
    scanf("%d",&pos);
    struct node*ptr=head;;
    if (pos == 0){
        DeleteAtBegin();
        return;
    }

    else{
        for(int i=0; i<pos; i++){
            if (ptr == NULL){
                printf("Inalid position\n");
                return;
            }
            ptr =ptr->next;
        }

        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }
    
}
// void Search();
// void Update();
// void freeList(struct node *ptr);


int main(){
    int choice;

    while (1)
    {
        printf("\n1.Insert at begin\n2.Insert at end\n3.Insert at position\n4.Delete at begin\n5.Delete at end\n6.Delete at position\n7.Display linked List\n8.Display Linked List(Reversed)\n9.Search data\n10.Update\n11.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsertAtBegin();
            break;
        case 2:
            InsertAtEnd();
            break;
        case 3:
            InsertAtPosition();
            break;
        case 4:
            DeleteAtBegin();
            break;
        case 5:
            DeleteAtEnd();
            break;
        case 6:
            DeleteAtPosition();
            break;
        case 7:
            Display();
            break;
        // case 8:
        //     DisplayReverse();
        //     break;
        // case 9:
        //     Search();
        //     break;
        // case 10:
        //     Update();
        //     break; 
        // case 11:
        //     freeList(head);
        //     exit(0);
        //     break;   
        default:
            printf("Invalid Operation\n\n");
            break;
        }
    }
}