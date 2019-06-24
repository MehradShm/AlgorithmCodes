#include <iostream>
using namespace std;
const int MAXN=10005;
int ans[MAXN] , inp[MAXN];

int main()
{
  int n;
  cin >> n;
  for(int i=1;i<=n;i++)
  {
    cin >> inp[i];
  }
  ans[0]=0;ans[1]=1;ans[2]=1;
  for(int i=3;i<=n;i++)
  {
    int case_pick=0 , case_npick=0 , delayn=0 , delayp=0 , index=i;

    //Doesn't Pick i
    for(int j=i-1;delayn+inp[j]<=inp[i] && j;j--)
    {
      delayn+=inp[j];
      case_npick++;
      index=j;
    }
    case_npick+=ans[index-1];

    //Does Pick i
    index=i;
    if(inp[i]>inp[i-1])
    {
      index=i-1;
        for(int j=i-2;delayp+inp[j]<=inp[i]-inp[i-1] && j;j--)
        {
          delayp+=inp[j];
          index=j;
        }
        case_pick=ans[index-1]+1;
    }
    else if(inp[i]==inp[i-1]) {case_pick = ans[i-2]+1;}
    else
    {
      index=i-1;
      for(int j=i-2;delayp+inp[j]<=inp[i-1]-inp[i] && j ; j--)
      {
        delayp+=inp[j];
        case_pick++;
        index=j;
      }
        case_pick+=ans[index-1]+1;
    }
    ans[i]=max(case_pick , case_npick);
  }
  cout << ans[n] << endl;
  return 0;
}
