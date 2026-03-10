#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int tmp[N],a[N];

void merge_sort(int a[],int l,int r) {
    if (l >= r) return ;
    int mid = l + r >> 1;
    merge_sort(a,l,mid);
    merge_sort(a,mid + 1,r);
    int i = l,j = mid + 1,cur = l;
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) tmp[cur++] = a[i++];
        else tmp[cur++] = a[j++];
    }
    while (i <= mid) tmp[cur++] = a[i++];
    while (j <= r) tmp[cur++] = a[j++];
    for (int i = l;i <= r;i++) a[i] = tmp[i];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    merge_sort(a,1,n);
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}