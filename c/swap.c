#include<stdio.h>
void swap(int* a, int* b){
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

int main(){

	int a=5, b=3;
	printf("before a: %d and b: %d\n",a,b);
	swap(&a,&b);
	printf("after a: %d and b: %d\n",a,b);
	return 0;
}
