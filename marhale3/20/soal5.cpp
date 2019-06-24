#include <iostream>
#include <algorithm>
using namespace std;
pair <int,int> g[10];
double f[730];
long double Abs(double x)
{
	if(x<0)
		x*=-1;
	return x;
}
void GSort()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3-i;j++)
		if(g[j].first>g[j+1].first)
			swap(g[j],g[j+1]);
		else
			if(g[j].first==g[j+1].first)
				if(g[j].second<g[j+1].second)
					swap(g[j],g[j+1]);
}
long double Score(pair<long double, long double> x , pair<long double,long double> y , int z , int x1 , int x2)
{
	long double d=50-(Abs(x.second-y.second));
	long double chance;
	if(z==0)
	{
		g[x1].first+=3;
		chance=((y.second*(100-d))/((x.second+y.second)*100));
	}
	else if(z==1)
	{
		g[x1].first++;
		g[x2].first++;
		chance=d/100;
	}
	else
	{
		g[x2].first+=3;
		chance=((x.second*(100-d))/((x.second+y.second)*100));
	}
	return chance;
}
int check2()
{
	GSort();
	if(g[3].second==21 or g[2].second==21)
		return 1;
	else
		return 0;
}
int check()
{
	if(check2())
	{
		int l=1;
	//	for(int i=3;i>=0;i--)
	//		cout << (4-i) << " " << g[i].second << " " << g[i].first << " %% " << endl;
	//	cerr << " -------------------------------------------------- " << endl;
	}
	else
	{
	//	for(int i=3;i>=0;i--)
	//		cout << (4-i) << " " << g[i].second << " " << g[i].first << " $$ " << endl;
	//	cerr << " --------------------------------------------------- " << endl;
	}
	if(g[3].second==21 or g[2].second==21)
		return 1;
	else
		return 0;
}
int main()
{
	long double delta;
	cin >> delta;
	g[0].second=7;
	g[1].second=13;
	g[2].second=21;
	g[3].second=30;
	int matloob=0;
//	for(int i=0; i<3; i++)
//		cout<< Score(g[0], g[1], i, 0, 1) << endl;
	//return 0;
	long double s1 , s2 , s3 ,s4 ,s5 , s6 , ans=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				for(int a=0;a<3;a++)
					for(int b=0;b<3;b++)
						for(int c=0;c<3;c++)
						{
							for(int o=0;o<4;o++)
								g[o].first=0;
							g[0].second=7;
							g[1].second=13;
							g[2].second=21;
							g[3].second=30;

							s1=Score(g[0],g[1],i,0,1);
							s2=Score(g[0],g[2],j,0,2);
							s3=Score(g[0],g[3],k,0,3);
							s4=Score(g[1],g[2],a,1,2);
							s5=Score(g[1],g[3],b,1,3);
							s6=Score(g[2],g[3],c,2,3);
							if(check())
							{
								f[matloob]=s1*s2*s3*s4*s5*s6;
								matloob++;
							}
							
						}
	for(int i=0;i<matloob;i++)
		ans+=f[i];
	cout << matloob << endl;
	cout << ans << endl;
	cout << (ans*(delta*delta)) << endl;
}
