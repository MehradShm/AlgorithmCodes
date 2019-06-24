#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int maxn=1005;
string f[maxn] , s[maxn] , j[maxn];

int main()
{
	int n , k;
	cin >> n >> k;
	for(int i=0;i<k;i++)
		cin >> f[i] >> s[i];
	for(int i=0;i<n;i++)
		cin >> j[i];
	for(int i=0;i<n;i++)
	{
		for(int u=0;u<k;u++)
			if(j[i]==f[u] or j[i]==s[u])
			{
				if(f[u].size()<s[u].size())
					j[i]=f[u];
				else if(f[u].size()>s[u].size())
					j[i]=s[u];
				else
					for(int y=0;y<s[u].size();y++)
					{
						char h1=s[u][y] , h2=f[u][y];
						int m1=h1-'a',m2=h2-'a';
						if(m1<m2)
							j[i]=f[u];
						else if(m1<m2)
							j[i]=s[u];
					}
			}
	}
	for(int i=0;i<n;i++)
		cout << j[i] << " ";
	cout << endl;
}

