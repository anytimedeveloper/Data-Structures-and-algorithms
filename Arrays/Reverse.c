#include<stdio.h>

void display(int array[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d  ",array[i]);
    }
    printf("\n");
}

void Reverse(int array[],int size){
    int temp;
    for (int i = 0; i < size/2; i++)
    {
        temp = array[i];
        array[i]=array[size-i-1];
        array[size - i - 1]=temp;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", array[i]);
    }
    
    printf("\n");
}

  
int main(){
  int array[100],size;
  printf("Enter the size of the array : ");
  scanf("%d",&size);
  printf("Enter the elements of the array : ");
  for (int i = 0; i < size; i++)
  {
      scanf("%d",&array[i]);
  }
  printf("Array elements are : ");
  display(array,size);

  printf("After reversing  the array is :");
  Reverse(array,size);
  display(array, size);
  return 0;
}