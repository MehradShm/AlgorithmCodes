#include <iostream>
using namespace std;

long long ANS(long long x)
{
	for(long long i=x+1;;i++)
	{
		long long k=i;
		while(k)
		{
			if(k%10==8 or k%10==-8)
				return i;
			k/=10;
		}
	}
}

int main()
{
	long long  a;
	cin >> a;
	long long ans=ANS(a);
	cout << ans-a << endl;
}
