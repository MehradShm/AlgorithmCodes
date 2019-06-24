#include <iostream>

using namespace std;
int d[55] , de[55];
pair<int,pair<int,int > > c[55][55] , e[55][55];
double ep=1/1000;
int n;

int Relax(int n , int x)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j and e[i][j].first)
				if(d[j]>d[i]+e[i][j].second)
				{
					if(x<n-2)
						d[j]=min(d[j],d[i]+e[i][j].second);
					else
						return 0;
				}
	return 1;

}

int BMF(int k)
{
	fill(d,d+n,101);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			e[i][j].first=c[i][j].first;
			e[i][j].first=((k*c[i][j].second)-c[i][j].first);
		}
	int s=2;
	for(int i=0;i<n;i++)
		s=Relax(n,i);
	if(s)
		return 1;
	return 0;
}

double BS(double st , double end)
{
	if(end-st<ep)
		return ep;
	double mid=double((end+st)/2);
	if(BMF(mid))
		return BS(mid,end);
	else
		return BS(st,end);

}
int main()
{
	int m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int t1 ,t2 ,t3 ,t4;
		cin >> t1 >> t2 >>t3 >> t4;
		pair<int,int> x;
		c[t1][t2].first=1;
		c[t2][t1].first=1;
		c[t1][t2].second=x;
		c[t2][t1].second=x;
	}
	int z=BS(0,5001);
}
