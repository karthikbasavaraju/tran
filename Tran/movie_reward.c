#include <stdio.h>
#include <limits.h>

typedef struct movie
{
	int s;
	int f;
	int r;
}movie;




void print(struct movie m[],int n)
{
	for(int i = 0; i<n ;i++)
	{
		printf("movie %d:%d to %d (%d)\n",i,m[i].s,m[i].f,m[i].r);
	}
}



int movie_selection(struct movie m[],int n)   
{
	for(int i=0;i<n;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(m[j].f<m[j-1].f )
			{
				struct movie temp;
				temp = m[j];
				m[j]=m[j-1];
				m[j-1]=temp;
			}
			else if(m[j].f==m[j-1].f && m[j].r < m[j-1].r)
			{
				struct movie temp;
				temp = m[j];
				m[j]=m[j-1];
				m[j-1]=temp;
			}
		}	
	}
	

	int reward[n];

	for(int i = 0 ; i<n;i++)
		reward[i]=0;

	for(int i = 0 ;i<n;i++)
	{
		int final_start = m[i].s,max= INT_MIN, index = i;
		for (int j = i-1; j>=0; --j)
		{
			if (m[j].f <= final_start)
			{
				if(reward[j]>max)
				{
					max=reward[j];
					index = j;
				}
			}
		}
		reward[i] = reward[index] + m[i].r;
	}
	int fmax = INT_MIN,index=-1;
	
	for(int i=0;i<n;i++)
	{
		if(fmax<reward[i])
		{
			fmax = reward[i];
			index = i;
		}
	}
	printf("Maximum Reward = %d\n",fmax);
	printf("Movie %dam to %dam with reward = %d\n",m[index].s,m[index].f,m[index].r);
	int last_start = m[index].s,r_index = index;
	for (int j = index-1; j>=0; --j)
	{
		if (m[j].f <= last_start && reward[j] == (reward[r_index]-m[r_index].r))
		{
			last_start = m[j].s;
			r_index = j;
			printf("Movie %dam to %dam with reward = %d\n",m[j].s,m[j].f,m[j].r);
		}
	}
}


int main()
{
	struct movie m[7];
	m[0].s = 1;
	m[0].f = 5;
	m[0].r = 100;
	
	m[1].s = 6;
	m[1].f = 12;
	m[1].r = 30;
	
	m[2].s = 14;
	m[2].f = 18;
	m[2].r = 10;
	
	m[3].s = 3;
	m[3].f = 8;
	m[3].r = 20;

	m[4].s = 10;
	m[4].f = 16;
	m[4].r = 200;
	
	m[5].s = 7;
	m[5].f = 20;
	m[5].r = 50;
	
	m[6].s = 6;
	m[6].f = 12;
	m[6].r = 50;
	
	movie_selection(m,7);	
	
		
}
