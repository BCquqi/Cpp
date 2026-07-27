#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 100000;
const int MAX_A = 1000;
const int MAX_S = 10000;

void generate_one() {
    int n = rand() % MAX_N + 1;
    int s = rand() % MAX_S + 1;
    printf("%d %d\n", n, s);
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