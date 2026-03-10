#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int a[N];

void quick_sort(int a[],int l,int r) {
    if (l >= r) return ;
    int x = a[(l + r) >> 1];
    int i = l,j = r;
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) swap(a[i++],a[j--]);
    }
    quick_sort(a,l,j);
    quick_sort(a,i,r);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    quick_sort(a,1,n);
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}