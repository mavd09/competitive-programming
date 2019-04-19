#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         100
#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         ( INT_MAX )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int INF_CAP = 2000000000;

struct Edge {
    int from, to, cap, flow, index;
    Edge( int from, int to, int cap, int flow, int index ) :
    from( from ), to( to ), cap( cap ), flow( flow ), index( index ) { }
};

struct Dinic {
    int N;
    vector< vector< Edge > > G;
    vector< Edge* > dad;
    vector< int > Q;
    
    Dinic( int N ) : N( N ), G( N ), dad( N ), Q( N ) { }
    
    void addDirEdge( int from, int to, int cap ) {
        G[ from ].push_back( Edge( from, to, cap, 0, int( G[ to ].size( ) ) ) );
        if( from == to ) G[ from ].back( ).index++;
        G[ to ].push_back( Edge( to, from, 0, 0, int( G[ from ].size( ) )-1 ) );
    }
    
    ll blockingFlow( int s, int t ) {
        fill( dad.begin( ), dad.end( ), ( Edge* ) NULL );
        dad[ s ] = &G[ 0 ][ 0 ]-1;
        
        int head = 0, tail = 0;
        Q[ tail++ ] = s;
        while( head < tail ) {
            int x = Q[ head++ ];
            for( int i = 0; i < int( G[ x ].size( ) ); i++ ) {
                Edge &e = G[ x ][ i ];
                if( !dad[ e.to ] && e.cap-e.flow > 0 ) {
                    dad[ e.to ] = &G[ x ][ i ];
                    Q[ tail++ ] = e.to;
                }
            }
        }
        if( !dad[ t ] ) return 0;
        
        ll totflow = 0;
        for( int i = 0; i < G[ t ].size( ); i++ ) {
            Edge *start = &G[ G[ t ][ i ].to ][ G[ t ][ i ].index ];
            int amt = INF_CAP;
            for( Edge *e = start; amt && e != dad[ s ]; e = dad[ e->from ] ) {
                if( !e ) { amt = 0; break; }
                amt = min( amt, e->cap-e->flow );
            }
            if( amt == 0 ) continue;
            for( Edge *e = start; amt && e != dad[ s ]; e = dad[ e->from ] ) {
                e->flow += amt;
                G[ e->to ][ e->index ].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }
    
    ll maxFlow( int s, int t ) {
        ll totflow = 0;
        while( ll flow = blockingFlow( s, t ) )
            totflow += flow;
        return totflow;
    }
};

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    map< string, int > id;
    
    id[ "XXL" ] = 0;
    id[ "XL" ]  = 1;
    id[ "L" ]   = 2;
    id[ "M" ]   = 3;
    id[ "S" ]   = 4;
    id[ "XS" ]  = 5;

    int nTest, n, m;
    int source = 36, sink = 37;
    string op1, op2;
    cin >> nTest;
    
    while( nTest-- ) {
        cin >> n >> m;
        Dinic netw( 38 );
        n /= 6;
        for( int i = 0; i < 6; i++ ) netw.addDirEdge( source, i, n );
        for( int i = 6; i < source; i++ ) netw.addDirEdge( i, sink, 1 );
        for( int i = 0; i < m; i++ ) {
            cin >> op1 >> op2;
            netw.addDirEdge( id[ op1 ], 6+i, 1 );
            netw.addDirEdge( id[ op2 ], 6+i, 1 );
        }
        if( netw.maxFlow( source, sink ) == m ) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
    
}