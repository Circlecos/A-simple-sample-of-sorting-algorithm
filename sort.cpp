#include "sort.h"
#ifndef N
#define N 1000
#endif
int InsertionSort(int n,int* x)
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

int ShellSort(int n,int* x)
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

int CountingSort(int n,int k,int* x)
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

int SelectionSort(int n,int* x)
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

int BubbleSort(int n,int* x)
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

int QuickSort(int *a,int l,int r)
{
	int i=0,j=0,key;
	
	if (l >=r ) return 0;
	i=l;j=r;key=a[i];
	while (i<j)
	{
		while ((i<j)&&(key<=a[j]))
			j--;
		a[i]=a[j];
		while ((i<j)&&(key>=a[i]))
			i++;
		a[j]=a[i];
	}
	a[i]=key;
	QuickSort(a,l,i-1);
	QuickSort(a,i+1,r);
	return 0;
}
int Merge(int *a,int p,int q,int r);
int MergeSort(int *a,int le,int ri)
{
	int q;
	if (le<ri)
	{
		q=(le+ri)/2;
		MergeSort(a,le,q);
		MergeSort(a,q+1,ri);
		Merge(a,le,q+1,ri);
	}
}
int Merge(int *a,int p,int q,int rig)
{
	int i,j,n1,n2,l[N],r[N],k;
	n1=q-p;
	n2=rig-q+1;
	for (i=0;i<n1;i++)
		l[i]=a[p+i];
	for (i=0;i<n2;i++)
		r[i]=a[q+i];
	l[n1]=99999999;
	r[n2]=99999999;
	i=0;j=0;
	for (k=p;k<=rig;k++)
		if (l[i]<=r[j]) { a[k]=l[i];i++; }
		else { a[k]=r[j];j++; }
}
