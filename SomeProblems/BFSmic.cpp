#include <iostream>
#include <queue>
using namespace  std;
bool a[1002][1002] , mark[1002][1002];
int b[1002][1002] , h[5][3]={{1,0},{0,-1},{0,1},{-1,0}};
queue <pair <int,int> > c;
int n , m;
int Check(pair <int,int> x)
{
	if(x.first<n and x.first>=0 and x.second>=0 and x.second<m)
		return 1;
	else
		return 0;
}
void VE( pair<int,int> x)
{
	for(int i=0;i<4;i++)
	{
		pair<int,int> k=x;
		k.first+=h[i][0];
		k.second+=h[i][1];
		if(Check(k))
		{
			b[k.first][k.second]++;
			if(mark[k.first][k.second]==0)
				if(b[k.first][k.second]>=2)
				{
					mark[k.first][k.second]=1;
					a[k.first][k.second]=1;
					c.push(k);
				}
		}
	}
}
void BFS()
{
	while(!c.empty())
	{
		pair <int,int> k=c.front();
		c.pop();
		VE(k);
	}
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin >> a[i][j];
			if(a[i][j]==1)
			{
				pair <int , int > l;
				l.first=i;
				l.second=j;
				mark[l.first][l.second]=1;
				c.push(l);
			}
		}
	BFS();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
