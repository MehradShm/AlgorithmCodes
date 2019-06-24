#include <iostream>
using namespace std;
long long f(int x , long long delta)
{
	long long ans=0;
	for(int i=1;i<delta;i++)
		for(int j=i;j<delta;j++)
			if((i*j)%x==0)
				if(i!=j)
				{
					ans+=2;
					ans%=delta;
				}
				else
				{
					ans++;
					ans%=delta;
				}
	return ans;
}
int main()
{
	long long ans=0 , delta;
	cin >> delta;
	for(int i=1;i*2<delta;i*=2)
	{
		long long x=f(i,delta);
		ans+=x;
		ans%=delta;
	}
	ans+=f(8192,delta);
	ans%=delta;
	cout << ans << endl;
}
