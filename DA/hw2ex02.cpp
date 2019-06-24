#include <iostream>
using namespace std;
const int MAXN=5005;

bool is[MAXN][MAXN]; // is sorted
int ans[MAXN][MAXN] , query[MAXN][2];
int a[MAXN];

int main()
{
  int n , q;
  cin >> n >> q;
  for(int i=0;i<n;i++)
  {
    cin >> a[i];
    ans[i][i+1]=1;
    is[i][i+1]=true;
  }
  for(int i=0;i<q;i++)
  {
    cin >> query[i][0] >> query[i][1];
  }
  for(int i=2;i<=n;i++)
  {
    int j = i-2;
    bool flag=true;
    while(j>=0)
    {
      if(a[j]>a[j+1])
      {
        flag=false;
      }
      is[j][i]=flag;
      j--;
    }
  }
  /*
  for(int i=0;i<n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cout << is[i][j] << " ";
    }
    cout << endl;
  }
  */

  for(int i=n-2;i>=0;i--)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(is[i][j])
      {
        ans[i][j]=1;
      }
      else
      {
        int k=(i+j)/2;
        ans[i][j]=ans[i][k]+ans[k][j]+1;
      }
    }
  }
  /*
  for(int i=0;i<n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  */

  for(int i=0;i<q;i++)
  {
    cout << ans[query[i][0]-1][query[i][1]-1] << endl;
  }
  return 0;
}
