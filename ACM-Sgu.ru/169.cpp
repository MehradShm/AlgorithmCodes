#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if(n==1)
		cout << "8" << endl;
	else
	{
		if(n%6==1)
			cout << "4" << endl;
		else if(n%3==1)
			cout << "3" << endl;
		else
			cout << "1" << endl;
	}
}
