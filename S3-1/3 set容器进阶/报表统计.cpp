#include<iostream>
#include<set>
#include<cmath>
using namespace std;

const int N = 5e5 + 5;
int last[N],a[N];
int n,m,minn = 1e9;
multiset<int> gap,num;

void insert_s(int x) {
    auto it = num.lower_bound(x);
    if (it != num.end()) minn = min(minn,*it - x);
    if (it != num.begin()) minn = min(minn,abs(x - *(--it)));
    num.insert(x);
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        insert_s(a[i]);
        last[i] = a[i];
        if (i > 1) gap.insert(abs(a[i] - a[i - 1]));
    }
    while (m--) {
        string op;
        cin >> op;
        if (op == "INSERT") {
            int i,k;
            cin >> i >> k;
            gap.insert(abs(k - last[i]));
            if (i < n) {
                gap.insert(abs(k - a[i + 1]));
                gap.erase(gap.find(abs(a[i + 1] - last[i])));
            }
            last[i] = k;
            insert_s(k);
        }
        else if (op == "MIN_GAP") cout << *gap.begin() << endl;
        else cout << minn << endl;
    }
    return 0;
}