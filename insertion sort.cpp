// insertion sort
#include <stdio.h>
#define N 1000
int s[N]; 
int main(void)
{
	int i,j,n,key;
	printf("Please input the number of data\n");
	scanf("%d",&n); 
	if (n<=0) {printf("error:input invalid\n");return 1;}
	printf("Please input the data\n");
	for (i=0;i<n;i++)
		scanf("%d",&s[i]);
	// input
	for (j=1;j<n;j++)
	{
		key=s[j];
		i=j-1;
		while ((i>=0)&&(s[i]>key))
		{
			s[i+1]=s[i];
			i=i-1;
		}
		s[i+1]=key;
	}
	//insertion-sort
	
	for (i=0;i<n;i++)
		printf("%d ",s[i]);	
	//output
}
