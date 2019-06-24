#include <iostream>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	if(n%2)
	{
		if(9<=n-9)
			cout << 9 << " " << n-9 <<endl;
		else
			cout << n-9 << " " << 9 << endl;
	}
	else
		cout << 4 << " " << n-4 << endl;
}
