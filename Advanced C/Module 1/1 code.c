#include<stdio.h>
int main(){
	int n,res;
	printf("\nEnter the number: ");
	scanf("%d",&n);
	res=n&1;
	if(res==1)
		printf("\nThe entered number is odd!");
	else
		printf("\nThe entered number is even!");
	return 0;
}
