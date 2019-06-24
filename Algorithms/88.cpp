#include <iostream>
using namespace std;

const int maxn=100;
int a[maxn][maxn] , b[maxn][maxn];
int n , ans=1;

pair<int,int> CP(int x1,int x2 , int y1,int y2)
{
	int s1=0 , s2=0;
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
			if(b[i][j])
			{
				s1=i;
				s2=j;
				break;
			}
	pair<int,int> m;
	if(s1==0)
		m.first=0;
	else
		m.first=s1/(((x1+x2)/2)+1);
	if(s2==0)
		m.second=0;
	else
		m.second=s2/(((y1+y2)/2)+1);
	return m;
}
void Find(int x1 , int x2 , int y1 , int y2)
{
	pair<int,int> t=CP(x1,x2,y1,y2);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			if(i!=t.first or j!=t.second)
			{
				b[((x2+x1)/2)+i][((y2+y1)/2)+j]=1;
				a[((x2+x1)/2)+i][((y2+y1)/2)+j]=ans;
			}
	}
	ans++;
	if(x2-x1>1)
	{
		Find(x1,((x1+x2)/2),y1,((y1+y2)/2));
		Find(x1,((x1+x2)/2),((y1+y2)/2)+1,y2);
		Find(((x1+x2)/2)+1,x2,y1,((y1+y2)/2));
		Find(((x1+x2)/2)+1,x2,((y1+y2)/2)+1,y2);
	}
}
int main()
{
	cin >> n;
	int x,y;
	cin >> x >> y;
	x--;
	y--;
	b[x][y]=1;
	a[x][y]=0;
	int x1=0,x2=n-1,y1=0,y2=n-1;
	Find(x1,x2,y1,y2);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << a[i][j] << " \t ";
		cout << endl;
	}
}
