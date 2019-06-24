#include <iostream>
#include <algorithm>
using namespace std;
pair <double , int> a[1000001];
int Meghdar(int x)
{
	int meghdar=0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			if(i*i==x)
				meghdar+=i;
			else
			{
				meghdar+=i;
				meghdar+=(x/i);
			}
	return meghdar+1;
}
int main()
{
	long long delta;
	int  ans=0 , tedad=0;
	cin >> delta;
	for(int i=1;i<1000000;i++)
	{
		if(i%10000==0)
			cout << i << " ! " << endl;
		int sum=Meghdar(i);
		if(sum>=i)
		{
			a[tedad].second=i;
			a[tedad].first=((double)sum/i);
			tedad++;
		}
	}
	sort(a,a+1000000);
	for(int i=999999;i>999985;i--)
		cout << a[i].second << " ====> " << a[i].first << " ===> " << 1000000-i << endl;
	long long d=498960;
	cout << (((d*d*d)+(d*d))%delta) << endl;
}
