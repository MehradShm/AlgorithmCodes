/*
ID: shadime1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
pair<pair<int,int>,string >  x[15];
pair<pair<string,int>,pair<int,int> > s[15];

int main()
{
	ifstream fin ("gift1.in");
	ofstream fout ("gift1.out");
	int n;
	fin >> n;
	for(int i=0;i<n;i++)
		fin>> x[i].second;
	for(int i=0;i<n;i++)
	{
		fin >> s[i].first.first;
		for(int j=0;j<n;j++)
			if(x[j].second==s[i].first.first)
			{
				s[i].first.second=j;
				break;
			}
		int f=s[i].first.second;
		fin >> s[i].second.first >> s[i].second.second;
		x[f].first.first=s[i].second.first;
		int r , t;
		if(s[i].second.first)
		{
			r=(s[i].second.first/s[i].second.second);
			t=(s[i].second.first%s[i].second.second);
		}
		else
		{
			r=0;
			t=0;
		}
		x[f].first.second+=t;
		for(int j=0;j<s[i].second.second;j++)
		{
			string g;
			fin >> g;
			for(int k=0;k<n;k++)
				if(g==x[k].second)
				{
					x[k].first.second+=r;
					break;
				}
		}
	}
	for(int i=0;i<n;i++)
		fout << x[i].second << " " << (x[i].first.second-x[i].first.first) << endl;
}
