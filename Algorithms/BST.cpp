#include <iostream>
using namespace std;

int a[5][5];
int root=-1;

void insert(int n , int s)
{
	if(root==-1)
	{
		root=0;
		a[0][0]=n;
	}
	else
	{
		int x=root , p=0;
		while(x!=-1)
		{
			p=x;
			if(a[x][0]>n)
				x=a[x][2];
			else
				x=a[x][3];
		}
		if(n>a[p][0])
		{
			a[s][0]=n;
			a[s][1]=p;
			a[p][3]=s;
		}
	}
}
int main()
{
	for(int i=0;i<100;i++)
		for(int j=0;j<4;j++)
			a[i][j]=-1;
	while(1)
	{
		int x , s=0;
		cin >> x;
		if(x==-5)
			break;
		else
		{
			insert(x,s);
			s++;
		}
	}
	return 0;
}
