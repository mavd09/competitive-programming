#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int(1e7+10)
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

ll L, N, sum;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( scanf( "%lld %lld", &L, &N ) != EOF ) && ( L+N > 0 ) ) {
        ll ans = 0LL;
        if( L & 1LL ) {
            ll ans1 = 0LL, ans2 = 0LL, tmp = N;

            sum = min( N, (L*L+1LL)/2LL );
            ans1 += 4LL*sum; N -= sum;
            sum = min( N, 4LL*(L/2LL) );
            ans1 -= 2LL*sum; N -= sum;
            sum = min( N, (L*L-(2LL*L+2LL*(L-2LL)))/2LL );
            ans1 -= 4LL*sum; N -= sum;

            N = tmp;
            sum = min( N, L*L/2LL );
            ans2 += 4LL*sum; N -= sum;
            sum = min( N, 4LL );
            N -= sum;
            sum = min( N, 4LL*(L-(L/2LL+2LL)) );
            ans2 -= 2LL*sum; N -= sum;
            sum = min( N, (L*L-(2LL*L+2LL*(L-2LL))+1LL)/2LL );
            ans2 -= 4LL*sum; N -= sum;

            ans = max( ans1, ans2 );
            N = tmp;
            if( L == 1LL ) ans = ( N == 1LL ? 4LL : 0LL );
        }
        else {
            sum = min( N, L*L/2LL );
            ans += 4LL*sum; N -= sum;
            sum = min( N, 2LL );
            N -= sum;
            sum = min( N, 4LL*(L-(L/2LL+1)) );
            ans -= 2LL*sum; N -= sum;
            sum = min( N, (L*L-(2LL*L+2LL*(L-2LL)))/2LL );
            ans -= 4LL*sum; N -= sum;
        }
        printf( "%lld\n", ans );
    }

    return 0;
}
