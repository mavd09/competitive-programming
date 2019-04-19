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
    
    string line;
    
    int nTest;
    cin >> nTest;
    cin.ignore( );
    getline( cin, line );
    
    for( int tc = 1; nTest--; tc++ ) {
        
        vector< string > data;
        int idN = 0, idP = 0, idC = 0;
        map< string, int > N, P, C;
        map< int, string > RN, RP, RC;
        string name, politicalParty, club;
        Network netw;
        
        while( ( getline( cin, line ) ) && ( line != "" ) ) {
            stringstream ss( line );
            data.PB( line );
            ss >> name >> politicalParty;
            if( !N.count( name ) ) {
                ++idN;
                N[ name ] = idN;
                RN[ idN ] = name;
            }
            if( !P.count( politicalParty ) ) {
                ++idP;
                P[ politicalParty ] = idP;
                RP[ idP ] = politicalParty;
            }
            while( ss >> club ) {
                if( !C.count( club ) ) {
                    ++idC;
                    C[ club ] = idC;
                    RC[ idC ] = club;
                }
            }
        }
        
        int source = 0, sink = idP+idN+idC+1;
        
        for( auto input : data ) {
            stringstream ss( input );
            ss >> name >> politicalParty;
            netw.addDirEdge( P[ politicalParty ], idP+N[ name ], 1 );
            while( ss >> club ) netw.addDirEdge( idP+N[ name ], idP+idN+C[ club ], 1 );
        }
        
        int maxPerParty = ( idC-1 )/2;
        for( int i = 1; i <= idP; i++ ) netw.addDirEdge( source, i, maxPerParty );
        for( int i = 1; i <= idC; i++ ) netw.addDirEdge( idP+idN+i, sink, 1 );
        
        if( tc > 1 ) cout << "\n";
        if( netw.maxFlow( source, sink ) == idC ) {
            for( int i = 1; i <= idN; i++ ) {
                for( auto& cur : netw.G[ idP+i ] ) {
                    if( cur.cap == 0 && idP+idN < cur.to && cur.to < sink ) {
                        cout << RN[ i ] << " "  << RC[ cur.to-idP-idN ] << "\n";
                    }
                }
            }
        }
        else cout << "Impossible.\n";
        
    }
    
    return 0;
    
}