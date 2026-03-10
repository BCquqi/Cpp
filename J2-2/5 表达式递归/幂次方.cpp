#include<iostream>
using namespace std;

string solve(int n) {
    string ans = "";
    for (int i = 15;i >= 0;i--) {
        int t = 1 << i;
        if (n & t) {
            if (i == 1) ans += "2";
            else if (i == 0) ans += "2(0)";
            else ans += "2(" + solve(i) + ")";
            n -= t;
            if (n != 0) ans += "+";
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}