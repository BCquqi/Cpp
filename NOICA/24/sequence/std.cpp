#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll NEG = -(1LL << 60);

bool better(ll value1, int pos1, ll value2, int pos2) {
    return value1 > value2 || (value1 == value2 && pos1 > pos2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll v;
    cin >> n >> m >> v;

    vector<ll> first_value(n + 1, NEG), second_value(n + 1, NEG);
    vector<int> first_pos(n + 1, 0), second_pos(n + 1, 0);
    ll best_value = NEG;
    ll next_value = NEG;
    int best_pos = 0;
    int next_pos = 0;
    for (int i = 1; i <= n; ++i) {
        ll a;
        cin >> a;
        ll w = a - 1LL * i * v;
        if (better(w, i, best_value, best_pos)) {
            next_value = best_value;
            next_pos = best_pos;
            best_value = w;
            best_pos = i;
        } else if (better(w, i, next_value, next_pos)) {
            next_value = w;
            next_pos = i;
        }
        first_value[i] = best_value;
        first_pos[i] = best_pos;
        second_value[i] = next_value;
        second_pos[i] = next_pos;
    }

    ll xor_sum = 0;
    ll add_sum = 0;
    for (int query = 0; query < m; ++query) {
        int x, k;
        cin >> x >> k;
        ll answer = 0;
        if (k <= n - x + 1) {
            int r = x + k - 1;
            ll value = first_value[r];
            int pos = first_pos[r];
            if (pos == x) {
                value = second_value[r];
                pos = second_pos[r];
            }
            if (pos != 0) {
                ll required = 1LL * x * v + value + (pos > x ? 1 : 0);
                answer = max(0LL, required);
            }
        }
        xor_sum ^= answer;
        add_sum += answer;
    }
    cout << xor_sum << ' ' << add_sum << '\n';
    return 0;
}
