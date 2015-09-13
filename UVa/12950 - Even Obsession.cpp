#include <bits/stdc++.h>

#define PB  push_back
#define MP  make_pair
#define FI  first
#define SE  second

#define MAXC    10100
#define MAXV    50100

#define INF    INT_MAX/10

using namespace std;

struct State {
    int v, c, n;
    State( ) { }
    State( int v, int c, int n ) : v( v ), c( c ), n( n ) { }
};

struct cmp {
    bool operator( ) ( const State& a, const State& b ) {
        return a.c > b.c;
    }
};

int C, V;
int minDist[ MAXC ][ 2 ];
vector< pair< int, int > > G[ MAXC ];
bool used[ MAXC ][ 2 ];

void initialize( ) {
    for( int i = 0; i < MAXC; i++ ) G[ i ].clear( ), minDist[ i ][ 0 ] = minDist[ i ][ 1 ] = INF;
    memset( used, false, sizeof( used ) );

}

int dijkstra( ) {

    priority_queue< State, vector< State >, cmp > Q;
    minDist[ 1 ][ 0 ] = 0;
    Q.push( State( 1, 0, 0 ) );

    while( !Q.empty( ) ) {
        State cur = Q.top( ); Q.pop( );
        if( used[ cur.v ][ cur.n%2 ] ) continue;
        used[ cur.v ][ cur.n%2 ] = true;
        for( int i = 0, v, c; i < int( G[ cur.v ].size( ) ); i++ ) {
            v = G[ cur.v ][ i ].FI;
            c = G[ cur.v ][ i ].SE;
            if( minDist[ v ][ (cur.n+1)%2 ] > minDist[ cur.v ][ cur.n%2 ]+c ) {
                minDist[ v ][ (cur.n+1)%2 ] = minDist[ cur.v ][ cur.n%2 ]+c;
                Q.push( State( v, minDist[ v ][ (cur.n+1)%2 ], (cur.n+1)%2 ) );
            }
        }
    }

    if( minDist[ C ][ 0 ] != INF ) return minDist[ C ][ 0 ];
    return -1;

}

int main( ) {

    while( cin >> C >> V ) {
        initialize( );
        for( int i = 0, u, v, c; i < V; i++ ) {
            cin >> u >> v >> c;
            G[ u ].PB( MP( v, c) );
            G[ v ].PB( MP( u, c) );
        }
        cout << dijkstra( ) << "\n";
    }

    return 0;
}
