#include <stdio.h>

void bin(int n){
    if(n!=1){
        bin(n/2);
    }
    printf("%d", n%2);

}

int main(){
    int m =32;
    printf("Binary number of %d  = ",m);
    bin(m);
    return 0;
}