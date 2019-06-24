#include <iostream>
using namespace std;
const int maxn=105;
pair<int,int> a[maxn];
int main()
{
	int n , ans=0;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i].first >>a[i].second;
	for(int i=0;i<n;i++)
		if(a[i].second-a[i].first>1)
			ans++;
	cout << ans << endl;
}
