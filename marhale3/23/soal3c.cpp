#include <iostream>
using namespace std;
long long a[5010][5010] , b[12502500] , d[5010][5010];
int main()
{
	long long delta , x=1;
	cin >> delta;
	b[1]=delta%10;
	a[4999][0]=delta%10;
	d[4999][0]=delta%10;
	cerr << b[1] << " :: " << a[6][0] << " :: " << d[6][0] << endl;
	for(int i=4999;i>=0;i--)
		for(int j=0;j<=i;j++)
		{
			if(x!=1)
			{
				b[x]=((b[x/2]+b[x-1])+1)%100;
				a[i][j]=b[x];
				d[i][j]=b[x];
			}
			x++;
		}
	for(int i=0;i<=6;i++)
	{
		for(int j=0;j<=i;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	for(int i=4998;i>=0;i--)
		for(int j=0;j<=4998;j++)
			d[i][j]+=max(d[i+1][j]+a[i+1][j+1],d[i+1][j+1]+a[i+1][j]);
	for(int i=0;i<=6;i++)
	{
		for(int j=0;j<=i;j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
	long long ans=d[0][0];
	ans%=delta;
	cout << ans << endl;
}
