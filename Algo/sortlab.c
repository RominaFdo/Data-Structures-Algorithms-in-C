//c program for insertion sort


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
        printf("a[%d+1] = %d\n" ,j ,key);

    }
}

int main(){
    int a[]={8,4,9,5,7,6,3,2};
    insertionsort(a,8);
    for (int i=0; i<8; i++){
        printf("a[%d] ==> %d ",i,a[i]);
    }
    return 0;
}
