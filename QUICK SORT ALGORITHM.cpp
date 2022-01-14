//WRITE A PROGRAM IN C TO SORT A GIVEN ALGORITHM USING QUICK SORT ALGORITHM//
#include<stdio.h>
void swap(int arr[],int x,int y)
{
	int temp=arr[x];
	arr[x]=arr[y];
	arr[y]=temp;
}
int partition(int arr[],int low,int high)
{
	int i=low;
	int j=high+1;
	int pivot=arr[low];
	while(i<j)
	{
		do{
			i++;
		}while(i<=high && arr[i]<=pivot);
		do{
			j--;
		}while(arr[j]>pivot);
		if(i<j)
			swap(arr,i,j);
	}
	swap(arr,low,j);
	return j;
}
void quicksort(int arr[],int low,int high)
{
	int j=partition(arr,low,high);
	if(low<high)
	{
		quicksort(arr,low,j-1);
		quicksort(arr,j+1,high);
	}
}
int printarray(int arr[],int n)
{
	int i;
	printf("Sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int main()
{
	int n,i;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	
	int arr[n];
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,n-1);
	printarray(arr,n);
	return 0;
}
