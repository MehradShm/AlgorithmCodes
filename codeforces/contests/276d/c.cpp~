#include <iostream>
using namespace std;

const int maxs=105;
int a[maxs] , b[maxs];

void maxm(int n , int s)
{
	for(int i=n-1;i>=0;i--)
		if(s>9)
		{
			a[i]=9;
			s-=9;
		}
		else
		{
			a[i]=s;
			s=0;
		}
}

void minm(int n , int s)
{
	int an=0;
	if((n-1)*9>=s)
	{
		s--;
		b[n-1]=1;
	}
	else
	{
		b[n-1]=(s-((n-1)*9));
		s-=b[n-1];
	}
	for(int i=0;i<=n-2 and s;i++)
		if(s>9)
		{
			b[i]=9;
			s-=9;
		}
		else
		{
			b[i]=s;
			s=0;
		}
}

int main()
{
	int n , m;
	cin >> n >> m;
	if(n==1 and m==0)
		cout << "0" << " " << "0" << endl;
	else if(n*9<m or m==0)
		cout << "-1" << " " << "-1" << endl;
	else
	{
		int g;
		maxm(n,m);
		minm(n,m);
		for(int i=n-1;i>=0;i--)
			cout << b[i];
		cout << " ";
		for(int i=n-1;i>=0;i--)
			cout << a[i];
		cout << endl;
	}
}
