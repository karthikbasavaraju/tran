
#include <stdio.h>

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int lcsubsequence(int *X,int n,int *Y,int m)
{
	int L[n+1][m+1];

	for (int i = 0; i <= m; ++i)
		L[0][i] = 0;

	for (int i = 0; i <= n; ++i)
		L[i][0] = 0;

	for (int r = 1; r <= n; ++r)
	{
		int trac,flag=0;
		for (int c = 1; c <= m; ++c)
		{
			if (X[r-1] == Y[c-1])
			{
				L[r][c] = 1 + L[r-1][c-1];
				trac = X[r-1];
				flag=1;
			}

			else
				L[r][c] = max(L[r-1][c], L[r][c-1]);
			if(flag == 1)
			{
				if(L[r][c]==L[r-1][c])flag=0;
			}
		}
		if(flag==1)printf("%d",trac);
	}
	printf("\n\t\t");
	for(int i = 0;i<m;i++)printf("%d\t",Y[i]);
	printf("\n");
	for(int i = 0; i<n+1;i++)
	{
		if(i!=0)printf("%d\t",X[i-1]);
		else printf("\t");
		for(int j = 0;j<m+1;j++)
		{
			printf("%d\t",L[i][j]);
		}
		printf("\n");
	}

	return L[n][m];
}


int lcsubstring(int X[],int n,int Y[],int m)
{
 	int ans = 0,index = 0;

	int L[n+1][m+1];

	for (int i = 0; i <= m; ++i)
		L[0][i] = 0;

	for (int i = 0; i <= n; ++i)
		L[i][0] = 0;

	for (int r = 1; r <= n; ++r)
	{
		for (int c = 1; c <= m; ++c)
		{
			if (X[r-1] == Y[c-1])
			{
				L[r][c] = 1 + L[r-1][c-1];
				
				ans = max(ans, L[r][c]);
				
				index = c-1;
				
			}
			else
			{
				L[r][c] = 0;
			}
		}
	}
	printf("\nindex=%d\n",index);
	for(int i =0;i<ans;i++)
		printf("%d",Y[index-ans+i+1] );
		
	printf("\n\t\t");
	for(int i = 0;i<m;i++)printf("%d\t",Y[i]);
	printf("\n");
	for(int i = 0; i<n+1;i++)
	{
		if(i!=0)printf("%d\t",X[i-1]);
		else printf("\t");
		for(int j = 0;j<m+1;j++)
		{
			printf("%d\t",L[i][j]);
		}
		printf("\n");
	}
	return ans;
}






int main()
{
	int a[8] ={1,2,3,1,3,9,2,4};
	int b[5] ={1,2,1,3,9};
	printf("\n%d\n",lcsubsequence(b,5,a,8));
	printf("\n%d\n",lcsubsequence(a,8,b,5));//lcsubstring
	
}
	
/*
	
*/
