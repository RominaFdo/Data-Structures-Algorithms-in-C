#include <stdio.h>
int temp, minIndex;
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

int main(){
    int arr[] = {25 , 64, 12, 11, 22};
    int n = sizeof(arr) / sizeof(int);
    selectionSorting(arr, n); 
    PrintSortedArray(arr, n);
   

    return 0;
}