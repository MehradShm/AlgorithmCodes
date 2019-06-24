#include <iostream>
#include <set>

using namespace std;

set<int> k , f;

int main()
{
	k.insert(5);
	k.insert(4);
	k.insert(7);
	k.insert(90);
	set<int> :: iterator g , t , e;
	g=k.find(4);
	cerr << *g << " @@ " << endl;
	t=g++;
	cerr << *g << " $$ " << *t << endl;
	t=g++;
	e=t--;
	cerr << *g << " !! " << *e << " !! " << *t << endl;
}
