#include <bits/stdc++.h>
using namespace std;
int main() {
    string S, T;
    cin >> S >> T;
    int n = S.size();
    int m = T.size();
    bool flag = false;
    for (int w = 1; w < n; ++w) {
        for (int c = 1; c <= w; ++c) {
            string result;
            for (int i = 0; i < n; i += w) {
                string group = S.substr(i, w);
                if (group.size() >= c) {
                    result += group[c - 1];
                }
            }
            if (result == T) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
