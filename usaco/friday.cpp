/*
ID: shadime1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int month1[15]={0,31,59,90,120,151,181,212,243,273,304,334};
int month2[15]={0,31,60,91,121,152,182,213,244,274,305,335};
int year[370];
int sat , sun , mon , tue, wed, thu , fri;

void count(int n)
{
	if(n%400==0 or (n%4==0 and n%100!=0))
	{
		for(int i=2;i<367;i++)
			year[i]=(year[i-1]+1)%7;
		for(int i=0;i<12;i++)
			if(year[month2[i]+13]==0)
				sat++;
			else if(year[month2[i]+13]==1)
				sun++;
			else if(year[month2[i]+13]==2)
				mon++;
			else if(year[month2[i]+13]==3)
				tue++;
			else if(year[month2[i]+13]==4)
				wed++;
			else if(year[month2[i]+13]==5)
				thu++;
			else if(year[month2[i]+13]==6)
				fri++;
		year[1]=(year[366]+1)%7;
	}
	else
	{
		for(int i=2;i<366;i++)
			year[i]=(year[i-1]+1)%7;
		for(int i=0;i<12;i++)
			if(year[month1[i]+13]==0)
				sat++;
			else if(year[month1[i]+13]==1)
				sun++;
			else if(year[month1[i]+13]==2)
				mon++;
			else if(year[month1[i]+13]==3)
				tue++;
			else if(year[month1[i]+13]==4)
				wed++;
			else if(year[month1[i]+13]==5)
				thu++;
			else if(year[month1[i]+13]==6)
				fri++;
		year[1]=(year[365]+1)%7;
	}
}

int main()
{
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	int n;
	fin >> n;
	year[1]=2;
	for(int i=1900;i<1900+n;i++)
		count(i);
	fout <<sat << " " << sun << " " << mon << " " << tue << " " <<wed << " " << thu << " " << fri << endl;
}
