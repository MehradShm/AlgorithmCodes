#include <iostream>
#include <vector>
using namespace std;
int d[405] , mark[405] , c[405][405] , tar[405] , tar2[405] , d2[405] , mark2[405];
vector<pair<int,int> > h[405];
void find(int n , int &tedad)
{
	int mini=9999999 , mis=0 , mit=0;
	for(int i=1;i<=n;i++)
		if(mark[i])
			for(int j=0;j<h[i].size();j++)
				if(mark[h[i][j].first]==0 and h[i][j].second+d[i]<mini)
				{
					mini=min(mini,d[i]+h[i][j].second);
					mit=h[i][j].first;
					mis=i;
				}
	mark[mit]=1;
	d[mit]=mini;
	tar[tedad]=mit;
	tedad++;
}
void find2(int n, int &tedad2)
{
	int mini=9999999 , mis=0 , mit=0;
	for(int i=1;i<=n;i++)
		if(mark2[i])
			for(int j=0;j<h[i].size();j++)
				if(mark2[h[i][j].first]==0 and h[i][j].second+d2[i]<mini and tar[n-1]!=h[i][j].first)
				{
					mini=min(mini,d2[i]+h[i][j].second);
					mit=h[i][j].first;
					mis=i;
				}
	mark2[mit]=1;
	d2[mit]=mini;
	tar2[tedad2]=mit;
	tedad2++;
}
int main()
{
	int tedad=2 , tedad2=2;
	int n , m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int temp1,temp2 , temp3;
		cin >> temp1 >> temp2 >> temp3;
		c[temp1][temp2]=1;
		c[temp2][temp1]=1;
		pair <int,int> u ,t;
		u.first=temp2;
		u.second=temp3;
		t.first=temp1;
		t.second=temp3;
		h[temp1].push_back(u);
		h[temp2].push_back(t);
	}
	int x=1;
	tar[1]=1;
	tar2[1]=1;
	for(int i=1;i<=n;i++)
		if(c[x][i]==0)
			d[i]=999999;
	int mini=9999999 , mi=0;
	mark[x]=1;
	mark2[x]=1;
	d[x]=0;
	d2[x]=0;
	for(int i=1;i<n;i++)
		find(n , tedad);
	for(int i=1;i<n;i++)
		find2(n,tedad2);
	for(int i=1;i<tedad;i++)
		cout << tar[i] << " ";
	for(int i=1;i<tedad2;i++)
		cout << tar2[i] << " ";
}
