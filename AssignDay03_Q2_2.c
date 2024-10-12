#include<stdio.h>
#define SIZE 10
#define SWAP(a, b) int temp=a; a=b; b=temp;
int iter, comp, iter1, comp1;

void bubble_sort(int arr[SIZE]){

    for(int i=0;i<SIZE-1;i++){
        iter++;
        for(int j=0;j<SIZE-1-i;j++){
            comp++;
            if(arr[j]>arr[j+1]){
            SWAP(arr[j],arr[j+1]);
            
        }
    }

}
}

void best_bubble_sort(int arr[SIZE]){
   
    int flag=0;

    for(int i=0;i<SIZE-1;i++){
        iter1++;
        for(int j=0;j<SIZE-1-i;j++){
            comp1++;
            if(arr[j]>arr[j+1]){
            SWAP(arr[j],arr[j+1]);
            flag=1;   
        }
    }
    if(!flag){
        break;
    }

}
}



void display_sort(int arr[SIZE]){
    for(int i=0; i<SIZE; i++){
        printf("   %d", arr[i]);
    }

}


int main(){
    int arr[SIZE]={11,22,33,44,55,66,77,88,99, 100};
    printf("Before sort:");
    display_sort(arr);
    bubble_sort(arr);
     printf("\nAfter sort:");
    display_sort(arr);
    printf("\n iter=%d, comp=%d", iter, comp);


     printf("\nBefore sort:");
    display_sort(arr);
   best_bubble_sort(arr);
     printf("\nAfter sort:");
    display_sort(arr);
    printf("\n iter=%d, comp=%d", iter1, comp1);
    return 0;
}