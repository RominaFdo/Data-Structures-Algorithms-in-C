#include <stdio.h>
#include <string.h>

void charArr(const char *arr){
    if (*arr == '\0'){
        return;
    }
    printf("%c ", *arr);
    charArr(arr+1);
}

int main(){
    char *b= "HelloWorld";
    charArr(b);
    return 0;
}