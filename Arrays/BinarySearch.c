#include<stdio.h>

void display(int array[],int n){
    for (int i = 0; i < n; i++)
    {
       printf("%d  ",array[i]);
    }
    printf("\n");
}

int binarySearch(int array[],int size,int element){
    int low=0;
    int high=size-1;
    while (low<=high)
    {
    int mid=(low+high)/2;
    if(array[mid]==element){
        return mid;
    }
    else if(array[mid]<element){
     low = mid+1;
    }
    else if(array[mid]>element){
        high=mid-1;
    }
    }
    return -1;
}

int main(){
    int array[100],size,element;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    printf("Enter the elements of the array : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Array elements are : ");
    display(array,size);
    printf("Enter the element you want to search : ");
    scanf("%d",&element);
    int result=binarySearch(array,size,element);
    (result == -1) ? printf("Element %d was not in the array", element) : printf("Element %d is present in the array at index %d", element, result);
}