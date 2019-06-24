#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
const int maxn=100*1000+10;
pair<string,string> a[maxn];
set <pair<string,string> > s;
int b[maxn];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin>> a[i].first >> a[i].second;
		pair<string,string> z;
		s.insert(a[i]);
	}
	for(int i=0;i<n;i++)
	{
		cin >> b[i];
		b[i]--;
	}
	sort(a,a+n);
	pair<string,string> f;
	f=*s.begin();
	for(int i=0;i<n;i++)
		cout << a[i].first << " :| " << a[i].second << " :| " << f.first << " :| " << f.second << endl;
	for(int i=0;i<n;i++)
	{
		pair<string,string> h;
		h=*s.begin();
		cout << h.first << " $$$$ " << h.second << endl;
		if(a[b[i]]==h)
		{
			cerr << " TTTT " << endl;
			pair<string,string> t;
			t=*s.begin();
			s.erase(t);
		}
		else
		{
			h=a[b[i]];
			s.erase(h);
			string u;
			u=h.first;
			h.first=h.second;
			h.second=u;
			s.insert(h);
			h=*s.begin();
			cout << h.first << " #### " << h.second << endl;
			if(h.first==a[b[i]].second and h.second==a[b[i]].first)
			{
				pair<string,string> v;
				v=*s.begin();
				cerr <<v.first << " &&&& " << v.second << endl;
				s.erase(s.begin());
				s.erase(s.begin());
				v=*s.begin();
				cerr <<v.first << " **** " << v.second << endl;
			}
			else
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}
