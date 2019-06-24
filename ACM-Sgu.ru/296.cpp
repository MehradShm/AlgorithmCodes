#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1005;
char c[maxn];
int a[maxn] , b[maxn];

int main()
{
	fill(a,a+1001,-1);
	int k , te=0;
	cin >> c >> k;
	int t=strlen(c);
	for(int i=0;i<t;i++)
		a[i]=c[i]-'0';
	int s=k;
	for(int j=0;j<s;j++)
	{
		int flag=1;
		for(int i=0;i<t-1 and k and flag;i++)
			if(a[i]!=-1 and a[i]<a[i+1])
			{
				k--;
				a[i]=-1;
				flag=0;
				for(int k=i;k<t-1;k++)
					swap(a[k],a[k+1]);
			}
	}
	if(k)
		for(int j=0;j<10 and k;j++)
			for(int i=0;i<t and k;i++)
				if(a[i]==j and k)
				{
					k--;
					a[i]=-1;
				}

	for(int i=0;i<t;i++)
		if(a[i]!=-1)
			cout << a[i];
	cout << endl;
}
