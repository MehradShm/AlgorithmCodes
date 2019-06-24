#include <iostream>
using namespace std;

int B(int x)
{
	if(x==1)
		return 2;
	if(x%2==1)
		return B((x/2))*2;
	if(x%2==0)
		return B((x/2));
}

int main()
{
	int n;
	cin >> n;
	int ans=B(n);
	cout << (n+1)-ans << endl;
}
