#include <iostream>
#include <algorithm>
#include <math>

using namespace std;

const int maxn=1050;
int a[maxn][maxn] , b[maxn][maxn] , p[maxn];

int main()
{
	int n;
	cin >> n;
	int minm=999999 , maxm=0;
	for(int i=0;i<n;i++)
		p[i]=i;
	do{
		for(int i=n-2;i>=0;i--)
			for(int j=i+1;j<n;j++)
				for(int k=i;k<j;k++)
					if(a[i][j]>abs(a[i][k]-a[k+1][j]))
					{
						a[i][j]


	}while(next_permutation())
}
