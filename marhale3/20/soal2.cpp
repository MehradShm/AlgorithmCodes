#include <iostream>
#include <cstring>
using namespace std;
int p[8];
int Put(int x)
{
	for(int i=0;x>0;i++)
	{
		p[i]=x%10;
		x/=10;
		if(x==0)
			return i+1;
	}
}		
int Check1(int len , string k)
{
	int flag=1 ,flag2=0;
	for(int i=len-1;i>=0;i--)
	{
		for(int j=i+1;flag2!=1 and j<=len-1;j++)
		{
			if(k[j]==k[i])
			{
				if(p[i]==p[j])
					flag2=1;
				else
					return 0;
			}
		}
		flag2=0;
	}
	cerr  << " :1: " << endl;

		return 1;
}
int Check2(int len , string k)
{
	int flag=1 ,flag2=0;
	for(int i=len-1;i>=0;i--)
	{
		for(int j=i+1;flag2!=1 and j<=len-1;j++)
		{
			if(k[j]==k[i])
			{
				if(p[i]==p[j])
					flag2=1;
				else
					return 0;
			}
		}
		flag2=0;
	}
	cerr << " :2: " << endl;

	if(flag)
		return 1;
	else
		return 0;
}
int Check3(int len , string k)
{
	int flag=1 ,flag2=0;
	for(int i=len-1;i>=0;i--)
	{
		for(int j=i+1;flag2!=1 and j<=len-1;j++)
		{
			if(k[j]==k[i])
			{
				if(p[i]==p[j])
					flag2=1;
				else
					return 0;
			}
		}
		flag2=0;
	}
	cerr << " :3: " << endl;
	if(flag)
		return 1;
	else
		return 0;
}
int Check4(int len , string k)
{
	int flag=1 ,flag2=0;
	for(int i=len-1;i>=0;i--)
	{
		for(int j=i+1;flag2!=1 and j<=len-1;j++)
		{
			if(k[j]==k[i])
			{
				if(p[i]==p[j])
					flag2=1;
				else
					return 0;
			}
		}
		flag2=0;
	}
	cerr << " :4: " << endl;

	if(flag)
		return 1;
	else
		return 0;
}
int Check5(int len , string k)
{
	int flag=1 ,flag2=0;
	for(int i=len-1;i>=0;i--)
	{
		for(int j=i+1;flag2!=1 and j<=len-1;j++)
		{
			if(k[j]==k[i])
			{
				if(p[i]==p[j])
					flag2=1;
				else
					return 0;
			}
		}
		flag2=0;
	}
	cerr << " :5: " << endl;

	if(flag)
		return 1;
	else
		return 0;
}
int Check6(int len , string k)
{
	int flag=1 ,flag2=0;
	for(int i=len-1;i>=0;i--)
	{
		for(int j=i+1;flag2!=1 and j<=len-1;j++)
		{
			if(k[j]==k[i])
			{
				if(p[i]==p[j])
					flag2=1;
				else
					return 0;
			}
		}
		flag2=0;
	}
	cerr << " :6: " << endl;

	if(flag)
		return 1;
	else
		return 0;
}
int Check7(int len , string k)
{
	int flag=1 ,flag2=0;
	for(int i=len-1;i>=0;i--)
	{
		for(int j=i+1;flag2!=1 and j<=len-1;j++)
		{
			if(k[j]==k[i])
			{
				if(p[i]==p[j])
					flag2=1;
				else
					return 0;
			}
		}
		flag2=0;
	}
	cerr << " :7: " << endl;

	if(flag)
		return 1;
	else
		return 0;
}
void Clear(int len)
{
	for(int i=0;i<len;i++)
		p[i]=0;
}
int main()
{
	string x="cccbbba" , y="cccbaaa" , z="cbbbaaa" , d="cccbbaa" , e="ccbbbaa" , f="ccbbaaa" , g="abababa";
	int ans=0 , delta=0;
	cin >> delta;
	for(int i=1000000;i<7801389;i++)
	{
		int len=Put(i);
		if(Check1(len,x) or Check2(len,y) or Check3(len,z) or Check4(len,d) or Check5(len,e) or Check6(len,f) or Check7(len,g))
		{
			ans++;
			cerr << i << " :| " << endl;
		}
		Clear(len);
	}
	cout << ans << endl;
	cout << ((ans*ans)%delta) << endl;
}
