/*
ID: shadime1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int n;
char a[12][12] , b[12][12] , c[12][12], d[12][12];

int t1()
{	
	int x=0;
	for(int i=0;i<n;i++)
		for(int j=n-1;j>=0;j--)
		{
			if(x!=0)
				b[x/n][x%n]=a[j][i];
			else
				b[0][0]=a[j][i];
			x++;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(b[i][j]!=c[i][j])
				return 0;
	return 1;
}
int t2()
{
	t1();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=b[i][j];
	if(t1())
		return 1;
	return 0;
}
int t3()
{
	t1();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=b[i][j];
	t1();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=b[i][j];
	if(t1())
		return 1;
	return 0;
}
void t4()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			b[i][n-j-1]=a[i][j];
}
int t5()
{
	t4();
	int x=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(b[i][j]!=c[i][j])
				x=0;

	if(x)
		return 4;
	else
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=b[i][j];
	if(t1())
		return 5;
	if(t2())
		return 5;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=b[i][j];
	if(t3())
		return 5;
	return 0;
}
int t6()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]!=c[i][j])
				return 0;
	return 1;
}

int main()
{
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	fin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fin >> d[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fin >> c[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=d[i][j];
	if(t1())
	{
		fout << 1 << endl;
		return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=d[i][j];
	if(t2())
	{
		fout << 2 << endl;
		return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=d[i][j];
	if(t3())
	{
		fout << 3 << endl;
		return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=d[i][j];
	int u=t5();
	if(u==4)
	{
		fout << 4 << endl;
		return 0;
	}
	else if(u==5)
	{
		fout << 5 << endl;
		return 0;
	}
	if(t6())
	{
		fout << 6 << endl;
		return 0;
	}
	fout << 7 << endl;
}
