#include <iostream>
using namespace std;

int a[30] , b[30] , c[30];

int main()
{
	long long  n1 , m , n2 , ansma=0 , ansmi=0;
	cin >> n1 >> m;
	n2=n1;
	//max
	n1-=(m-1);
	ansma+=((n1*(n1-1))/2);
	//min
	long long  k=n2%m;
	long long s=m-k;
	long long h=n2/m , h1;
	if(n2%m==0)
		ansmi+=(((h*(h-1))/2)*s);
	else
	{
		h1=h+1;
		ansmi+=(((h*(h-1))/2)*s);
		ansmi+=(((h1*(h1-1)/2)*k));
	}
	//output
	cout << ansmi << " " << ansma << endl;
}
