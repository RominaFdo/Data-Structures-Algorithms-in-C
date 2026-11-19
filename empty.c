#include <stdio.h>
//void get(int n){
//    if(n<1){
//        return;
//    }
//    get(n-1);
//    get(n-3);
//    printf("%d ",n );
//}
void InsertionSort(int arr[], int n,int s){
    int key;
    for(int i=1; i<n; i++){
        key = arr[i];
        int j =i-1;
        if(j>=0 && arr[j]>key) {
//            printf("%d +%d\n" , key, arr[j]);
            arr[j+1]= arr[j];
            j = j-1;
        }
        arr[j+1]=key;

    }
}
int main(){
//    get(6);

    int arr[]={8,4,3,7};
    InsertionSort(arr, 4, 10);
    for (int i = 0; i < 4; i++) {
        printf("%d  ",arr[i]);
    }
    return 0;
}