#include<iostream>
using namespace std;
int a[11000],print[11000],adadj[11000],ans[11000];
bool mark[11000],mark2[11000];
void Copy(int p)
{
	for(int i=0;i<p;i++)
		mark2[i]=mark[i];
}
int main()
{
	int n , p , b;
	cin >> n >> p >> b;
	mark[0]=1;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		Copy(p);
		for(int j=0;j<p;j++)
		{
			if(mark2[j])
			{				
				int temp1=j,temp2=(a[i]+temp1)%p;
				while(!mark2[temp2])
				{
					mark[temp2]=1;
					adadj[temp2]=i;
					ans[temp2]=temp1;
					temp1=temp2;
					temp2=(temp2+a[i])%p;
				}
			}
		}
	}
	if(mark[b]==0)
		cout << "NO" << endl;
	else
	{
		int b1=b;
		while(b1>0)
		{
			print[adadj[b1]]++;
			b1=ans[b1];
		}
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
			cout<<print[i]<<" ";
	}
}

