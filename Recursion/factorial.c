#include <stdio.h>

unsigned int factorial(unsigned  int  n, unsigned  int result){
    if(n == 0 || n== 1){
        return result;
    }
    else{
        return factorial(n-1, n*result);
    }
}
int main(){
    unsigned int num = 5;
    unsigned int result = factorial(num, 1);
    printf("Factorial of %u  = %u", num, result);
    return 0;
}