#include <iostream>
using namespace std;
pair<int,int> b[20];
pair<int, int> c[20];
int Kahesh(int harakat , int size ,int a[] )
{
	for(int i=0;i<size;i++)
		b[i].first=a[i];
	for(int i=0;i<harakat;i++)
	{
		for(int j=1;j<size;j++)
			if(b[j].first<b[j-1].first)
				b[j].second=1;
		int size2=0;
		for (int j=0; j<size; ++j)
			if ( b[j].second==0 )
				c[size2++] = b[j];
		for (int j=0; j<size2; ++j)
			b[j] = c[j];
		size = size2;
		//for(int i=0;i<size;i++)
		//	cout << b[i].first << " ";
		//cout << endl;
	}
	if(size==1)
		return 1;
	else
		return 0;
}
int main()
{
	long long  harekat , delta , matloob=0 , tedad , halat=0;
	cin >> tedad >> harekat;
	int a[tedad];
	a[0]=tedad;
	for(int i=1;i<tedad;i++)
		a[i]=i;
	//cin >> delta;
	do
	{
		halat++;
		if(Kahesh(harekat,tedad,a))
			matloob++;
		for(int i=0;i<tedad;i++)
		{
			b[i].second=0;
			c[i].first=0;
			c[i].second=0;
		}
	}while(next_permutation(a+1,a+tedad));
	cout << matloob%delta << endl;
}
