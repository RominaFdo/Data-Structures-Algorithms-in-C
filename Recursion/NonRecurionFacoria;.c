#include <stdio.h>

int factorial(int n){
    int result = 1;
    for(int i=1; i<=n; i++){
        result = result * i;
    }
    return result;
}

int main(){
    int num = 5;
    int result = factorial(num);
    printf("Factorial of %d  = %d", num, result);
    return 0;
}