#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF=1000*1000*1000;
const int Max=100+10;
int d[Max][Max];
int mini[Max];
int v[Max*Max];
int n,m;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>v[i];
	for(int i=1;i<m;++i)
		d[0][i]=v[i];
	for(int i=1;i<=n;++i)
	{
		int mi=INF;
		for(int j=i-1;j>i-m;--j)
		{
			if(j>=0)
				mi=min(mi,d[j%m][i-j]);
			mini[i-j]=mi;
		}
		for(int j=1;j<m;++j)
			d[i%m][j]=v[i+j]+mini[m-j];
	}
	int mi=INF;
	for(int i=0;i<m;++i)
		for(int j=1;j<m;++j)
			if(j<=i)
				mi=min(mi,d[(n-i)%m][j]);
	cout<<mi<<endl;
}

