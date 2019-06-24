#include <iostream>
#include <vector>
using namespace std;

vector <int> p;
const int maxn=1000*1000+10;
bool mark[maxn];
vector <pair<int,int> > ans;

int main()
{
	int n;
	cin >> n;
	for(int i=2;i<=n;i++)
		if(mark[i]==0)
			for(int j=2;i*j<=n;j++)
				mark[i*j]=1;
	for(int i=2;i<=n;i++)
		if(mark[i]==0)
			p.push_back(i);
	for(int j=1;j<p.size();j++)
	{
		if(mark[p[0]+p[j]]==0 and p[0]+p[j]<=n)
		{
			pair<int,int> z;
			z.first=p[0];
			z.second=p[j];
			ans.push_back(z);
		}
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i].first << " " << ans[i].second << endl;
}
