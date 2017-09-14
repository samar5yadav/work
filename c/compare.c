#include<stdio.h>

int comp(const void *a, const void *b){
    int x = *((int*)a); //conversion from void pointer to integer pointer then der
    int y = *((int*)b);
    return x>y?1:
      x==y?0:-1;
}


int main(){
  int a=2, b=1;
  printf("%d\n",comp(&a,&b));
  return 0;
}
