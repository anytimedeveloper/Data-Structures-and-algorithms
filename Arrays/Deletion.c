#include<stdio.h>

void display(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}
void deletion(int array[],int size,int index){
    if(index>100){
        printf("Index out of Bounds");
    }
    for (int i = index-1; i <= size; i++)
    {
        array[i]=array[i+1];
    }
    
}

int main(){
 int array[100],size,index;
 printf("Enter the size of the array : ");
 scanf("%d",&size);
 printf("Enter the elements of the array : ");
 for (int i = 0; i < size; i++)
 {
     scanf("%d",&array[i]);
 }
 printf("Array before deletion is : ");
 display(array, size);
 printf("Entert the element no. you want to delete : ");
 scanf("%d",&index);
 deletion(array,size,index);
 size-=1;
 printf("Array after deletion is : ");
 display(array, size);
 }