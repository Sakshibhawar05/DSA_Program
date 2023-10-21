/*Circular-queue*/

/*
Name = Sakshi Bhawar
Roll No = 68
pid = 3
SE-IT
2023-24
*/


#include <stdio.h>
#define size 5
int cqueue[size];
int front = -1;
int rear = -1;


void enqueue(int x, int cqueue[]){
    if((rear==size-1 && front==0) || front==rear+1){
        printf("Queue Full");
        return;
    }
    else{
        if(front==-1 && rear==-1){
            front++;
            rear++;
            cqueue[rear]=x;
        }
        else{
            rear=(rear++)%size;
            cqueue[rear]=x;
        }
    }
}

void dequeue(int cqueue[]){
    if(front==-1 && rear==-1){
        printf("Queue Empty");
        return;
    }
    else{
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%size;
        }
    }
}

void display(int cqueue[]){
    if(front==-1){
        printf("Queue empty");
    }
    else{
        for(int i=front; i!=rear; i=(i+1)%size){
        printf("%d\n", &cqueue[i]);
        } 
        printf("%d\n", cqueue[rear]);   
    }
    
}

void main(){
    int x, ch;
    while (ch!=4)
    {
        printf("\n---Menu---\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
            printf("\nEnter the element to be enqueued: ");
            scanf("%d", &x);
            enqueue(x, cqueue);
            break;

            case 2:
            dequeue(cqueue);
            break;

            case 3:
            display(cqueue);
            break;

            case 4:
            break;

            default: printf("Invalid choice");
        }
    }
}