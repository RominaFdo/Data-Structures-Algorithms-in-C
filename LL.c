
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node*next;
};

struct node*head = NULL;
 
void InsertAtBegin(){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert in to the new node:");
    scanf("%d" , &temp->data);
    temp->next =NULL;
    if (head == NULL){
        head = temp;
        return;
    }
    else{
        temp->next =head;
        head = temp;
    }
}
void InsertAtEnd(){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert in to the new node:");
    scanf("%d" , &temp->data);

    if (head == NULL){
        head = temp;
        return;
    }
    else{
        struct node*ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        temp ->next = NULL;
        ptr->next = temp;

    }
}
void InsertAtPosition(){
    printf("Enter position:");
    int pos;
    scanf("%d" , &pos);
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    int data;
    if (pos==0){
        InsertAtBegin();
        return;
    }
    else{
        struct node*prev_ptr;
        struct node*ptr =head;
        for (int i=0; i<pos; i++){
            if(ptr == NULL){
                printf("Invalid postion.\n");
                return;
            }
            prev_ptr = ptr;
            ptr= ptr->next;
        }

        printf("Enter data to add: ");
        scanf("%d", &data);

        temp->data = data;
        prev_ptr->next = temp;
        temp->next = ptr;

        
    }


}
void DeleteAtBegin(){
    struct node*ptr;

    if (head ==NULL){
        printf("Nothing to delete, the Linked List is already empty.\n");
        return;
    }
    else{
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Node succesfully deleted.\n");
    }
}

void DeleteAtEnd(){

    if (head ==NULL){
        printf("Nothing to delete, the Linked List is already empty.\n");
        return;
    }
    else if (head->next == NULL)
    {
        struct node *ptr = head;
        head = NULL;
        free(ptr);
        printf("Node Deleted!\n\n");
    }
    else{
        struct node*ptr;
        struct node*a;
        ptr = head;
        struct node*prev_ptr = NULL;
        while(ptr ->next !=NULL){
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = NULL;
        free(ptr);
        // while((ptr->next)->next!=NULL){
        //     ptr = ptr->next;
        // }
        // a = ptr->next;
        // free(ptr->next);
        // a->next =NULL;
        printf("Node succesfully deleted.\n");
    }
}

void DeleteAtPosition(){
    int pos;
    printf("Enter position to delete:");
    scanf("%d",&pos);
    if (head ==NULL){
        printf("Nothing to delete, the Linked List is already empty.\n");
        return;
    }
    else if (pos == 0)
    {
        struct node *ptr = head;
        head = ptr->next;
        free(ptr);
        printf("Node Deleted!\n\n");
    }
    else{
        struct node*ptr=head;
        struct node* prev_ptr =NULL;
        for (int i=0; i<pos; i++){
            if (ptr ==NULL){
                printf("Invalid position.\n");
                return;
            }
            prev_ptr = ptr;
            ptr =ptr->next;
        }
        
        prev_ptr->next = ptr->next;
        free(ptr);

        printf("Node succesfully deleted.\n");
    }
}
void Search(){
    int data;
    printf("Enter data to find:");
    scanf("%d" , &data);
    struct node*ptr =head;
    while(ptr !=NULL){
        if(ptr->data == data){
            printf("Data is in the Linked List.\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("Data not found in the Linked List.\n");
}

void Update(){
    int pos;
    printf("Enter position to update the data: ");
    scanf("%d",&pos);
    if (head == NULL){
        printf("Linked List is empty! Nothing to update!\n");
        return ;
    }
    
    else{
        struct node *ptr = head;
        for (int i = 0; i < pos; i++)
        {
            if (ptr == NULL)
            {
                printf("Invalid position! Enter a valid position!\n\n");
                return ;
            }
            ptr = ptr->next;
        }
        printf("Enter new data:");
        scanf("%d", &ptr->data);

    }
}


void freeList(struct node *ptr){
    if(ptr->next != NULL){
      freeList(ptr->next);   
    }
    free(ptr);
}


void Display(){
    struct node*ptr = head;
    if (ptr==NULL){
        printf("Empty Linked List Nothing to display.\n");
        return;
    }
    else{
        printf("Elements of the Linked List:\n");
        while (ptr !=NULL){
            printf("%d =>",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }

}


void DisplayReverse(struct node*ptr){
    if (ptr->next != NULL){

        DisplayReverse(ptr->next);
    }
    printf("%d =>" , ptr->data);
}
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
            case 8:
                DisplayReverse(head);
                break;
            case 9:
                Search();
                break;
            case 10:
                Update();
                break; 
            case 11:
                freeList(head);
                exit(0);
                break;   
            default:
                printf("Invalid Operation\n\n");
                break;
        }
    
    }
    
    return 0;
}