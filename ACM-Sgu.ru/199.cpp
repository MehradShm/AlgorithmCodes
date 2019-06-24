#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=100050;
pair<int,int> a[maxn];
int x[maxn],m[maxn];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i].first >> a[i].second;
	sort(a,a+n);
	x[1]=a[0].second;
	int size=1;
	for(int i=2;i<n;i++)
		if(a[i].second>x[size])
		{
			size++;
			x[size]=a[i].second;
		}
		else
		{
			int k=BS(1,i,a[i].second);
			if(a[i].second<k)
		}
}
