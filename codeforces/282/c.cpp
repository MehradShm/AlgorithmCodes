#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn=100005;
int t[maxn] , e[maxn] , p[maxn];
vector<int> f;

int M(int k)
{
	if(k==0)
		return 0;
	if(t[k]>1)
	{
		t[k]--;
		return 1;
	}
	return M(p[k]);
}

int main()
{
	string s;
	cin >> s;
	if(s[0]=='#')
	{
		cout << "-1" << endl;
		return 0;
	}
	p[0]=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			e[i]=e[i-1]+1;
			if(s[i-1]=='#')
				p[i]=i-1;
			else
				p[i]=p[i-1];
		}
		else if(s[i]==')')
		{
			e[i]=e[i-1]-1;
			if(s[i-1]=='#')
				p[i]=i-1;
			else
				p[i]=p[i-1];
			if(e[i]<0)
				if(M(p[i])==0)
				{
					cout << "-1" << endl;
					return 0;
				}
			e[i]=0;
		}
		else
		{
			e[i]=e[i-1];
			f.push_back(i);
			if(s[i-1]=='#')
				p[i]=i-1;
			else
				p[i]=p[i-1];
			if(e[i]==0)
			{
				if(M(p[i])==0)
				{
					cout << "-1" << endl;
					return 0;
				}
				t[i]=1;
			}
			else
			{
				t[i]=e[i];
				e[i]=0;
			}
		}
	}
	for(int i=0;i<f.size();i++)
		cout << t[f[i]] << endl;
}
