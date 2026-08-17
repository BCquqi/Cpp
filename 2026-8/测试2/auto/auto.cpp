#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;
string a[N];
int n,q;

int check(string x,string y) {
    if (x == y) return 1;
    else if (x.size() == y.size() + 1) { // 多一个字才可能触发 2
        int len1 = x.size(),len2 = y.size();
        bool flag = false,chk = false; // 记录是否已经有过错位和是否(不)满足 2 的要求
        for (int i = 0,j = 0;j < len2;i++,j++) { // 双指针，i 指向 x, j 指向 y
            if (x[i] == y[j]) continue;
            if (flag) {
                chk = true;
                break;
            }
            flag = true, j--;
            // 理论上实现 i++ 效果，但是下一轮会跳过 ++i 和 j 的匹配，所以这里使用 j-- 进入下一轮
        }
        if (!chk) return 2;
    }
    else if (x.size() == y.size()) {
        int len = x.size();
        bool flag = false;
        for (int i = 0;i < len;i++) {
            if (x[i] == y[i]) continue;
            if (flag) return 0;
            if (x[i + 1] == y[i] && x[i] == y[i + 1]) flag = true, i++; // 跳过下一个
            else return 0; // 不一样但是不符合交换要求
        }
        if (flag == true) return 3;
    }
    return 0;
}

void solve() {
    string s;
    cin >> s;
    bool flag2 = false,flag3 = false;
    string str2 = "",str3 = "";
    for (int i = 1;i <= n;i++) {
        if (check(s,a[i]) == 1) {
            cout << "OK" << '\n';
            return ;
        }
        else if (check(s,a[i]) == 2 && !flag2) flag2 = true, str2 = a[i];
        else if (check(s,a[i]) == 3 && !flag3) flag3 = true, str3 = a[i];
    }
    if (flag2) cout << str2 << '\n';
    else if (flag3) cout << str3 << '\n';
    else cout << "Not Found" << '\n';
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("auto.in","r",stdin);
    freopen("auto.out","w",stdout);
    cin >> n >> q;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    while (q--) solve();
    return 0;
}