#include<iostream>
using namespace std;

const int N = 205,mod = 998244353;
int a[N],cnt[(1 << 15) + 5],sor2[15],sor3[(1 << 15) + 5],pow2[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("partition.in","r",stdin);
    freopen("partition.out","w",stdout);
    int n,T = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
        T |= a[i];
    }
    for (int i = 0;i < 15;i++)
        for (int s = 0;s < (1 << 15);s++)
            if (s & (1 << i)) cnt[s] += cnt[s ^ (1 << i)];
    for (int i = 1;i <= n;i++)
        for (int j = 0;j < 15;j++)
            if (a[i] & (1 << j)) sor2[j] |= a[i];
    for (int i = 1;i < (1 << 15);i++) {
        int lowbit = i & -i;
        int pos = __builtin_ctz(lowbit);
        sor3[i] = sor3[i ^ lowbit] | sor2[pos];
    }
    pow2[0] = 1;
    for (int i = 1;i <= n;i++)
        pow2[i] = pow2[i - 1] * 2 % mod; // 由于要取模，提前处理
    int pc[1<<15];
    for (int i = 1; i < (1 << 15); i++) // 省时间，__builtin_popcount
        pc[i] = pc[i >> 1] + (i & 1);
    long long ans = 0;
    for (int s1 = T; ;s1 = (s1 - 1) & T) { // 子集枚举
        int rest = T ^ s1; // 重要! 预处理 s1, s2 不相交 节省时间复杂度
        for (int s2 = rest; ;s2 = (s2 - 1) & rest) { // 玄学，T 要放在后面 -1 的位运算性质
            if (sor3[s1] & s2) continue;
            long long tmp = pow2[cnt[T ^ (s1 | s2)]];
            if ((pc[s1] + pc[s2]) % 2 == 1)
                ans = (ans - tmp + mod) % mod;
            else ans = (ans + tmp) % mod;
            if (s2 == 0) break; // 0 的情况也要处理
        }
        if (s1 == 0) break; // 0 的情况也要处理
    }
    cout << ans << '\n';
    return 0;
}