#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 1e4 + 5;
int a[N],n,d;
struct Node {ll x; int id;};
unordered_set<ll> s;

inline ll sortmax(ll mx) {
    vector<int> num;
    int cnt = 0;
    while (mx) {
        num.push_back(mx % 10);
        mx /= 10, cnt++;
    }
    while (d - cnt > 0) num.push_back(0), cnt++;
    sort(num.begin(),num.end(),[](int x,int y) {return x > y;});
    ll ret = 0;
    for (auto m : num)
        ret = ret * 10 + m;
    return ret;
}

inline ll sortmin(ll mn) {
    vector<int> num;
    while (mn) {
        num.push_back(mn % 10);
        mn /= 10;
    }
    sort(num.begin(),num.end());
    ll ret = 0;
    for (auto m : num)
        ret = ret * 10 + m;
    return ret;
}

inline ll change(ll x) {
    ll mx = x,mn = x;
    mx = sortmax(mx), mn = sortmin(mn);
    return mx - mn;
}

int main() {
	freopen("gravity.in","r",stdin);
	freopen("gravity.out","w",stdout);
    cin >> n >> d;
    for (int i = 1;i <= n;i++) {
        s.clear();
        ll x;
        cin >> x;
        s.insert(x);
        while (true) {
            x = change(x);
            if (s.count(x)) {
                cout << x << endl;
                break;
            }
            s.insert(x);
        }
    }
    return 0;
}