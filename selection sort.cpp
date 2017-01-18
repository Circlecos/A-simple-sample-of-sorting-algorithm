// selection sort
#include <stdio.h>
#define N 1000
int s[N]; 
int main(void)
{
	int i,j,n,swap,min;
	printf("Please input the number of data\n");
	scanf("%d",&n);
	if (n<=0) {printf("error:input invalid");return 1;}
	printf("Please input the data\n");
	for (i=0;i<n;i++)
		scanf("%d",&s[i]);
	// input
	for (i=0;i<n-1;i++)
	{
		min=i;
		for (j=i+1;j<n;j++)
			if (s[j]<s[min]) 
				min=j;
		swap=s[i];s[i]=s[min];s[min]=swap;
	}
	//selection-sort
	
	for (i=0;i<n;i++)
		printf("%d ",s[i]);	
	//output
}
