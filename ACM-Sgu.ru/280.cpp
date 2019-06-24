#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn=30*1000+10;
vector <int> c[maxn] , ans;
int mark[maxn] , d[maxn] , p[maxn];
int n , k , root=1;

void fix(int x)
{
	if(x!=root and c[x].size()==1)
		d[x]=0;
	else
	{
		int mz=0 , mb=-1 , flagb=0 , flagz=0;
		for(int i=0;i<c[x].size();i++)
			if(c[x][i]!=p[x])
			{
				if(d[c[x][i]]>=0)
				{
					flagb=1;
					mb=max(mb,d[c[x][i]]);
				}
				else
				{
					flagz=1;
					mz=min(mz,d[c[x][i]]);
				}
			}
		if(flagb==0 and flagz==1)
			d[x]=mz+1;
		else if(flagb==1 and flagz==0)
			d[x]=mb+1;
		else if(flagb and flagz)
		{
			if(((mz*-1)-1)>=mb+2)
				d[x]=mz+1;
			else
				d[x]=mb+1;
		}
		if(d[x]==k)
		{
			ans.push_back(x);
			d[x]=((k*-1)-1);
		}
	}
}

void DFS(int x)
{
	mark[x]=1;
	for(int i=0;i<c[x].size();i++)
	{
		if(mark[c[x][i]]==0)
		{
			p[c[x][i]]=x;
			DFS(c[x][i]);
		}
	}
	fix(x);
}
int main()
{
	cin >> n >> k;
	for(int i=0;i<n-1;i++)
	{
		int t1 , t2;
		cin >> t1 >> t2;
		c[t2].push_back(t1);
		c[t1].push_back(t2);
	}
	DFS(1);
	if(d[1]>=0)
		ans.push_back(1);
	sort(ans.begin(),ans.end());
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
	cout << endl;
}
