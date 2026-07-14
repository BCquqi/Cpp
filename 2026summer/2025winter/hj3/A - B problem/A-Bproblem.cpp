#include<iostream>
using namespace std;

int main() {
	int a,b;
	cin >> a >> b;
	int ans1 = (900 + a % 100) - b;
	int ans2 = (100 + a % 100) - b;
	int ans3 = (a / 100 * 100 + 90 + a % 10) - b;
	int ans4 = (a / 100 * 100 + 0 + a % 10) - b;
	int ans5 = (a / 10 * 10 + 9) - b;
	int ans6 = (a / 10 * 10 + 0) - b;
	int ans7 = a - (100 + b % 100);
	int ans8 = a - (b / 100 * 100 + 0 + b % 10);
	int ans9 = a - (b / 10 * 10 + 0);
	int ans = ans1;
	ans = max(ans, ans2);
	ans = max(ans, ans3);
	ans = max(ans, ans4);
	ans = max(ans, ans5);
	ans = max(ans, ans6);
	ans = max(ans, ans7);
	ans = max(ans, ans8);
	ans = max(ans, ans9);
	cout << ans << endl;
	return 0;
}