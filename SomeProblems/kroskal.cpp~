#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n , m , meghdar=0;
const int MAXN=(1000*1000)+10;
int p[MAXN];
vector <pair<int,pair<int,int> > > w;
vector <int> g[MAXN];
vector < pair<int,int> > ans;
void merge(int x , int y)
{
	int s=p[x] , d=p[y];
	if(g[p[x]].size()>=g[p[y]].size())
		while(g[d].size())
		{
			g[s].push_back(g[d][g[d].size()-1]);
			p[g[d][g[d].size()-1]]=s;
			g[d].pop_back();
		}
	else
		while(g[s].size())
		{
			g[d].push_back(g[s][g[s].size()-1]);
			p[g[s][g[s].size()-1]]=d;
			g[s].pop_back();
		}
}
void find()
{
	int tedad=0;
	for(int i=0;i<w.size();i++)
		if(tedad<n-1)
			if(p[w[i].second.first]!=p[w[i].second.second])
			{
				merge(w[i].second.first,w[i].second.second);
				meghdar+=w[i].first;
				ans.push_back(w[i].second);
				tedad++;
			}
	if(tedad<n-1)
		cout << " Impossible " << endl;
	else
	{
		cout << meghdar << endl;
		for(int i=0;i<n-1;i++)
			cout << ans[i].first << " " << ans[i].second << endl;
	}
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int temp1 , temp2 , temp3;
		cin >>temp1>>temp2>>temp3;
		p[temp1]=temp1;
		p[temp2]=temp2;
		if(!g[temp1].size())
			g[temp1].push_back(temp1);
		if(!g[temp2].size())
			g[temp2].push_back(temp2);
		pair <int , int > yal;
		yal.first=temp1;
		yal.second=temp2;
		pair<int,pair<int,int> > s;
		s.first=temp3;
		s.second=yal;
		w.push_back(s);
	}
	sort(w.begin(),w.end());
	find();
}

