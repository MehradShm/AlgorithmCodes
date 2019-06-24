#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn=200050;
bool mark[maxn];
vector<int> v[maxn], ind[maxn] , ans;
vector<bool> pe[maxn];
int h[maxn] , tp[maxn] , tl[maxn] , p[maxn];

void DFS(int x)
{
	mark[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(mark[v[x][i]]==0)
		{
			int tmp=v[x][i];
			h[tmp]=h[x]+1;
			p[tmp]=x;
			if(pe[x][i])
				tp[tmp]=tp[x]+1;
			else
				tp[tmp]=tp[x];
			tl[tmp]=((h[tmp]+1)/2)-tp[tmp];
			DFS(tmp);
		}
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p[x])
			tl[x]=max(tl[x],tl[v[x][i]]);

}

void DFST(int x ,int k)
{
	if(k==tl[x])
		return ;
	mark[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(mark[v[x][i]]==0)
			if(tl[v[x][i]]>k)
			{
				if(pe[x][i])
					DFST(v[x][i],k);
				else
				{
					ans.push_back(ind[x][i]);
					DFST(v[x][i],k+1);
				}
			}
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >>n;
	for(int i=0;i<n-1;i++)
	{
		int temp1 , temp2;
		cin >> temp1 >> temp2;
		temp1--;
		temp2--;
		string s;
		cin >> s;
		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
		ind[temp1].push_back(i+1);
		ind[temp2].push_back(i+1);
		if(s=="almost")
		{
			string s1;
			cin >> s1;
			pe[temp1].push_back(0);
			pe[temp2].push_back(0);
		}
		else
		{
			pe[temp1].push_back(1);
			pe[temp2].push_back(1);
		}
	}
	DFS(0);
	fill(mark,mark+n,0);
	DFST(0,0);
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
	cout << endl;
}
