#include <iostream>
using namespace std;
int main()
{
	int a , b;
	cin >> a >> b;
	if(a==b)
		cout << "infinity" << endl;
	else if(b>a)
		cout << "0" << endl;
	else if(a==0)
		cout << "0" << endl;
	else
	{
		long long ans=0;
		int c=a-b;
		for(int i=b+1;i<=(c/2);i++)
			if(c%i==0)
				ans++;
		if((a/2)!=b or a%b)
		{
			cout << ans+1 << endl;
			return 0;
		}
		cout << ans << endl;
	}
}
