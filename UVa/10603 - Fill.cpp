#include <bits/stdc++.h>

#define FILE    0

#define MP      make_pair
#define PB      push_back
#define FI      first
#define SE      second

#define MAX     40100

#define INF     ( 1<<29 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct State {
    int a, b, c, d;
    State( ) { }
    State( int a, int b, int c, int d ) : a( a ), b( b ), c( c ), d( d ) { }
};

void go( int& CA, int& CB, int& CC, int& D ) {
    vector< vector< int > > minDist( CA+2, vector< int >( CB+2, INF ) );
    vector< int > ans( max( CA, max( CB, CC ) )+2, INF );
    queue< State > q;
    q.push( State( 0, 0, CC, 0 ) );
    minDist[ 0 ][ 0 ] = 0;
    while( !q.empty( ) ) {
        State cur = q.front( ); q.pop( );

        ans[ cur.a ] = min( ans[ cur.a ], cur.d );
        ans[ cur.b ] = min( ans[ cur.b ], cur.d );
        ans[ cur.c ] = min( ans[ cur.c ], cur.d );

        if( minDist[ cur.a ][ cur.b ] < cur.d ) continue;

        int r;
        if( cur.a > 0 ) {
            if( cur.b < CB ) {
                r = min( cur.a, CB-cur.b );
                if( minDist[ cur.a-r ][ cur.b+r ] > minDist[ cur.a ][ cur.b ]+r ) {
                    minDist[ cur.a-r ][ cur.b+r ] = minDist[ cur.a ][ cur.b ]+r;
                    q.push( State( cur.a-r, cur.b+r, cur.c, cur.d+r ) );
                }
            }
            if( cur.c < CC ) {
                r = min( cur.a, CC-cur.c );
                if( minDist[ cur.a-r ][ cur.b ] > minDist[ cur.a ][ cur.b ]+r ) {
                    minDist[ cur.a-r ][ cur.b ] = minDist[ cur.a ][ cur.b ]+r;
                    q.push( State( cur.a-r, cur.b, cur.c+r, cur.d+r ) );
                }
            }
        }

        if( cur.b > 0 ) {
            if( cur.a < CA ) {
                r = min( cur.b, CA-cur.a );
                if( minDist[ cur.a+r ][ cur.b-r ] > minDist[ cur.a ][ cur.b ]+r ) {
                    minDist[ cur.a+r ][ cur.b-r ] = minDist[ cur.a ][ cur.b ]+r;
                    q.push( State( cur.a+r, cur.b-r, cur.c, cur.d+r ) );
                }
            }
            if( cur.c < CC ) {
                r = min( cur.b, CC-cur.c );
                if( minDist[ cur.a ][ cur.b-r ] > minDist[ cur.a ][ cur.b ]+r ) {
                    minDist[ cur.a ][ cur.b-r ] = minDist[ cur.a ][ cur.b ]+r;
                    q.push( State( cur.a, cur.b-r, cur.c+r, cur.d+r ) );
                }
            }
        }

        if( cur.c > 0 ) {
            if( cur.a < CA ) {
                r = min( cur.c, CA-cur.a );
                if( minDist[ cur.a+r ][ cur.b ] > minDist[ cur.a ][ cur.b ]+r ) {
                    minDist[ cur.a+r ][ cur.b ] = minDist[ cur.a ][ cur.b ]+r;
                    q.push( State( cur.a+r, cur.b, cur.c-r, cur.d+r ) );
                }
            }
            if( cur.b < CB ) {
                r = min( cur.c, CB-cur.b );
                if( minDist[ cur.a ][ cur.b+r ] > minDist[ cur.a ][ cur.b ]+r ) {
                    minDist[ cur.a ][ cur.b+r ] = minDist[ cur.a ][ cur.b ]+r;
                    q.push( State( cur.a, cur.b+r, cur.c-r, cur.d+r ) );
                }
            }
        }
    }

    while( ans[ D ] == INF ) D--;
    cout << ans[ D ] << " " << D << "\n";

}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    if( FILE&1 ) freopen( "input" , "r", stdin  );
    if( FILE&2 ) freopen( "output", "w", stdout );

    int nTest;
    cin >> nTest;
    while( nTest-- ) {
        int CA, CB, CC, D;
        cin >> CA >> CB >> CC >> D;
        go( CA, CB, CC, D );
    }

    return 0;
}
