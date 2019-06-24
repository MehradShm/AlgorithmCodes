#include<iostream>
#include <vector>
#include <queue>
using namespace std;
int n , e , s;
int  d[1000] , yal[1000][1000] , tb[1000];
bool myali[1000][1000] , mark[1000];
vector<int>c[1000];
vector<pair<int,int> > y;
queue<int> bq;
void DFS(int x)
{
	for(int i=0;i<c[x].size();i++)
		if(mark[c[x][i]]==0 and myali[x][c[x][i]]==0)
		{
			mark[c[x][i]]=1;
			d[c[x][i]]=d[x];
			bq.push(c[x][i]);
			DFS(c[x][i]);
		}
}
void BFS()
{
	int k=bq.front();
	bq.pop();
	for(int i=0;i<c[k].size();i++)
		if(mark[c[k][i]]==0 and myali[k][c[k][i]])
		{
			mark[c[k][i]]=1;
			d[c[k][i]]=d[k]+1;
			bq.push(c[k][i]);
			DFS(c[k][i]);
		}
}
int Check(int meghdar)
{
	DFS(1);
	while(bq.size())
		BFS(); 
	if(d[n]<=s)
		return 1;
	else
		return 0;
}
int bs(int st,int end)
{
	if(st+1==end)
		return end;
	else
	{
		int mid=((st+1)+end)/2;
		for(int i=1;i<=n;i++)
		{
			d[i]=0;
			mark[i]=0;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				myali[i][j]=0;
		d[1]=0;
		mark[1]=1;
		bq.push(1);
		for(int i=0;i<e;i++)
			if(yal[y[i].first][y[i].second]>mid)
			{
				myali[y[i].first][y[i].second]=1;
				myali[y[i].second][y[i].first]=1;
			}
		if(Check(mid))
			return bs(st,mid);
		else
			return bs(mid,end);
	}
}
int main()
{
	int maxi=0 , ans;
	cin >> n>> e >> s;
	for(int i=0;i<e;i++)
	{
		int temp1,temp2,temp3;
		cin >> temp1 >> temp2 >> temp3;
		yal[temp1][temp2]=temp3;
		yal[temp2][temp1]=temp3;
		c[temp1].push_back(temp2);
		c[temp2].push_back(temp1);
		pair<int,int> zoj;
		zoj.first=temp1;
		zoj.second=temp2;
		y.push_back(zoj);
		maxi=max(maxi,temp3);
	}
	ans=bs(-1,maxi);
	cout << ans <<endl;
}
