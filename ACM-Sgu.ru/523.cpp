#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool mark[102] , vorood[102];
queue<int> c;
vector<int> ans;
void Move(int n , int f)
{
	if(n==0)
		;
	else
	{
		int k=c.front();
		if(c.front()>=f)
		{
			for(int i=f;i<=c.front();i++)
				if(!mark[i])
					if(vorood[i])
					{
						ans.push_back(i);
						mark[i]=1;
					}
		}
		else
		{
			for(int i=f;i>=c.front();i--)
				if(!mark[i])
					if(vorood[i])
					{
						ans.push_back(i);
						mark[i]=1;
					}
		}
		while(c.size()>0 and mark[c.front()])
		{
			c.pop();
			n--;
		}
		Move(n,k);
	}
}
int main()
{
	int n , f;
	cin >> n >> f;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin >> temp;
		vorood[temp]=1;
		c.push(temp);
	}
	Move(n,f);
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
}
