#include <iostream>
using namespace std;

int log(int x)
{
	long long  k=0;
	long long s=1;
	for(int i=0;s<x;i++)
	{
		if(s*2<=x)
		{
			s*=2;
			k++;
		}
		else
			break;
	}
	return k;
}

int main()
{
	long long n , ans;
	cin >> n;
	if(n==1)
		cout << 0 << endl;
	else if(n==2 or n==3)
		cout << "1" << endl;
	else
	{
		ans=log(n)-1;
		cout << ans << endl;
	}
}
