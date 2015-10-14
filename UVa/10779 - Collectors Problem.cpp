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

struct Edge {
    int to, cap, rIdx;
    Edge( ) { }
    Edge( int to, int cap, int rIdx ) :
        to( to ), cap( cap ), rIdx( rIdx ) { }
};

struct Network {
    vector< vector< Edge > > out;
    vector< bool > seen;
    
    int sink;
    
    Network( int n ) {
        out.assign( n, vector< Edge >( ) );
        seen.resize( n );
    }
    
    int augment( int i, const int cur ) {
        if( i == sink ) return cur;
        if( seen[ i ] ) return false;
        seen[ i ] = true;
        int ans;
        for( Edge& e : out[ i ] )
            if( e.cap > 0 && ( ans = augment( e.to, min( cur, e.cap ) ) ) ) {
                e.cap -= ans;
                out[ e.to ][ e.rIdx ].cap += ans;
                return ans;
            }
        return 0;
    }
    
    int maxFlow( int source, int _sink ) {
        sink = _sink;
        int curflow = 0, aug;
        while( true ) {
            fill ( seen.begin( ), seen.end( ), false );
            aug = augment( source, INT_MAX );
            if( aug == 0 ) break;
            curflow += aug;
        }
        return curflow;
    }
    
    void addDirEdge( int fr, int to, int c ) {
        out[ fr ].push_back( Edge( to, c, int( out[ to ].size( ) ) ) );
        out[ to ].push_back( Edge( fr, 0, int( out[ fr ].size( ) )-1 ) );
    }
    
};

const int BOB = 1;

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    int nTest;
    cin >> nTest;
    
    for( int tc = 1; nTest--; tc++ ) {
        int n, m;
        cin >> n >> m;
        vector< vector< int > > cnt( n+1, vector< int >( m+1, 0 ) );
        for( int i = 1, k; i <= n; i++ ) {
            cin >> k;
            for( int t; k--; ) {
                cin >> t;
                cnt[ i ][ t ]++;
            }
        }
        Network netw( n+m+2 );
        int source = 0, sink = n+m+1;
        for( int j = 1; j <= m; j++ ) {
            if( cnt[ BOB ][ j ] )
                netw.addDirEdge( source, n+j, cnt[ BOB ][ j ] );
            netw.addDirEdge( n+j, sink, 1 );
        }
        for( int i = 2; i <= n; i++ ) {
            for( int j = 1; j <= m; j++ ) {
                if( cnt[ i ][ j ] > 1 )
                    netw.addDirEdge( i, n+j, cnt[ i ][ j ]-1 );
                if( cnt[ i ][ j ] == 0 )
                    netw.addDirEdge( n+j, i, 1 );
            }
        }
        cout << "Case #" << tc << ": " << netw.maxFlow( source, sink ) << "\n";
    }
    
    return 0;
    
}