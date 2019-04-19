#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1<<17 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int m, n, k, t;
int dp[ MAX ];

int main( ) {

	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> m >> n ) && ( m+n > 0 ) ) {
        memset( dp, -1, sizeof( dp ) );
        for( int i  = 0, mask1 = 0; i < m; i++, mask1 = 0 ) {
            cin >> k;
            for( int j = 0; j < k; j++ ) {
                cin >> t;
                mask1 |= ( 1 << (t-1) );
            }
            dp[ mask1 ] = 1;
            for( int mask2 = 1; mask2 < MAX; mask2++ ) {
                if( dp[ mask2 ] == -1 ) continue;
                if( dp[ mask1|mask2 ] == -1 ) dp[ mask1|mask2 ] = dp[ mask1 ]+dp[ mask2 ];
                else                          dp[ mask1|mask2 ] = min( dp[ mask1|mask2 ], dp[ mask1 ]+dp[ mask2 ] );
            }
        }
        for( int i  = 0, mask = 0; i < n; i++, mask = 0 ) {
            cin >> k;
            for( int j = 0; j < k; j++ ) {
                cin >> t;
                mask |= ( 1 << (t-1) );
            }
            if( i ) cout << " ";
            cout << max( 0, dp[ mask] );
        }
        cout << "\n";
    }

    return 0;
}
