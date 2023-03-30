#include <stdio.h>
#define MAX_OF_STACK_SIZE 10
int top = -1;
int stack[MAX_OF_STACK_SIZE];
// prototypes
int pop(); // takes a value on top of stack and removes it from the stack
void push(int value); // push a value into stack


int main(){
    int n;
    printf("Enter number:");
    scanf("%d", &n);
    push(n);
    printf("Value : %d\n",pop());
    return 0;
}

void push(int value){
    if(top < MAX_OF_STACK_SIZE - 1){
        stack[++top] = value;
    }else{
        printf("Stack is full\n");
    }
}
int pop(){
    if(top >=0){
        return stack[top--];
    }else{
        printf("Stack is empty\n");
        return -1;
    }
}