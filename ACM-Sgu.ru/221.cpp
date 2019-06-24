#include <iostream>
#include <vector>

using namespace std;
const int maxn=15 , maxk=105;
long long a[maxn][maxm];
vector<int> v[5];

int main()
{
	int n , k;
	cin >> n >> k;
	v[n%2].push_back(n);
	for(int i=n-1;i>0;i++)
	{
		v[i%2].push_back(i);
		v[i%2].push_back(i);
	}
	a[1][0]=1;
	a[1][1]=1;
	v[1].pop_back();
	for(int i=1;i<v[1].size;i++)
	{
		for(int j=0;j<=i;j++)
			for(int k=0;k<2;k++)
				a[(i*2)+1][j+k]=a[((i-1)*2)+1][j];
	}
}
