#include <iostream>
using namespace std;

int c[15];

int n , m , k;

void PIA(int x)
{
	int t=0;
	while(x)
	{
		c[t]=x%2;
		x>>=1;
		t++;
	}
}

int Check(int x ,int y , int z)
{
	int t=0;
	for(int i=0;i<=n-m;i++)
	{
		t=0;
		for(int j=0;j<m;j++)
			if(c[i+j])
				t++;
		if(t<y)
			return 0;
	}
	return 1;
}

int main()
{
	int ans=0;
	cin >> n >> m >> k;
	int f=1;
	f<<=n;
	for(int i=0;i<f;i++)
	{
		PIA(i);
		cout << i << " : ";
		for(int j=n-1;j>=0;j--)
			cout << c[j];
		cout << endl;
		if(Check(m,k,i))
		{
			ans++;
			cerr << i << " !!! " << endl;
		}
	}
	cerr << ans << endl;
}
