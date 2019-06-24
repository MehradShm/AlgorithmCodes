/*
ID: shadime1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector <pair<char,int> > x;

int main()
{
	ifstream fin ("ride.in");
	ofstream fout ("ride.out");
	int ta=1 , tb=1;
	string a , b;
	fin >> a >> b;
	for(int i=0;i<26;i++)
	{
		pair<char,int> p;
		p.first=char(('A'-'0')+i+'0');
		p.second=i+1;
		x.push_back(p);
	}
	for(int i=0;i<a.size();i++)
		for(int j=0;j<26;j++)
			if(x[j].first==a[i])
			{
				ta*=x[j].second;
				break;
			}
	for(int i=0;i<b.size();i++)
		for(int j=0;j<26;j++)
			if(x[j].first==b[i])
			{
				tb*=x[j].second;
				break;
			}
	string ans;
	if((ta%47)==(tb%47))
		ans="GO";
	else
		ans="STAY";
	fout << ans << endl;
}
