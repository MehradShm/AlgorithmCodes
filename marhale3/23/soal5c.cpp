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
	for(int i=0;i<=700;i++)
	{
		for(int j=0;j<=1000;j++) if ( i+j>=310 )
			for(int k=0;k<=1000-j-i;k++)
				if(j+k>=300 and k+i>=320)
				{
					ans+=(((((a[k][1000]*a[j][1000-k])%delta)*a[i][1000-k-j])%delta)*b[1000-i-j-k])%delta;
					ans%=delta;
				}
	//	cout << i << " %% " << ans << endl;
	}
	cout << ans << endl;
}
