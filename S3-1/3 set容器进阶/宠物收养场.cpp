#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

const int mod = 1000000;
multiset<int> o,p; // owner, pet

int main() {
    int n,ans = 0;
    cin >> n;
    while (n--) {
        int a,b;
        cin >> a >> b;
        if (a == 0) {
            if (p.empty()) o.insert(b);
            else {
                auto it1 = p.lower_bound(b);
                auto it2 = it1;
                if (it2 != p.begin()) it2--;
                if (it1 == p.end() || it2 != it1 && b - *it2 <= *it1 - b) {
                    ans += b - *it2,ans %= mod;
                    p.erase(p.find(*it2));
                } else {
                    ans += *it1 - b,ans %= mod;
                    p.erase(p.find(*it1));
                }
            }
        } else {
            if (o.empty()) p.insert(b);
            else {
                auto it1 = o.lower_bound(b);
                auto it2 = it1;
                if (it2 != o.begin()) it2--;
                if (it1 == o.end() || it2 != it1 && b - *it2 <= *it1 - b) {
                    ans += b - *it2,ans %= mod;
                    o.erase(o.find(*it2));
                } else {
                    ans += *it1 - b,ans %= mod;
                    o.erase(o.find(*it1));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}