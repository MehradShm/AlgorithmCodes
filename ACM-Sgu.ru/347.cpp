#include <iostream>
#include <set>
#include <string>

using namespace std;
set <string> s;

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string k;
		cin >> k;
		s.insert(k);
	}
	while(s.size())
	{
		string k;
		k=*s.begin();
		s.erase(k);
		cout << k;
	}
	cout << endl;
}
