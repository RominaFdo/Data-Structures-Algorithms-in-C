#include <stdio.h>

int Fibonacci(int n){
    if (n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return (Fibonacci(n-1)+Fibonacci(n-2));
    }
}
int main(){
    int n;
    printf("Number of elements in the Fibonacci series :");
    scanf("%d" , &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d " ,Fibonacci(i) );
    }
    
    
    return 0;
}