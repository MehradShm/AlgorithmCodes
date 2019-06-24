/*
ID: shadime1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
int n;
int a[10] , b[100];

int CP(int size)
{
	int x=0;
	if(size%2==1)
		x=1;
	if(x==0)
		for(int i=0;i<=((size-1)/2);i++)
			if(b[i]!=b[size-i-1])
				return 0;
	if(x==1)
		for(int i=0;i<(size/2);i++)
			if(b[i]!=b[size-i-1])
				return 0;
	return 1;
} 

int main()
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	fin >> n;
	for(int i=1;i<=300;i++)
	{
		int x=i;
		int k=x , sa=0 , sb=0;
		while(x>=n)
		{
			a[sa]=x%n;
			x/=n;
			sa++;
		}
		if(x>0)
		{
			a[sa]=x;
			sa++;
		}
		k*=k;
		while(k>=n)
		{
			b[sb]=k%n;
			k/=n;
			sb++;
		}
		if(k>0)
		{
			b[sb]=k;
			sb++;
		}
		if(CP(sb))
		{
			for(int i=sa-1;i>=0;i--)
				if(a[i]==10)
					fout << 'A';
				else if(a[i]==11)
					fout << 'B';
				else if(a[i]==12)
					fout << 'C';
				else if(a[i]==13)
					fout << 'D';
				else if(a[i]==14)
					fout << 'E';
				else if(a[i]==15)
					fout << 'F';
				else if(a[i]==16)
					fout << 'G';
				else if(a[i]==17)
					fout << 'H';
				else if(a[i]==18)
					fout << 'I';
				else if(a[i]==19)
					fout << 'J';
				else
					fout << a[i];
			fout << " ";
			for(int i=sb-1;i>=0;i--)
				if(b[i]==10)
					fout << 'A';
				else if(b[i]==11)
					fout << 'B';
				else if(b[i]==12)
					fout << 'C';
				else if(b[i]==13)
					fout << 'D';
				else if(b[i]==14)
					fout << 'E';
				else if(b[i]==15)
					fout << 'F';
				else if(b[i]==16)
					fout << 'G';
				else if(b[i]==17)
					fout << 'H';
				else if(b[i]==18)
					fout << 'I';
				else if(b[i]==19)
					fout << 'J';
				else
					fout << b[i];
			fout << endl;
		}
	}
}
