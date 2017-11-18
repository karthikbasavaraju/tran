
#include <stdio.h>

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int z,y;

void display(int *x,int l[z][y],int n,int m)
{
	if(n==0 || m==0)
	{
		
		return;
	}
	else if((l[n-1][m-1] == l[n][m-1]) && (l[n-1][m-1] == l[n-1][m]))
	{
		display(x,l,n-1,m-1);	
		printf("%d",x[n-1]);
	}
	else if(l[n][m-1]>l[n-1][m])
		display(x,l,n,m-1);
	else
		display(x,l,n-1,m);
}

void print_tabulation(int L[z][y],int n, int m, int X[],int Y[])
{
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

}

int lcsubsequence(int *X,int n,int *Y,int m)
{
	int L[n+1][m+1];
	z = n+1;
	y = m+1;

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
			}

			else
				L[r][c] = max(L[r-1][c], L[r][c-1]);
		}

	}
	
	display(X,L,n+1,m+1);
	
	//print_tabulation(L,n,m,X,Y);

	return L[n][m];
}


int lcsubstring(int X[],int n,int Y[],int m)
{
 	int ans = 0,index = -1;

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
				if(ans==L[r][c]) index =c-1;	
			}
			else
			{
				L[r][c] = 0;
			}
		}
	}
	
	//printf("\nindex=%d\n",index);
	for(int i =index-ans+1;i<index+1;i++)
		printf("%d",Y[i] );
	
	//print_tabulation(L,n,m,X,Y);	

	return ans;
}


int main()
{
	int a[8] ={1,2,3,1,3,9,2,4};
	int b[5] ={1,2,1,3,9};
	printf("\n%d\n",lcsubstring(b,5,a,8));
	printf("\n%d\n",lcsubsequence(a,8,b,5));//lcsubstring lcsubsequence
	
}
	
/*
	
*/
