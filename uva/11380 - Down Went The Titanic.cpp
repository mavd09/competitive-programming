#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define INF         ( 2000000000 )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int dx[ ] = {  0  ,  0  ,  1  , -1  };
const int dy[ ] = {  1  , -1  ,  0  ,  0  };

const int INF_CAP = 2000;

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
    
    int X, Y, P;
    
    while( cin >> X >> Y >> P ) {
        vector< string > board( X );
        for( auto& b : board ) cin >> b;
        Dinic netw( 2*X*Y+2 );
        int source = 2*X*Y, sink = 2*X*Y+1;
        for( int i = 0; i < X; i++ ) {
            for( int j = 0; j < Y; j++ ) {
                char c = board[ i ][ j ];
                if( c == '~' ) continue;
                if( c == '*' || c == '.' ) {
                    netw.addDirEdge( i*Y+j, ( X*Y )+( i*Y+j ), 1 );
                    for( int k = 0; k < 4; k++ ) {
                        int ni = i+dx[ k ];
                        int nj = j+dy[ k ];
                        if( ni < 0 || X <= ni || nj < 0 || Y <= nj || board[ ni ][ nj ] == '~'  || board[ ni ][ nj ] == '*' )
                            continue;
                        netw.addDirEdge( ( X*Y )+( i*Y+j ), ni*Y+nj, 1 );
                    }
                    if( c == '*' ) netw.addDirEdge( source, i*Y+j, 1 );
                }
                if( c == '@' || c == '#' ) {
                    netw.addDirEdge( i*Y+j, ( X*Y )+( i*Y+j ), INF_CAP );
                    for( int k = 0; k < 4; k++ ) {
                        int ni = i+dx[ k ];
                        int nj = j+dy[ k ];
                        if( ni < 0 || X <= ni || nj < 0 || Y <= nj || board[ ni ][ nj ] == '~'  || board[ ni ][ nj ] == '*' )
                            continue;
                        netw.addDirEdge( ( X*Y )+( i*Y+j ), ni*Y+nj, INF_CAP );
                    }
                    if( c == '#' ) netw.addDirEdge( ( X*Y )+( i*Y+j ), sink, P );
                }
            }
        }
        cout << netw.maxFlow( source, sink ) << "\n";
    }
    
    return 0;
    
}