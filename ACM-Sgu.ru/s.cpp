#include <iostream>
#include <vector>
using namespace std;

vector<int> c;

int main()
{
	c.push_back(3);
	c.push_back(1);
	c.push_back(2);
	cout << c.back() << " ## " << c.front() << endl;
}
