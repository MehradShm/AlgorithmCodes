#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int maxn=200050;
bool mark[maxn], pe[maxn];
map<pair<int,int>,int> m;
int d[maxn] , tn[maxn],tp[maxn] , p[maxn];
vector<int> v[maxn] , ans;

void DFS(int x)
{
	mark[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(mark[v[x][i]]==0)
		{
			int u=v[x][i];
			d[v[x][i]]=d[x]+1;
			pair<int,int>o;
			o.first=x;
			o.second=u;
			p[u]=x;
			tn[u]=((d[u]+1)/2)-tp[u];
			if(pe[m[o]])
				tp[u]=tp[x]+1;
			else
			{
				swap(o.first,o.second);
				if(pe[m[o]]==1)
					tp[u]=tp[x]+1;
			}
			DFS(u);
		}
}

void DFS1(int x,int k)
{
	mark[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p[x])
			tn[x]=max(tn[x],tn[v[x][i]]);
	if(tn[x]<=k)
		return;
	for(int i=0;i<v[x].size();i++)
		if(mark[v[x][i]]==0)
		{
			pair<int,int> o;
			o.first=x;
			o.second=v[x][i];
			if(pe[m[o]])
				DFS1(v[x][i],k);
			else
			{
				swap(o.first,o.second);
				if(pe[m[o]])
					DFS1(v[x][i],k);
				else
				{
					ans.push_back(m[o]);
					DFS1(v[x][i],k+1);
				}
			}
		}
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++)
	{
		pair<int,int> t;
		cin >> t.first >> t.second;
		t.first--;
		t.second--;
		v[t.first].push_back(t.second);
		v[t.second].push_back(t.first);
		string s;
		cin >> s;
		if(s=="almost")
		{
			string s1;
			cin >> s1;
		}
		else
			pe[i+1]=1;
		pair<pair<int,int>,int> a;
		a.first=t;
		a.second=i+1;
		m.insert(a);
	}
	DFS(0);
	fill(mark,mark+n,0);
	DFS1(0,0);
	cout << ans.size() << "\n";
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
	if(ans.size())
		cout << "\n";
}
