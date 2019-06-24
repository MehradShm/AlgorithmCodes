#include <iostream>
using namespace std;
long long h(long long x , long long delta)
{
	long long zarib=1;
	for(int i=0;x>0;i++)
	{
		if(x%2==0)
			zarib*=2;
		else
			zarib*=3;
		zarib%=delta;
		x/=2;
	}
	return zarib;
}
int main()
{
	long long delta , zarib=0;
	cin >> delta;
	for(long long i=1;i<(delta*delta)+3;i++)
	{
		zarib+=h(i,delta);
		zarib%=delta;
		if(i%1000000==0)
			cout << i << " :: " << endl;
	}
//	long long meghdar=((((((delta*delta)+3)/2)%delta)*(((delta*delta)+2)%delta))%delta);
	long long tmp = (delta * delta + 3) / 2 % delta;
	long long meghdar = tmp * ((delta * delta + 2) % delta) % delta;
	long long ans=(meghdar*zarib)%delta;
	cout << meghdar << " $$ " << zarib << endl;
	cout << ans << endl;
}
