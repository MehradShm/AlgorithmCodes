#include <iostream>
#include <vector>
using namespace std;

const int maxn=10050;
int a[maxn] , mark[maxn];
vector<int> p;

int TA(int x)
{
	int t=0;
	for(int i=0;i<p.size() and x;i++)
		while(x%p[i]==0)
		{
			x/=p[i];
			t++;
		}
	return t;

}

int main()
{
	int n;
	cin >> n;
	mark[1]=1;
	for(int i=2;i<=n;i++)
		if(mark[i]==0)
			for(int j=2;i*j<=n;j++)
				mark[i*j]=1;
	for(int i=2;i<=n;i++)
		if(mark[i]==0)
			p.push_back(i);
	a[1]=1;
	int tc=1;
	for(int i=2;i<=n;i++)
	{
		a[i]=TA(i)+1;
		tc=max(tc,a[i]);
	}
	cout << tc << endl;
	for(int i=1;i<=n;i++)
		cout << a[i] << " ";
	cout << endl;
}
