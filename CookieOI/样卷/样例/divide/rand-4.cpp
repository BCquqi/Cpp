#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 20;
const int MAX_A = 1000;
const int MAX_S = 10000;

void generate_one() {
    int n = rand() % MAX_N + 1;
    vector<int> a(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % MAX_A + 1;
        total += a[i];
    }
    int s = total / (2 + rand() % 3);
    s = max(s, 1);
    printf("%d %d\n", n, s);
    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    putchar('\n');
}

int main() {
    freopen("divide.in","w",stdout);
    srand(time(0));
    generate_one();
    return 0;
}