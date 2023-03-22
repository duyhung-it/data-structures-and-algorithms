#include <stdio.h>

void enter_values(int arr[]);// this method will enter values to the array
void print(int arr[]); // this method will print the values in the array
int main(void){
    int array[5]; // declare an array of integers with length 5
    enter_values(array);
    printf("The values in the array: \n");
    print(array);
    return 0;
}

void enter_values(int arr[]){
    for(int i=0; i<5; i++){
        printf("Enter value %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}
void print(int arr[]){
    for(int i=0; i<5; i++){
        printf("Arr[%d]: %d\n",i+1,arr[i]);
    }
}  
