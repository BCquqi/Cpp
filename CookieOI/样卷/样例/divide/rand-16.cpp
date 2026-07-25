#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

// 数据范围控制（可随意修改）
const int MAX_N = 100000;   // 最大 n
const int MAX_A = 1000;     // 最大 a[i]
const int MAX_S = 10000;    // 最大 s

// 生成一组测试数据，输出到标准输出
void generate_one() {
    // 随机生成 n 和 s，保证 1 <= n <= MAX_N, 1 <= s <= MAX_S
    int n = rand() % MAX_N + 1;
    int s = rand() % MAX_S + 1;
    printf("%d %d\n", n, s);
    // 生成 n 个数，每个在 [1, MAX_A] 之间
    for (int i = 1; i <= n; ++i) {
        int a = rand() % MAX_A + 1;
        if (i > 1) putchar(' ');
        printf("%d", a);
    }
    putchar('\n');
}

int main() {
    freopen("divide20.in","w",stdout);
    srand(time(0));
    generate_one();
    return 0;
}