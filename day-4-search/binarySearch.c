#include <stdio.h>

int binarySearch(int x, int left, int right, int arr[]){
    while(left <= right){
        int middle = (left+right)/2;
        if(arr[middle] == x){
            return middle;
        }else if(arr[middle] >= x){
            right = middle - 1;
        } else {
            left = middle + 1;
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
    int result = binarySearch(x,0,7, arr);
    if(result == -1){
        printf("x not exist\n");
    }else{
        printf("x found at index %d\n",result);
    }
    return 0;
}