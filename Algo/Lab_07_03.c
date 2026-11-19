#include <stdio.h>
int temp, minIndex;
void selectionSorting(int arr[], int n);
void PrintSortedArray(int arr[], int n);
void CreateArrty(int arr[],int m);


int main(){

    int n;
    printf("Enter number of products: ");
    scanf("%d" , &n);
    if (n>0 && n<=10){
        int arr[n];
        CreateArrty(arr, n);
        selectionSorting(arr,n);
        printf("Products from the lowest-priced to highest-priced : ");
        PrintSortedArray(arr,n);
    }
    else{
        printf("System cannot handle %d  No of products at once.\n" , n);
    
    }

    return 0;
}
void CreateArrty(int arr[],int m){
    for (int i=0; i<m; i++){
        printf("Enter element %d :" ,i+1  );
        scanf("%d" , &arr[i]);
    }
}


void selectionSorting(int arr[], int n){
     for (int i=0; i<n-1; i++){
        minIndex = i;
        for(int j= i+1; j<n; j++){
            if(arr[minIndex]>arr[j]){
                minIndex=j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex]=temp;

    } 
}
void PrintSortedArray(int arr[], int n){
    for (int i=0; i<n; i++){
        printf("%d " ,arr[i]);
    }
}