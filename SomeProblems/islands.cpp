#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef pair<int, pair<int,int> > PIP;

const int MAXN=1000+50 , MAXH=1000*1000+100;
int h[MAXN][MAXN] , ans[MAXH] , p[MAXH] , o[MAXH] ;
vector<int> qu;
int qu2[MAXH];

set<PIP, greater<PIP> > s;
int a[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n , m , q=1000005;

int num(pair<int,int> x)
{
	int number=0;
	number=((x.first*m)+x.second);
	return number;
}

int MCheck(PIP x)
{
	int r1=x.second.first , r2=x.second.second;
	if(r2>=m or r2<0 or r1>=n or r1<0)
		return 0;
	return 1;
}

int findroot(int x)
{
	if(p[x]!=x)
		p[x]=findroot(p[x]);
	return p[x];
}

int Merge(PIP x , PIP y,int hfeli)
{
	int e=num(x.second) , f=num(y.second);
	int roote=findroot(e) , rootf=findroot(f);
	if(roote==rootf)
		return 0;
	if(o[roote]>o[rootf])
		p[rootf]=roote;
	else if(o[rootf]>o[roote])
		p[roote]=rootf;
	else
	{
		p[rootf]=roote;
		o[e]++;
	}
	return 1;
}
void Check(PIP x , int hfeli)
{
	for(int i=0;i<4;i++)
	{
		PIP k=x;
		k.second.first+=a[i][0];
		k.second.second+=a[i][1];
		int u1=k.second.first , u2=k.second.second;
		if(MCheck(k) and h[u1][u2]>hfeli)
			ans[hfeli]-=Merge(x,k,hfeli);
	}
}
void jazr(int afeli)
{
	if(afeli<0)
		return;
	if(qu[afeli+1]!=qu[afeli])
	{
		if(afeli+1!=qu.size())
			ans[qu[afeli]]+=ans[qu[afeli+1]];
	}
	else
	{
		ans[qu[afeli]]+=ans[qu[afeli+1]];
		jazr(afeli-1);
	}
	while(1)
	{
		PIP k=*s.begin();
		if(k.first<=qu[afeli])
		{
			jazr(afeli-1);
			break;
		}
		s.erase(s.begin());
		int g=num(k.second);
		ans[qu[afeli]]++;
		Check(k,qu[afeli]);
	}
}
int main()
{
	int maxe=0;
	cin >> n >> m;
	int zarb=m*n;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin >> h[i][j];
			pair<int,int> x;
			x.first=i;
			x.second=j;
			pair<int,pair<int,int> > z;
			z.first=h[i][j];
			z.second=x;
			s.insert(z);
			p[num(x)]=num(x);
			maxe=max(maxe,h[i][j]);
		}
	int q;
	cin >> q;
	for(int i=0;i<q;i++)
	{
		int temp;
		cin >> temp;
		qu.push_back(temp);
		qu2[i]=temp;
	}
	sort(qu.begin(),qu.end());
	jazr(qu.size()-1);
	for(int i=0;i<q;i++)
		cout << ans[qu2[i]] << " ";
	cout << endl;
}


