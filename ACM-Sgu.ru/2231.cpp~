#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long d[15][15][1100]; 
bool a[15] , b[15] , Problem[1100] , c[15];
bool match[1100][1100];
int to[1100];
int n , k;

void PIA(int x ,int y)
{
	int te=0;
	while(x>=2)
	{
		a[te]=x%2;
		x>>=1;
		te++;
	}
	a[te]=x;
	te=0;
	while(y>=2)
	{
		b[te]=y%2;
		y>>=1;
		te++;
	}
	b[te]=y;
}

bool Check(int x , int y)
{ 
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	PIA(x,y);
	for(int i=0;i<n;i++)
		if(b[i]==1)
		{
			if(a[i-1]==1 or a[i]==1 or a[i+1]==1)
				return 0;
		}
	return 1;
}

int t1(int x)
{
	int t=0;
	int u=x;
	while(x)
	{
		if((x%2)==1)
			t++;
		x>>=1;
	}
	return t;
}

void PA(int x)
{
	int te=0;
	while(x)
	{
		c[te]=x%2;
		x>>=1;
		te++;
	}
}
int Check2()
{
	for(int i=0;i<n;i++)
		if(c[i]==1)
			if(c[i+1]==1)
				return 1;
	return 0;
}

int main()
{
	cin >> n >> k;
	int f=1<<n;
	for(int i=0;i<f;i++)
	{
		int g=t1(i);
		to[i]=g;
		PA(i);
		Problem[i]=Check2();
		if(Problem[i]==0 and to[i]<=k)
			d[1][to[i]][i]=1;
	}	
	for(int i=0;i<f-1;i++)
		for(int j=i+1;j<f;j++)
			match[i][j]=Check(i,j);
	match[0][0]=1;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<f;j++)
			if(Problem[j]==0)
				for(int w=0;w<f;w++)
					if(Problem[w]==0)
						if(match[j][w] or match[w][j])
							if(to[w]<=k)
								for(int t=to[w];t<=k;t++)
									d[i+1][t+to[j]][j]+=d[i][t][w];
								
	}
	for(int i=0;i<f;i++)
		ans+=d[n][k][i];
	cout << ans << endl;
}
