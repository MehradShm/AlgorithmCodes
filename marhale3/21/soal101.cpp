#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 10;

int a[MAX_N][MAX_N];
int n = 6;

int bt(int i, int j)
{
	if ( i==n ) return 1;
	int ans = 0;
	for (int t=0; t<4; ++t)
		if ( a[i][j]==-1 || a[i][j]==t )
		{
			if ( i>0 && j>0 )
				if ( (1<<t)+(1<<a[i-1][j])+(1<<a[i][j-1])+(1<<a[i-1][j-1]) != 15 )
					continue;
			int prev = a[i][j];
			a[i][j] = t;
			int ni = (j==n-1 ? i+1 : i  );
			int nj = (j==n-1 ? 0   : j+1);
			ans += bt(ni, nj);
			a[i][j] = prev;

		}
	return ans;
}

int main()
{
	memset(a, -1, sizeof a);
	a[0][2] = 3;
	a[1][0] = 0;
	a[1][5] = 1;
	a[4][1] = 2;
	a[5][3] = 2;
	cout << bt(0, 0) << endl;
	return 0;
}



