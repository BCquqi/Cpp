#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

// 数据范围控制（可随意修改）
const int MAX_N = 20;   // 最大 n
const int MAX_A = 1000;     // 最大 a[i]
const int MAX_S = 10000;    // 最大 s

// 生成一组测试数据，输出到标准输出
void generate_one() {
    int n = rand() % MAX_N + 1;
    vector<int> a(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % MAX_A + 1;
        total += a[i];
    }
    // 让 s 在总和的 1/4 到 1/2 之间随机
    int s = total / (2 + rand() % 3);
    // 确保 s 至少为 1
    s = max(s, 1);
    printf("%d %d\n", n, s);
    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    putchar('\n');
}

int main() {
    freopen("divide13.in","w",stdout);
    srand(time(0));
    generate_one();
    return 0;
}