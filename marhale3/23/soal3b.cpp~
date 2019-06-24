#include <iostream>
using namespace std;
long long a[5002][5002] , d[5002][5002];
int main()
{
	long long delta;
	cin >> delta;
	for(int i=0;i<=4999;i++)
		for(int j=0;j<=i;j++)
		{
			if(i==0)
			{
				a[i][j]=1;
				d[i][j]=1;
			}
			else if(j==0 or j==i)
			{
				a[i][j]=1;
				d[i][j]=1;
			}
			else
			{
				a[i][j]=(a[i-1][j]+a[i-1][j-1])%delta;
				d[i][j]=a[i][j]%delta;
			}

		}
	for(int i=4999;i>=0;i--)
		for(int j=0;j<=i;j++)
		{
			d[i][j]+=max(d[i+1][j]+a[i+1][j+1],d[i+1][j+1]+a[i+1][j]);
			d[i][j]%=delta;
		}
	long long ans=d[0][0];
	cout << ans << endl;
}
