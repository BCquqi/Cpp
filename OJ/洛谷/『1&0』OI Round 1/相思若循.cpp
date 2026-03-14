#include<iostream>
using namespace std;
typedef long long LL;

LL qpow(LL a,LL b,LL p)
{
	LL ans = 1;
	while (b)
	{
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

void solve() {
    int n,mod = 998244353;
    cin >> n;
    if (n == 1) {cout << "NO" << endl; return ;}
    LL ans = qpow(2,n,mod) - 1;
    cout << ans << endl;
    return ;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}