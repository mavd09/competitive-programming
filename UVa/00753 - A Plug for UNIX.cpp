#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#include <math.h>
#include <iomanip>
#include <algorithm>
#include <limits.h>

#include <complex.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define INF         ( 1<<29 )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int MAX_PLUG = 1000;
const int TAM      = 2000;
const int INF_CAP  = 1e9;

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
    
    for( int tc = 1; nTest--; tc++ ) {
        int n, m, k, idR = 0;
        map< string, int > idReceptacles;
        vector< vector< bool > > convertPlug( MAX_PLUG, vector< bool >( MAX_PLUG, false ) );
        cin >> n;
        for( int i = 0; i < n; i++ ) {
            string curReceptacle;
            cin >> curReceptacle;
            convertPlug[ idR ][ idR ] = true;
            idReceptacles[ curReceptacle ] = ++idR;
        }
        cin >> m;
        vector< int > plug( m+1 );
        for( int i = 1; i <= m; i++ ) {
            string curDevice, curPlug;
            cin >> curDevice >> curPlug;
            if( !idReceptacles.count( curPlug ) ) {
                convertPlug[ idR ][ idR ] = true;
                idReceptacles[ curPlug ] = ++idR;
            }
            plug[ i ] = idReceptacles[ curPlug ];
        }
        cin >> k;
        for( int i = 0; i < k; i++ ) {
            string curReceptacle, curPlug;
            cin >> curReceptacle >> curPlug;
            if( !idReceptacles.count( curReceptacle ) ) {
                convertPlug[ idR ][ idR ] = true;
                idReceptacles[ curReceptacle ] = ++idR;
            }
            if( !idReceptacles.count( curPlug ) ) {
                convertPlug[ idR ][ idR ] = true;
                idReceptacles[ curPlug ] = ++idR;
            }
            convertPlug[ idReceptacles[ curReceptacle ] ][ idReceptacles[ curPlug ] ] = true;
        }
        for( int k = 1; k <= idR; k++ )
            for( int i = 1; i <= idR; i++ )
                for( int j = 1; j <= idR; j++ )
                    convertPlug[ i ][ j ] = convertPlug[ i ][ j ]|( convertPlug[ i ][ k ]&convertPlug[ k ][ j ] );
        int source = 0, sink = n+m+1;
        Network netw;
        for( int i = 1; i <= m; i++ ) netw.addDirEdge( source, i, 1 );
        for( int i = 1; i <= m; i++ ) {
            for( int j = 1; j <= n; j++ ) {
                if( convertPlug[ plug[ i ] ][ j ] )
                    netw.addDirEdge( i, m+j, 1 );
            }
        }
        for( int i = 1; i <= n; i++ ) netw.addDirEdge( m+i, sink, 1 );
        if( tc > 1 ) cout << "\n";
        cout << m-netw.maxFlow( source, sink ) << "\n";
    }
    
    return 0;
    
}