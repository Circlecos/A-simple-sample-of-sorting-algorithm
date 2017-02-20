#include "sort.h"
#include <math.h>
#ifndef N
#define N 1000
#endif
int InsertionSort(int n,int *x)
{
	int key,i=0,j=0;
	for (j=1;j<n;j++)
	{
		key=x[j];
		i=j-1;
		while ((i>=0)&&(x[i]>key))
		{
			x[i+1]=x[i];
			i=i-1;
		}
		x[i+1]=key;	
	}
	return 0;
}

int ShellSort(int n,int *x)
{
	int gap,i=0,j=0,k,key;
	for (gap=n/2;gap>0;gap/=2)
	{
		for (i=0;i<gap;i++)
		{
			for (j=i+gap;j<n;j+=gap)
			{
				key=x[j];
				k=j-gap;
				while ((k>=0)&&(x[k]>key))
				{
					x[k+gap]=x[k];
					k=k-gap;
				}
				x[k+gap]=key;
			}
		}
	}
	return 0;
}

int CountingSort(int n,int k,int *x)
{
	int i=0,j=0,c[N],y[N];
	for (i=0;i<=k;i++)
		c[i]=0;
	for (j=0;j<n;j++)
		c[x[j]]++;
	for (i=1;i<=k;i++)	
		c[i]=c[i]+c[i-1];
	for (j=n-1;j>=0;j--)
	{
		y[c[x[j]]-1]=x[j];
		c[x[j]]=c[x[j]]-1;
	}
	for (i=0;i<n;i++)
		x[i]=y[i];
	return 0;
}

int SelectionSort(int n,int *x)
{
	int swap,i=0,j=0,min;
	for (i=0;i<n-1;i++)
	{
		min=i;
		for (j=i+1;j<n;j++)
			if (x[j]<x[min]) min=j;
		swap=x[i];x[i]=x[min];x[min]=swap;
	}
	return 0;
}

int BubbleSort(int n,int *x)
{
	int i=0,j=0,swap;
	for (j=0;j<n-1;j++)
	{
		for (i=0;i<n-1-j;i++)
			if (x[i]>x[i+1]) 
			{ swap=x[i];x[i]=x[i+1];x[i+1]=swap;}
	}
	return 0;
}

int QuickSort(int *x,int l,int r)
{
	int i=0,j=0,key;
	
	if (l >=r ) return 0;
	i=l;j=r;key=x[i];
	while (i<j)
	{
		while ((i<j)&&(key<=x[j]))
			j--;
		x[i]=x[j];
		while ((i<j)&&(key>=x[i]))
			i++;
		x[j]=x[i];
	}
	x[i]=key;
	QuickSort(x,l,i-1);
	QuickSort(x,i+1,r);
	return 0;
}
int Merge(int *x,int p,int q,int r);
int MergeSort(int *x,int le,int ri)
{
	int q;
	if (le<ri)
	{
		q=(le+ri)/2;
		MergeSort(x,le,q);
		MergeSort(x,q+1,ri);
		Merge(x,le,q+1,ri);
	}
}
int Merge(int *x,int p,int q,int rig)
{
	int i,j,n1,n2,l[N],r[N],k;
	n1=q-p;
	n2=rig-q+1;
	for (i=0;i<n1;i++)
		l[i]=x[p+i];
	for (i=0;i<n2;i++)
		r[i]=x[q+i];
	l[n1]=99999999;
	r[n2]=99999999;
	i=0;j=0;
	for (k=p;k<=rig;k++)
		if (l[i]<=r[j]) { x[k]=l[i];i++; }
		else { x[k]=r[j];j++; }
}

int RadixSort(int *x,int n)
{
	int dig[N];
	int di=1,k=0,flag=1,wid;//1 still have a number having k on digit i
	while (flag==1)
	{
		flag=0;
		wid=pow(10,di);
		for (k=0;k<n;k++)
		{
			dig[k]=(x[k]/(wid/10))%10;
			if (x[k]/wid!=0) flag=1;
		}	
		int i=0,j=0,c[N],y[N];
		for (i=0;i<=10;i++)
			c[i]=0;
		for (j=0;j<n;j++)
			c[dig[j]]++;
		for (i=1;i<=10;i++)	
			c[i]=c[i]+c[i-1];
		for (j=n-1;j>=0;j--)
		{
			y[c[dig[j]]-1]=x[j];
			c[dig[j]]=c[dig[j]]-1;
		}
		for (i=0;i<n;i++)
			x[i]=y[i];
		di++;
	}
	return 0;
}

int b[N][N]={0},next[N]={0};

int BucketSort(int *a,int min,int max,int n)
{
	int i,length=0,step=1,left=0,right=0;

	for (i=0;;i++)
		if ((10*i<=max)&&(max<=10*(i+1)))
		{
			right=i+1;
			break;
		}

	for (i=0;;i++)
		if ((10*i<=min)&&(min<=10*(i+1)))
		{
			left=i;
			break;
		}

	length=right-left+1;
	step=static_cast<int>((max-min)/length);

	int j;
	for (i=0;i<n;i++)
	{
		j=0;
		while (!((min+step*j<=a[i])&&(min+step*(j+1))))
		{
			j++;
		}
		b[j][next[j]]=a[i];
		next[j]++;
	}
	for (i=0;i<length;i++)
		InsertionSort(next[i],b[i]);
	int now=0;
	for (i=0;i<length;i++)
	{
		for (j=0;j<next[i];j++)
		{
			a[now]=b[i][j];
			now++;
		}
	}
	return 0;
}
