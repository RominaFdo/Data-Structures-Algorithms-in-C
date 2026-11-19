#include <stdio.h>
int temp, minIndex, maxIndex;
void selectionSortingAscending(int arr[], int n);
void PrintSortedArray(int arr[],int n);
void CreateArrty(int arr[],int m);
void selectionSortingDescending(int arr[], int m); 

int main(){
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d" , &n);
    int arr[n];
    CreateArrty(arr, n);

    return 0;
}

void selectionSortingAscending(int arr[], int n){
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
void selectionSortingDescending(int arr[], int m){
    for(int i=0; i<m; i++){
        maxIndex= i;
        for(int j=i+1; j<m; j++){
            if(arr[maxIndex]< arr[j]){
                maxIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}
void PrintSortedArray(int arr[],int n){
    for (int i=0; i<n; i++){
        printf("%d " ,arr[i]);
    }
}

void CreateArrty(int arr[],int m){
    for (int i=0; i<m; i++){
        printf("Enter element %d :" ,i+1  );
        scanf("%d" , &arr[i]);
    }
    selectionSortingAscending(arr, m); 
    printf("Array Sorted in Ascending Order  :\n");
    PrintSortedArray(arr,m);
    selectionSortingDescending(arr, m); 
    printf("Array Sorted in Descending Order  :\n");
    PrintSortedArray(arr,m);
}
