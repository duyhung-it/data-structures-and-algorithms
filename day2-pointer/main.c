#include <stdio.h>

void swap(int *a, int *b);

int main(){
    int *a, *b; // a,b are two pointers 
    printf("enter a: ");
    scanf("%d",a);
    printf("enter b: ");
    scanf("%d",b);
    printf("a = %d, b = %d\n",*a,*b);
    swap(a,b);
    printf("After swap:\n");
    printf("a = %d, b = %d\n",*a,*b);
    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}