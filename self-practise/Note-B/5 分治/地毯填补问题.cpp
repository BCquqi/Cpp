#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

/*
思路: 
判断四个部分中公主的位置，剩下三个部分在中间放一个 L 形，后续处理空出这个 L 即当做公主格
*/

void merge(int x,int y,int p,int q,int len) { // x / y 公主坐标 a / b 左上角坐标 len 边长
    if (len == 1) return ;
    if (x - p <= len / 2 - 1 && y - q <= len / 2 - 1) {
        cout << p + len / 2 << ' ' << q + len / 2 << " 1" << endl;
        merge(x,y,p,q,len / 2);
        merge(p + len / 2 - 1,q + len / 2,p,q + len / 2,len / 2);
        merge(p + len / 2,q + len / 2 - 1,p + len / 2,q,len / 2);
        merge(p + len / 2,q + len / 2,p + len / 2,q + len / 2,len / 2);
    }
    else if (x - p <= len / 2 - 1 && y - q > len / 2 - 1) {
        cout << p + len / 2 << ' ' << q + len / 2 - 1 << " 2" << endl;
        merge(p + len / 2 - 1, q + len / 2 - 1, p, q, len / 2);
        merge(x, y, p, q + len / 2, len / 2);
        merge(p + len / 2, q + len / 2 - 1, p + len / 2, q, len / 2);
        merge(p + len / 2, q + len / 2, p + len / 2, q + len / 2, len / 2);
    }
    else if (x - p > len / 2 - 1 && y - q <= len / 2 - 1) {
        cout << p + len / 2 - 1 << ' ' << q + len / 2 << " 3" << endl;
        merge(p + len / 2 - 1, q + len / 2 - 1, p, q, len / 2);
        merge(p + len / 2 - 1, q + len / 2, p, q + len / 2, len / 2);
        merge(x, y, p + len / 2, q, len / 2);
        merge(p + len / 2, q + len / 2, p + len / 2, q + len / 2, len / 2);
    }
    else {
        cout << p + len / 2 - 1 << ' ' << q + len / 2 - 1 << " 4" << endl;
        merge(p + len / 2 - 1, q + len / 2 - 1, p, q, len / 2);
        merge(p + len / 2 - 1, q + len / 2, p, q + len / 2, len / 2);
        merge(p + len / 2, q + len / 2 - 1, p + len / 2, q, len / 2);
        merge(x, y, p + len / 2, q + len / 2, len / 2);
    }
}

int main() {
    int x,y,k;
    cin >> k >> x >> y;
    merge(x,y,1,1,1 << k);
    return 0;
}