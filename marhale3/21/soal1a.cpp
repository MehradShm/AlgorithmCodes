#include <iostream>
using namespace std;
long long Behtarin(long long m)
{
	long long x=1;
	for(int i=1;x*2<=m;i++)
		x*=2;
	return x;
}
int main()
{
	long long delta;
	cin >> delta;
	long long k=Behtarin(delta*delta);
	cout << delta*delta << " $$ " <<  k << " %% " << k%delta << " :: " << 112763161%delta << endl;
	cout << ((k*k*3)%delta) << endl;
}
