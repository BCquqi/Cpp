#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int a[15],n;

bool check()
{
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
		{
			if (a[i] == a[j]) return false;
			if (abs(a[i] - a[j]) == abs(i - j)) return false;
		}
	return true;
}

int main(){
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (check()) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}