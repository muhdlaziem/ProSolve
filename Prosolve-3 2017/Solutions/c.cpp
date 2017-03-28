/**
 * Attacking this problen naively might give us TLE because P can be large as 2 billions.
 * Instead, we can use Pisano Period, where for fib(n) % mod, the number will repeat itself at some threshold period.
 *
 * References:
 * - https://en.wikipedia.org/wiki/Pisano_period
 * - https://medium.com/competitive/huge-fibonacci-number-modulo-m-6b4926a5c836#.cqvjkbuvh
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll modRes[100000];
int mi;

int getFibMod(int nth, int mod) {

    ll a = 0, b = 1, c, i;
    modRes[0] = a, modRes[1] = b, mi=2;

    for(i=1; ; i++) {
        c = (a+b)%mod;
        a = b; b = c;
        modRes[mi++] = c; // store each mod for easy access later
        if(a == 0 && b == 1) break;
    }

    return modRes[nth % i]; 
}

int main() {

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        int nth, mod;
        cin >> nth >> mod;
        printf("Case #%d: %d\n", i, getFibMod(nth, mod));
    }
}