#include<iostream>
using namespace std;

int main()
{
    int n;
	cin >> n;
	int cnt = 0,floor = 0;
	while (cnt < n) floor++,cnt += floor;
	if (floor % 2 == 0) cout << cnt + 1 - n << '/' << floor - cnt + n;
	else cout << floor - cnt + n << '/' << cnt + 1 - n;
	return 0;
}
