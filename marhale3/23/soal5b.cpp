#include <iostream>
using namespace std;
long long a[1002][1002] , b[1002];
int main()
{
	b[0]=1;
	long long delta , ans=0;
	cin >> delta;
	for(int i=0;i<=1000;i++)
		a[0][i]=1;
	for(int i=1;i<=1000;i++)
		for(int j=i;j<=1000;j++)
			if(i==j)
				a[i][j]=1;
			else
				a[i][j]=(a[i][j-1]+a[i-1][j-1])%delta;
	for(int i=1;i<=1000;i++)
		b[i]=(2*b[i-1])%delta;
	for(int i=200;i<=800;i++)
		for(int j=200;j<=i;j++)
		{
			ans+=((a[i][1000]*(a[j][i]*b[i-j]))%delta);
			ans%=delta;
		}
	cout << ans << endl;
}
