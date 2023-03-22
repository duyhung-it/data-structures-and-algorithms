#include <stdio.h>

void input_values(int arr[][3]);
void print_values(int arr[][3]);

int main(void){
    int  arr[2][3];// declare a double array with 2 rows and 3 columns
    input_values(arr);
    printf("Output values: \n");
    print_values(arr);
}

void input_values(int arr[][3]){
    for(int i= 0; i < 2; i++){ // loop over values of each row
        for(int j = 0; j < 3; j++){ // loop over values of each column
            printf("array[%d][%d]: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        } 
    }
}
void print_values(int arr[][3]){
    for(int i= 0; i < 2; i++){ // loop over values of each row
        for(int j = 0; j < 3; j++){ // loop over values of each column
            printf("%d ",arr[i][j]);
        } 
        printf("\n");
    }
}
