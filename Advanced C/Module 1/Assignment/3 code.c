#include<stdio.h>

void swap(int *x, int *y);

int main(){
	void (*p)(int *,int *);
	int a,b;
	printf("\nEnter the value of a: ");
	scanf("%d",&a);
	printf("Enter the value of b: ");
	scanf("%d",&b);
	p=swap;
	(*p)(&a,&b);
	printf("\n\nAfter Swap: ");
	printf("\n\nThe value of a is: %d",a);
	printf("\nThe value of b is: %d",b);
	return 0;
}

void swap(int *x,int *y){
	*x=*x+*y;
	*y=*x-*y;
	*x=*x-*y;
}
