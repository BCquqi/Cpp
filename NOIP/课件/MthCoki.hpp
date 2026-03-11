#ifndef curmath
#define curmath

#include<cmath>
using namespace std;

namespace math {
    template<typename T>
    T gcd(T a,T b) {
        while (b != 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }

    template<typename T>
    T lcm(T a,T b) {
        if (a == 0 || b == 0) return 0;
        long long absa = abs(a),absb = abs(b);
        long long copya = absa,copyb = absb;
        while (absb != 0) {
            long long tmp = absb;
            absb = absa % absb;
            absa = tmp;
        }
        long long gcd = absa;
        return copya / gcd * copyb;
    }
    
    template<typename T>
    T qpow(T a,T b,T p) {
		long long ans = 1;
		while (b)
		{
			if (b & 1) ans = ans * a % p;
			a = a * a % p;
			b >>= 1;
		}
		return ans;
	}
}
#endif
