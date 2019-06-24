#include <iostream>
#include <string>
#include <set>

using namespace std;
set <pair<int,int> > h;
const int maxn=500*101;
int s[maxn] , t[maxn];

int Check(string k)
{
	int sum=0 , sum2=0;
	for(int i=0;i<k.size();i++)
	{
		if(k[i]=='(')
			sum++;
		else if(k[i]==')')
			sum--;
		if(sum<0)
			return 1;
	}
	if(sum!=0)
		return 1;
	return 0;
}

int main()
{
	string k;
	cin >> k;
	int sum=0 ;
	long long ans=0;
	for(int i=0;i<k.size();i++)
		if(k[i]=='?')
			cin >> s[i] >>t[i];
	for(int i=0;i<k.size();i++)
	{
		if(k[i]=='(')
			sum++;
		else if(k[i]==')')
			sum--;
		else if(k[i]=='?')
		{
			k[i]=')';
			sum--;
			ans+=t[i];
			pair<int,int> x;
			x.first=s[i]-t[i];
			x.second=i;
			h.insert(x);
		}
		if(sum<0)
		{
			if(h.size())
			{
				pair<int,int> y=*h.begin();
				h.erase(y);
				k[y.second]='(';
				sum+=2;
				ans+=y.first;
			}
			else
			{
				cout <<"-1" << endl;
				return 0;
			}
		}
	}
	if(Check(k))
	{
		cout << "-1" << endl;
		return 0;
	}
	cout << ans << endl;
	cout << k << endl;
}
