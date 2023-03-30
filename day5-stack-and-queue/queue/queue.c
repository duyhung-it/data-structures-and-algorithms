#include <stdio.h>
#define MAX_OF_QUEUE_SIZE 10

int queue[MAX_OF_QUEUE_SIZE];
int rear = -1;
int front = -1;
// prototypes
void enqueue(int value); // pushes value to queue
int dequeue(); // takes value from queue
int main(){
    
    return 0;
}

void enqueue(int value){
    if(rear < MAX_OF_QUEUE_SIZE - 1){
        rear = rear + 1;
        queue[rear] = value;
    }else{
        printf("Queue is full\n");
    }
}
int dequeue(){
    if(front == rear){
        printf("Queue is empty\n");
        exit(0);
    }
    front = front + 1;
    return queue[front];
}