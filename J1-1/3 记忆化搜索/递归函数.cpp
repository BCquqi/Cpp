#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int mod = 1e9 + 7;

long long f[1005][1005];

long long F(int n,int k)
{
	if (f[n][k]) return f[n][k];
	if (n > 0 && k == 0) return f[n][k] = 0;
	if (n >= 0 && k == n) return f[n][k] = 1;
	if (k > n) return f[n][k] = 0;
	return f[n][k] = (F(n - 1,k - 1) + k * F(n - 1,k) % mod) % mod;
}

int main(){
	int n,k;
	cin >> n >> k;
	cout << F(n,k) << endl;
	return 0;
}