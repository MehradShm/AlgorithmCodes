#include <iostream>
using namespace std;
int a[3000] , b[15];
int TMabna(int x)
{
	for(int i=0;x>0;i++)
	{
		b[i]=x%2;
		x/=2;
		if(x==1)
		{
			b[i+1]=x;
			return i+2;
		}
	}
}
int Read(int x , int y)
{
	if(b[x])
	{
		int meghdar=0;
		int h=1;
		for(int i=y;i<=x;i++)
		{
			meghdar+=(b[i]*h);
			h*=2;
		}
		return meghdar;
	}
	else
		return -1;
}
int Check(int x , int y)
{
	int p=x-1;
	if(b[p])
	{
		if(y>=x)
			for(int i=y-1-x;i<y;i++)
				if(!b[p]==a[i])
					return 0;
				else
					p--;
		return p;
	}
}
int main()
{
	a[0]=1;
	int delta=0 , tool=1;
	for(int i=2;i<=5;i++)
	{
		int flag=1 , v=0;
		int len=TMabna(i);
		for(int j=1;j+len<=tool;j++)
			if(Read(j,j+len-1)==i)
				flag=0;
		if(flag)
		{
			//cerr << " :: " << endl;
			for(int j=len;j>0;j--)
				if(Check(j,tool))
					v=Check(j,tool);
			cerr << i << " && " << tool << " $$ " << v << " %% " << len << endl;
			if(v<len-1)
			{
				for(int j=len-v-1;j>=0;j--)
				{
					//cerr << " $$ " << endl;
					a[tool]=b[j];
					tool++;
				}
			}
			else
			{
				for(int j=len-1;j>=0;j--)
				{
					a[tool]=b[j];
					tool++;
				}
			}
		}
		for(int j=0;j<15;j++)
			b[j]=0;
	}
	cout << tool << endl;
	for(int i=0;i<tool;i++)
		cout << a[i];
}
