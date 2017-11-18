#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void disp(int a[],int n,int count[],int max)
{
	if(n==-1)
		return;
	if(count[n]==max)
	{
		disp(a,n-1,count,max-1);
		printf("%d ",a[n]);
	}
	else
	disp(a,n-1,count,max);
}
int dp_nondec( int a[], int n )
{
    int count[n];
 	
    for (int i = 0; i < n; i++ )
        count[i] = 0;
    
    int max_count=-1;
    
    for (int i = 0; i < n; i++ )
    {
    	int max= INT_MIN;
    	if(i==0)
    		max=i;
	else
	{
		for (int j = i; j>0; j-- ) 
        	{
            		if (a[i]>=a[j-1] && a[max]<a[j-1])
            		{
            	      		max=j-1;
               		}
    		}
    	}	
    	
    	count[i] = count[max]+1;
    	
    	if(max_count<count[i])
    		max_count=count[i];
 
    }
    printf("Longest non dec subsequence count = %d\n",max_count);
    disp(a,n,count,max_count);

}

int main()
{
    int a[10] ={14,17,11,24,90,100,40,60,30,80};
    dp_nondec(a,10);
}
