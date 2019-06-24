#include <iostream>
#include <vector>

using namespace std;

const int maxn=100050;
const int maxm=1000050;
int tedad=0;

pair<int,int> e;
int nu[maxn];
vector<int> v[maxn] , rb;
vector<pair<int,int> >yb;
bool mark[maxn];

int DFS(int x)
{
	int k=999999;
	mark[x]=1;
	nu[x]=nu[p[x]]+1;
	for(int i=0;i<v[x].size();i++)
		if(mark[v[x][i]]==0)
		{
			p[v[x][i]]=x;
			k=min(k,DFS(v[x][i]));
		}
	for(int i=0;i)
			
}

int main()
{
	int n , m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		cin >> e[i].first >> e[i].second;
		v[e[i].first].push_back(e[i].second);
		v[e[i].second].push_back(e[i].first);
	}
	nu[0]=0;
	p[0]=0;
	int u=DFS(0);
}
