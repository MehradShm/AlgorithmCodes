#include <iostream>
#include <vector>
using namespace std;
vector<int> c[500000];
vector <int> build(int n)
{
	for(int j=2;j<=n;j++)
	{
		int zoj=j/2 , fard=(j+1)/2;
		for(int i=0;i<c[zoj].size();i++)
			c[j].push_back((c[zoj][i]*2));
		for(int i=0;i<c[fard].size();i++)
			c[j].push_back(((c[fard][i]*2)-1));
	}
	vector <int> ans;
	ans=c[n];
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> ans;
	c[1].push_back(1);
	ans=build(n);
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
	cout << endl;
}
