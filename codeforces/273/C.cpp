#include <iostream>
using namespace std;

long long t=0 , r , g , b;

int ma(int x , int y)
{
	long long tedad=0;
	if(x+y>=3 and (x and y))
	{
		int h=max(x,y) , h1=min(x,y);
		int s=h-h1;
		tedad+=s;
		h-=(s*2);
		h1-=s;
		if(h%3==0)
			tedad+=((h/3)*2);
		else if(h%3==2)
			tedad+=(((h-2)/3)*2)+1;
	}
	return tedad;
}
int main()
{
	cin >> r >> g >> b;
	long long k=min(r,min(b,g));
	r-=k;
	g-=k;
	b-=k;
	t+=k;
	int y1 , y2;
	if(r==0)
	{
		y1=g;
		y2=b;
	}
	else if(g==0)
	{
		y1=r;
		y2=b;
	}
	else
	{
		y1=r;
		y2=g;
	}
	t+=ma(y1,y2);
	cout << t << endl;
}
