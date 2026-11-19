#include <stdio.h>

void dis(int n){
    if (n<0){
        return;
    }
    printf("%d ", n);
    dis(n-1);
}
int main(){
    dis(10);
    return 0;
}