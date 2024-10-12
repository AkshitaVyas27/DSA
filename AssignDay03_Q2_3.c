#include<stdio.h>
#define SIZE 10
int comp, iter;

void insertion_sort(int arr[SIZE]){
    int temp,j;
    for(int i=1;i<SIZE;i++){
        iter++;
        temp=arr[i];
        for(j=i-1;j>=0&& temp<arr[j];j--){
            comp++;
                arr[j+1]=arr[j];
            
        }
        arr[j+1]=temp;
    }

}
void print_sort(int arr[SIZE]){
    for(int i=0; i<SIZE; i++){
        printf("   %d", arr[i]);
    }

}


int main(){
    int arr[SIZE]={323,45545,23,22,4,32,4,544,5,10};
    printf("Before swap");
    print_sort(arr);
    insertion_sort(arr);
    printf("\nAfter swap");
    print_sort(arr);
    printf("Iteration= %d, comparision= %d", iter, comp);


return 0;

}