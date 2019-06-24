#include <iostream>
using namespace std;
int main()
{
	long long delta;
	cin >> delta;
	long long x=1 , y=1 , z=1;
	for(int i=0;i<=1000;i++)
	{
		x*=5;
		x%=delta;
		y*=4;
		y%=delta;
		z*=3;z%=delta;
	}
	y*=2;
	y%=delta;
	cerr << x << " :: " << y << " :: " << z << endl;
	cerr << x << " :: " << y << " :: " << z << endl;

	cout << ((x-y+z)%delta);
}
