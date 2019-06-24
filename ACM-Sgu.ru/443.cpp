#include <iostream>
#include <vector>
using namespace std;
vector <int> p;

int prime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main()
{
	int x , y;
	cin >> x >> y;
	int k=max(x,y);
	for(int i=2;i<=k;i++)
		if(prime(i))
			p.push_back(i);
	int x1=-1 , y1=-1 , f1=0 , f2=0;
	for(int i=p.size()-1;i>=0;i--)
		if(f1==0)
		{
			if(x%p[i]==0)
			{
				x1=p[i];
				f1=1;
			}
		}
		else
			if(x%p[i]==0)
				x1-=p[i];
	for(int i=p.size()-1;i>=0;i--)
		if(f2==0)
		{
			if(y%p[i]==0)
			{
				y1=p[i];
				f2=1;
			}
		}
		else
			if(y%p[i]==0)
				y1-=p[i];
	if(x1>y1)
		cout << 'a' << endl;
	else
		cout << 'b' << endl;
}
