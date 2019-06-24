#include <iostream>
using namespace std;
int a[10] , b[15];
int main()
{
	int n=6;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	int flag=0 , x=0 , z=0;
	for(int i=0;i<10;i++)
	{
		if(b[i])
			z++;
		if(b[i]>4)
			flag=1;
		else if(b[i]==4)
			x=1;
	}
	if(flag or x)
	{
		if(flag)
		{
			if(z==1)
				cout << "Elephant" << endl;
			else if(z==2)
				cout << "Bear" << endl;
		}
		else
		{
			if(z==2)
				cout << "Elephant" << endl;
			else if(z==3)
				cout << "Bear" << endl;
		}
	}
	else
		cout << "Alien" << endl;
	return 0;
}
	

