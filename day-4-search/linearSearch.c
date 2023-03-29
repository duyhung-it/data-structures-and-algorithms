#include <stdio.h>

int linearSearch(int x, int arr[]){
    for(int i=0; i<7; i++){
        if(arr[i] == x){ // if found x in the array
            return i;
        }
    }
    // if not found x in the array
    return -1;
}

int main(){
    int arr[] = {0,1,2,3,4,5,6};
    int x;
    printf("Enter x: ");
    scanf("%d", &x);
    int result = linearSearch(x, arr);
    if(result == -1){
        printf("x not exist\n");
    }else{
        printf("x found at index %d\n",result);
    }
}