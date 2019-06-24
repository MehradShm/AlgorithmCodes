#include <iostream>
using namespace std;
long long a[110] , b[110];
long long n , c , p , t;

long long Check(long long k) 
{ 
	for(int i=1;i<=n;i++) 
		b[i]=a[i]; 
	long long maxi=0 , maxis=0; 
	for(int i=1;i<=n;i++) {
		if(maxis+b[i]>=k)
		{
			maxi=i;
			b[i]=k-maxis;
			maxis+=b[i];
			break;
		}
		maxis+=b[i];
	}
	long long tedad=0, time=maxi*p , flag=0;
	if(maxis>=k)
	{
		while(maxi>0)
		{
			if(b[maxi]+tedad>c)
			{
				if(tedad>0)
				{
					time+=(maxi*2*p);
					b[maxi]-=(c-tedad);
					tedad=0;
				}
				long long h=b[maxi]/c;
				b[maxi]%=c;
				if(b[maxi])
					time+=(h*2*p*maxi);
				else
				{
					time+=(h*2*p*maxi)-p;
					flag=1;
					maxi--;
				}
			}
			if(flag!=1)
			{
				tedad+=b[maxi];
				time+=p;
				maxi--;
			}
			flag=0;
		}
		if(time<=t)
			return 1;
		else
			return 0;
	}
	return 0;
}		
long long bs(long long st,long long end)
{
	if(st+1==end)
		return st;
	else
	{
		long long mid=((end+st)/2);
		if(Check(mid))
			return bs(mid,end);
		else
			return bs(st,mid);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	long long sum=0;
	cin >> n >>c>>p>>t;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		sum+=a[i];
	}
	long long ans=bs(0,sum+1);
	cout << ans << endl;
}
