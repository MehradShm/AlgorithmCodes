/*
ID: shadime1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int a[11] , ma[11];

int RFA(int c[] ,int s)
{
	int k=1 , m=0;
	for(int i=0;i<s;i++)
	{
		m+=(k*c[i]);
		k*=10;
	}
	return m;
}

int check(int x)
{
	while(x)
	{
		if(ma[x%10]==0)
			return 0;
		x/=10;
	}
	return 1;
}

int main()
{
	ifstream fin ("crypt1.in");
	ofstream fout ("crypt1.out");
	int n , ans=0;
	fin >>n;
	for(int i=0;i<n;i++)
	{
		fin >> a[i];
		ma[a[i]]=1;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			{
				int me1=(a[i]*100)+(a[j]*10)+a[k];
				for(int h=0;h<n;h++)
					for(int g=0;g<n;g++)
					{
						int me2=(a[h]*10)+a[g];
						int u=(me2%10)*me1;
						if(check(u))
						{
							int y=(me2/10)*me1;
							if(check(y))
								if(check(me1*me2))
									if(me1*me2>=1000 and me1*me2<=9999)
									{
										int v1=me1*me2;
										if(y>=100 and y<1000 and u>=100 and u<1000)
											ans++;
									}
						}
					}
			}
	fout << ans << endl;
}
