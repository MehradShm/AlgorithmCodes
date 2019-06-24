/*
ID: shadime1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int a[100];

int cp(int size)
{
	int x=0;
	if(size%2==1)
		x=1;
	if(x==0)
		for(int i=0;i<=((size-1)/2);i++)
			if(a[i]!=a[size-i-1])
				return 0;
	if(x==1)
		for(int i=0;i<(size/2);i++)
			if(a[i]!=a[size-i-1])
				return 0;
	return 1;
}

int Mabna(int n , int m)
{
	int s=0 , k=n;
	while(n>=m)
	{
		a[s]=n%m;
		n/=m;
		s++;
	}
	if(n>0)
	{
		a[s]=n;
		s++;
	}
	if(cp(s))
		return 1;
	return 0;
}
int Check(int n)
{
	int tedad=0;
	for(int i=2;i<=10;i++)
		tedad+=Mabna(n,i);
	return tedad;
}
		
int main()
{
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	int x , s;
	fin >> x >> s;
	int counter=0;
	for(int i=s+1;counter<x;i++)
	{
		if(Check(i)>1)
		{
			fout << i << endl;
			counter++;
		}
	}
}


