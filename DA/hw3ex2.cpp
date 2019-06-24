#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=500 + 5 , maxk = 100 + 5;
long long k[maxn] , sump[maxn],sumw[maxn],order[maxn][maxk];
pair<long long , long long> pw[maxn][maxk] , sumin[maxn],ein[maxn][maxk];

int main()
{
  long long ans = 0 , time = 0 , counter = 1 , n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    cin >> k[i];
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<k[i];j++)
    {
      cin >> pw[i][j].first;
      sump[i]+=pw[i][j].first;
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<k[i];j++)
    {
      cin >> pw[i][j].second;
      sumw[i]+=pw[i][j].second;
      ein[i][j].first=((double)pw[i][j].first)/(double)pw[i][j].second;
      ein[i][j].second=j;
    }
  }
  for(int i=0;i<n;i++){
    sumin[i].first=((double)sump[i])/(double)sumw[i];
    sumin[i].second=i;
  }
  sort(sumin,sumin+n);
  for(int i=0;i<n;i++){;
    sort(ein[sumin[i].second],ein[sumin[i].second]+k[sumin[i].second]);
    for(int j=0;j<k[sumin[i].second];j++)
    {
      int ti=sumin[i].second , tj=ein[sumin[i].second][j].second;
      time+=pw[ti][tj].first;
      ans+=time*pw[ti][tj].second;
      order[ti][tj]=counter++;
    }
  }
  cout << ans << endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<k[i];j++)
    {
      cout << order[i][j] << " ";
    }
  }
  cout << endl;
  return 0;
}
