#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=3000;
int s[maxn][maxn];
int n;

void m1()
{
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int j=1;flag;j++)
		{
			int k1=i+j,k2=i-j;
			if(i+j>=n+1)
				k1%=n;
			else if(i-j<=0)
				k2=n-(j-i);
			s[k1][k2]=i;
			s[k2][k1]=i;
			if(k1-k2==1 or k2-k1==1)
				flag=0;
		}
	}
}

void m2()
{
	for(int i=1;i<=n-1;i++)
	{
		int flag=1;
		s[n][i]=i;
		s[i][n]=i;
		if(n>2)
			for(int j=1;flag;j++)
			{
				int k1=i+j,k2=i-j;
				if(i+j>=n)
					k1%=(n-1);
				else if(i-j<=0)
					k2=n-1-(j-i);
				s[k1][k2]=i;
				s[k2][k1]=i;
				if(k1-k2==1 or k2-k1==1)
				flag=0;
			}
	}
}

int main()
{
	cin >> n;
	if(n==1)
	{
		cout << "0" << endl;
		cout << "0" << endl;
	}
	else
	{
		if(n%2)
		{
			cout << n << endl;
			m1();
		}
		else
		{
			cout << n-1 << endl;
			m2();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%d ",s[i][j]);
			cout << endl;
		}
	}
}
