#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int e[16005] , d[16005] , mark[16005] , p[16005] , ans[16005];
void DFS(int x , vector <int> c[])
{
	mark[x]=1;
	for(int i=0;i<c[x].size();i++)
		if(mark[c[x][i]]==0)
			DFS(c[x][i],c);
	if(x!=1 and c[x].size()!=1 or x==1)
	{
		for(int i=0;i<c[x].size();i++)
			d[x]+=e[c[x][i]];
		d[x]++;
	}
	int l=0;
	for(int i=0;i<c[x].size();i++)
	{
		int y=0;
		for(int j=0;j<c[x].size();j++)
			if(i!=j)
				y+=e[c[x][j]];
		y+=d[c[x][i]];
		if(y>l)
		{
			l=max(l,y);
			p[x]=c[x][i];
		}
		e[x]=l;
	}
}
void DFS1(int x , int y , int &tedad , vector <int> c[])
{
	mark[x]=0;
	if(y)
	{
		ans[tedad]=x;
		tedad++;
		for(int i=0;i<c[x].size();i++)
			if(mark[c[x][i]])
				DFS1(c[x][i],0,tedad,c);
	}
	else
	{
		for(int i=0;i<c[x].size();i++)
			if(mark[c[x][i]])
				if(c[x][i]!=p[x])
					DFS1(c[x][i],0,tedad,c);
		if(c[x].size()>1)
			DFS1(p[x],1,tedad,c);
	}
}
int main()
{
	int n;
	cin >> n;
	vector <int> c[16005];
	for(int i=2;i<=n;i++)
	{
		int m;
		cin >> m;
		c[m].push_back(i);
		c[i].push_back(m);
	}
	for(int i=2;i<=n;i++)
		if(c[i].size()==1)
			d[i]=1;
	int f=0;
	DFS(1,c);
	DFS1(1,0,f,c);
	sort(ans,ans+f);
	cout << e[1]*1000 << endl;
	for(int i=0;i<f;i++)
		if(ans[i]!=1)
			cout << ans[i] << " ";
}
