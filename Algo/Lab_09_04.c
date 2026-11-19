#include <stdio.h>

int Prime(int n,int m){
    if (m == 1){
        return 1;
    }
    else{
        if(n %m == 0){
            return 0;
        }
        else{
            return Prime(n,m-1);
        }
    }
}
int main(){
    int n;
    printf("Enter Number to check whether Prime or Not :");
    scanf("%d" ,&n);
    int r = Prime(n,n-1);
    if (r== 1){
        printf("Is A Prime Number.");
    }
    else{
        printf("Not A Prime Number.");
    }
    return 0;
}