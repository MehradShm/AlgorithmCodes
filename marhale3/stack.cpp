#include <iostream>
#include <vector>
using namespace std;
vector <int> a;
int Big(int x)
{
	int y=a.size();
	for(int j=y-1;;j--)
		if(a.size()==0)
		{
			a.push_back(x);
			return -1;
		}
		else
			if(x>=a[j])
				a.pop_back();
			else
			{
				a.push_back(x);
				return a[j];
			}
}
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int y=0;
		cin >> y;
		int z=Big(y);
		if(z==-1)
			cout << y << " ====> " << " Nadarad " << endl;
		else
			cout << y << " ====> " << z << endl;
		cout << endl;
	}
	return 0;
}
