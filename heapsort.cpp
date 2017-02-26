#include "heapsort.h"

#define PARENT(i) (i/2)
#define LEFT(i) (2*i)
#define RIGHT(i) (2*i+1)

extern int HeapSize;
extern int HeapLength;

int ChangeArray(int *a,int *to,int n)
{
    int i;
    for (i=0;i<n;i++)
        to[i+1]=a[i];
    return 0;
}


int RecoverArray(int *a,int *to,int n)
{
    int i;
    for (i=1;i<=n;i++)
        to[i-1]=a[i];
    return 0;
}

int MaxHeapify(int *a,int i)
{
    int l,r,max=i,temp;
    l=LEFT(i);
    r=RIGHT(i);
    if ((l<=HeapSize)&&(a[l]>a[i]))
        max=l;
    else max=i;
    if ((r<=HeapSize)&&(a[r]>a[max]))
        max=r;
    if (max!=i)
    {
        temp=a[max];
        a[max]=a[i];
        a[i]=temp;
        MaxHeapify(a,max);
    }
    return 0;
}

int BuildMaxHeap(int *a)
{
    HeapSize=HeapLength;
    int i;
    for (i=HeapLength/2;i>0;i--)
        MaxHeapify(a,i);
    return 0;
}

#undef PARENT
#undef LEFT
#undef RIGHT
