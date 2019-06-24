#include <iostream>
#include <cstdio>
using namespace std;

int a[50];

int main()
{
	int k ;
	cin >> k;
	for(int i=0;i<k;i++)
	{
		int tmp1;
		cerr << tmp1 << " ### " << endl;
		scanf("%d",&tmp1);
		cerr << tmp1 << " ** " << endl;
	}
	for(int i=0;i<k;i++)
		cout << a[i] << endl;
}
