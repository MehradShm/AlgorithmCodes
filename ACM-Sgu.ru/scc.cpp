#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

const int max
vector<int> v[maxn];

int main()
{
	cin >> n;
	string s;
	getline(cin,s);
	for(int i=0;i<n;i++)
	{
		a[i]=i;
		getline(cin,s);
		int x=0;
		for(int j=0; j<s.size(); j++)
		{
			if(s[j]==' ' && x)
			{
				d[i][x-1]=1;
				d[x-1][i]=1;
				x=0;
			}
			else
				x=x*10+s[j]-'0';
		}
		if(x)
		{
			d[i][x-1]=1;
			d[x-1][i]=1;
		}

	}
}
