#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
pair<int , int> a[2010];
vector<int>ans[5];
int b[2010];
int main()
{
	int n , t=0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i].first;
		a[i].second=i+1;
		b[a[i].first]++;
	}
	int bt=0, ba=0 , bt1=0 , ba1=0;
	for(int i=1;i<=10;i++)
	{
		if(b[i]>bt)
		{
			bt=b[i];
			ba=i;
		}
	}
	if(bt<2)
		cout << "NO" << endl;
	else if(bt==2)
	{
		for(int i=1;i<=2000;i++)
			if(i!=ba and b[i]>bt1)
			{
				bt1=b[i];
				ba1=i;
			}
		if(bt1<2)
			cout << "NO" << endl;
		else if(bt1==2)
		{
			sort(a,a+n);
			int x1=min(ba,ba1);
			int x2=max(ba,ba1);
			for(int i=0;i<n;i++)
				ans[t].push_back(a[i].second);
			t++;
			cout << "Yes" << endl;
			for(int i=0;i<n;i++)
			{
				if(a[i].first==x1)
				{
					a[i].first=0;
					swap(a[i],a[i+1]);
				}
				ans[t].push_back(a[i].second);
			}
			t++;
			for(int i=0;i<n;i++)
				if(a[i].first==0)
				{
					a[i].first=x1;
				}
			int flag=0;
			sort(a,a+n);
			for(int i=0;i<n;i++)
			for(int i=0;i<n;i++)
			{
				if(a[i].first==x2)
					if(flag==0)
					{
						swap(a[i],a[i+1]);
						flag=1;
					}
				ans[t].push_back(a[i].second);
			}
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<n;j++)
					cout << ans[i][j]<< " ";
				cout << endl;
			}
		}
	}
	else if(bt>2)
	{
		sort(a,a+n);
		int s=0;
		for(int i=0;i<n;i++)
			if(a[i].first==ba)
			{
				s=a[i].second;
				break;
			}
		for(int i=0;i<n;i++)
			ans[t].push_back(a[i].second);
		t++;
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(flag==0)
				if(a[i].second==s)
				{
					flag=1;
					swap(a[i],a[i+1]);
				}
			ans[t].push_back(a[i].second);
		}
		t++;
		flag=0;
		for(int i=0;i<n;i++)
		{
			if(flag==0)
				if(a[i].second==s)
				{
					flag=1;
					swap(a[i],a[i+1]);
				}
			ans[t].push_back(a[i].second);
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<n;j++)
				cout << ans[i][j] << " ";
			cout << endl;
		}
	}
}
