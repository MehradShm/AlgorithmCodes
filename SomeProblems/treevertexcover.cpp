#include <iostream>
#include <vector>
using namespace std;
const int maxn=(100*1000)+10;
int c[maxn],u[maxn],mark[maxn],p[maxn];
vector <int> v[maxn];
void DFS(int x)
{
	mark[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(!mark[v[x][i]])
		{
			p[v[x][i]]=x;
			DFS(v[x][i]);
		}
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p[x])
			u[x]+=c[v[x][i]];
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p[x])
			c[x]+=min(u[v[x][i]],c[v[x][i]]);
	c[x]++;
}
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++)
	{
		int temp, temp2;
		cin >> temp >> temp2;
		temp--;
		temp2--;
		v[temp].push_back(temp2);
		v[temp2].push_back(temp);
	}
	for(int i=0;i<n;i++)
		if(v[i].size()==1)
			c[i]=1;
	DFS(0);
	int ans=min(c[0],u[0]);
	cout << ans << endl;
}
