#include <iostream>
#include <string>
#include <vector>

using namespace std;

int h[105] , a[105];
vector<pair<pair<string,int>,int> > ans;
bool mark1[105] , mark2[105];

int main()
{
	string n1 , n2;
	cin >> n1;
	cin >> n2;
	int n;
	cin >> n;

	for(int i=0;i<n;i++)
	{
		int min , nu;
		char t , c;
		cin >> min;
		cin>> t;
		cin >> nu;
		cin >> c;
		if(t=='h')
		{
			if(c=='y')
				h[nu]++;
			else
				h[nu]+=2;
			if(mark1[nu]==0)
				if(h[nu]>=2)
				{
					pair<pair<string,int>,int> g;
					g.first.first=n1;
					g.first.second=nu;
					g.second=min;
					ans.push_back(g);
					mark1[nu]=1;
				}
		}
		else
		{
			if(c=='y')
				a[nu]++;
			else
				a[nu]+=2;
			if(mark2[nu]==0)
				if(a[nu]>=2)
				{
					pair<pair<string,int>,int> g;
					g.first.first=n2;
					g.first.second=nu;
					g.second=min;
					ans.push_back(g);
					mark2[nu]=1;
				}
		}
	}
	for(int i=0;i<ans.size();i++)
		cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
}
