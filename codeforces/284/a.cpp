#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=505;
int l[maxn],r[maxn];

int main()
{
	int n , x , ans=0;
	cin >> n >> x;
	for(int i=0;i<n;i++)
		cin >> l[i] >> r[i];
	int t=1 , k=0;
	while(k<n)
	{
		if(t+x<=l[k])
			t+=x;
		else
		{
			ans+=r[k]-t+1;
			t=r[k]+1;
			k++;
		}
	}
	cout << ans << endl;
}
