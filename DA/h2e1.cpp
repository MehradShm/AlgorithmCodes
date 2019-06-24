#include<iostream>

using namespace std;

const int MAXN=10005 , MAXM=2005;
int ans[MAXN][MAXM];
int inp[MAXN];

int main()
{
  int n;
  cin >> n;
  inp[0]=2000;
  for(int i=1;i<=n;i++)
  {
    cin >> inp[i];
  }
  for(int i=0;i<=2000;i++)
  {
    ans[0][i]=0;
    ans[1][i]=1;
  }
  for(int i=2;i<=n;i++)
  {
    for(int j=0;j<=2000;j++)
    {
      int case1=0 , case2=0;

      //Dont Pick i;
      case1=ans[i-1][inp[i]];

      //pick i;
      if(j>=inp[i])
      {
        case2=ans[i-1][j-inp[i]]+1;
      }
      else
      {
        int k=j-inp[i] , index=i-1;
        while(k<0)
        {
          k+=inp[index];
          index--;
        }
        if(index==-1)
        {
          case2=1;
        }
        else if(index>=0)
        {
          case2=ans[index][k]+1;
        }
      }
      ans[i][j]=max(case1,case2);
    }
  }
  cout << ans[n][0] << endl;
}
