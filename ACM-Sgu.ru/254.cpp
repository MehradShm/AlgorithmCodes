#include <iostream>
using namespace std;

const int maxn=(2*1000*1000)+10;
int a[maxn];
int n,k;

int Delete(int x,int p)
{
	int ne=a[x]-p;
	a[p]-=x;
	a[p]+=ne;
	a[ne]-=x;
	a[ne]+=p;
	return ne;
}

pair <int,int> find(int st,int p)
{
	pair<int,int> x;
	if((st+1)%2)
	{
		for(int i=0;i<k-1;i++)
		{
			int g=p;
			p=st;
			st=a[st]-g;
		}
		st=Delete(st,p);
		x.first=st;
		x.second=p;
	}
	else
	{
		int g=p;
		p=st;
		st=g;
		for(int i=0;i<k-2;i++)
		{
			int h=st;
			st=a[h]-p;
			p=h;
		}
		int u=Delete(st,p);
		st=p;
		p=u;
		x.first=st;
		x.second=p;
	}
	return x;
}
int main()
{
	cin >> n >> k;
	if(k==1)
	{
		cout << n << endl;
		return 0;
	}
	a[0]=n;
	a[n-1]=n-2;
	for(int i=1;i<n-1;i++)
		a[i]=2*i;
	int tedad=n , s=0 , p=n-1;
	while(tedad>1)
	{
		pair<int,int> z;
		z=find(s,p);
		s=z.first;
		p=z.second;
		tedad--;
	}
	cout << s+1 << endl;
}
