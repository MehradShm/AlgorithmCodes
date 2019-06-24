#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=1005;
int a[MAXN] , b[MAXN] , d[MAXN][MAXN];
int main()
{
	int n , m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=m;i++)
		cin >> b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int x=max(d[i][j-1],d[i-1][j]);
			d[i][j]=max(x,(d[i-1][j-1]+(a[i]*b[j])));
		}
	cout << d[n][m] << endl;
}

