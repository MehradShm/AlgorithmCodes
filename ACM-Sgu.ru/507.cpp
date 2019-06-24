// avval bara barga set negah midarim. bara har rase gheire barg oon rasio negah midarim ke bishtarin ozvo too zirshakhash dare. bad hamashoono mirizim tooye oon bozorgtarine. ekhtelafaye jadido hamoon moghe ke ozve jadid varese set mishe hesab mikonim. bara har kasam 2 ta adade min zir shakhe ro az bache hash va minimume ozvaye jadido hengame merge kardan bedast miarimo minimum migirim. hamoonjoori ke maloome inja har kas hadeaksar logn bar jabeja mishe. hala age ordere jabejaii ro ham  logn begirim, order bayad n*logn^2 beshe. logn ham taghriban 15 hast pas logn^2 taghriba mishe 2.25*100, n ham ke mishe . n ham ke hadeaksar 5*10^4 e. pas manteghan nabayad time beshe vali in time mishe.

#include <iostream>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;

// s ke sete bara negahdashtane meghdare barga bara har zirshakhe. bz[i] shomare bargi ro negah midare ke bozorgtarin set ro too zirshakheye rase i dare. 
// p[i] parente rase i e. 

const int maxn=50005;
set<int> s[maxn];
int bz[maxn] , p[maxn] , mark[maxn];
vector<int> v[maxn];
int ans[maxn];
int inf=1000*1000+5;
int n , m;

int Merge(int x , int y)
{
	int mini=9999999;
		for(set<int> :: iterator i=s[y].begin();i!=s[y].end();i++)
		{
			s[x].insert(*i);
			set<int>::iterator t , g;
			t=s[x].find(*i);
			// agar t adade avval bashe faghat bayad ba joloiish check beshe.
			if(*t==*s[x].begin())
			{
				g=t++;
				mini=min(mini,(*t-*g));
			}
			else
			{
				t++;
				// age akhari bashe bayad ba aghabish check beshe
				if(t==s[x].end())
				{
					t--;
					g=t--;
					mini=min(mini,(*g-*t));
				}
				// va agar hich kodoom nabashe bayad ba joloiio aghabish check beshe.
				else
				{
					t--;
					set<int>::iterator t1,t2;
					t1=t++;
					t1--;
					t2=t1++;
					mini=min(mini,(*t-*t1));
					mini=min(*t1-*t2,mini);
				}
			}
		}
	return mini;
}

int DFS(int x)
{
	mark[x]=1;
	int ms=0;
	ans[x]=inf;
	for(int i=0;i<v[x].size();i++)
		if(mark[v[x][i]]==0)
		{
			int r=DFS(v[x][i]);
			// donbale bozorgtarin sete zir shakhe khodeshe.
			if(r>ms)
			{
				bz[x]=bz[v[x][i]];
				ms=r;
			}
			if(v[x][i]<n-m)
				ans[x]=min(ans[x],ans[v[x][i]]);
		}

	//merge beine bache haye har kas.

	for(int i=0;i<v[x].size();i++)
		if(bz[x]!=v[x][i])
			if(v[x][i]!=p[x])
			{
				int mm=Merge(bz[x],bz[v[x][i]]);
				ans[x]=min(mm,ans[x]);
			}
	//return bara parente ke bozrgtarin seto peida kone. bara barga 1 hast ke faghat adade khodeshoone va baraye rasa bozorgtarine zir shakhashoon.
	if(x>=n-m)
		return 1;
	else
		return s[bz[x]].size();

}

inline void random_intput()
{
	srand(time( 0 )) ;
	n = 500 * 100;
	m = 0;
	for(int i=1;i<n;++i) {
		p[i] = rand() % i;
		v[i].push_back(p[i]);
		v[p[i]].push_back(i);
	}
	for(int i=1;i<n;++i)
		if(p[i] == 1) {
			m++;
		}
	int cnt = n - m;
	for(int i=1;i<n;++i)
		if(p[i] == 1) {
			s[cnt].insert(i);
			bz[cnt]=cnt;
			cnt++;
		}

}

int main()
{
	//cin >> n >> m;
	/*
	for(int i=1;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		tmp--;
		v[i].push_back(tmp);
		v[tmp].push_back(i);
		p[i]=tmp;
	}
	/**/
	
	random_intput();
	
	/*for(int i=n-m;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		s[i].insert(tmp);
		bz[i]=i;
	}*/
	int h=DFS(0);
	for(int i=0;i<n-m;i++)
		if(ans[i]==inf)
		{
			int o=1;
			o<<=31;
			o--;
			printf("%d ",o);
		}
		else
			printf("%d ",ans[i]);
	cout << endl;
}


