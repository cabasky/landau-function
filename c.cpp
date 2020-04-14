#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long ll;

const int INF = 0x7f7f7f7f;
const int maxn = 101;

int n;
int maxlcm[ maxn ];

int gcd ( int a, int b ) { return b ? gcd ( b, a % b ) : a; }

int dp[ maxn ][ maxn ]; // i分解成j份的最大lcm
void splitlcm () {
    memset ( dp, 0, sizeof ( dp ) );

    for ( int i = 1; i < maxn; ++i )
        dp[ i ][ 1 ] = i;

    for ( int i = 1; i < maxn; ++i )
        for ( int j = 1; j <= i; ++j )
            for ( int k = 1; k < i && i - k >= j - 1; ++k ) {
                dp[ i ][ j ] = max ( dp[ i ][ j ],
                                     dp[ i - k ][ j - 1 ] * k / gcd ( dp[ i - k ][ j - 1 ], k ) );
            }

    //找到每个数分解后最小公倍数最大的值
    for ( int i = 1; i < maxn; ++i ) {
        int mx = -1;
        for ( int j = 1; j < maxn; ++j )
            mx = max ( mx, dp[ i ][ j ] );
        maxlcm[ i ] = mx;
    }
}

int fnum = 0;
int primes[ 25 ] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int factors[ maxn ];
void splitprime ( int num ) {
    fnum = 0;
    memset ( factors, 1, sizeof ( factors ) );

    for ( int i = 0; i < 25; ++i )
        if ( num % primes[ i ] == 0 ) {
            factors[ fnum ] = 1;
            while ( num % primes[ i ] == 0 ) {
                factors[ fnum ] *= primes[ i ];
                num /= primes[ i ];
            }
            fnum++;
        }
}

int main () {
#ifdef LOCAL
    freopen ( "in", "r", stdin );
    freopen ( "out", "w", stdout );
#endif
    splitlcm ();

    int T;
    scanf ( "%d", &T );
    while ( T-- ) {
        scanf ( "%d", &n );
        printf ( "%d", maxlcm[ n ] );

        //最小公倍数数最大的数分解为素因子
        splitprime ( maxlcm[ n ] );
        sort ( factors, factors + fnum );
        int sum = 0;
        for ( int i = 0; i < fnum; ++i )
            sum += factors[ i ];

        //单个循环,直接输出
        int cur = max ( 0, n - sum );
        for ( int i = 1; i <= cur; ++i )
            printf ( " %d", i );
        ++cur;
        //因子长度的循环节的输出,移动一位保证最小
        for ( int i = 0; i < fnum; ++i ) {
            for ( int j = 1; j < factors[ i ]; ++j )
                printf ( " %d", cur + j );
            printf ( " %d", cur );
            cur += factors[ i ];
        }
        printf ( "\n" );
    }

    return 0;
}