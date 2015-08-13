#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 200 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int nTest, n;
int b[ MAX ][ MAX ];

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> nTest;
    for( int t = 1; t <= nTest; t++ ) {
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
            for( int j = 1; j <= n; j++ ) {
                cin >> b[ i ][ j ];
                b[ i+n ][ j ] = b[ i ][ j+n ] = b[ i+n ][ j+n ] = b[ i ][ j ];
            }
        }
        int cur;
        for( int i = 1; i <= 2*n; i++ ) {
            cur = 0;
            for( int j = 1; j <= 2*n; j++ ) {
                cur += b[ i ][ j ];
                b[ i ][ j ] = b[ i-1 ][ j ]+cur;
            }
        }
        int ans = 0;
        for( int i = 1; i <= 2*n; i++ ) {
            for( int j = 1; j <= 2*n; j++ ) {
                for( int ii = i; ii <= 2*n; ii++ ) {
                    for( int jj = j; jj <= 2*n; jj++ ) {
                        if( ii-i+1 > n || jj-j+1 > n ) continue;
                        ans = max( ans, b[ ii ][ jj ]-b[ ii ][ j-1 ]-b[ i-1 ][ jj ]+b[ i-1 ][ j-1 ] );
                    }
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
