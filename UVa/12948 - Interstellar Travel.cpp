#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second

#define MAX_PLANETS 310

#define INF  INT_MAX/10

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Edge {
    int v, c, t;
    Edge( ) { }
    Edge( int v, int c, int t ) : v( v ), c( c ), t( t ) { }
};

struct State {
    int v, c, t, n;
    State( ) { }
    State( int v, int c, int t, int n ) : v( v ), c( c ), t( t ), n( n ) { }
};

struct cmp {
    bool operator( ) ( const State& a, const State& b ) {
        if( a.c != b.c ) return a.c > b.c;
        return a.t > b.t;
    }
};

int p, f, q, id;
int C[ MAX_PLANETS ][ MAX_PLANETS ], T[ MAX_PLANETS ][ MAX_PLANETS ];
bool used[ MAX_PLANETS ][ MAX_PLANETS ];
vector< Edge > G[ MAX_PLANETS ];
map< string, int > ID;

void initialize( ) {
    id = 0;
    ID.clear( );
    for( int i = 0; i < MAX_PLANETS; i++ ) {
        G[ i ].clear( );
        for( int j = 0; j < MAX_PLANETS; j++ ) {
            C[ i ][ j ] = T[ i ][ j ] = INF;
            used[ i ][ j ] = false;
        }
    }
}

int getId( string planet ) {
    if( ID.count( planet ) ) return ID[ planet ];
    int ret = id++;
    ID[ planet ] = ret;
    return ret;
}

void bellmanFord( int u ) {
    
    int v, c, t;
    C[ u ][ 0 ] = T[ u ][ 0 ] = 0;
    for( int k = 1; k < MAX_PLANETS; k++ ) {
        for( int i = 0; i < p; i++ ) {
            if( C[ i ][ k-1 ] < C[ i ][ k ] ) {
                C[ i ][ k ] = C[ i ][ k-1 ];
                T[ i ][ k ] = T[ i ][ k-1 ];
            }
            else if( C[ i ][ k-1 ] == C[ i ][ k ] ) {
                T[ i ][ k ] = min( T[ i ][ k ], T[ i ][ k-1 ] );
            }
            for( int j = 0; j < int( G[ i ].size( ) ); j++ ) {
                v = G[ i ][ j ].v; c = G[ i ][ j ].c; t = G[ i ][ j ].t;
                if( C[ i ][ k-1 ]+c < C[ v ][ k ] ) {
                    C[ v ][ k ] = C[ i ][ k-1 ]+c;
                    T[ v ][ k ] = T[ i ][ k-1 ]+t;
                }
                else if( C[ i ][ k-1 ]+c == C[ v ][ k ] ) {
                    T[ v ][ k ] = min( T[ v ][ k ], T[ i ][ k-1 ]+t );
                }
            }
        }
    }
    
}

void dijkstra( int u ) {
    int v, c, t, n;
    priority_queue< State, vector< State >, cmp > Q;
    Q.push( State( u, 0, 0, 0 ) );
    C[ u ][ 0 ] = T[ u ][ 0 ] = 0;
    
    while( !Q.empty( ) ) {
        v = Q.top( ).v; c = Q.top( ).c;
        t = Q.top( ).t; n = Q.top( ).n;
        Q.pop( );
        if( used[ v ][ n ] ) continue;
        used[ v ][ n ] = true;
        for( int i = 0; i < int( G[ v ].size( ) ); i++ ) {
            if( n+1 < MAX_PLANETS && !used[ G[ v ][ i ].v ][ n+1 ] ) {
                if( c+G[ v ][ i ].c < C[ G[ v ][ i ].v ][ n+1 ] ) {
                    C[ G[ v ][ i ].v ][ n+1 ] = c+G[ v ][ i ].c;
                    T[ G[ v ][ i ].v ][ n+1 ] = t+G[ v ][ i ].t;
                    Q.push( State( G[ v ][ i ].v, c+G[ v ][ i ].c, t+G[ v ][ i ].t, n+1 ) );
                }
                else if( c+G[ v ][ i ].c == C[ G[ v ][ i ].v ][ n+1 ] && t+G[ v ][ i ].t < T[ G[ v ][ i ].v ][ n+1 ] ) {
                    T[ G[ v ][ i ].v ][ n+1 ] = t+G[ v ][ i ].t;
                    Q.push( State( G[ v ][ i ].v, c+G[ v ][ i ].c, t+G[ v ][ i ].t, n+1 ) );
                }
            }
        }
    }
    
    for( int n = 1; n < MAX_PLANETS; n++ ) {
        for( int i = 0; i < p; i++ ) {
            if( C[ i ][ n-1 ] < C[ i ][ n ] ) {
                C[ i ][ n ] = C[ i ][ n-1 ];
                T[ i ][ n ] = T[ i ][ n-1 ];
            }
            else if( C[ i ][ n-1 ] == C[ i ][ n ] ) {
                T[ i ][ n ] = min( T[ i ][ n ], T[ i ][ n-1 ] );
            }
        }
    }
    
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    for( int tc = 1; ( cin >> p >> f >> q ); tc++ ) {
        
        if( tc > 1 ) cout << ".\n";
        
        initialize( );
        string frPlanet, toPlanet, planet;
        int n, u, v, c, t;
        for( int i = 0; i < p; i++ ) {
            cin >> planet;
            getId( planet );
        }
        
        for( int i = 0; i < f; i++ ) {
            cin >> frPlanet >> toPlanet >> c >> t;
            u = getId( frPlanet );
            v = getId( toPlanet );
            G[ u ].PB( Edge( v, c, t ) );
        }
        
        cin >> frPlanet;
        u = getId( frPlanet );
        bellmanFord( u );
        //dijkstra( u );
        
        for( int i = 0; i < q; i++ ) {
            cin >> toPlanet >> n;
            v = getId( toPlanet );
            if( C[ v ][ n+1 ] != INF )
                cout << C[ v ][ n+1 ] << " " << T[ v ][ n+1 ] << "\n";
            else
                cout << "* *\n";
        }
        
    }
    
    return 0;
    
}