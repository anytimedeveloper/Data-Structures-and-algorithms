#include <stdio.h>

void display(int array[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d  ",array[i]);
    }
    printf("\n");
}

void insertion(int array[],int size,int index,int element){
       if(size == 100){
           printf("Array is full");
       }
       for (int i = size-1; i >=index ; i--)
           {
               array[i+1]=array[i];
           }
           array[index]=element;
}

int main()
{
    int array[100], size,index,element;
    printf("Enter Array Size : ");
    scanf("%d", &size);
    printf("Enter Array Elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Array before insertion is : ");
    display(array,size);
    printf("Enter the index where you want to insert : ");
    scanf("%d",&index);
    printf("Enter the element you want to insert : ");
    scanf("%d",&element);
    insertion(array,size,index,element);
    size+=1;
    printf("Array after insertion is : ");
    display(array, size);
    return 0;
}