#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=20*250+10;
int a[maxn];
int main()
{
	int n , m , k;
	cin >> n >> m >> k;
	sort(a,a+n);
	for(int i=k;i>=0;i--)
	{

