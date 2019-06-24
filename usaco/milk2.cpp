/*
ID: shadime1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int maxn=5010;
pair<int,int> t[maxn];

int main()
{
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	int n;
	fin >> n;
	for(int i=0;i<n;i++)
		fin >> t[i].second >> t[i].first;
	sort(t,t+n);
	int sar1=t[n-1].second,tah1=t[n-1].first;
	int ans1=tah1-sar1;
	int ans0=0 , sar0=t[n-1].second , tah0=t[n-1].first;
	for(int i=n-2;i>=0;i--)
		if(t[i].second<sar1 and t[i].first>=sar1)
		{
			sar1=t[i].second;
			ans1=max(ans1,(tah1-sar1));
		}
		else if(t[i].first<sar1)
		{
			sar1=t[i].second;
			tah1=t[i].first;
			ans1=max(ans1,(tah1-sar1));
		}
	for(int i=n-2;i>=0;i--)
		if(t[i].second<sar0 and t[i].first>=sar0)
			sar0=t[i].second;
		else if(t[i].first<sar0)
		{
			ans0=max(ans0,(sar0-t[i].first));
			tah0=t[i].first;
			sar0=t[i].second;
		}
	fout << ans1 << " " << ans0 << endl;
}
