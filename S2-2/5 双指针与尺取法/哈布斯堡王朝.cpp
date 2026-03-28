#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
int Lcnt[N];
map<int,int> mp;

bool check(char c) {return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');}

int main() {
	int n,k;
	long long ans = 0;
	cin >> n >> k;
	string s;
	cin >> s;
	int len = s.size(); s = '?' + s;
	for (int i = 2;i <= len;i++) {
		if (check(s[i - 1]))
			Lcnt[i] = Lcnt[i - 1] + 1;
		else Lcnt[i] = 0;
	}
	int sum = 0,cnt = 0;
	for (int l = 1,r = 1;r <= n;r++) {
		if (check(s[r])) {
			if (++mp[s[r]] == 1) cnt++;
			sum++;
		}
		while (cnt == 5 && r - l + 1 - sum > k) {
			if (check(s[l])) {
				sum--;
				if (--mp[s[l]] == 0) cnt--;
			}
			l++;
		}
		if (cnt == 5 && r - l + 1 - sum == k) {
			while (check(s[l]) && mp[s[l]] > 1) sum--,mp[s[l]]--,l++;
			ans += Lcnt[l] + 1;
		}
	}
	cout << ans << endl;
	return 0;
}