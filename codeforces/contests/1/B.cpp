#include <iostream>
#include <vector>
const int maxm=1010;
using namespace std;
int c[maxm][maxm];
long long a[maxm] , s[maxm];

int main()
{
	int n , k , m , ans=0;
	cin >> n >> m >> k;
	for(int i=0;i<=m;i++)
		cin >> a[i];
	for(int i=0;i<=m;i++)
	{
		int x=0;
		while(a[i]>0)
		{
			if(a[i]%2)
			{
				c[i][x]=1;
				a[i]=(a[i]-1)/2;
				x++;
			}
			else
			{
				c[i][x]=0;
				a[i]/=2;
				x++;
			}
		}
		s[i]=x;
	}
	for(int i=0;i<m;i++)
	{
		int size=max(s[i],s[m]) , d=0;
		for(int j=size;j>=0;j--)
			if(c[i][j]!=c[m][j])
				d++;
		if(d<=k)
			ans++;
	}
	cout << ans << endl;
}

