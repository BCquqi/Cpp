#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100000 + 5;
int h[N];

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> h[i];
	}
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		if (h[i] > h[i - 1])
		{
			ans += h[i] -  h[i - 1];
		}
	}
	cout << ans << endl;
	return 0;
}
