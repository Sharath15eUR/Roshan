#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,**matrix1,**matrix2,**res;
	int i,j,k;
	
	printf("\nEnter the dimension of the square matrix(n): ");
	scanf("%d",&n);
	
	matrix1=(int**)malloc(n*sizeof(int*));
	matrix2=(int**)malloc(n*sizeof(int*));
	res=(int**)malloc(n*sizeof(int*));
	
	for(i=0;i<n;i++){
		matrix1[i]=(int*)malloc(n*sizeof(int));
		matrix2[i]=(int*)malloc(n*sizeof(int));
		res[i]=(int*)malloc(n*sizeof(int));
	}
	
	printf("\nEnter the values of Matrix 1: ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matrix1[i][j]);
		}
	}
	
	printf("\nEnter the values of Matrix 2: ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matrix2[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        	res[i][j]=0;
            for(k=0;k<n;k++){
            	res[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    printf("\nThe resultant Matrix is: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
