#include <iostream>
using namespace  std;
int a[100];
int Mabna(long long x)
{
	int len=0;
	while(x)
	{
		a[len]=(x%2);
		x/=2;
		len++;
	}
	return len;
}
long long BProcess(long long x)
{
	int lena=Mabna(x) , m=0;
	for(int i=lena-1;i>=0;i--)
		cout << a[i];
	cout << endl;
	
	long long ans = 1;
	for (int i=0; i<lena; ++i)
		ans = ans*2 + (1-a[i]);
	ans *= 2;
	return ans;
}
int main()
{
	long long x;
	cin >> x;
	long long ans=BProcess(x);
	cout << ans << endl;
}
