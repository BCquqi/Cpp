#include <cstdio>
#include <vector>
using namespace std;

vector<int> primes;

// 筛出 sqrt(1e9) 以内的所有质数
void init_primes() {
    const int LIM = 31623;          // sqrt(1e9)
    vector<bool> vis(LIM + 1, false);
    for (int i = 2; i <= LIM; ++i) {
        if (!vis[i]) {
            primes.push_back(i);
            if (1LL * i * i <= LIM) {
                for (long long j = 1LL * i * i; j <= LIM; j += i)
                    vis[j] = true;
            }
        }
    }
}

// 求 n 的最小质因子
int smallest_prime_factor(int n) {
    if (n <= 1) return n;
    for (int p : primes) {
        if (1LL * p * p > n) break;
        if (n % p == 0) return p;
    }
    return n;   // n 本身是质数
}

// 获取从 n 到 1 的路径（包含 n 和 1）
vector<int> get_path(int n) {
    vector<int> path;
    while (n > 1) {
        path.push_back(n);
        int p = smallest_prime_factor(n);
        n /= p;
    }
    path.push_back(1);
    return path;
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    int Q;
    scanf("%d", &Q);
    init_primes();

    while (Q--) {
        int x, y;
        scanf("%d%d", &x, &y);

        vector<int> px = get_path(x);
        vector<int> py = get_path(y);

        // 从路径末尾（根节点 1）开始，寻找公共后缀长度
        int i = (int)px.size() - 1;
        int j = (int)py.size() - 1;
        int common = 0;
        while (i >= 0 && j >= 0 && px[i] == py[j]) {
            ++common;
            --i; --j;
        }

        // 树上距离 = (lenx - 1) + (leny - 1) - 2 * (common - 1)
        // 简化后 = lenx + leny - 2 * common
        int ans = (int)px.size() + (int)py.size() - 2 * common;
        printf("%d\n", ans);
    }

    return 0;
}