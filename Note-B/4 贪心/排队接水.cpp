#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
  
struct Node {int id,t;} a[1005];

int main() {
    int n = 0;
    long long sum =0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].t;
        a[i].id = i;
    }
    sort(a + 1,a + n + 1,[](Node x,Node y) {return x.t != y.t ? x.t < y.t : x.id < y.id;});
    for (int i = 1;i <= n;i++) {
        cout << a[i].id << " ";
        sum += (n - i) * a[i].t;
    }
    printf("\n%.2lf",sum * 1.0 / n);
    return 0;
}