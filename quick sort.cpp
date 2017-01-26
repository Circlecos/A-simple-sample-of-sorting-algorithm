// quick sort
#include <stdio.h>
#define N 1000

int quicksort(int *arr,int left,int right);

int s[N]; 
int main(void)
{
	int i,j,n,swap;
	printf("Please input the number of data\n");
	scanf("%d",&n);
	if (n<=0) {printf("error:input invalid");return 1;}
	printf("Please input the data\n");
	for (i=0;i<n;i++)
		scanf("%d",&s[i]);
	// input
	
	quicksort(s,0,n-1);
	
	for (i=0;i<n;i++)
		printf("%d ",s[i]);	
	//output
}

