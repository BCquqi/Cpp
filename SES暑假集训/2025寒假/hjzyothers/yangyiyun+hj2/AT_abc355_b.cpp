#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c.push_back(a[i]);
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        c.push_back(b[i]);
    }
    sort(c.begin(), c.end());
    vector<bool> is_a(201, false);
    for (int i = 0; i < n; ++i) {
        is_a[a[i]] = true;
    }
    bool ans = false;
    for (int i = 1; i < c.size(); ++i) {
        if (is_a[c[i]] && is_a[c[i-1]]) {
            ans = true;
            break;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
