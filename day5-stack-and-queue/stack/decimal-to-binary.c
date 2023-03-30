#include "stdio.h"
#define MAX_OF_STACK_SIZE 10

int top = -1; // top of stack
int stack[MAX_OF_STACK_SIZE]; // stack
// prototypes
int pop(); // takes a value on top of stack and removes it from the stack
void push(int value); // pushes a value on top of stack
void h10Toh2(int n){
    while(n != 0){
        push(n%2);
        n = n / 2;
    }
    while(top >= 0){
        printf("%d", pop());
    }
}
int main(){
    int n;
    printf("Enter number:");
    scanf("%d", &n);
    printf("Binary:\n");
    h10Toh2(n);
    return 0;
}
int pop(){
    if(top >= 0){
        return stack[top--];
    }else{
        printf("stack is empty\n");
        return -1;
    }
}
void push(int value){
    if(top < MAX_OF_STACK_SIZE - 1){
        stack[++top] = value;
    }else{
        printf("Stack is full\n");
    }
}