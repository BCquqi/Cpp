#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
    freopen("eval20.in", "w", stdout);
    srand(time(0));
    int n = rand() % 1000 + 1;
    int k = rand() % n + 1;
    printf("%d %d\n", n, k);
    for (int i = 0; i < n; ++i) {
        int x = rand() % 2001 - 1000;
        int y = rand() % 2001 - 1000;
        int z = rand() % 2001 - 1000;
        printf("%d %d %d\n", x, y, z);
    }
    return 0;
}