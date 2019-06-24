/*
ID: shadime1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
int n , a1 , b1 , c1 ,a2 , b2 , c2 , ans=0;

int Check(int x , int y , int z)
{
	int m1=0 , m2=0 ,  m3=0;
	m1=x-a1;
	m2=y-b1;
	m3=z-c1;
	if(m1<0)
		m1*=-1;
	if(m2<0)
		m2*=-1;
	if(m3<0)
		m3*=-1;
	if((m1==2 or m1==1 or m1==0 or m1==n-1 or m1==n-2) and (m2==2 or m2==1 or m2==0 or m2==n-1 or m2==n-2) and (m3==2 or m3==1 or m3==0 or m3==n-1 or m3==n-2))
		return 1;
	m1=x-a2;
	m2=y-b2;
	m3=z-c2;
	if(m1<0)
		m1*=-1;
	if(m2<0)
		m2*=-1;
	if(m3<0)
		m3*=-1;
	if((m1==2 or m1==1 or m1==0 or m1==n-1 or m1==n-2) and (m2==2 or m2==1 or m2==0 or m2==n-1 or m2==n-2) and (m3==2 or m3==1 or m3==0 or m3==n-1 or m3==n-2))
		return 1;
	return 0;


}

int main()
{
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	fin >> n;
	fin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(Check(i,j,k))
					ans++;
	fout << ans << endl;
}
