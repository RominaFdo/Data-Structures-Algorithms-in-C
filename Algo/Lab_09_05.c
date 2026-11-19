#include <stdio.h>

void rec(int num){
    if (num > 10) {
        return;
    }

    if (num % 2 == 0) {
        printf("%d ", num - 1);
    } else {
        printf("%d ", num + 1);
    }

    rec(num+1);
}
int main(){
    rec(1);
    return 0;
}