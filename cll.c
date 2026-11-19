#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

void Display(){
    if(head == NULL){
        printf("Nothing to display, Circular Linked List is empty.\n");
        return;
    }
    struct node*ptr=head;
    while(ptr->next!=head){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d -> ", ptr->data);
    printf("\n");
}

void DisplayReverse(struct node *ptr){
    if(ptr->next != head){
        DisplayReverse(ptr->next);
    }
    printf("%d=>",ptr->data);    
}

void InsertAtBegin(){
    struct node*temp =(struct node*)malloc (sizeof(struct node));
    printf("Enter data to enter:");
    scanf("%d",&temp->data);

    if(head == NULL){
        head = temp;
        temp->next = head;
    }
    else{
        temp->next = head;
        struct node *ptr = head;
        while(ptr->next!= head){
            ptr= ptr->next;
        }
        ptr->next=temp;
        head  =temp;
    }
}
void InsertAtEnd(){
    struct node*temp =(struct node*)malloc (sizeof(struct node));
    printf("Enter data to enter:");
    scanf("%d",&temp->data);

    if(head == NULL){
        head = temp;
        temp->next = head;
    }
    else{
        struct node *ptr = head;
        while(ptr->next!= head){
            ptr= ptr->next;
        }
        ptr->next = temp;
        temp ->next = head;
    }
}
void InsertAtPosition(){
    printf("Enter position to add data:");
    int pos;
    scanf("%d" , &pos);
    if (pos == 0){
        InsertAtBegin();
    }
    else{
        struct node *prev_ptr=head;
        struct node *ptr = head->next;
        for(int i=1; i<pos; i++){
            if (ptr == head){
                printf("Invalid position\n");
                return;
            }
            prev_ptr =ptr;
            ptr = ptr->next;
        }
        struct node*temp =(struct node*)malloc (sizeof(struct node));
        printf("Enter data to enter:");
        scanf("%d",&temp->data);
        prev_ptr->next=temp;
        temp->next =ptr;
    }
}
void DeleteAtBegin(){
    struct node*ptr=head;

    if(head == NULL){
        printf("Empty Circular List nothing to delete.\n");
        return;
    }
    else if(head->next == head){
        head = NULL;
        free(ptr);
        return;
    }
    else{
        while(ptr->next!= head){
            ptr = ptr->next;
        }
        ptr->next = head ->next;
        ptr = head;
        head = head->next;
        free(ptr);
    }

}
void DeleteAtEnd(){
    struct node*ptr=head;

    if(head == NULL){
        printf("Empty Circular List nothing to delete.\n");
        return;
    }
    else if(head->next == head){
        head = NULL;
        free(ptr);
        return;
    }
    else{
        struct node *prev_ptr = head;
        while (ptr->next != head)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = head;
        free(ptr);
        
    }
}
void DeleteAtPosition(){
    int pos;
    printf("Enter position to delete data:");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("Linked List is empty! Nothing to delete!\n");
        return ;
    }
    else if(pos == 0){
        DeleteAtBegin();
    }
    else{
        struct node*prev_ptr =head;
        struct node*ptr=head->next;
        for(int i=1; i<pos; i++){
            if (ptr == head)
            {
                printf("Invalid position! Enter a valid position!\n\n");
                return ;
            }
            prev_ptr = ptr;
            ptr=ptr->next;
        }
        prev_ptr->next = ptr->next;
        free(ptr);
    }
}
void Search(){
    int data;
    printf("Enter data to be searched withing the circular Linked List:");
    scanf("%d",&data);

    struct node*ptr = head;
    while(ptr->next !=head){
        if(ptr->data == data){
            printf("Data is in the Circular Linked LIst\n");
            return;
        }
    }
    printf("Data is not found withing the Circular Linked List\n");
}

void Update(){
    int pos;
    int data;
    printf("Enter position to update the data:");
    scanf("%d",&pos);
    struct node*ptr=head;

    if (head == NULL){
        printf("Nothing to update, empty Cicular Linked List\n");
        return;
    }

    else{
        if (pos == 0){
            ptr = head;
        }
        else{
            ptr = head->next;
            for(int i=1; i<pos; i++){
                if(ptr == head){
                    printf("Invalid position\n");
                    return;
                }
                ptr = ptr->next;
            }

        }
        printf("Enter data to update:");
        scanf("%d",&data);
        ptr->data = data;
    }
}
void freeList(struct node *ptr){
    if(ptr->next != head){
        freeList(ptr->next);
    }
    free(ptr);
    
}


int main()
{
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
}

