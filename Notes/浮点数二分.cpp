const double eps = 1e-5;
double L = 0,R = 1,ans = 0;
while (R - L >= eps) {
    double mid = (L + R) / 2;
    if (check(mid)) {
        ans = mid;
        L = mid;
    } else R = mid;
}