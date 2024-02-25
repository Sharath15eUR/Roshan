#include<stdio.h>
int main(){
	int n,n2,res=0;
	printf("\nEnter the number: ");
	scanf("%d",&n);
	while(n!=0){
		n2=n&1;
		if(n2==1)
			res+=1;
		n>>=1;
	}
	printf("\nThe no.of bits set in the entered number are: %d", res);
	return 0;
}
