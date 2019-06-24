#include <iostream>
using namespace std;

// The mysterious function inside the blackbox!
int process(long long x)
{
  	int y = 0;
  	if (x % 2)
		  return -1;
	for (x = x / 2; x > 1; x = x / 2) 
	{
		int b = (x + 1) % 2;
	   	int k = 0;
   		for (int i=y+2; i>2; i--)
   		  	k++;
   		y += k;
   		y += b;
  	}
  	return y;
}

int main() 
{
	long long alpha;
  	cin >> alpha;
  	long long output = process(alpha);
	cout << output << endl;
	return 0;
}
