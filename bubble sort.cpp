// bubble sort
#include <stdio.h>
#define N 1000
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
	for (j=0;j<n-1;j++)
	{
		for (i=0;i<n-1-j;i++)
			if (s[i]>s[i+1]) 
			{ swap=s[i];s[i]=s[i+1];s[i+1]=swap;}
	}
	//bubble-sort
	
	for (i=0;i<n;i++)
		printf("%d ",s[i]);	
	//output
}
