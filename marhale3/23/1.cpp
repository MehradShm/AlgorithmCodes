#include <iostream>
using namespace std;
int main()
{
	long long x=64976;
	long long delta=12253;
	cout << ((((((x*x)%delta)*x)%delta)*x)delta);
}

