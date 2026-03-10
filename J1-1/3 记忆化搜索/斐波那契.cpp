#include<iostream>
#include<cstring>
using namespace std;

long long f[55];

long long dfs(int n)
{
	if (f[n] != 0) return f[n];
	if (n == 1) return f[1] = 1;
	if (n == 2) return f[2] = 1;
	return f[n] = dfs(n - 1) + dfs(n - 2);
}

int main()
{
	int n;
	cin >> n;
	cout << dfs(n) << endl;
	return 0;
}

#include<iostream>
#include<cstring>
using namespace std;

long long dfs(int n)
{
	if (n == 1 || n == 2) return 1;
	return dfs(n - 1) + dfs(n - 2);
}

int main()
{
	int n;
	cin >> n;
	cout << dfs(n) << endl;
	return 0;
}