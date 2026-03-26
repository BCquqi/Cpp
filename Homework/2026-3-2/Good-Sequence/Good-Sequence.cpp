#include<iostream>
#include<map>
using namespace std;

const int N = 1e5 + 10;
int a[N];
map<int,int> mp;

int main() {
    int n,ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (auto i : mp) {
        int a = i.first,b = i.second;
        ans += (b >= a) ? (b - a) : b;
    }
    cout << ans << endl;
    return 0;
}

// https://atcoder.jp/contests/arc087/submissions/74033095