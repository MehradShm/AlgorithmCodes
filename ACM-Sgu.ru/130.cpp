#include <iostream>
using namespace std;
long long c[35];
int main()
{
	int k;
	cin >> k;
	c[0]=1;
	c[1]=1;
	for(int i=2;i<=k;i++)
		for(int j=0;j<i;j++)
			c[i]+=c[j]*c[i-j-1];
	cout << c[k] << " " << k+1 << endl;
}
