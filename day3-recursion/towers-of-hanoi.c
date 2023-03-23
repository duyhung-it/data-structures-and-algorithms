#include <stdio.h>

void towersOfHaNoi(int n,char a,char b, char c){
    if(n <= 1){
        printf("%c -> %c\n",a,c);
        return;
    }
    towersOfHaNoi(n-1,a,c,b);
    printf("%c -> %c\n",a,c);
    towersOfHaNoi(n-1,b,a,c);
}

int main(){
    printf("Step by step of puzzle: \n");
    towersOfHaNoi(2,'A','B','C');
    return 0;
}