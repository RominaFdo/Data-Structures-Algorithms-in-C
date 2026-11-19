#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max_Size 10

int queue[Max_Size];

int front = 0;
int rear = -1;
int size = 0;

bool isFull();
bool isEmpty();
void enqueue();
int dequeue();
void peek();
void QueueRear();
void display();

int main(){
    
    int choice;
    while(1){
        printf("\n QUEUE OPERATIONS \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. peek\n");
        printf("4. Queue Rear\n");
        printf("5. IsFull\n");
        printf("6. IsEmpty\n");
        printf("7. Display\n");
        printf("8. Exit\n");
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
                if (isFull()){
                    printf("Queue is full\n");
                }
                else{
                    printf("Queue is not full\n");
                }
                break;


            case 6:
                if(isEmpty()){
                    printf("Queue is empty\n");
                }
                else{
                    printf("Queue is  not empty\n");    
                }
                break;


            case 7:
                display();
                break;

            case 8:
                exit(0);
                break;

            default:
                printf("Inavlid choice\n");
                break;

        }

}

    
}

bool isFull(){
    return size == Max_Size;
}

bool isEmpty(){
    return size == 0;
}

void enqueue(){
    if(isFull()){
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    printf("Enter value to enqueue :");
    rear = (rear+1) % Max_Size;
    scanf("%d" ,&queue[rear]);
    size++;
}

int dequeue(){
    if(isEmpty()){
        printf("Queue is empty. Nothing to dequeue.\n");
        return -1;
    }

    int x = queue[front];
    printf("Dequeued value is: %d" , x);
    front = (front+1)%Max_Size;
    size--;
    return x;
}
void peek(){
    if(isEmpty()){
        printf("Queue is empty, Cannot peek\n");
        return;
    }
    printf("Peek value of the queue is : %d", queue[front]);
}
void QueueRear(){
    if(isEmpty()){
        printf("Queue is empty, Cannot show rear value.\n");
        return;
    }
    printf("Rear value of the queue is : %d", queue[rear]);\
}
void display(){
    if(isEmpty()){
        printf("Queue is empty, Nothing to display.\n");
        return;
    }
    else{
        for(int i = front; i<=rear; i++){
            printf("%d =>", queue[i]);
        }
    }
}