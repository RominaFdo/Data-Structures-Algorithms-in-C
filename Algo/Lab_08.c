#include<stdio.h>

void Bubblesort(int arr[] , int n){
    int i,j,temp;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }
    
}

void Avg(int arr[] , int n){
    int sum=0;
    for (int i = 0; i <n; i++)
    {
        sum += arr[i];
    }
    
}

int main(){
    int arr[] = {120,33,59,10,75,85,165,8,90,44};
    int m =sizeof(arr)/sizeof(int);
    Bubblesort(arr,m);
    printf("Sorted\n");
    for(int i = 0; i < m; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    Avg(arr,m);
    for (int i = 0; i < m; i++)
    {
        if(arr[i]>=50){
            printf("%d ",arr[i]);
        }
    }
    
    return 0;
}