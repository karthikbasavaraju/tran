#include<stdio.h>

typedef struct max1
{
	int sum;
	int max;
	int ending_index;
}max1;
struct max1 m1;

int max(int a,int b)
{
	if(a>b)
		return a;
	else return b;
}

struct max1 td_subarray(int a[],int n)
{
	if(n==0)
	{
		struct max1 mm = {.sum=a[n],.max=a[n],.ending_index=n};
		return mm;
		
	}	
	struct max1 m2 = td_subarray(a,n-1);
	printf("%d,%d\n",m2.sum,m2.max);
	
	
	m2.sum = max(a[n],a[n]+m2.sum);

	m2.max = max(m2.sum,m2.max);
	if(m2.max==m2.sum)
		m2.ending_index=n;
	
	return m2;	
}

int main()
{
	int a[]= {12,-4,4,0,6,-7,1,12,-3,0};
	
	
	printf("%d\n",td_subarray(a,9).ending_index);
}
