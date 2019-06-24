#include <iostream>
#include <algorithm>

using namespace std;

pair<long long,long long> a[105];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i].second;
	for(int i=0;i<n;i++)
		cin >> a[i].first;
	sort(a,a+n);
	for(int i=n-2;i>=0;i--)
		a[i].second+=a[i+1].second;
	long long ans=0;
	for(int i=n-1;i>=0;i--)
	{
		a[i].first+=a[i].second;
		ans=max(a[i].first,ans);
	}
	cout << ans << endl;
}
