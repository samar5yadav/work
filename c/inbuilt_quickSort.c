#include<stdio.h>
#include<stdlib.h>

int comp(const void *a, const void *b){ //void pointer is a special type of pointer which can point to any kind of data type
  int x = *((int*)a); //conversion from void pointer to integer pointer then dereference
  int y = *((int*)b);
  return x>y?1:
    x==y?0:-1;
}
void printArr(int *a, int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
}
int main(){
  int n=9;
  int a[]={5,3,1,2,6,0,0,7,6};
  qsort(a,9,sizeof(int),comp);
	printArr(a,n);
  
  return 0;
}
