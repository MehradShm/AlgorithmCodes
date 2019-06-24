#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

queue <int> q;
int mark[100] , d[100];
vector<int> c[100] , ans;

void BFS(int x)
{
	d[x]=0;
	mark[x]=1;
	q.push(x);
	while(q.size())
	{
		int k=q.front();
		q.pop();
		for(int i=0;i<c[k].size();i++)
			if(mark[c[k][i]]==0)
			{
				q.push(c[k][i]);
				mark[c[k][i]]=1;
				d[c[k][i]]=d[k]+1;
			}
	}
}

int main()
{
	int n , x;
	cin >> n >> x;
	x--;
	for(int i=0;i<n;i++)
	{
		int t;
		cin >> t;
		for(int j=0;j<t;j++)
		{
			int k;
			cin >> k;
			k--;
			c[i].push_back(k);
		}
	}
	BFS(x);
	for(int i=0;i<n;i++)
		if(d[i]==2)
			ans.push_back(i);
	sort(ans.begin(),ans.end());
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i]+1 << " ";
	cout << endl;
}
