#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1e3+100 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n;
int dp[ MAX ], p[ MAX ];

struct Data {
    int id, w, s;
    bool operator < ( const Data &o )const {
        if( w != o.w ) return w < o.w;
        return s > o.s;
    }
}d[ MAX ];

pair< int, int  > lis( ) {
    int maxLength = 1, bestEnd = 0;

    dp[ 0 ] = 1;
    p[ 0 ] = -1;

    for( int i = 1; i < n; i++ ) {
        dp[ i ] = 1;
        p[ i ] = -1;
        for( int j = i-1; j >= 0; j-- ) {
            if( dp[ j ]+1 > dp[ i ] && d[ j ].w < d[ i ].w && d[ j ].s > d[ i ].s ) {
                dp[ i ] = dp[ j ]+1;
                p[ i ] = j;
            }
        }
        if( dp[ i ] > maxLength ) {
            maxLength = dp[ i ];
            bestEnd = i;
        }
    }

    return MP( maxLength, bestEnd );
}

void rebuildLis( int cur ) {
    if( p[ cur ] != -1 ) rebuildLis( p[ cur ] );
    cout << d[ cur ].id+1 << "\n";
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> d[ n ].w >> d[ n ].s ) d[ n ].id = n++;
    sort( d, d+n );
    if( n == 0 ) cout << "0\n";
    else {
        pair< int, int > ans = lis( );
        cout << ans.FI << "\n";
        rebuildLis( ans.SE );
    }

    return 0;
}
