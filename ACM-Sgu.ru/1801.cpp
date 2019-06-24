#include <iostream>
using namespace std;
const int maxn=70000;
long long a[maxn], b[maxn] , c[maxn];
long long ans=0;
int n;

void Merge(int x ,int y , int z)
{
	int bs=0 , cs=0;
	//cerr << " ===== " << endl;
	//cerr << x << " $$ " << z << endl;
	for(int i=x;i<=y;i++)
	{
		b[bs]=a[i];
	//	if(b[bs])
	//		cerr << " $$$$$ " << endl;
		bs++;
	}
	for(int i=y+1;i<=z;i++)
	{
		c[cs]=a[i];
	//	if(c[cs])
			//cerr << " !!!!!! " << endl;
		cs++;
	}
	int pb=0 , pc=0;
	for(int i=x;i<=z;i++)
	{
		if(pb<bs and pc<cs)
		{
			//cerr << " ::::::::::::::: " << endl;
			//if(c[pc]==1 or b[pb]==1)
			//	cerr << " @@ " << endl;
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
	//for(int i=1;i<=z;i++)
	//	cerr << i << " %% " << a[i] << endl;

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
	//for(int i=1;i<=n;i++)
		//cout << i << " :: " << a[i] << endl;
	cout << ans << endl;
	
}

