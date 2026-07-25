#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
    freopen("percom20.in", "w", stdout);
    
    const int MAXN = 1000000000;
    int n, m;
    
    srand(time(0));
    
    n = rand() % MAXN + 1;
    m = rand() % (n + 1);
    
    printf("%d %d\n", n, m);
    
    return 0;
}