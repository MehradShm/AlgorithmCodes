#include <iostream>
using namespace std;

int a[105] , b[105] , ans[105];
int n;

void copy()
{
	for(int i=0;i<n;i++)
		ans[i]=a[i];
}
void check()
{
	for(int i=0;i<n;i++)
	{
		if(ans[i]>a[i])
			copy();
		else if(ans[i]<a[i])
			break;
	}
}
void sum()
{
	for(int i=0;i<n;i++)
	{
		a[i]++;
		a[i]%=10;
	}
}
void shift()
{
	for(int i=0;i<n;i++)
		b[(i+1)%n]=a[i];
	for(int i=0;i<n;i++)
		a[i]=b[i];

}	
int main()
{
	cin >> n;
	char c[1005];
	cin >> c;
	for(int i=0;i<n;i++)
	{
		a[i]=c[i]-'0';
		ans[i]=c[i]-'0';
	}
	for(int i=0;i<n;i++)
	{
		check();
		for(int j=0;j<10;j++)
		{
			sum();
			check();
		}
		shift();
	}
	for(int i=0;i<n;i++)
		cout << ans[i];
	cout << endl;
}
