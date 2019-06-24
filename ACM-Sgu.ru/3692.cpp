#include <iostream>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

const int maxn=200010;
vector<int> h[maxn],l[maxn];
map<int,int> x[maxn],cx,cy;
int p[maxn];

int FR(int k)
{
	if(p[k]==k)
		return k;
	else
		return FR(p[k]);
}

void Merge(int k , int m)
{
	if(x[k].size()>=x[m].size())
	{
		while(h[m].size())
		{
			if(x[k].find(h[m].back())==x[k].end())
			{
				pair<int,int> tmp;
				tmp.first=h[m].back();
				x[k].insert(tmp);
				h[k].push_back(h[m].back());
			}
			h[m].pop_back();
		}
		p[m]=k;
	}
	else
	{
		while(h[k].size())
		{
			if(x[m].find(h[k].back())==x[m].end())
			{
				pair<int,int> tmp;
				tmp.first=h[k].back();
				x[m].insert(tmp);
				h[m].push_back(h[k].back());
			}
			h[k].pop_back();
		}
		p[k]=m;
	}
}

void Check(int k)
{
	for(int i=0;i<x[k].size();i++)
	{
		int tmp=h[k][i];
		for(int j=0;j<l[tmp].size();j++)
			if(l[tmp][j]!=k)
			{
				int p1=FR(k) , p2=FR(l[tmp][j]);
				if(p1!=p2)
					Merge(p1,p2);
			}
	}
}

int main()
{
	int n , t=0;
	cin >> n;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		int tmp1,tmp2;
		scanf("%d",&tmp1);
		scanf("%d",&tmp2);
		pair<int,int>f;
		pair<int,int> tmp;
		if(cx.find(tmp1)==cx.end())
		{
			f.first=tmp1;
			f.second=cx.size();
			cx.insert(f);
			p[cx[tmp1]]=cx[tmp1];
			t++;
		}
		if(cy.find(tmp2)==cy.end())
		{
			tmp.first=tmp2;
			tmp.second=cy.size();
			cy.insert(tmp);
		}
		pair<int,int> tmp3 , tmp4;
		tmp3.first=cy[tmp2];
		x[cx[tmp1]].insert(tmp3);
		tmp4.first=cx[tmp1];
		l[cy[tmp2]].push_back(cx[tmp1]);
		h[cx[tmp1]].push_back(cy[tmp2]);
	}
	for(int i=0;i<t;i++)
		if(p[i]==i)
			Check(i);
	for(int i=0;i<t;i++)
	{
		int tmp=FR(i);
		ans+=x[tmp].size();
	}
	cout << ans << endl;
}
