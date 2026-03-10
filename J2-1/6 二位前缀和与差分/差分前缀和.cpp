#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N],d[N],sumd[N];

int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {cin >> a[i]; d[i] = a[i] - a[i - 1];}
	while (m--)
	{
		int l,r,c;
		cin >> l >> r >> c;
		d[l] += c,d[r + 1] -= c;
	}
	for (int i = 1;i <= n;i++) {sumd[i] = sumd[i - 1] + d[i]; cout << sumd[i] << ' ';}
	cout << endl;
	return 0;
}