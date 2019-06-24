#include <iostream>
#include <vector>

using namespace std;

const int maxn=3050;
int d[maxn][maxn];
vector<int> c[maxn];

int Check(int x)
{
	int tedad=0;
	for(int i=0;i<c[x].size();i++)
		for(int j=0;j<c[c[x][i]].size();j++)
			if(c[c[x][i]][j]!=x)
			{
				tedad+=d[x][c[c[x][i]][j]];
				d[x][c[c[x][i]][j]]++;
			}
	return tedad;
}

int main()
{
	long long ans=0;
	int n , m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int t1 , t2;
		cin >> t1 >> t2;
		c[t1].push_back(t2);
	}
	for(int i=1;i<=n;i++)
		ans+=Check(i);
	cout << ans << endl;
}
