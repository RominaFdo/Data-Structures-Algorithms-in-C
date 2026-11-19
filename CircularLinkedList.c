#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void Display();
void DisplayReverse(struct node *ptr);
void InsertAtBegin();
void InsertAtEnd();
void InsertAtPosition();
void DeleteAtBegin();
void DeleteAtEnd();
void DeleteAtPosition();
void Search();
void Update();
void freeList(struct node *ptr);


struct node *head = NULL;

int main()
{
    int choice;

    while (1)
    {
        printf("\n1.Insert at begin\n2.Insert at end\n3.Insert at position\n4.Delete at begin\n5.Delete at end\n6.Delete at position\n7.Display linked List\n8.Search data\n9.Update\n10.Exit\n");
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
            Search();
            break;
        case 9:
            Update();
            break; 
        case 10:
            freeList(head);
            exit(0);
            break;   
        default:
            printf("Invalid Operation\n\n");
            break;
        }
    }
}

void Display()
{
    if (head == NULL)
    {
        printf("Linked List is empty! Nothing to delete!\n");
        return ;
    }
    struct node *ptr = head;
    while (ptr->next != head)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d -> ", ptr->data);
    printf("H\n\n");
}

void InsertAtBegin()
{
    int data;
    printf("Enter data to add: ");
    scanf("%d", &data);

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
    {
        temp->data = data;
        head = temp;
        temp->next = head;
    }
    else
    {
        temp->data = data;
        temp->next = head;
        struct node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        head = temp;
    }
    printf("Node Added!\n\n");
}

void InsertAtEnd()
{
    int data;
    printf("Enter data to add: ");
    scanf("%d", &data);

    struct node *temp = (struct node*)malloc(sizeof(struct node));

    if (head == NULL)
    {
        temp->data = data;
        head = temp;
        temp->next = head;
    }
    else
    {
        struct node *ptr = head;
        while(ptr->next != head)
        {
            ptr = ptr->next;
        }
        
        temp->data = data;
        temp->next = head;
        ptr->next = temp;
    }
    printf("Node Added!\n\n");
}

void InsertAtPosition()
{
    int pos;
    printf("Enter position to add the data: ");
    scanf("%d", &pos);

    if (pos == 0)
    {
        InsertAtBegin(); 
    }
    else
    { 
        int data;

        struct node *prevptr = head;
        struct node *ptr = head->next;

        struct node *temp = (struct node*)malloc(sizeof(struct node));

        for (int i = 1; i < pos; i++)
        {
            if (ptr == head)
            {
                printf("Invalid position! Enter a valid position!\n\n");
                return ;
            }
            prevptr = ptr;
            ptr = ptr->next;
        }

        printf("Enter data to add: ");
        scanf("%d", &data);

        
        temp->data = data;
        temp->next = ptr;
        prevptr->next = temp;
    }
    printf("Node Added!\n\n");
}

void DeleteAtBegin()
{
    if (head == NULL)
    {
        printf("Linked List is empty! Nothing to delete!\n");
        return ;
    }
    else if (head->next == head)
    {
        struct node *ptr = head;
        head = NULL;
        free(ptr);
        printf("Node Deleted!\n\n");
        return ;
    }
    else
    {
        struct node *ptr = head;
        while(ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Node Deleted!\n\n");
    }
}

void DeleteAtEnd()
{
    if (head == NULL)
    {
        printf("Linked List is empty! Nothing to delete!\n");
        return ;
    }
    else if (head->next == head)
    {
        struct node *ptr = head;
        head = NULL;
        free(ptr);
        printf("Node Deleted!\n\n");
        return ;
    }
    else
    {
        struct node *prevptr = head;
        struct node *ptr = head;
        while (ptr->next != head)
        {
            prevptr = ptr;
            ptr = ptr->next;
        }
        prevptr->next = head;
        free(ptr);
        printf("Node Deleted!\n\n");
    }
}

void DeleteAtPosition()
{
    int pos;
    printf("Enter position to delete the data: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("Linked List is empty! Nothing to delete!\n");
        return ;
    }
    else if (pos == 0)
    {
        DeleteAtBegin();
    }
    else{
        struct node *prevptr = head;
        struct node *ptr = head->next;
            
        for (int i = 1; i < pos; i++)
        {
            if (ptr == head)
            {
                printf("Invalid position! Enter a valid position!\n\n");
                return ;
            }
            prevptr = ptr;
            ptr = ptr->next;
        }
        prevptr->next = ptr->next;
        free(ptr);
        printf("Node Deleted!\n\n");
    }
}

void Search()
{
    int data;
    printf("Enter data to search: ");
    scanf("%d", &data);

    struct node *ptr = head;

    while(ptr->next != head)
    {
        if (ptr->data == data)
        {
            printf("\nData in the list\n\n");
            return ;
        }
        ptr = ptr->next;
    }
    printf("Data not in the list\n\n");
}

void Update()
{
    int pos;
    printf("Enter position to update the data: ");
    scanf("%d", &pos);
    
    if (head == NULL)
    {
        printf("Linked List is empty! Nothing to update!\n");
        return ;
    }
    
    else{
        struct node *ptr = head;
        if (pos == 0)
        {
            ptr = head;
        }
        else
        {
            ptr = head->next;
            if (ptr == head)
            {
                printf("Invalid position! Enter a valid position!\n\n");
                return ;
            }
        }

        for (int i = 1; i < pos; i++)
        {
            if (ptr == head)
            {
                printf("Invalid position! Enter a valid position!\n\n");
                return ;
            }
            ptr = ptr->next;
        }

        int data;
        printf("Enter new data: ");
        scanf("%d", &data);

        ptr->data = data;

        printf("Node Updated!\n\n");
    }
}

void freeList(struct node *ptr)
{
    if (ptr->next != head)
    {
        freeList(ptr->next);
    }
    free(ptr);
}

