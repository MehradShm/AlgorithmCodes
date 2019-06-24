#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=505 , maxk=105;
pair <double,int > eg[maxn][maxk] , ag[maxn]; //each group , all groups
long long k[maxn] , order[maxn][maxk] , w[maxn][maxk] , p[maxn][maxk] , sump[maxn],sumw[maxn];

int main()
{
	long long n , ans=0 , time=0 , counter=1;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> k[i];

	for(int i=0;i<n;i++)
		for(int j=0;j<k[i];j++)
		{
			cin >> p[i][j];
			eg[i][j].second=j;
			sump[i]+=p[i][j];
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<k[i];j++)
		{
			cin >> w[i][j];
			sumw[i]+=w[i][j];
			eg[i][j].first=((double)p[i][j])/((double)w[i][j]);
		}
	for(int i=0;i<n;i++)
	{
		ag[i].first=((double)sump[i])/((double)sumw[i]);
		ag[i].second=i;
	}
	sort(ag,ag+n);
	for(int i=0;i<n;i++)
	{
		
		sort(eg[ag[i].second],eg[ag[i].second]+k[ag[i].second]);
		for(int j=0;j<k[ag[i].second];j++)
		{

			int ti=ag[i].second , tj=eg[ag[i].second][j].second;

			order[ti][tj]=counter++;
			time+=p[ti][tj];
			cerr << ti << " @@@ " << tj << " !!  p:" << p[ti][tj] << " ## w:" << w[ti][tj] << " $$ t: " << time << endl;
			ans+=time*w[ti][tj];
		}
		
	}
	cout << ans << endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<k[i];j++)
			cout << order[i][j] << " ";
	cout << endl;
	return 0;
}		
