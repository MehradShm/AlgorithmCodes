#include <iostream>
#include <vector>
using namespace std;
char a[5]={'A','B','C','D','E'};
vector <string> c[10];
c[5].push_back("A");
int main()
{
	string s;
	cin >> s;
	c[5].push_back("A");
	cout << s << endl;
	cout << s+a[0]+a[3] << endl;
}
