#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[10010];
pair<int,vector<int> > ans[10010];
bool mark[10010] , sp[10010];

int main()
{
	mark[1]=1;
	int n , s=1;
	cin >> n;
	for(int i=2;i<=n;i++)
		if(mark[i]==0)
			for(int j=2;i*j<=n;j++)
				mark[i*j]=1;
	for(int i=1;i<=n;i++)
		if(mark[i]==0)
		{
			p[s]=i;
			s++;
		}
	for(int i=1;i<s;i++)
		if(mark[i]==0)
			sp[p[i]]=1;
	for(int i=2;i<=n;i++)
	{
		if(mark[i]==0 and sp[i])
		{
			ans[i].first=1;
			ans[i].second.push_back(i);
		}
		else
		{
			int x=1000000 , k=0;
			for(int j=2;i-j>=(i/2);j++)
			{
				if(ans[i-j].first and ans[j].first)	
					if(x>ans[i-j].first+ans[j].first)
					{
						x=ans[i-j].first+ans[j].first;
						k=j;
					}
			}
			if(x!=1000000)
				ans[i].first=x;
			for(int j=0;j<ans[k].second.size();j++)
				ans[i].second.push_back(ans[k].second[j]);
			for(int j=0;j<ans[i-k].second.size();j++)
				ans[i].second.push_back(ans[i-k].second[j]);
		}
	}
	if(ans[n].first==1000000)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << ans[n].first << endl;
	sort(ans[n].second.begin(),ans[n].second.end());
	for(int i=ans[n].second.size()-1;i>=0;i--)
		cout << ans[n].second[i] << " ";
	cout << endl;
}
