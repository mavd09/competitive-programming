#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         1010
#define LOG_MAX     14

#define MAX_TIME    4000

#define INF         ( INT_MAX )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m;

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( ( cin >> n >> m ) && ( n+m > 0 ) ) {
        vector< int > dp( n ), row( m );
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < m; j++ ) {
                cin >> row[ j ];
                if( j ) {
                    if( j == 1 ) row[ j ] = max( row[ j-1 ], row[ j ] );
                    else         row[ j ] = max( row[ j-2 ]+row[ j ], row[ j-1 ] );
                }
            }
            dp[ i ] = row[ m-1 ];
            if( i ) {
                if( i == 1 ) dp[ i ] = max( dp[ i ], dp[ i-1 ] );
                else         dp[ i ] = max( dp[ i-2 ]+dp[ i ], dp[ i-1 ] );
            }
        }
        cout << dp[ n-1 ] << "\n";
    }
    
    return 0;
    
}