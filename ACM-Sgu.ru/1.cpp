#include <iostream>
#include <vector>
using namespace std;
const int maxn=101*100;
pair <int,int> a[maxn];
vector< int > c[maxn];
int v[maxn][maxn];
int mark[maxn] , p[maxn] , k[maxn];
void DFS(int x)
{
	mark[x]=1;
	for(int i=0;i<c[x].size();i++)
	{
		if(mark[c[x][i]]==0)
		{
			p[c[x][i]]=x;
			DFS(c[x][i]);
			if(a[c[x][i]].first+v[x][c[x][i]]>a[x].first)
			{
				k[x]=c[x][i];
				a[x].first=max(a[x].first,a[c[x][i]].first+v[x][c[x][i]]);
			}
		}
	}

}	
void DFS1(int x)
{
	mark[x]=0;
	a[1].second=a[1].first;
	if(x!=k[p[x]])
	{
		a[x].second=max(a[p[x]].second+v[x][p[x]],a[k[p[x]]].first+v[x][p[x]]+v[x][k[p[x]]]);
		for(int i=0;i<c[x].size();i++)
			if(mark[c[x][i]]==1)
				DFS1(c[x][i]);
	}
	else
	{
		int z=0 , l=0;
		for(int i=0;i<c[p[x]].size();i++)
		{
			if(c[p[x]][i]!=x and (a[c[p[x]][i]].first+v[x][p[x]]+v[x][c[p[x]][i]])>l)
			{
				l=i;
				if(x==3)
					cerr << v[x][p[x]] << " @@ " << v[p[x]][c[p[x]][i]] << " @@ " << c[p[x]][i] << " @@ " << a[c[p[x]][i]].first << endl;
				z=a[c[p[x]][i]].first+v[x][p[x]]+v[p[x]][c[p[x]][i]];
			}
		}
		if(p[x]!=1)
			a[x].second=max(a[p[x]].second+v[x][p[x]],z);
		else
			a[x].second=z;
		for(int i=0;i<c[x].size();i++)
			if(mark[c[x][i]]==1)
				DFS1(c[x][i]);
	}
}
int main()
{
	int n, m=0;
	cin >> n;
	for(int i=2;i<=n;i++)
	{
		int temp1=i , temp2 , temp3;
		cin >> temp2 >> temp3;
		c[temp2].push_back(temp1);
		v[temp2][temp1]=temp3;
		c[temp1].push_back(temp2);
		v[temp1][temp2]=temp3;
	}
	DFS(1);
	a[1].second=a[1].first;
	DFS1(1);
	for(int i=1;i<=n;i++)
	{
	//	cout << i << " :: " << a[i].first << " :: " << a[i].second << endl;
		cout << max(a[i].first,a[i].second) << endl;
	}
}
