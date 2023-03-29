#include <stdio.h>

int factorial(int n){
    if(n == 0) return 1;
    else{
        return n * factorial(n-1);
    }
}

int main(){
    int arr[]= {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d",n);
    return 0;
}