#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>


using namespace std;

vector < string > c;

const int maxn=40050;
const int maxm=100050;
string g[maxn] , s[maxm];
char f[maxn][10];

int main()
{
	ios::sync_with_stdio(false);
	int n , m , k;
	cin >> n >> m >> k;
	for(int i=0;i<n;i++)
		scanf("%s",&f[i]);
	for(int i=n-1;i>=0;i--)
		c.push_back(f[i]);
	for(int i=0;i<m;i++)
		scanf("%s",&s[i]);
	int t=0;
	for(int i=0;i<m;i++)
	{
		if(s[i]=="ROTATE")
		{
			t++;
			if(s[i+1]!="ROTATE")
				if(t%2)
					if(c.size()>k)
						for(int j=0;j<(k/2);j++)
							swap(c[c.size()-1-j],c[c.size()-k+j]);
					else
						for(int j=0;j<(c.size())/2;j++)
							swap(c[0+j],c[c.size()-1-j]);
		}
		else
		{
			t=0;
			string s1;
			int s1s=0;
			for(int j=4;;j++)
				if(s[i][j]!=')')
					s1+=s[i][j];
				else
					break;
			c.push_back(s1);
		}	
	}
	for(int i=c.size()-1;i>=0;i--)
		printf("%d",c[i]);
}
