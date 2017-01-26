// counting sort
#include <stdio.h>
#define N 1000
int s[N],out[N],c[N]; 
int main(void)
{
	int i,j,n,k,key;
	printf("Please input the number of data\n");
	scanf("%d",&n);
	printf("Please input the upper bound of data \n");
	scanf("%d",&k);
	if ((n<=0)||(k<=0)) {printf("error:input invalid");return 1;}
	printf("Please input the data\n");
	for (i=0;i<n;i++)
		scanf("%d",&s[i]);
	// input
	
	//counting-sort
	
	for (i=0;i<n;i++)
		printf("%d ",out[i]);	
	//output
}
