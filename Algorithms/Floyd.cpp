#include <iostream>
using namespace std;
int a[500][500][500] , c[500][500];
// arraye a dar asl a[n][n][n] hast vali chon har laye az laye paiinesh update mishe bara kam shodan ordere hafeze mishe az 2 laye estefade kard.
// a[i][j][k]=kamtarin fasele i ta j ba estefade az rasaye 1 ta k.
int main()
{
	int n , m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int temp1 , temp2;
		cin >> temp1 >> temp2;
		c[temp1][temp2]=1;
		c[temp2][temp1]=1;
		a[temp1][temp2][0]=1;
		a[temp2][temp1][0]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				if(c[i][j]==0)
					a[i][j][0]=9999999;
	int x , y;
	cin >> x >> y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				a[j][k][i]=min(a[j][k][i-1],a[j][i][i-1]+a[i][k][i-1]);
	cout << a[x][y][n] << endl;
}
