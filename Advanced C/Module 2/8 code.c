#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

bool isSubset(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if(arr1[i] == arr2[j])
                break;
        }
        if (j == n)
            return false;
    }
    return true;
}

int main() {
	int m,n,i;
    int arr1[20],arr2[10];
    printf("\nEnter the size of array 1 (size of arr1<arr2) : ");
    scanf("%d",&m);
    printf("\nEnter elements of array 1: ");
    for(i=0;i<m;i++)
    	scanf("%d",&arr1[i]);
    
    printf("\nEnter the size of array 2 (size of arr1<arr2) : ");
    scanf("%d",&n);
    printf("\nEnter elements of array 1: ");
    for(i=0;i<n;i++)
    	scanf("%d",&arr2[i]);

    // Sort both arrays using bubble sort
    bubbleSort(arr1, m);
    bubbleSort(arr2, n);

    if (isSubset(arr1, arr2, m, n))
        printf("arr1[] is a subset of arr2[]\n");
    else
        printf("arr1[] is not a subset of arr2[]\n");

    return 0;
}
