#include <iostream>
#include <algorithm>
using namespace std;
long long a[5] , b[100000];

int Check(long long x, long long y)
{
	b[0]=max(x,y);
	b[1]=min(x,y);
	long long bmm=-1;
	for(int i=2;;i++)
	{
		b[i]=b[i-2]%b[i-1];
		if(b[i]==0)
		{
			bmm=b[i-1];
			break;
		}
	}
	return bmm;
			
}

int main()
{
	long long l , r;
	cin >> l >> r;
	for(long long  i=l;i<=r;i++)
		for(long long j=l;j<=r;j++)
			for(long long k=l;k<=r;k++)
			{
				if(i!=j and j!=k and i!=k)
				{
					if(Check(i,j)==1)
					{
						if(Check(j,k)==1)
							if(Check(i,k)>1)
							{
								a[0]=i;
								a[1]=j;
								a[2]=k;
								cout << Check(i,k) << " ## " << endl;
								sort(a,a+3);
								cout << a[0] << " " << a[1] << " " << a[2] << endl;
								return 0;
							}
					}
				}
			}
	cout << "-1" << endl;
	
}
