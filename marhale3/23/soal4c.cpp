#include <iostream>
using namespace std;
long long f(long long delta)
{
	long long ans=0;
	for(int i=1;i<delta;i++)
		for(int j=i;j<delta;j++)
			for(int k=1;k<delta;k++)
				if((i*j)%k==0)
				{
					if(i%10==0 and j%1000==0)
						cout << i << endl;
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
				}
	return ans;
}
int main()
{
	long long ans=0 , delta;
	cin >> delta;
	ans=f(delta);
	cerr << " ---- " << endl;
	cout << ans << endl;
}
