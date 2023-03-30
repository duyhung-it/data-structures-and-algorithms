#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_OF_QUEUE_SIZE 10

typedef struct Customer
{
    int id;
    char name[50];
}Customer;

Customer * queue[MAX_OF_QUEUE_SIZE];
int rear = -1;
int front = -1;
// prototypes
void enqueue(Customer * customer); // pushes value to queue
Customer * dequeue(); // takes value from queue
int isEmpty();
int main(){
    Customer * c1 = malloc(sizeof(Customer));
    c1->id = 1;
    strcpy(c1->name,"An");
    enqueue(c1);
    Customer * c2 = malloc(sizeof(Customer));
    c2->id = 2;
    strcpy(c2->name,"Hung");
    enqueue(c2);
    while(!isEmpty()) {
        Customer *tmp = dequeue();
        printf("Customer id: %d\n", tmp->id);
        printf("Customer name: %s\n", tmp->name);
    }
    return 0;
}

void enqueue(Customer * customer){
    if(rear < MAX_OF_QUEUE_SIZE - 1){
        rear = rear + 1;
        queue[rear] = customer;
    }else{
        printf("Queue is full\n");
    }
}
Customer * dequeue(){
    if(front == rear){
        printf("Queue is empty\n");
        return NULL;
    }
    front = front + 1;
    return queue[front];
}

int isEmpty(){
    if(front == rear){
        return 1;
    } else {
        return 0;
    }
}