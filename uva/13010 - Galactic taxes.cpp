#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         10100
#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         1e18

#define EPS         1e-9

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Edge {
    int v;
    double a, b;
    Edge( ) { }
    Edge( int v, double a, double b ) : v( v ), a( a ), b( b ) { }
};

struct State {
    int u;
    double d;
    State( ) { }
    State( int u, double d ) : u( u ), d( d ) { }
};

struct cmp {
    bool operator( ) ( const State& a, const State& b ) {
        return a.d > b.d;
    }
};

double dijkstra( int& n, vector< vector< Edge > >& G, double t ) {
    vector< double > minDist( n, INF );
    vector< bool > used( n, false );
    priority_queue< State, vector< State >, cmp > Q;
    Q.push( State( 0, 0 ) );
    minDist[ 0 ] = 0;
    while( !Q.empty( ) ) {
        int u = Q.top( ).u; Q.pop( );
        if( u == n-1 ) return minDist[ u ];
        for( int i = 0; i < int( G[ u ].size( ) ); i++ ) {
            int v = G[ u ][ i ].v;
            double c = G[ u ][ i ].a*t+G[ u ][ i ].b;
            if( minDist[ u ]+c < minDist[ v ] ) {
                minDist[ v ] = minDist[ u ]+c;
                Q.push( State( v, minDist[ v ] ) );
            }
        }
    }
    return -1;
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    int n, m;
    
    while( cin >> n >> m ) {
        vector< vector< Edge > > G( n );
        int u, v;
        double a, b;
        for( int i = 0; i < m; i++ ) {
            cin >> u >> v >> a >> b;
            u--; v--;
            G[ u ].PB( Edge( v, a, b ) );
            G[ v ].PB( Edge( u, a, b ) );
        }
        double lo = 0, hi = 24.0*60.0, mi1, mi2;
        for( int i = 0; i < 164; i++ ) {
            mi1 = lo+( hi-lo )/3.0;
            mi2 = lo+2.0*( hi-lo )/3.0;
            if( dijkstra( n, G, mi1 ) < dijkstra( n, G, mi2 ) )
                lo = mi1;
            else hi = mi2;
        }
        cout << fixed << setprecision( 5 ) << dijkstra( n, G, lo ) << "\n";
    }
    
    return 0;
}