#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

const int N = 1e5 + 5;
long long cpy[N];
unordered_set<long long> s;

void solve() {
    s.clear();
    int a,n,m;
    cin >> a >> n >> m;
    for (int i = 1;i <= a;i++) {
        long long x;
        cin >> x;
        s.insert(x);
        cpy[i] = x;
    }
    for (int i = 1;i <= a;i++) {
        // n 行 m 列，每个依次按照行列顺序标数，需要知道 cpy[i] 的关于该网格图长度为 m 的边上的垂直平分线对称点是否在 s 中：
        int col = (cpy[i] - 1) % m + 1; // 标号从 1 开始，不能直接除
        int revcol = m - col + 1;
        long long id = cpy[i] - col + revcol;
        if (s.count(id) == 0) {
            cout << "No" << endl;
            return ;
        }
    }
    cout << "Yes" << endl;
    return ;
}

int main() {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}