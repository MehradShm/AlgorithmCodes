#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> c;
int n , k;

int move()
{
	int t=0 , m=1 , time=0;
	for(int i=0;c.size() and i<k;i++)
	{
		int x=0;
		if(c.size())
			x=c[c.size()-1];
		c.pop_back();
		time+=abs(x-m);
		m=x;
	}
	time+=(m-1);
	return time;
}

int main()
{
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		int t;
		cin >> t;
		c.push_back(t);
	}
	int tedad=n , zaman=0;
	sort(c.begin(),c.end());
	while(tedad)
	{
		int l=move();
		zaman+=l;
		if(tedad>=k)
			tedad-=k;
		else
			tedad=0;
	}
	cout << zaman << endl;
}
