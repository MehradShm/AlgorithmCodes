#include <iostream>
using namespace std;
pair<char,int> c[1500];
int Prime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0 and x!=i)
			return 0;
	return 1;
}
int main()
{
	long long flag=1 , marhale=0 , delta=0 , ans=0;
	cin >> delta;
	c[1].first='L';
	for(int i=1;i<=1389;i++)
		if(Prime(i))
			c[i].first='R';
		else
			c[i].first='L';

	for(long long i=0;;i++)
	{
		flag=0;
		for(int j=1;j<=1389;j++)
			if(c[j].first=='R' and c[j+1].first=='L' and c[j].second==0 and c[j+1].second==0)
			{
				swap(c[j],c[j+1]);
				c[j].second=1;
				c[j+1].second=1;
				flag++;
			}
		if(flag==0)
		{
			marhale=i-1;
			break;
		}
		for(int j=0;j<=1389;j++)
			c[j].second=0;
	}
	ans=(marhale+(marhale*marhale)+(marhale*marhale*marhale));
	cout << (ans%delta) << endl;
}
