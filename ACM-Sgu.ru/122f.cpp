#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
const int maxn=100*11;
int a[maxn];
bool d[maxn][maxn];
vector<int> c[maxn] , v , ans;
int n;

void rev(int e,int f)
{
	for(int i=f;;i--)
	{
		if(i==-1)
			i=n-1;
		v.push_back(a[i]);
		if(i==e)
			break;
	}
	for(int i=f;;i--)
	{
		if(i==-1)
			i=n-1;
		a[i]=v[v.size()-1];
		v.pop_back();
		if(i==e)
			break;
	}
	return;
}

void fix(int x)
{
	int k=(x+1)%n , s=1;
	if(d[a[x]][a[k]])
		return;
	for(int i=k+1;;i++)
	{
		int y , z;
		y=i%n;
		z=(i+1)%n;
		if(d[a[x]][a[y]] and d[a[k]][a[z]])
		{
			rev(k,y);
			return;
		}
	}
}

int check()
{
	for(int i=0;i<n;i++)
		if(a[i]==0)
		{
			ans.push_back(1);
			return i;
		}
}

int main()
{
	cin >> n;
	string s;
	getline(cin,s);
	for(int i=0;i<n;i++)
	{
		a[i]=i;
		getline(cin,s);
		int x;
		istringstream sin(s);
		while(sin>>x)
		{
			c[i].push_back(x-1);
			d[i][x-1]=1;
			d[x-1][i]=1;
		}
	}
	for(int i=0;i<n;i++)
		a[i]=i;
	for(int i=0;i<n;i++)
		fix(i);
	int g=check();
	for(int i=g+1;i!=g;i++)
	{
		if(i==n)
			i=-1;
		if(i>=0)
			ans.push_back(a[i]+1);
	}
	ans.push_back(1);
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
	cout << endl;
}
