#include <iostream>
#include <vector>
using namespace std;
int d[2000] , mark[2000] , c[2000][2000];
vector<pair<int,int> > h[2000];
void find(int n)
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

}
int main()
{
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
	int x,y;
	cin >> x >> y;
	for(int i=1;i<=n;i++)
		if(c[x][i]==0)
			d[i]=999999;
	int mini=9999999 , mi=0;
	mark[x]=1;
	d[x]=0;
	for(int i=1;i<n;i++)
		find(n);
	cout << d[y] << endl; 
}
