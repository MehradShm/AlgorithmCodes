#include <iostream>
#include <vector>
using namespace std;
int a[16005] , d[16005] , mark[16005];
void DFS(int x,vector <int> c[])
{
	mark[x]=1;
	for(int i=0;i<c[x].size();i++)
	{
		if(mark[c[x][i]]==0)
		{
			DFS(c[x][i],c);
			d[x]+=max(d[c[x][i]],0);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> c[n+2];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		d[i]=a[i];
	}
	for(int i=1;i<n;i++)
	{
		int temp1 , temp2;
		cin >> temp1 >> temp2;
		c[temp1].push_back(temp2);
		c[temp2].push_back(temp1);
	}
	DFS(1,c);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,d[i]);
	cout << ans << endl;
}
