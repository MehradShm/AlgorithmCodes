#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=1050 , maxm=20050;
bool d[maxn][maxn] , mark[maxn];
vector<int> v[maxn] , ans[maxm];
pair<int,int> e[maxm];
int n , m;

int Check(int x)
{
	int t=2;
	for(int i=0;i<n;i++)
		if(i!=e[x].first and i!=e[x].second)
			if((d[e[x].first][i]==1 or d[e[x].second][i]==1) and (d[i][e[x].first]==1 or d[i][e[x].second]==1))
				t++;
	return t;
}

void DFS(int x , int p)
{
	d[p][x]=1;
	mark[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(mark[v[x][i]]==0)
			DFS(v[x][i],p);
}

int main()
{
	int mx=0;
	cin >> n >> m;
	if(m==0 or n==1)
	{
		cout << "1" << "\n";
		cout << "0" << "\n";
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		int t1 , t2;
		cin >> t1 >> t2;
		t1--;
		t2--;
		e[i].first=t1;
		e[i].second=t2;
		v[t1].push_back(t2);
	}
	for(int i=0;i<n;i++)
	{
		DFS(i,i);
		memset(mark,0,sizeof(mark));
	}
	for(int i=0;i<m;i++)
	{
		int te=Check(i);
		if(te>=mx)
		{
			mx=te;
			ans[te].push_back(i);
		}
	}
	cout << mx << "\n";
	cout << ans[mx].size() << "\n";
	for(int i=0;i<ans[mx].size();i++)
		cout << ans[mx][i]+1 << " ";
	cout << "\n";
}
