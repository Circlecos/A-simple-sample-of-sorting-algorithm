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
	for (i=0;i<=k;i++)
		c[i]=0;
	for (j=0;j<n;j++)
		c[s[j]]++;
	for (i=1;i<=k;i++)	
		c[i]=c[i]+c[i-1];
	for (j=n-1;j>=0;j--)
	{
		out[c[s[j]]-1]=s[j];
		c[s[j]]=c[s[j]]-1;
	}
	//counting-sort
	
	for (i=0;i<n;i++)
		printf("%d ",out[i]);	
	//output
}
