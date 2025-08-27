#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high){
    int pivot= arr[high];
    int i= low-1;
    for(int j=low; j<high; j++){
        if(arr[j]<=pivot){
            i++;
            int temp= arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    int temp= arr[i+1];
    arr[i+1]=arr[high];
    arr[high]= temp;
    return i+1;
}

int quick_sort(int arr[], int low, int high){
    if(low<high){
        int pi= partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
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
    if(n<=8000){ //n= 10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000
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
        quick_sort(arr,0, n-1);
    }
    clock_t end= clock();
    double time_taken= ((double)(end-start))/CLOCKS_PER_SEC/1000.0;  
    printf("Time taken to sort %d elements: %f seconds\n",n,time_taken);
    free(arr);
    return 0;
}

