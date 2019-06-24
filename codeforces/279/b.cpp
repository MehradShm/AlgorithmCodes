#include <iostream>
#include <queue>
using namespace std;

const int maxn=200050;
pair<int,int> a[maxn];
int t[maxn];
pair<int,int> f;
queue<pair<int,int > > q;
bool mark[maxn];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i].first >> a[i].second;
		f[a[i].first].first=i;
		f[a[i].second].second=i;
		if(a[i].first==0)
		{
			t[2]=a[i].second;
			pair<int,int> x;
			x.first=a[i].second;
			x.second=2;
			q.push(x);
		}
		if(a[i].second==0)
		{
			pair<int,int> x;
			x.first=a[i].first;
			a.second=n-1;
			t[n-1]=a[i].first;
			q.push_back(x);
		}
	}
	if(n%2==0)
	{
		while(q.size())
		{
			pair<int,int> k=q.front();
			q.pop();
			f[k].first
		}
	}
			
}
