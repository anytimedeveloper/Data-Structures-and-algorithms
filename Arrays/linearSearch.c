#include<stdio.h>

void display(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

 int linearSearch(int array[],int size,int element){
   for (int i = 0; i <= size; i++)
   {
       if(array[i]==element){
       return i;   
       }
   }
   return -1;
}


int main(){
    int array[100],size,element;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    printf("Enter the elements of the array :");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Array elements are : ");
    display(array,size);
    printf("Enter the element you want to search : ");
    scanf("%d",&element);
    int result=linearSearch(array,size,element);
    (result == -1) ? printf("Element %d was not in the array",element) : printf("Element %d is present in the array at index %d",element,result);
}