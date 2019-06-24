#include <iostream>
using namespace std;
long long fa[12] , ta[12];
int main()
{
	int n , k;
	cin >> n >> k;
	for(long long i=1;i<=10;i++)
		ta[i]=i*i;
	fa[1]=1;
	for(long long i=2;i<=10;i++)
		fa[i]=i*fa[i-1];
	if(k==0)
		cout << "1" << endl;
	if(k>n)
		cout << "0" << endl;
	else if(k<=n and k>0)
	{
		long long x=1;
		for(int i=0;i<k;i++)
		{
			x*=ta[n-i];
			x/=(i+1);
		}
		cout << x << endl;
	}
}
