#include <iostream>
#define int long long
using namespace std;
const int maxn=30;
int t[maxn] , tp[maxn] , m[maxn];
int Check(int x)
{
	for(int i=0;i<maxn;i++)
		if(x>tp[i] and x<=tp[i+1])
			return i+1;
}
int mp(int x , int k,int s,int u)
{ 
	int size=u-1;
	while(x>0)
	{
		m[size]=(x%10);
		x/=10;
		size--;
	}
	size=u;
	if(s)
	{
		m[size]=k;
		size++;
		for(int i=size-2;i>=0;i--)
		{
			m[size]=m[i];
			size++;
		}
	}
	else
		for(int i=size-1;i>=0;i--)
		{
			m[size]=m[i];
			size++;
		}
	return size;
}
int T(int x)
{
	x--;
	int s=1;
	for(int i=0;i<x;i++)
		s*=10;
	return s;
}
void findpalindrom(int x , int jaigah)
{
	int size;
	if(jaigah%2)
	{
		int o=x%10 , k=x/10;
		int f1=T((jaigah/2));
		f1+=k;
		size=mp(f1,o,1,(jaigah/2));
	}
	else
	{
		int f1=T((jaigah/2));
		f1+=x;
		size=mp(f1,0,0,(jaigah/2));
	}
	for(int i=0;i<size;i++)
		cout << m[i];
	cout << endl;
}
#undef int
int main()
#define int long long
{
	int n;
	cin >> n;
	t[0]=0;
	t[1]=9;
	tp[0]=0;
	tp[1]=9;
	for(int i=2;i<maxn;i++)
		t[i]=t[i-1]*10;
	for(int i=2;i<maxn;i++)
		if(i%2==0)
			tp[i]=t[(i/2)]+tp[i-1];
		else
			tp[i]=(t[(i/2)]*10)+tp[i-1];
	int jaigah=Check(n);
	if(jaigah==1)
		cout << n << endl;
	else
	{
		n-=(tp[jaigah-1]+1);
		findpalindrom(n,jaigah);
	}
	return 0;
} 
