#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubble_sort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int swapped=0;
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;
            }
        }
        if(!swapped){
            break;
        }
    }
    return 0;
}
void generateRandomArray(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i]= rand() % 100000; 
    }
}

int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n); 
    if(n<=10){ //n= 10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000
        printf("Please enter a value greater than 8000\n");
        return 1; 
    }
    int *arr= (int*)malloc(n* sizeof(int));
    if(arr==NULL){
        printf("Memory allocation failed\n");
        return 1; 
    }

    clock_t start= clock(); 
    for(int i=0; i<1000; i++){
        generateRandomArray(arr,n);
        bubble_sort(arr,n);
    }
    clock_t end= clock();
    double time_taken= ((double)(end-start))/CLOCKS_PER_SEC/1000.0;  
    printf("Time taken to sort %d elements: %f seconds\n",n,time_taken);
    free(arr);
    return 0;
}