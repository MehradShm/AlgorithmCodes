#include <iostream>
using namespace std;
long long zarib[10005] , meghdar[10005]; 
int main()
{
	long long x=1 , delta , ans=0 , zaribk=3 , meghdark=1;
	cin >> delta;
	zarib[1]=3;
	meghdar[1]=1;
	for(int i=2;i<=10000;i++)
	{
		zarib[i]=((zarib[i-1]*5)%delta);
		zaribk+=zarib[i];
		zaribk%=delta;
	}
	for(int i=2;i<=10000;i++)
	{
		meghdar[i]=(((meghdar[i-1]*4)+x)%delta);
		x*=2;
		x%=delta;
		meghdark+=meghdar[i];
		meghdark%=delta;
	}
	cerr << meghdar[0] << " " << meghdar[1] << " " << meghdar[2] << " " << meghdar[3] << endl;
	cout << meghdark << " !! " << zaribk << endl;
	ans=(meghdark*zaribk)%delta;
	cout << ans << endl;
}
