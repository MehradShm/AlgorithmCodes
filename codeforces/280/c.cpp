#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> f,s;

int a[1000000];
int main()
{
	int n , m , maxi=0;
	long long ma=0 , mb=0 , me=0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		f.push_back(x);
	}
	cin >> m;
	for(int i=0;i<m;i++)
	{
		int k;
		cin >> k;
		s.push_back(k);
	}
	sort(f.begin(),f.end());
	sort(s.begin(),s.end());
	for(int i=0;i<f.size();i++)
		for(int j=0;j<s.size();j++)
			if(i==0 and j==0)
			{
				if(s[j]>=f[i])
				{
					int sa=0,sb=0;
					sb=n*3;
					sa=(i*2)+((n-i)*3);
					if(maxi<sa-sb)
					{
						maxi=sa-sb;
						ma=sa;
						mb=sb;
					}
					else if(maxi==sa-sb)
						if(ma<sa)
						{
							ma=sa;
							mb=sb;
						}
				}
			}
			else if(i==0)
			{
				if(s[j]!=s[j-1])
					if(s[j]>=f[i])
					{
						int sa=0,sb=0;
						sb=n*3;
						sa=(i*2)+((n-i)*3);
						if(maxi<sa-sb)
						{
							maxi=sa-sb;
							ma=sa;
							mb=sb;
						}
						else if(maxi==sa-sb)
							if(ma<sa)
							{
								ma=sa;
								mb=sb;
							}
					}
			}
			else if(j==0)
			{
				if(f[i]!=f[i-1])
					if(s[j]>=f[i])
					{
						int sa=0,sb=0;
						sb=n*3;
						sa=(i*2)+((n-i)*3);
						if(maxi<sa-sb)
						{
							maxi=sa-sb;
							ma=sa;
							mb=sb;
						}
						else if(maxi==sa-sb)
							if(ma<sa)
							{
								ma=sa;
								mb=sb;
							}
					}
			}
			else
			{
				if(f[i]!=f[i-1])
					if(s[j]!=s[j-1])
						if(s[j]>=f[i])
						{
							int sa=0,sb=0;
							sb=n*3;
							sa=(i*2)+((n-i)*3);
							if(maxi<sa-sb)
							{
								maxi=sa-sb;
								ma=sa;
								mb=sb;
							}
							else if(maxi==sa-sb)
								if(ma<sa)
								{
									ma=sa;
									mb=sb;
								}
						}
			}
	cout << ma << ":" << mb << endl;
}
