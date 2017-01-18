// shell sort
#include <stdio.h>
#define N 1000
int s[N]; 
int main(void)
{
	int i,j,gap,key,k,n;
	printf("Please input the number of data\n");
	scanf("%d",&n);
	if (n<=0) {printf("error:input invalid");return 1;}
	printf("Please input the data\n");
	for (i=0;i<n;i++)
		scanf("%d",&s[i]);
	// input
	for (gap=n/2;gap>0;gap/=2)
	{
		for (i=0;i<gap;i++)
		{
			for (j=i+gap;j<n;j+=gap)
			{
				key=s[j];
				k=j-gap;
				while ((k>=0)&&(s[k]>key))
				{
					s[k+gap]=s[k];
					k=k-gap;
				}
				s[k+gap]=key;
			}
		}
	}
	//shell-sort
	
	for (i=0;i<n;i++)
		printf("%d ",s[i]);	
	//output
}
