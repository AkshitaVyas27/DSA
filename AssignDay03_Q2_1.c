#include<stdio.h>
#define SIZE 10
#define SWAP(a,b) int temp=a; a=b; b=temp;
int comp, iteration;

void selection_sort(int arr[SIZE]){
    int i,j,temp;
for(i=0; i<SIZE-1; i++){
    iteration++;
    for(j=i+1; j<SIZE; j++){
        if(arr[i]>arr[j]){
            comp++;
           SWAP(arr[i], arr[j]);
        }
    }
}

}
void print_sort(int arr[SIZE]){
    for(int i=0; i<SIZE; i++){
        printf("   %d", arr[i]);
    }

}



int main(){

int arr[SIZE]={12, 34, 122, 43, 1, 55, 87, 78, 0, 40};
    printf("Before swap:  ");
    print_sort(arr);
    selection_sort(arr);
      printf("\nAfter swap:  ");
    print_sort(arr);


    printf("\nIteration=%d, Comparison= %d",iteration, comp);

return 0;
}