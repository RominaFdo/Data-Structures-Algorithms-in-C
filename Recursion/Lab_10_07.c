#include <stdio.h>
void even(int n);

void odd(int n){
    if(n<0){
        return;
    }
    else{
        printf("%d " , n);
        if(n!=0){
            even(n-1);
        }
    }
}

void even(int n){
    if(n<0){
        return;
    }
    else{
        printf("%d " , n);
        if(n!= 0){
            odd(n-1);
        }
    }
}



int main(){
    even(10);
    return 0;
}