#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[105];

int main()
{
	int n , ans=9999999;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=1;i<n-1;i++)
	{
		int k=0;
		for(int j=1;j<n;j++)
			if(j==i+1)
				k=max(k,a[j]-a[j-2]);
			else if(i!=j)
				k=max(k,a[j]-a[j-1]);
		ans=min(ans,k);
	}
	cout << ans << endl;
}
