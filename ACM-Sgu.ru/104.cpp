
#include <iostream>
#include <vector>
using namespace std;
const int maxn=105;
int a[maxn][maxn],b[maxn][maxn];
int inf=-50000;
vector<int> ans;
int f,v;

void PBP(int i,int j)
{
	if(i==0)
		return ;
	else
	{
		if(b[i][j]==b[i][j-1])
			PBP(i,j-1);
		else if(b[i][j]-a[i][j]==b[i-1][j-1])
		{
			ans.push_back(j);
			PBP(i-1,j-1);
		}
	}
}

int main()
{
	cin >> f >> v;
	for(int i=1;i<=f;i++)
		for(int j=1;j<=v;j++)
			cin >> a[i][j];
	for(int i=0;i<=f;i++)
		for(int j=0;j<=v;j++)
			b[i][j]=inf;
	for(int j=0;j<=v;j++)
		b[0][j]=0;
	for(int i=1;i<=f;i++)
		for(int j=i;j<=v;j++)
			b[i][j]=max(b[i][j-1],b[i-1][j-1]+a[i][j]);
	PBP(f,v);
	cout << b[f][v] << endl;
	for(int i=ans.size()-1;i>=0;i--)
		cout << ans[i] << " ";
	cout << endl;
}
