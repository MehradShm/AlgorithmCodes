#include <iostream>
using namespace std;
int d[1000] ,de[1000];
pair <int ,int > e[10000][10000];
void Relax(int n , int x)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j and e[i][j].first)
				if(d[j]>d[i]+e[i][j].second)
				{
					if(x<n-2)
						d[j]=min(d[j],d[i]+e[i][j].second);
					else
					{
						cout << " Dore Manfi " << endl;
					}
				}

}
int main()
{
	int n , m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		d[i]=999999;
	for(int i=0;i<m;i++)
	{
		int temp1 , temp2 , temp3;
		de[temp1]++;
		cin >> temp1 >> temp2 >> temp3;
		e[temp1][temp2].first=1;
		e[temp1][temp2].second=temp3;
	}
	d[1]=0;
	for(int i=0;i<n-1;i++)
		Relax(n , i);
	cout << endl;
	for(int i=1;i<=n;i++)
		cout << d[i] << " ";
	cout << endl;
	
}
