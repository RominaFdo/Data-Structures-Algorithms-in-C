#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node{
    int data;
    struct node*next;
};

struct node*front = NULL;
struct node*rear = NULL;

struct node*createNode(){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL){
        printf("Memory allocation failed. \n");
        exit(1);
    }

    printf("Enter value to enqueue into the queue :");
    scanf("%d" , &temp->data);
    temp->next = NULL;
    return temp;

};


bool isEmpty();
void enqueue();
void dequeue();
void peek();
void QueueRear();
void display();

int main(){
    
    int choice;
    while(1){
        printf("\n\nQUEUE OPERATIONS \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. peek\n");
        printf("4. Queue Rear\n");
        printf("5. IsEmpty\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice){
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                QueueRear();
                break;


            case 5:
                if(isEmpty()){
                    printf("Queue is empty\n");
                }
                else{
                    printf("Queue is  not empty\n");    
                }
                break;


            case 6:
                display();
                break;

            case 7:
                exit(0);
                break;

            default:
                printf("Inavlid choice\n");
                break;

        }

}

    
}


bool isEmpty(){
    return front == NULL;
}

void enqueue(){
    struct node*ptr = createNode();
    if (isEmpty()){
        front = ptr;
    }
    else{
        rear->next = ptr;
    }
    rear = ptr;
    
}

void dequeue(){
    if(isEmpty()){
        printf("Nothing to dequeue.\n");
        return;
    }
    else{
        struct node*ptr = front;
        printf("Value dequeued from the queue : %d", ptr->data);

        front = front->next;
        free(ptr);

        if(front == NULL){
            rear = NULL;
        }
    }
}
void peek(){
    
   if(isEmpty()){
        printf("Nothing to peek. Enpty queue.\n");
        return;
    }
    printf("Peek value :%d", front->data);
}

void QueueRear(){
    if(isEmpty()){
        printf("No rear value. Enpty queue.\n");
        return;
    }
    printf("Rear value :%d", rear->data);
}
void display(){
   if(isEmpty()){
        printf("Nothing to display. Empty Queue.\n");
        return;
    }
    else{
        struct node*ptr = front;
        while (ptr !=  NULL){
            printf("%d =>" , ptr->data);
            ptr = ptr->next;
        }
        
    }

}