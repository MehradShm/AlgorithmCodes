#include <iostream>
#include <algorithm>
using namespace std;

int a[6];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	if(n==0)
	{
		cout << "YES" << endl;
		cout << "1" << endl;
		cout << "1" << endl;
		cout << "3" << endl;
		cout << "3" << endl;
		return 0;
	}
	if(n==1)
	{
		if(a[0]==1)
		{
			cout << "YES" << endl;
			cout << "2" << endl;
			cout << "2" << endl;
			cout << "3" << endl;
			return 0;
		}
		if(a[0]==2)
		{
			cout << "YES" << endl;
			cout << "1" << endl;
			cout << "2" << endl;
			cout << "3" << endl;
			return 0;
		}
		if(a[0]==3)
		{
			cout << "YES" << endl;
			cout << "1" << endl;
			cout << "2" << endl;
			cout << "2" << endl;
			return 0;
		}
		cout << "NO" << endl;
	}
	if(n==2)
	{
		if(a[0]==1 and a[1]==1)
		{
			cout << "YES" << endl;
			cout << "3" << endl;
			cout << "3" << endl;
			return 0;
		}
		if(a[0]==1 and a[1]==2)
		{
			cout << "YES" << endl;
			cout << "2" << endl;
			cout << "3" << endl;
			return 0;
		}
		if(a[0]==1 and a[1]==3)
		{
			cout << "YES" << endl;
			cout << "1" << endl;
			cout << "3" << endl;
			return 0;
		}
		if(a[0]==2 and a[2]==2)
		{
			cout << "YES" << endl;
			cout << "1" << endl;
			cout << "3" << endl;
			return 0;
		}
		if(a[0]==2 and a[1]==3)
		{
			cout << "YES" << endl;
			cout << "1" << endl;
			cout << "2" << endl;
			return 0;
		}
		if(a[0]==3 and a[1]==3)
		{
			cout << "YES" << endl;
			cout << "1" << endl;
			cout << "1" << endl;
			return 0;
		}
		cout << "NO" << endl;
	}
	if(n==3)
	{
		if(a[1]!=2)
		{
			if(a[1]==1)
			{
				cout << "YES" << endl;
				cout << "3" << endl;
				return 0;
			}
			else
			{
				cout << "YES" << endl;
				cout << "1" << endl;
				return 0;
			}
		}
		else
		{
			if(a[0]==2 and a[2]==3)
			{
				cout << "YES" << endl;
				cout << "1" << endl;
				return 0;
			}
			else
			{
				cout << "YES" << endl;
				cout << "3" << endl;
				return 0;
			}
		}
		cout << "NO" << endl;
	}
	if(n==4)
	{
		int t1=(a[0]+a[1]+a[2]+a[3])/4;
		int t2=(a[1]+a[2])/2;
		int t3=a[3]-a[0];
		if(t1==t2 and t2==t3)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
}
