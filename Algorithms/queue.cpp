#include <iostream>
#include <queue>
using namespace std;
queue <int> c , b , a;
int l[10000];
int Check(int x , int n)
{
	if(x==n)
		return 1;
	else if(l[x]==b.front() or l[x]==c.front())
	{
		if(c.front()==l[x])
			c.pop();
		else
			b.pop();
		return Check(x+1,n);
	}
	else if(l[x]<(n+1)-a.size())
		if(b.front()!=l[x] and c.front()!=l[x])
			return 0;
	else if(a.front()==l[x])
	{
		c.push(a.front());
		a.pop();
		return Check(x,n);
	}
	else
	{
		b.push(a.front());
		a.pop();
		return Check(x,n);
	}
}				
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> l[i];
	if(Check(0 , n))
		cout << " YES " << endl;
	else
		cout << " NO " << endl;
}
