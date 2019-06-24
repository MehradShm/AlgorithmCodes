/*
ID: shadime1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
const int maxn=5010;
pair <int,int> a[maxn];

int main()
{
	ifstream fin ("milk.in");
	ofstream fout ("milk.out");
	int n , m , cost=0 ,  k=0;
	fin >> n >> m;
	for(int i=0;i<m;i++)
		fin >> a[i].first >> a[i].second;
	sort(a,a+m);
	for(int i=0;n>0;i++)
		if(n>=a[i].second)
			n-=a[i].second;
		else
		{
			a[i].second-=(a[i].second)-n;
			n=0;
			k=i;
		}
	cost=0;
	for(int i=0;i<=k;i++)
		cost+=(a[i].first*a[i].second);
	fout << cost << endl;
}
