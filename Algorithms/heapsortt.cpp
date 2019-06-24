#include <iostream>
using namespace std;
const int maxn=100000;
int a[maxn];
int hs;

void Max_Heapify(int r,int size)
{
	if(r<=(size/2))
		if(a[r]>a[(r*2)] and a[r]>a[(r*2)+1])
			return ;
		else
		{
			int x;
			if(((r*2)+1)>size or a[(r*2)]>a[((r*2)+1)])
				x=0;
			else
				x=1;
			if(a[r]<a[(r*2)+x])
			{
				swap(a[r],a[(r*2)+x]);
				Max_Heapify(((r*2)+x),size);
			}
		}
}

void Heap_Sort(int size)
{
	if(size==1)
		return;
	else
	{
		swap(a[1],a[size]);
		Max_Heapify(1,size-1);
		Heap_Sort(size-1);
	}
}

void BMH(int hs)
{
	int x=hs/2;
	for(int i=x;i>0;i--)
		Max_Heapify(i,hs);
}

int main()
{
	cin >> hs;
	for(int i=1;i<=hs;i++)
		cin >>a[i];
	BMH(hs);
	Heap_Sort(hs);
	for(int i=1;i<=hs;i++)
		cout << a[i] << " " ;
	cout << endl;
}
