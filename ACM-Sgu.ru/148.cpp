#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=15005;
int w[maxn] , l[maxn] , p[maxn] , mark[maxn] , s[maxn];
long long sum=0 , inf=15002 , km=0;
int n;
vector<int> ans;

int bs(int st , int end , int v , int ka , int saghf)
{
	if(st==end-1)
		return st;
	int mid=(st+end)/2;
	if(s[saghf]-s[ka]<=v)
		return inf;
	else if(s[mid]-s[ka]>v)
		return bs(mid,end,v,ka,saghf);
	else
		return bs(st,mid,v,ka,saghf);
}

int Destroy(int x, int &saghf)
{
	if(w[x]>l[x])
		return 0;
	if(x==saghf)
	{
		ans.push_back(saghf);
		saghf+=1;
		return p[saghf];
	}
	int k=l[x]-w[x];
	int g=bs(saghf,x+1,k,x,saghf) , g1=g , g2;
	if(x==n and g==inf)
	{
		cout << x << endl;
		return 0;
	}
	for(int i=x-1;i>g;i--)
	{
		int k1=l[i]-w[i];
		g2=bs(saghf,i+1,k1,i,saghf);
		if(g2==inf)
			ans.push_back(i);
		g1=min(g1,g2);
	}
	int ha=min(p[x],Destroy(g1,saghf));
	if(p[x]==min(p[x],ha))
	{
		km=p[x];
		while(ans.size())
			ans.pop_back();
		ans.push_back(x);
	}
	km+=ha;
	return km;
}

int main()
{
	int ans1;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> w[i] >> l[i] >> p[i];
		sum+=w[i];
	}
	for(int i=1;i<=n;i++)
	{
		s[i]=sum;
		sum-=w[i];
	}
	int e=1;
	ans1=Destroy(n,e);
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << endl;
}
