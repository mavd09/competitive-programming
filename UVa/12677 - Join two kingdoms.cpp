#include <bits/stdc++.h>

#define FILE 	1
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 4e4+100 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, q;
int fr, to;
int H[ 3 ][ MAX ][ 3 ];
int diam[ 3 ];
vector< int > G[ 3 ][ MAX ];
int seen[ MAX ];

int dfs( int t, int v ) {
    if( seen[ v ] == t ) return 0;
    seen[ v ] = t;
    for( int i = 0; i < int( G[ t ][ v ].size( ) ); i++ ) {
        int u = G[ t ][ v ][ i ];
        if( seen[ u ] != t ) {
            int h = dfs( t, u )+1;
            if( h > H[ t ][ v ][ 0 ] ) {
                H[ t ][ v ][ 1 ] = H[ t ][ v ][ 0 ];
                H[ t ][ v ][ 0 ] = h;
            }
            else {
                H[ t ][ v ][ 1 ] = max( H[ t ][ v ][ 1 ], h );
            }
        }
    }
    return H[ t ][ v ][ 0 ];
}

void bfs( int t ) {
    queue< int > q;
    q.push( 1 );
    seen[ 1 ] = t;
    while( !q.empty( ) ) {
        int v = q.front( ); q.pop( );
        diam[ t ] = max( diam[ t ], H[ t ][ v ][ 0 ]+H[ t ][ v ][ 1 ] );
        for( int i = 0; i < int( G[ t ][ v ].size( ) ); i++ ) {
            int u = G[ t ][ v ][ i ];
            if( seen[ u ] != t ) {
                seen[ u ] = t;
                if( H[ t ][ v ][ 0 ]-1 == H[ t ][ u ][ 0 ] ) {
                    H[ t ][ u ][ 1 ] = max( H[ t ][ u ][ 1 ], H[ t ][ v ][ 1 ]+1 );
                    if( H[ t ][ u ][ 0 ] < H[ t ][ u ][ 1 ] ) swap( H[ t ][ u ][ 0 ], H[ t ][ u ][ 1 ] );
                }
                else {
                    int cur =  H[ t ][ v ][ 0 ]+1;
                    if( cur > H[ t ][ u ][ 0 ] ) {
                        H[ t ][ u ][ 1 ] = H[ t ][ u ][ 0 ];
                        H[ t ][ u ][ 0 ] = cur;
                    }
                    else {
                        H[ t ][ u ][ 1 ] = max( H[ t ][ u ][ 1 ], cur );
                    }
                }
                q.push( u );
            }
        }
    }
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( scanf( "%d %d", &n, &q ) != EOF ) {

        for( int i = 0; i <= max( n, q ); i++ ) {
            seen[ i ] = 0;
            G[ 1 ][ i ].clear( );
            G[ 2 ][ i ].clear( );
            H[ 1 ][ i ][ 0 ] = H[ 1 ][ i ][ 1 ] = 0;
            H[ 2 ][ i ][ 0 ] = H[ 2 ][ i ][ 1 ] = 0;
            diam[ 1 ] = diam[ 2 ] = 0;
        }

        for( int i = 1; i < n; i++ ) {
            scanf( "%d %d", &fr, &to );
            G[ 1 ][ fr ].PB( to );
            G[ 1 ][ to ].PB( fr );
        }
        for( int i = 1; i < q; i++ ) {
            scanf( "%d %d", &fr, &to );
            G[ 2 ][ fr ].PB( to );
            G[ 2 ][ to ].PB( fr );
        }

        double ans = 0;
        memset( seen, 0, sizeof( seen ) );
        dfs( 1, 1 );
        dfs( 2, 1 );
        memset( seen, 0, sizeof( seen ) );
        bfs( 1 );
        bfs( 2 );

        int n1 = 0, n2 = 0, q1 = 0, q2 = 0;
        for( int i = 1; i <= n; i++ ) {
            if( H[ 1 ][ i ][ 0 ] < diam[ 2 ]/2 ) n1++;
            else n2++;
        }
        for( int i = 1; i <= q; i++ ) {
            if( H[ 2 ][ i ][ 0 ] < diam[ 1 ]/2 ) q1++;
            else q2++;
        }

        cout << n1 << " " << n2 << " " << q1 << " " << q2 << endl;

        for( int i = 1; i <= n; i++ ) {
            if( H[ 1 ][ i ][ 0 ] < diam[ 2 ]/2 ) { }
            else ans += ( H[ 1 ][ i ][ 0 ] )*q2;
        }
        for( int i = 1; i <= q; i++ ) {
            if( H[ 2 ][ i ][ 0 ] < diam[ 1 ]/2 ) { }
            else ans += ( H[ 2 ][ i ][ 0 ] )*n2;
        }
        ans += diam[ 2 ]*n1*q2;
        ans += diam[ 1 ]*q1*n2;
        ans += q2*n2;
        ans /= n*q*1.0;
        printf( "%.3f\n", ans );

    }

    return 0;
}
