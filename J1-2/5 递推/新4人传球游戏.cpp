#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

long long a[50],b[50],c[50],d[50];

int main(){
	int n;
	cin >> n;
	a[0] = 1;
	b[0] = 0;
	c[0] = 0;
	d[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		a[i] = c[i - 1] + d[i - 1];
		b[i] = a[i - 1] + c[i - 1] + d[i - 1];
		c[i] = a[i - 1] + b[i - 1] + d[i - 1];
		d[i] = a[i - 1] + b[i - 1] + c[i - 1];
	}
	cout << a[n] << endl;
	return 0;
}
