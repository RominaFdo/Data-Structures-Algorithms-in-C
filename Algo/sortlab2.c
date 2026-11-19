//c program for insertion sort q 2


#include <stdio.h>

void insertionsort(int a[],int length){
    for (int i=1; i<length; i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;

    }
}

int main(){
    int n;
    printf("Enter number of elements i  the array:");
    scanf("%d" , &n);
    int a[n];
    for (int i=0; i< n; i++ ){
        printf("Enter element %d :",i+1);
        scanf("%d",&a[i]);
    }

    insertionsort(a,n);
    for (int i=0; i<n; i++){
        printf("a[%d] ==> %d ",i,a[i]);
    }
    return 0;
}
