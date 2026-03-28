#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<pair<long long, char> > p(N);
    int t1 = 0;
    for (int i = 0; i < N; ++i) {
        cin >> p[i].first;
        p[i].second = S[i];
        if (S[i] == '1') {
            t1++;
        }
    }
    sort(p.begin(), p.end());
    int maxn = t1;
    int now = t1;
    int i = 0;
    while (i < N) {
        long long w = p[i].first;
        int cnt0 = 0, cnt1 = 0;
        while (i < N && p[i].first == w) {
            if (p[i].second == '0') {
                cnt0++;
            } else {
                cnt1++;
            }
            i++;
        }
        now += cnt0;
        now -= cnt1;
        if (now > maxn) {
            maxn = now;
        }
    }
    cout << maxn << endl;
    return 0;
}
