#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAXN 	int( 2e2 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n;
int b[ MAXN ][ MAXN ];
int s[ MAXN ][ MAXN ];

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        int cur = 0;
        for( int j = 1; j <= n; j++ ) {
            cin >> b[ i ][ j ];
            cur += b[ i ][ j ];
            s[ i ][ j ] = s[ i-1 ][ j ]+cur;
        }
    }
    int ans = 0;
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= n; j++ ) {
            for( int ii = i; ii <= n; ii++ ) {
                for( int jj = j; jj <= n; jj++ ) {
                    ans = max( ans, s[ ii ][ jj ]-s[ i-1 ][ jj ]-s[ ii ][ j-1 ]+s[ i-1 ][ j-1 ] );
                }
            }
        }
    }
    cout << ans << "\n";


    return 0;
}
