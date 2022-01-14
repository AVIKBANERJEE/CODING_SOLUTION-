//WRITE A PROGRAM IN C TO SORT A GIVEN ARRAY USING MERGE SORT ALGORITHM//
#include<stdio.h>
 
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
 
int main()
{
int a[20],n,i;
printf("\nHow many elements? ");
scanf("%d",&n);
printf("\nEnter array elements:\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
mergeSort(a,0,n-1);
printf("\nSorted array is :");
for(i=0;i<n;i++)
printf("%d ",a[i]);
return 0;
}

 
void mergeSort(int a[],int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergeSort(a,low,mid); //left recursion
mergeSort(a,mid+1,high); //right recursion
merge(a,low,mid,mid+1,high); //merging of two sorted sub-arrays
}
}
void merge(int a[],int i1,int j1,int i2,int j2)
{
int temp[50]; //array used for merging
int i,j,k;
i=i1; //beginning of the first list
j=i2; //beginning of the second list
k=0;
while(i<=j1 && j<=j2) //while elements in both lists
{
if(a[i]<a[j])
{

temp[k]=a[i];
k++;
i++;
}
else{

temp[k]=a[j];
k++;
j++;
}
}
while(i<=j1)
{ //copy remaining elements of the first list
temp[k]=a[i];
k++;
i++;
}
while(j<=j2)
{ //copy remaining elements of the second list
temp[k]=a[j];
k++;
j++;
}
//Transfer elements from temp[] back to a[]
for(i=i1,j=0;i<=j2;i++,j++)
a[i]=temp[j];
}
