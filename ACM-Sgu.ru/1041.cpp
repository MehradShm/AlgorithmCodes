#include <iostream>
#include <vector>
using namespace std;

const int maxn=150;
vector <int> ans;
int a[maxn][maxn],b[maxn][maxn];
int f,v;

void PBP(int i , int j)
{
	if(i==1)
		return ;
	else
		if(b[i][j]==b[i][j-1])
			PBP(i,j-1);
		else if(b[i][j]==b[i-1][j-1]+a[i][j])
		{
			ans.push_back(j);
			PBP(i-1,j-1);
		}
}

int main()
{
	cin >>f >>v ;
	for(int i=1;i<=f;i++)
		for(int j=1;j<=v;j++)
			cin >> a[i][j];
	b[1][1]=a[1][1];
	for(int i=1;i<=v;i++)
		b[1][i]=max(b[1][i-1],a[1][i]);
	for(int i=2;i<=f;i++)
		for(int j=i;j<=v;j++)
			if(i==j)
				b[i][j]=b[i-1][j-1]+a[i][j];
			else
				b[i][j]=max(b[i][j-1],b[i-1][j-1]+a[i][j]);
	PBP(f,v);
	int k=-15500 , k1=0;
	for(int i=ans.back()-1;i>=1;i--)
		if(a[1][i]>k)
		{
			k=a[1][i];
			k1=i;
		}
	ans.push_back(k1);
	cout << b[f][v] << endl;
	for(int i=f-1;i>=0;i--)
		cout << ans[i] << " ";
	cout << endl;
}
