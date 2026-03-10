#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[1005];

void s2BIG (string s,int a[])
{
	int al = s.length();
	for (int i = 1;i <= al;i++) a[i] = s[al - i] - '0';
	a[0] = al;
}

void printBIG(int a[])
{
	int al = a[0];
	for (int i = al;i >= 1;i--) cout << a[i];
}


int main()
{
	string s;
	cin >> s;
	s2BIG(s,a);
	printBIG(a);
	return 0;
}
