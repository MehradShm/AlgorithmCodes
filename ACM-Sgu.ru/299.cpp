//tooye in, adado be soorate b esoorate string migirim va hamashoono be toole 500 miresoonim. bad inaro mirizim too set ke sort mishan.bad be tartib az koochik be bozorg dareshoon miarimo mizarim too vector. hala az avval shoroo mikonim o mirim jolo. agar ye i vojood dashte bashe ke v[i]+v[i+1]>v[i+2] bashe oon javabe masalas. dar gheire insoorat javab 0 0 0 mishe. agaram ye anadaze tekrari bashe , tedadesho negah midarim. in wronge 21 mishe.

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Bignum
{
	int a[550] , size;

	Bignum()
	{
		for(int i=0;i<550;i++)
			a[i]=0;
		size=0;
	}

	void Input(string u)
	{
		bool flag=0;
		for(int i=501;i>=0;i--)
		{
			if(flag==0)
			{
				if(u[i-1]!='0')
				{
					flag=1;
					size=i;
				}
			}
			else
				a[i]=u[i]-'0';
		}

				
	}

	void Normalize()
	{
		for(int i=0;i<size;i++)
		{
			a[i+1]+=(a[i]/10);
			a[i]%=10;
			if(i==size-1)
				if(a[i+1])
					size++;
		}
	}

	void Sum(Bignum b)
	{
		int m=max(size,b.size);
		for(int i=0;i<m;i++)
			a[i]+=b.a[i];
		Normalize();
	}

	int Check(Bignum b)
	{
		int m=max(size,b.size);
		if(size>b.size)
			return 1;
		else if(b.size>size)
			return 0;
		else
			for(int i=m-1;i>=0;i--)
				if(a[i]>b.a[i])
					return 1;
				else if(a[i]<b.a[i])
					return 0;
		return -1;
	}

	Bignum Cross(Bignum b)
	{
		Bignum c;
		c.size=b.size+size-1;
		for(int i=0;i<size;i++)
			for(int j=0;j<b.size;j++)
				c.a[i+j]+=(a[i]*b.a[j]);
		c.Normalize();
		return c;
	}
};

const int maxn=1005;
Bignum b[maxn];
vector<Bignum> v;
set <string> s;
map<string,int> m;

int main()
{
	int n;
	cin >> n;
	//tikhtane adad too vector.
	for(int i=0;i<n;i++)
	{
		string tmp , tmp2;
		cin >> tmp;
		for(int i=500;i>=tmp.size();i--)
			tmp2+="0";
		tmp2+=tmp;
		if(s.find(tmp2)==s.end())
		{
			pair<string , int > ha;
			ha.first=tmp2;
			ha.second=1;
			m.insert(ha);
			s.insert(tmp2);
		}
		else
		{
			m[tmp2]++;
		}
	}
	// khali kardane set too vector.
	while(s.size())
	{
		string k=*s.begin();
		s.erase(k);
		int te=m[k];
		reverse(k.begin(),k.end());
		Bignum x;
		x.Input(k);
		for(int i=0;i<te;i++)
			v.push_back(x);
	}
	// bara peida kardane javab.
	for(int i=0;i<v.size()-2;i++)
	{
		Bignum k=v[i];
		k.Sum(v[i+1]);
		if(k.Check(v[i+2])==1)
		{
			for(int j=v[i].size-1;j>=0;j--)
				cout << v[i].a[j];
			cout << " ";
			for(int j=v[i+1].size-1;j>=0;j--)
				cout << v[i+1].a[j];
			cout << " ";
			for(int j=v[i+2].size-1;j>=0;j--)
				cout << v[i+2].a[j];
			cout << "\n";
			return 0;
		}
	}
	cout << "0" << " " << "0" << " " << "0" << "\n";
	return 0;
}
