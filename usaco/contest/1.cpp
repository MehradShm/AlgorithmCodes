#include <iostream>
#include <fstream>
using namespace std;

const int maxn=100005;
pair<int,int > a[maxn];
long long d[maxn] , dw[maxn];

int main()
{
	ifstream fin("marathon.in");
	ofstream fout("marathon.out");
	int n;
	long long ans=99999999;
	fin >> n;
	for(int i=0;i<n;i++)
	{
		fin >> a[i].first >> a[i].second;
		if(i)
		{
			long long k1=a[i].first-a[i-1].first , k2=a[i].second-a[i-1].second;
			if(k1<0)
				k1*=(-1);
			if(k2<0)
				k2*=(-1);
			d[i]=d[i-1]+k1+k2;
		}
	}
	for(int i=1;i<n-1;i++)
	{
		long long k1=a[i+1].first-a[i-1].first , k2=a[i+1].second-a[i-1].second;
		long long k3=a[i].first-a[i-1].first , k4=a[i].second-a[i-1].second;
		long long k5=a[i+1].first-a[i].first , k6=a[i+1].second-a[i].second;
		if(k1<0)
			k1*=(-1);
		if(k2<0)
			k2*=(-1);
		if(k3<0)
			k3*=(-1);
		if(k4<0)
			k4*=(-1);
		if(k5<0)
			k5*=(-1);
		if(k6<0)
			k6*=(-1);
		dw[i]=d[n-1]-k3-k4-k5-k6+k1+k2;
		ans=min(ans,dw[i]);
	}
	fout << ans << endl;
}
