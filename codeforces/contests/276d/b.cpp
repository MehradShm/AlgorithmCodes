#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=105;
pair<int ,bool> b[maxn],g[maxn];

int main()
{
	int n , ans=0;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> b[i].first;
	int m;
	cin >> m;
	for(int i=0;i<m;i++)
		cin >> g[i].first;
	sort(b,b+n);
	sort(g,g+m);
	if(n<=m)
		for(int i=0;i<n and b[i].second==0;i++)
		{
			int flag=1;
			for(int j=0;j<m and flag;j++)
				if(g[j].second!=1 and b[i].second!=1 and (b[i].first==g[j].first-1 or b[i].first==g[j].first or b[i].first==g[j].first+1))
				{
					flag=0;
					ans++;
					g[j].second=1;
					b[i].second=1;
				}
				else if(g[j].first>b[i].first)
					flag=1;
		}
	else
		for(int i=0;i<m and g[i].second==0;i++)
		{
			int flag=1;
			for(int j=0;j<n and flag;j++)
				if(g[i].second!=1 and b[j].second!=1 and (g[i].first==b[j].first+1 or g[i].first==b[j].first or g[i].first==b[j].first-1))
				{
					flag=0;
					ans++;
					g[i].second=1;
					b[j].second=1;
				}
				else if(g[i].first < b[j].first)
					flag=1;
		}
	cout << ans << endl;
}
