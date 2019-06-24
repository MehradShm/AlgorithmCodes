#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn=50000;
vector<int>v[maxn];
int num[maxn] , d[maxn];
queue<int> q;
bool mark[maxn];

void BFS()
{
	pair<int,int> best;
	while(q.size())
	{
		int k=q.front();
		q.pop();
		for(int i=0;i<v[k].size();i++)
			if(mark[v[k][i]]==0)
			{
				if((v[k][i]/2)!=(k/2))
					d[v[k][i]]=d[k]+1;
				else
					d[v[k][i]]=d[k];
				mark[v[k][i]]=1;
				q.push(v[k][i]);
			}
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
			for(int j=0;j<(2*n);j++)
			{
				int k=(i/2)*(2*(n-1))+(((i/2)*(2*n))) , f=k+j-((2*n)-1);
				cin >> num[k+j];
				if(j%2)
				{
					v[k+j].push_back(k+j-1);
					v[k+j-1].push_back(k+j);
				}
				if(j and ((k+j)/2!=(k+j-1)/2) and num[k+j]==num[k+j-1])
				{
					v[k+j].push_back(k+j-1);
					v[k+j-1].push_back(k+j);
				}
				if(i and j!=0 and j!=(2*n)-1)
					if(num[k+j]==num[f])
					{
						v[k+j].push_back(f);
						v[f].push_back(k+j);

					}
			}
		else
			for(int j=0;j<((2*n)-2);j++)
			{
				int k=(((i+1)/2)*(2*n))+((i/2)*(2*(n-1))),f=k+j-((2*n)-1);
				cin >> num[k+j];
				if(num[k+j]==num[f])
				{
					v[k+j].push_back(f);
					v[f].push_back(k+j);
				}
				if(j and ((k+j)/2!=(k+j-1)/2) and num[k+j]==num[k+j-1])
				{
					v[k+j].push_back(k+j-1);
					v[k+j-1].push_back(k+j);
				}
				if(j%2)
				{
					v[k+j].push_back(k+j-1);
					v[k+j-1].push_back(k+j);
				}
			}
	}
	q.push(0);
	mark[0]=1;
	d[0]=1;
	BFS();
	int tedad=(((n+1)/2)*n)+((n/2)*(n-1));
	for(int i=tedad-1;i>=0;i--)
		if(min(d[i*2],d[(i*2)+1]))
		{
			cout << min(d[i*2],d[(i*2)+1]) << endl;
			return 0;
		}
}
