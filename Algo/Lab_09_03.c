#include <stdio.h>

int Product(int n, int m){
    if (m==1){
        return n;
    }
    else{
        return (n+ Product(n, m-1));
    }
}
int main(){
    int n,m;
    printf("Enter Number 1 :");
    scanf("%d" , &n);
    printf("Enter Number 2 :");
    scanf("%d" , &m); 
    int r;
    r =Product(n,m);
    printf("%d x %d = %d" , n, m ,r);
    return 0;
}