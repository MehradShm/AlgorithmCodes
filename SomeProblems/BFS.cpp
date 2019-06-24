#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue <int> s;
const int maxn=100*100+10;
vector <int> c[maxn];
int p[maxn] , mark[maxn] , dis[maxn];
void ST(int start, int po)
{
	if(po==start)
		cout << po+1 << " ";
	else
	{
		ST(start,p[po]);
		cout << po+1 << " ";
	}
}
void BFS (int start)
{
	s.push(start);
	mark[start]=1;
	while(!s.empty())
	{
		int k=s.front();
		s.pop();
		for(int i=0;i<c[k].size();i++)
		{
			int l=c[k][i];
			if(!mark[l])
			{
				p[c[k][i]]=k;
				dis[l]=dis[k]+1;
				s.push(l);
				mark[l]=1;
			}
		}
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int a1,a2;
		cin >> a1 >> a2;
		a1--;
		a2--;
		c[a1].push_back(a2);
		c[a2].push_back(a1);
	}
	int x,y;
	cin >> x >>y;
	x--;
	y--;
	BFS(x);
	if(mark[y]==1)
	{
		cout << dis[y] << endl;
		ST(x,y);
	}
	else
		cout << -1 << endl;
}
