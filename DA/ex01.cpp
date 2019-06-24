#include <iostream>

using namespace std;

long long divide(long long s , long long m)
{
	if(s==m and s!=1)
		return -1;
	if(s>m)
	{
		if(m==1)
			return s-1;
		long long k = (s%m) , flag=0;
		if(k==0)
		{
			flag=-1;
			k+=m;
		}
		long long tmp=divide(k,m);
		if(tmp==-1)
			return -1;
		return tmp + s/m;
	}
	else
	{
		if(s==1)
			return m-1;
		long long k= (m%s) , flag=0;
		if(k==0)
		{
			flag=-1;
			k+=s;
		}
		long long tmp = divide( s,k );
		if(tmp==-1)
			return -1;
		return tmp + m/s + flag;
	}
}

int main()
{
	long long s , m , ans;
	cin >> s >> m;

	ans = divide(s,m);

	if(ans==-1)
		cout << "impossible" << endl;
	else
		cout << ans << endl;
	return 0;
}

