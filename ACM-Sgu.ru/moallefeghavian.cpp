#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn=10050;
vector<int> v[maxn] , v2[maxn] , ans[maxn];
bool mark[maxn] , mark2[maxn];
vector <int> topol;
int tedad;

void DFS(int x)
{
	mark[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(mark[v[x][i]]==0)
			DFS(v[x][i]);
	topol.push_back(x);
}

void DFS2(int x)
{
	mark2[x]=1;
	for(int i=0;i<v2[x].size();i++)
		if(mark2[v2[x][i]]==0)
			DFS2(v2[x][i]);
	ans[tedad].push_back(x);
}

int main()
{
	int n , e;
	cin >> n >> e;
	for(int i=0;i<e;i++)
	{
		int t1 , t2;
		cin >> t1 >> t2;
		t1--;
		t2--;
		v[t1].push_back(t2);
		v2[t2].push_back(t1);
	}
	for(int i=0;i<n;i++)
		if(mark[i]==0)
			DFS(i);
	while(topol.size())
	{
		if(mark2[topol.back()]==0)
		{
			DFS2(topol.back());
			tedad++;
		}
		topol.pop_back();
	}
	for(int i=0;i<tedad;i++)
	{
		sort(ans[i].begin(),ans[i].end());
		for(int j=0;j<ans[i].size();j++)
			cout << ans[i][j]+1 << " ";
		cout << endl;
	}
}
