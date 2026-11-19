#include <stdio.h>

void RevArr(int arr[],int n,int i){
    if (i==n){
        return;
    }
    RevArr(arr,n,i+1);
    printf("%d ",arr[i]);
}

int main(){
    int a[] = {1,4,5,2,3,7,8,9};
    int m = sizeof(a)/sizeof(int);
    RevArr(a,m,0);
    return 0;
}