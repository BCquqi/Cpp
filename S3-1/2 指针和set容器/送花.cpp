#include<iostream>
#include<map>
#include<set>
using namespace std;

map<int,int> mp;
set<int> s;

int main() {
    int op;
    while (cin >> op) {
        if (op == -1) break;
        switch (op) {
            case 1 : {
                int w,c;
                cin >> w >> c;
                if (s.find(c) == s.end()) {
                    mp[c] = w;
                    s.insert(c);
                }
                break;
            }
            case 2 : {
                if (s.size()) s.erase(--s.end());
                break;
            }
            case 3 : {
                if (s.size()) s.erase(s.begin());
                break;
            }
        }
    }
    int sumw = 0,sumc = 0;
    for (auto t : s)
        sumc += t,sumw += mp[t];
    cout << sumw << ' ' << sumc << endl;
    return 0;
}