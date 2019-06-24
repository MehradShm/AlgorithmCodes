#include <iostream>
using namespace std;
int a[105] , b[105];
int main()
{
	int n , m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
		cin >> b[i];
	int k=1;
	for(int i=0;i<m;i++)
		for(int j=0;j<b[i];j++)
		{
			a[k]++;
			k++;
			if(k==n+1)
				k=1;
		}
	for(int i=1;i<n;i++)
		if(a[i]==a[i+1]+1)
		{
			cout << i << endl;
			return 0;
		}
	cout << "0" << endl;
	return 0;
}
