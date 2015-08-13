#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 5e4+100 )
#define MAXX 	int( 5e5+100 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, seen[ MAX ], t;
vector< int > G[ MAX ];
vector< pair< ll, int > > X[ MAXX ];

struct Point { ll x, y; }P[ MAX ];

bool can( Point a, Point b ) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) > 25;
}

int solve( ) {

    ++t;
    int subset1 = 0, subset2 = 0;
    for( int i = 0; i < n; i++ ) {
        if( seen[ i ] == t ) continue;
        int a[ 2 ];
        a[ 0 ] = a[ 1 ] = 0;
        queue< int > q;
        q.push( i );
        q.push( 0 );
        seen[ i ] = t;
        while( !q.empty( ) ) {
            int cur = q.front( ); q.pop( );
            int typ = q.front( ); q.pop( );
            a[ typ ]++;
            for( int j = 0; j < int( G[ cur ].size( ) ); j++ ) {
                if( seen[ G[ cur ][ j ] ] == t ) continue;
                seen[ G[ cur ][ j ] ] = t;
                q.push( G[ cur ][ j ] );
                q.push( !typ );
            }
        }
        subset1 += min( a[ 0 ], a[ 1 ] );
        subset2 += max( a[ 0 ], a[ 1 ] );
    }

    return min( subset1, subset2 );
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( scanf( "%d", &n ) != EOF ) {

        set< int > s;

        for( int i = 0; i < n; i++ ) {
            scanf( "%lld %lld", &P[ i ].x, &P[ i ].y );
            X[ P[ i ].x ].PB( MP( P[ i ].y, i ) );
            s.insert( P[ i ].x );
        }

        for( set< int >::iterator it = s.begin( ); it != s.end( ); it++ )
            sort( X[ (*it) ].begin( ), X[ (*it) ].end( ) );

        for( int i = 0; i < n; i++ ) {
            for( int x = max( 0LL, P[ i ].x-5 ); x <= P[ i ].x+5; x++ ) {
                int lo = 0, hi = int( X[ x ].size( ) )-1, mi;
                while( lo <= hi ) {
                    mi = ( lo+hi )/2;
                    if( X[ x ][ mi ].FI < P[ i ].y-5 ) lo = mi+1;
                    else hi = mi-1;
                }
                for( int y = lo; y < int( X[ x ].size( ) ); y++ ) {
                    if( X[ x ][ y ].FI > P[ i ].y+5 ) break;
                    if( !can( P[ i ], P[ X[ x ][ y ].SE ] ) ) G[ i ].PB( X[ x ][ y ].SE );
                }
            }
        }
        printf( "%d\n", solve( ) );

        for( int i = 0; i < n; i++ ) G[ i ].clear( );
        for( set< int >::iterator it = s.begin( ); it != s.end( ); it++ ) X[ (*it) ].clear( );

    }

    return 0;
}
