#include <iostream>

using namespace std;

int sc[10] , hp[10];

int main()
{
	int n , m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		hp[i]=100;
	for(int j=0;j<m;j++)
	{
		int t1 , t2;
		cin >> t1 >> t2;
		if(hp[t1]>0)
		{
			if(hp[t2]>0)
				sc[t1]+=3;
			hp[t2]-=8;
		}
	}
	int k=0;
	for(int i=1;i<=n;i++)
		if(hp[i]>0)
		{
			k=hp[i];
			sc[i]+=(k/2);
		}
	for(int i=1;i<=n;i++)
		cout << hp[i] << " " << sc[i] << endl;
}
