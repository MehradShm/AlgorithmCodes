#include <iostream>

using namespace std;

const int MAXN= 1000005 , MOD= 1000 * 1000 * 1000 + 7;

int a[MAXN] , c[MAXN];
long long ans=0;
int s , m , pointer;

// [ ] intervals
void merge(int start , int mid , int end)
{
	s=start;m=mid+1;pointer=s-1;
	while(s<=mid and m<=end)
	{
		pointer++;
		if(a[s]>a[m])
		{
			c[pointer]=a[m];
			m++;
		}
		else
		{
			c[pointer]=a[s];
			ans+=m-mid-1;
			ans%=MOD;
			s++;
		}
	}
	if(s>mid)
		for(int i=0;i<=end-m;i++)
			c[pointer+i+1]=a[m+i];

	if(m>end)
		for(int i=0;i<=mid-s;i++)
		{
			c[pointer+i+1]=a[s+i];
			ans+=end-mid;
			ans%=MOD;
		}
	for(int i=start;i<=end;i++)
		a[i]=c[i];
}

void Msort(int start , int end)
{
	int mid;
	if(start==end)
		return ;
	mid=(start+end)/2;
	Msort(start , mid);
	Msort(mid+1 , end);
	merge(start , mid , end);
}

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	Msort(1,n);
	cout << ans << endl;
	return 0;
}
