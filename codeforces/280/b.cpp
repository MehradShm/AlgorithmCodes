#include <iostream>
#include <vector>
using namespace std;

long long o[5000000];
vector<long long> k1 , k0;

int main()
{
	int n , man , mos;
	long long sum=0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> o[i];
		sum+=o[i];
		if(o[i]<0)
		{
			k0.push_back(o[i]);
			man++;
		}
		else
		{
			k1.push_back(o[i]);
			mos++;
		}
	}
	if(sum>0)
	{
		cout << "first" << endl;
		return 0;
	}
	else if(sum<0)
	{
		cout << "second" << endl;
		return 0;
	}
	else
	{
		int s=min(k0.size(),k1.size());
		for(int i=0;i<s;i++)
			if(k1[i]<(k0[i]*(-1)))
			{
				cout << "second" << endl;
				return 0;
			}
			else if(k1[i]>(k0[i]*(-1)))
			{
				cout << "first" << endl;
				return 0;
			}
	}
	if(o[n-1]<0)
		cout << "second" << endl;
	else
		cout << "first" << endl;
}
