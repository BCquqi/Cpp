#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int h[N];
long long suml,sumr;

multiset<int> l,r;

void balance() {
    if (l.size() > r.size()) {
        auto it = l.end();
        it--;
        suml -= *it, sumr += *it;
        l.erase(it); r.insert(*it);
    } else if (l.size() < r.size() - 1) {
        auto it = r.begin();
        suml += *it, sumr -= *it;
        l.insert(*it); r.erase(it);
    }
}

void ins(int x) {
    if (x < *r.begin()) l.insert(x),suml += x;
    else r.insert(x),sumr += x;
    balance();
}

void del(int x) {
    if (x < *r.begin()) l.erase(l.find(x)), suml -= x;
    else r.erase(r.find(x)),sumr -= x;
    balance();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k;
    long long ans = 1e18;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) cin >> h[i];
    for (int i = 1;i < k;i++) ins(h[i]);
    for (int i = k;i <= n;i++) { // 右端点
        ins(h[i]);
        if (i - k > 0) del(h[i - k]);
        ans = min(ans,sumr - suml - (k % 2) * (*r.begin()));
    }
    cout << ans << '\n';
    return 0;
}