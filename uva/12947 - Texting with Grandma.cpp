#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second

#define MAX  100100
#define MAX_LEN  10100
#define MAXN 10
#define MAXM 20
#define MAXK 1010

#define INF  ( 1<<29 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

string line;
int v, id;
int t[ MAX ], cnt[ MAX ];
vector< int > G[ MAX ];
priority_queue< int > Q;

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    for( int tc = 1; getline( cin, line ); tc++ ) {
        
        if( tc > 1 ) cout << "*\n";
        memset( cnt, 0, sizeof( cnt ) );
        for( int i = 0; i < MAX; i++ ) G[ i ].clear( );
        while( !Q.empty( ) ) Q.pop( );
        
        stringstream ss( line );
        for( v = 0; ss >> t[ v ]; v++ )
            cnt[ t[ v ] ]++;
        
        v += 2;
        bool can = true;
        
        for( int i = 0; i < v; i++ )
            if( cnt[ i ] == 0 )
                Q.push( -i );
        
        for( int i = 0; i < v-2; i++ ) {
            if( t[ i ] >= v ) {
                can = false;
                break;
            }
            if( Q.empty( ) ) {
                can = false;
                break;
            }
            id = -Q.top( ); Q.pop(  );
            G[ t[ i ] ].PB( id );
            G[ id ].PB( t[ i ] );
            cnt[ t[ i ] ]--;
            if( cnt[ t[ i ] ] == 0 ) Q.push( -t[ i ] );
        }
        
        if( can ) {
            
            int a, b;
            a = -Q.top( ); Q.pop(  );
            b = -Q.top( ); Q.pop(  );
            
            G[ a ].PB( b );
            G[ b ].PB( a );
            
            cout << v << "\n";
            for( int i = 0; i < v; i++ ) {
                sort( G[ i ].begin( ), G[ i ].end( ) );
                for( int j = 0; j < int( G[ i ].size( ) ); j++ ) {
                    if( j ) cout << " ";
                    cout << G[ i ][ j ];
                }
                cout << "\n";
            }
            
        }
        else cout << "impossible\n";
        
    }
    
    return 0;
    
}
