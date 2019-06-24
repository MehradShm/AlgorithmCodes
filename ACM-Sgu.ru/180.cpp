#include <iostream>
using namespace std;
const int maxn=70000;
long long a[maxn], b[maxn] , c[maxn];
long long ans=0;
int n;

void Merge(int x ,int y , int z)
{
	int bs=0 , cs=0;
	for(int i=x;i<=y;i++)
	{
		b[bs]=a[i];
		bs++;
	}
	for(int i=y+1;i<=z;i++)
	{
		c[cs]=a[i];
		cs++;
	}
	int pb=0 , pc=0;
	for(int i=x;i<=z;i++)
	{
		if(pb<bs and pc<cs)
		{
			if(b[pb]>c[pc])
			{
				a[i]=c[pc];
				ans+=(bs-pb);
				pc++;
			}
			else if(b[pb]<c[pc])
			{
				a[i]=b[pb];
				pb++;
			}
			else if(b[pb]==c[pc])
			{
				a[i]=b[pb];
				pb++;
			}
		}
		else if(pc==cs and pb<bs)
		{
			a[i]=b[pb];
			pb++;
		}
		else if(pb==bs and pc<cs)
		{
			a[i]=c[pc];
			pc++;
		}
		else if(pb==bs and pc==cs)
			break ;
	}

}

void Merge_Sort(int x , int y)
{
	if(x==y)
		return ;
	else
	{
		int mid=(x+y)/2;
		Merge_Sort(x,mid);
		Merge_Sort(mid+1,y);
		Merge(x,mid,y);
	}
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	Merge_Sort(1,n);
	cout << ans << endl;
	
}
