#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         100100
#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         ( INT_MAX )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m;
vector< pair< int, int > > G[ MAX ];
int d[ MAX ];

void solve( ) {
    memset( d, -1, sizeof( d ) );
    
    queue< int > q;
    q.push( n );
    d[ n ] = 0;
    while( !q.empty( ) ) {
        int u = q.front( ); q.pop( );
        for( auto v : G[ u ] ) {
            if( d[ v.FI ] == -1 ) {
                q.push( v.FI );
                d[ v.FI ] = d[ u ]+1;
            }
        }
    }
    
    set< int > Q;
    Q.insert( 1 );
    
    cout << d[ 1 ] << "\n";
    
    for( int i = 0; i < d[ 1 ]; i++ ) {
        int bestColor = INF;
        set< int > bestNodes;
        for( auto& u : Q ) {
            for( auto& v : G[ u ] ) {
                if( d[ v.FI ]+1 == d[ u ] ) {
                    if( v.SE < bestColor ) {
                        bestColor = v.SE;
                        bestNodes.clear( );
                        bestNodes.insert( v.FI );
                    }
                    else if( v.SE == bestColor )
                        bestNodes.insert( v.FI );
                }
            }
        }
        if( i ) cout << " ";
        cout << bestColor;
        Q = bestNodes;
    }
    
    cout << "\n";
    
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> n >> m ) {
        for( int i = 0; i <= n; i++ ) G[ i ].clear( );
        for( int i = 0, u, v, c; i < m; i++ ) {
            cin >> u >> v >> c;
            G[ u ].PB( MP( v, c ) );
            G[ v ].PB( MP( u, c ) );
        }
        solve( );
    }
    
    return 0;
    
}
