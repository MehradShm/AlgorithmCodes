#include <iostream>
using namespace std;
const int MAXN=200005;
char c[MAXN];
int ans[MAXN];
int n;

int Find(int x)
{
  // 1 -> (  ) , 2 -> [ ] , 3 -> < > , 4 -> {}
  int count1=0 , count2=0 , count3=0 , count4=0;
  int index=x+1;
  if(c[x]=='[')
  {
    count2=1;
    while( count2  && count1>=0 && count3>=0 && count4>=0 && index<n)
    {
      //cerr << x << " DAFAQ " <<  index << " !! " << count2 << endl;
      if(c[index]=='(') {count1++;}
      else if(c[index]==')'){count1--;}
      else if(c[index]=='['){count2++;}
      else if(c[index]==']'){count2--;}
      else if(c[index]=='<'){count3++;}
      else if(c[index]=='>'){count3--;}
      else if(c[index]=='{'){count4++;}
      else if(c[index]=='}'){count4--;}
      index++;
    }
    //cerr << x << ": " << count1 << " @ " << count2 << " @ " << count3 << " @ " << count4 << endl;
  }
  else if(c[x]=='(')
  {
      count1=1;
      while( count1  && count2>=0 && count3>=0 && count4>=0 && index<n)
      {
        if(c[index]=='(') {count1++;}
        else if(c[index]==')') {count1--;}
        else if(c[index]=='[') {count2++;}
        else if(c[index]==']') {count2--;}
        else if(c[index]=='<') {count3++;}
        else if(c[index]=='>') {count3--;}
        else if(c[index]=='{') {count4++;}
        else if(c[index]=='}') {count4--;}
        index++;
      }
  }
    else if(c[x]=='<')
    {
      count3=1;
      while( count3  && count2>=0 && count1>=0 && count4>=0 && index<n)
      {
        if(c[index]=='(') {count1++;}
        else if(c[index]==')') {count1--;}
        else if(c[index]=='[') {count2++;}
        else if(c[index]==']') {count2--;}
        else if(c[index]=='<') {count3++;}
        else if(c[index]=='>') {count3--;}
        else if(c[index]=='{') {count4++;}
        else if(c[index]=='}') {count4--;}
        index++;
      }
    }
    else if(c[x]=='{')
    {
      count4=1;
      while( count4  && count2>=0 && count3>=0 && count1>=0 && index<n)
      {
        if(c[index]=='(') {count1++;}
        else if(c[index]==')') {count1--;}
        else if(c[index]=='[') {count2++;}
        else if(c[index]==']') {count2--;}
        else if(c[index]=='<') {count3++;}
        else if(c[index]=='>') {count3--;}
        else if(c[index]=='{') {count4++;}
        else if(c[index]=='}') {count4--;}
        index++;
      }
    }
    if(count1==0 && count2==0 && count3==0 && count4==0)
    {
        return (index-1);
    }
    else
    {
      return -1;
    }
}
int main()
{
  cin >> n;
  cin >> c;

  for(int i=n-1;i>=0;i--)
  {
      if(c[i]==']' || c[i]==')' || c[i]=='>' || c[i]=='}')
      {
        ans[i]=0;
      }
      else
      {
        int k=Find(i);
          //cerr << i << ": " << k << " LOL " << endl;
        if(k>=0)
        {
          if(k+1<n)
          {
            ans[i]=(k-i+1)+ans[k+1];
          }
          else
          {
            ans[i]=(k-i+1);
          }
        }
        else
        {
          ans[i]=0;
        }
      }
  }
  for(int i=0;i<n;i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
