#include<stdio.h>

void printArr(int a[],int start, int end){
    int i=0;
    for(i=start;i<=end;i++){
       printf("%d ",a[i]);
    }
	printf("\n");
}


void merge(int a[], int p, int q, int r){
  int left[q-p], right[r-q+1],i,j;
  for(i=p;i<q;i++){
    left[i-p]=a[i];
  }
  for(i=q;i<=r;i++){
    right[i-q]=a[i];
  }
  i=0;
  j=0;
  int k=p;
  while(i<q-p && j<r-q+1){
    if(left[i]<=right[j]){
      a[k]=left[i];
      i++;
      k++;
    }
    else{
      a[k]=right[j];
      j++;
      k++;
    }
  }
  while(i<q-p){
    a[k]=left[i];
    i++;
    k++;
  }
  while(j<r-q+1){
    a[k]=right[j];
    j++;
    k++;
  }
}
void mergeSort(int a[], int start, int end){
  if (end-start<1){
    return;
  }
  else{
    int middle=0;
    middle=(start+end)/2;
    mergeSort(a,start, middle);
	mergeSort(a,middle+1, end);
	merge(a,start,middle+1,end);
  }
}


int main(){
    int n;
    printf("enter the size of array:");
    scanf("%d",&n);
    int a[n];
    int i;
    for (i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
    printf("before\n");
    printArr(a,0,n-1);
    mergeSort(a,0,n-1);
    printf("\nafter\n");
    printArr(a,0,n-1);
    return 0;
}

























