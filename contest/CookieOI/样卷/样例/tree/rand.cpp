#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
    freopen("tree20.in", "w", stdout);
    srand(time(0));
    int Q = rand() % 1000 + 1;          // Q 随机 1~20
    int N = rand() % 1000000000 + 1;        // N 随机 1~1000
    printf("%d\n", Q);
    for (int i = 0; i < Q; i++)
        printf("%d %d\n", rand() % N + 1, rand() % N + 1);
    return 0;
}