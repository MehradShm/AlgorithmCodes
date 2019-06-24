#include <iostream>
using namespace std;

int a[15];

int main()
{
	a[0]=2;
	a[1]=7;
	a[2]=2;
	a[3]=3;
	a[4]=3;
	a[5]=4;
	a[6]=2;
	a[7]=5;
	a[8]=1;
	a[9]=2;
	int n;
	cin >> n;
	int ans=1;
	ans*=(a[n%10]);
	ans*=a[n/10];
	cout << ans << endl;
}
