#include <iostream>
#include <set>
#include <vector>
using namespace std;
set <vector<int> > b;
int a[8][8];
void Put()
{
	vector <int> c;
	for(int i=1;i<=4;i++)
	{
		int x=0;
		for(int j=1;j<=4;j++)
			x+=a[i][j];
		c.push_back(x);
	}
	for(int i=1;i<=4;i++)
	{
		int x=0;
		for(int j=1;j<=4;j++)
			x+=a[j][i];
		c.push_back(x);
	}
	b.insert(c);
}
int main()
{
	long long delta , matloob=0;
	cin >> delta;
	int x=1024*64;
	for(int i=0;i<x;i++)
	{
		if(i%1000==0)
			cerr << i << " TT "  << b.size() << endl;
		int l=i;
		for(int j=1;j<=4;j++)
			for(int k=1;k<=4;k++)
			{
				if(l%2==0)
					a[j][k]=0;
				else
					a[j][k]=1;
				l>>=1;
			}
		Put();
	}
	matloob=b.size();
	cout << (matloob*matloob*matloob*matloob)%delta << endl;
}
