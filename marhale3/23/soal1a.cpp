#include <iostream>
using namespace std;
long long f(int x , int y)
{
	if(y==0)
		return x;
	else if(y%2==0)
		return 2*(f(x,(y/2)));
	else
		return 3*(f(x,(y/2)));
}
long long g(int n , int delta)
{
	long long sum=0;
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
		{
			if(j%10000==0)
				cout << i << " :: " << j << " $$ " << f(i,j)%delta << endl;
			sum+=(f(i,j)%delta);
			sum%=delta;
		}
	return sum;
}
int main()
{
	long long delta;
	cin >> delta;
	int m1=g((delta*delta)+3 , delta);
	cout << m1%delta << endl;
}
