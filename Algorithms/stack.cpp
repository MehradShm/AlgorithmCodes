#include <iostream>
#include <vector>
using namespace std;
vector <int> a,b;
int p[1000];
int Check(int s , int n)
{
	if(s==n-1)
		return 1;
	else
	{
		int bs=b.size() , as=a.size();
		if(bs and p[s]==b[bs-1])
		{
			b.pop_back();
			return Check(s+1 , n);
		}
		else if(as)
		{
			b.push_back(a[as-1]);
			a.pop_back();
			return Check(s , n);
		}
		else
			return 0;
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> p[i];
	for(int i=n;i>0;i--)
		a.push_back(i);
	int s=0;
	if(Check(s , n))
		cout << " Yes " << endl;
	else
		cout << " No " << endl;
}
