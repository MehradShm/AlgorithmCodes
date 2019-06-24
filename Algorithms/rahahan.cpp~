#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue <int> a , b;
int p[1000];
vector <int> c;

int abf(int k)
{
	if(a.size())
		if(a.front()==k)
			return 2;
	if(b.size())
		if(b.front()==k)
			return 1;
	return 0;
}

int Check(int k,int n)
{
	if(k==n)
		return 1;
	if(c.size()>=n+1-p[k])
	{
		while(c.size() and c[c.size()-1]!=p[k])
		{
			a.push(c[c.size()-1]);
			c.pop_back();
		}
		b.push(c[c.size()-1]);
		c.pop_back();
	}
	int x=abf(p[k]);
	if(x==2)
	{
		a.pop();
		return Check(k+1,n);
	}
	if(x==1)
	{
		b.pop();
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
		cout << " NO " << endl;
}
