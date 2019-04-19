#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         10100
#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         ( INT_MAX )/10

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    int d, p, r, b;
    
    while( cin >> d >> p >> r >> b ) {
        vector< int > cost( d+p );
        for( auto& e : cost ) cin >> e;
        vector< vector< int >  > G( d+p );
        for( int i = 0, u, v; i < r; i++ ) {
            cin >> u >> v;
            u--; v--;
            v += d;
            G[ u ].PB( v );
            G[ v ].PB( u );
        }
        int nComponents = 0;
        vector< int > cc;
        vector< pair< int, int > > cp;
        vector< bool > used( d+p, false );
        queue< int > q;
        for( int i = 0; i < d+p; i++ ) {
            if( used[ i ] == true ) continue;
            int c = 0, td = 0, tp = 0;
            q.push( i );
            used[ i ] = true;
            while( !q.empty( ) ) {
                int u = q.front( ); q.pop( );
                td +=  ( u < d );
                tp += !( u < d );
                c  += cost[ u ];
                for( auto& v : G[ u ] ) {
                    if( !used[ v ] ) {
                        used[ v ] = true;
                        q.push( v );
                    }
                }
            }
            cc.PB( c );
            cp.PB( MP( td, tp ) );
            nComponents++;
        }
        vector< int > ans( 2 );
        vector< vector< int > > dp( 2, vector< int >( MAX, 0 ) );
        for( int j = 0; j < nComponents; j++ ) {
            for( int i = b; i >= 0; i-- ) {
                dp[ 0 ][ i ] += cp[ j ].FI;
                dp[ 1 ][ i ] += cp[ j ].SE;
                if( i-cc[ j ] >= 0 ) {
                    dp[ 0 ][ i ] = max( dp[ 0 ][ i ], dp[ 0 ][ i-cc[ j ] ]+cp[ j ].SE );
                    dp[ 1 ][ i ] = max( dp[ 1 ][ i ], dp[ 1 ][ i-cc[ j ] ]+cp[ j ].FI );
                }
                ans[ 0 ] = max( ans[ 0 ], dp[ 0 ][ i ] );
                ans[ 1 ] = max( ans[ 1 ], dp[ 1 ][ i ] );
            }
        }
        cout << ans[ 0 ] << " " << ans[ 1 ] << "\n";
    }
    
    return 0;
}