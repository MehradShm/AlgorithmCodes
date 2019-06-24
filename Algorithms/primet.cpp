#include <iostream>
#include <vector>
using namespace std;
int mark[1000] , d[1000];
vector <pair <int,int > > c[1000];
int main()
{
	int n , m , ans=0;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int temp1 , temp2 , temp3;
		cin >> temp1 >> temp2 >> temp3;
		pair <int,int> k , l;
		k.first=temp2;
		k.second=temp3;
		l.first=temp1;
		l.second=temp3;
		c[temp1].push_back(k);
		c[temp2].push_back(l);
	}
	mark[1]=1;
	for(int i=0;i<n-1;i++)
	{
		int min1=999999 , min2=999999;
		for(int j=1;j<=n;j++)
			if(mark[j]==1)
				for(int k=0;k<c[j].size();k++)
					if(mark[c[j][k].first]==0 and c[j][k].second<min1)
					{
						min1=min(min1,c[j][k].second);
						min2=c[j][k].first;
					} 
		mark[min2]=1;
		ans+=min1;
	}
	cout << ans << endl;
}
