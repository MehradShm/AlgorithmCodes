#include <iostream>
#include <cstdio>
using namespace std;

const int mxn=100000;

int a[mxn];
int d[mxn];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int mint=a[0];
	for(int i=1;i<m;i++)
	{
		d[i]=a[i]+mint;
		mint=min(mint ,a[i]);
	}
	for(int i=m;i<n;i++)
	{
		int mi=d[i-1];
		for(int j=2 ; j<m ;j++)
			if(i-j>=0)
				mi=min(mi,d[i-j]);
		d[i]=a[i]+mi;
	//	cout<<"d["<<i<<"]  =  "<<d[i]<<endl;
	}
	int ans=d[n-1];
	for(int i=n-2; i>=n-m  && i>=0 ;i--)
	{
		int r_ans=d[i];
		int min_2=a[i+1];
		for(int j=i+1;j<=n-1;j++)
			min_2=min(a[j],min_2);
		r_ans+=min_2;
	//	cout<<i<<"  r_ans  "<<r_ans<<endl;
		ans=min(ans,r_ans);
	}
	printf("%d",ans);
	return 0;
}
