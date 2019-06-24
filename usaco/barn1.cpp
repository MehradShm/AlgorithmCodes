/*
ID: shadime1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
const int maxs=205;
bool a[maxs];
const int maxm=55;

int main()
{
	ifstream fin ("barn1.in");
	ofstream fout ("barn1.out");
	int m ,s , c ;
	fin >> m >> s >> c;
	for(int i=1;i<=c;i++)
	{
		int x;
		fin >> x;
		a[x]=1;
	}
	pair<int,int> bb;
	int total=0 , tedad=0 , bt=0;
	int start=-1 , end;
	for(int i=1;;i++)
		if(a[i]==0)
		{
			total++;
			a[i]=1;
		}
		else
			break;
	for(int i=s;;i--)
		if(a[i]==0)
		{
			total++;
			a[i]=1;
		}
		else
			break;

	for(int j=0;j<=m-2;j++)
	{
		tedad=0;
		bt=0;
		for(int i=1;i<s+1;i++)
		{
			if(a[i]==0)
			{
				if(start==-1)
				{
					start=i;
					tedad++;
				}
				else
				{
					tedad++;
					if(i==s)
					{
						end=s+1;
						if(tedad>bt)
						{
							bt=tedad;
							bb.first=start;
							bb.second=end;
						}
					}

				}
			}
			else
			{
				if(start!=-1)
				{
					end=i;
					if(tedad>bt)
					{
						bt=tedad;
						bb.first=start;
						bb.second=end;
					}
					start=-1;
					tedad=0;
				}
			}
		}
		total+=bt;
		for(int i=bb.first;i<bb.second;i++)
			a[i]=1;
	}
	fout << s-total << endl;
}
