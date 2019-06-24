#include <iostream>
#include <vector>
using namespace std;
int p[1000];
vector<int> a,b,c;

int move(int k)
{
	if(a[a.size()-1]==k)
	{
		b.push_back(a[a.size()-1]);
		a.pop_back();
	}
	b.pop_back();
}

int Check(int k , int n)
{
	if(k==n)
		return 1;
	if(c.size()>=n+1-p[k])
	{
		while(c.size() and c[c.size()-1]!=p[k])
		{
			a.push_back(c[c.size()-1]);
			c.pop_back();
		}
		a.push_back(c[c.size()-1]);
		c.pop_back();
	}
	if((a.size() and a[a.size()-1]==p[k]) or (b.size() and b[b.size()-1]==p[k]))
	{
		move(p[k]);
		return Check(k+1,n);
	}
	return 0;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> p[i];
		c.push_back(n-i);
	}
	if(Check(0,n))
		cout << " Yes " << endl;
	else
		cout << " No " << endl;
}
