#include <iostream>
using namespace std;

const int maxn=1005;
pair<int,int> a[maxn];
int d[maxn][maxn] , u[maxn][maxn];

void PB(int i , int j)
{
	if(i==j)
	{
		cout << "A" << i;
		return;
	}
	cout << "(";
	PB(i,u[i][j]);
	cout << "*";
	PB(u[i][j]+1,j);
	cout << ")";
}

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]=9999999;
	for(int i=1;i<=n;i++)
		cin >> a[i].first >> a[i].second;
	for(int i=1;i<=n;i++)
		d[i][i]=0;
	for(int i=n-1;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			for(int k=i;k<j;k++)
				if(d[i][j]>d[i][k]+d[k+1][j]+(a[i].first*a[k].second*a[j].second))
				{
					d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]+(a[i].first*a[k].second*a[j].second));
					u[i][j]=k;
				}
	cout << d[1][n] << endl;
	PB(1,n);
	cout << endl;
}	
