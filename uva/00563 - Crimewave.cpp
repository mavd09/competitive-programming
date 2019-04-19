#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         20
#define MAXT        60

#define INF         ( 1<<29 )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int TAM     = 6000;
const int INF_CAP = 1e9;

const int dx[ ] = {  0  ,  0  ,  1  , -1  };
const int dy[ ] = {  1  , -1  ,  0  ,  0  };

struct Edge {
    int to, cap, invIdx;
    Edge( ) { }
    Edge( int a, int b, int c ) : to( a ), cap( b ), invIdx( c ) { }
};

struct Network {
    
    vector< Edge > G[ TAM ];
    int from[ TAM ], n;
    
    int maxFlow( int A, int B ) {
        int flow = 0;
        while( true ) {
            memset( from, -1, sizeof( from ) );
            
            queue< int > q;
            q.push( A );
            from[ A ] = -2;
            for( int i; !q.empty( ); q.pop( ) ) {
                i = q.front( );
                for( Edge& e : G[ i ] )
                    if( from[ e.to ] == -1 && e.cap ) {
                        from[ e.to ] = e.invIdx;
                        q.push( e.to );
                    }
            }
            
            if( from[ B ] == -1 ) break;
            
            int aug = INF_CAP;
            for( int i = B, j; i != A; i = j ) {
                j = G[ i ][ from[ i ] ].to;
                aug = min( aug, G[ j ][ G[ i ][ from[ i ] ].invIdx ].cap );
            }
            
            for( int i = B, j; i != A; i = j ) {
                j = G[ i ][ from[ i ] ].to;
                G[ j ][ G[ i ][ from[ i ] ].invIdx ].cap -= aug;
                G[ i ][ from[ i ] ].cap += aug;
            }
            
            flow += aug;
        }
        
        return flow;
    }
    
    void addNonDirEdge( int a, int b, int c ) {
        G[ a ].push_back( Edge( b, c, int( G[ b ].size( ) ) ) );
        G[ b ].push_back( Edge( a, c, int( G[ a ].size( ) )-1 ) );
    }
    
    void addDirEdge( int a, int b, int c ) {
        G[ a ].push_back( Edge( b, c, int( G[ b ].size( ) ) ) );
        G[ b ].push_back( Edge( a, 0, int( G[ a ].size( ) )-1 ) );
    }
    
};

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    int nTest;
    cin >> nTest;
    
    while( nTest-- ) {
        int s, a, b;
        cin >> s >> a >> b;
        Network netw;
        int source = 0, sink = 2*s*a+1;
        for( int i = 1; i <= s; i++ ) {
            for( int j = 1; j <= a; j++ ) {
                int u = ( ( i-1 )*a+j );
                netw.addDirEdge( u, s*a+u, 1 );
                u = s*a+u;
                for( int k = 0; k < 4; k++ ) {
                    int ni = i+dx[ k ];
                    int nj = j+dy[ k ];
                    if( 1 <= ni && ni <= s && 1 <= nj && nj <= a )
                        netw.addDirEdge( u, ( ni-1 )*a+nj, 1 );
                }
                if( i == 1 || i == s || j == 1 || j == a )
                    netw.addDirEdge( u, sink, 1 );
            }
        }
        for( int i = 0, u, v; i < b; i++ ) {
            cin >> u >> v;
            netw.addDirEdge( source, ( u-1 )*a+v, 1 );
        }
        if( netw.maxFlow( source, sink ) == b ) cout << "possible\n";
        else                                    cout << "not possible\n";
    }
    
    return 0;
    
}