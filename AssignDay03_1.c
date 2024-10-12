#include<stdio.h>
#define SIZE 9
int i;
int linear_search(int arr[], int key, int j){
    if(j>=0){
    if(arr[j]==key){
    return j;
    }
	else{ 
    i++;
	linear_search(arr, key, SIZE-i);
}
    }
    else
    return -1;
}


int main(){
    int arr[SIZE]={11, 22, 33, 44, 55, 66, 77, 88, 99};
    int key;
    printf("Enter the number you want to search:");
    scanf("%d", &key);
    int val= linear_search(arr, key, SIZE-i);
    if(val==-1)
    printf("\nUnfortunately the key wasn't found.");

    else
    printf("The key was found at index: %d", val);
   

return 0;
}