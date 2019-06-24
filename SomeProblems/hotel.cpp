#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;
const int MAXN=1000*1000+10;
const int INF = 1000 * 1000 * 1000;
const int MAXH=10*10+10;
typedef pair<int,int> PII;
set <PII> z;
queue <int> q;
vector <int> c[MAXN] , c2[MAXN];
vector <int> hotel[MAXN] , hotelha;
int d[MAXN] , h[MAXN] , ans[MAXN], mark[MAXN];
int n, th , m;
void Dijkstra(int x)
{
	fill(d, d+n, INF);
	d[x]=0;
	for(int i=0;i<n;i++)
		if(i!=x)
			z.insert(PII(INF,i));
	z.insert(PII(0,x));
	for(int i=0;i<n-1;i++)
	{
		PII tmp=*z.begin();
		z.erase(z.begin());
		int f=tmp.second;
		for(int j=0;j<c[f].size();j++)
			if(d[c[f][j]]>d[f]+c2[f][j])
			{
				z.erase(PII(d[c[f][j]],c[f][j]));
				d[c[f][j]]=d[f]+c2[f][j];
				z.insert(PII(d[c[f][j]],c[f][j]));
			}
	}
	for(int i=0;i<n;i++)
		if(i!=x and h[i] and d[i]<=600)
		{
			hotel[x].push_back(i);
			hotel[i].push_back(x);
		}
}
void BFS()
{
	fill(d,d+n,-1);
	q.push(0);
	mark[0]=1;
	d[0]=-1;
	while(q.size())
	{
		int k=q.front();
		q.pop();
		for(int i=0;i<hotel[k].size();i++)
			if(mark[hotel[k][i]]==0)
			{
				q.push(hotel[k][i]);
				mark[hotel[k][i]]=1;
				d[hotel[k][i]]=d[k]+1;
			}
	}
	cout << d[n-1] << endl;
}
int main()
{
	cin >> n >> th;
	for(int i=0;i<th;i++)
	{
		int temp;
		cin >> temp;
		h[temp-1]=1;
		hotelha.push_back(temp-1);
	}
	hotelha.push_back(0);
	hotelha.push_back(n-1);
	cin >> m;
	h[0]=1;
	h[n-1]=1;
	for(int i=0;i<m;i++)
	{
		int temp , temp2 , temp3;
		cin >> temp >> temp2 >> temp3;
		temp--;
		temp2--;
		c[temp].push_back(temp2);
		c2[temp].push_back(temp3);
		c[temp2].push_back(temp);
		c2[temp2].push_back(temp3);
	}
	for(int i=0;i<hotelha.size();i++)
		Dijkstra(hotelha[i]);
	BFS();
}
