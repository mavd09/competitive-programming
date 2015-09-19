#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second

#define MAX  400100
#define MAXN 10
#define MAXM 20
#define MAXK 1010

#define INF  ( 1<<29 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ull N, K, M[ MAXN ];
ull a[ MAXN ][ MAXM ], b[ MAXN ][ MAXM ], g[ MAXN ][ MAXM ];
ull dp[ 2 ][ MAXN ][ MAXK ];

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> N >> K ) {
        
        for( int i = 1; i <= N; i++ ) cin >> M[ i ];
        for( int i = 1; i <= N; i++ ) {
            for( int j = 0; j <= M[ i ]; j++ ) {
                if( !j )
                    a[ i ][ j ] = b[ i ][ j ] = g[ i ][ j ] = 0;
                else {
                    cin >> a[ i ][ j ] >> b[ i ][ j ] >> g[ i ][ j ];
                    a[ i ][ j ] = b[ i ][ j ]-a[ i ][ j ];
                }
            }
        }
        
        for( int i = 0; i <= N; i++ ) {
            for( int k = 0; k <= K; k++ ) {
                dp[ 0 ][ i ][ k ] = 0;
                dp[ 1 ][ i ][ k ] = 1;
            }
        }
        for( int k = 0; k <= K; k++ )
            dp[ 0 ][ 0 ][ k ] = dp[ 1 ][ 0 ][ k ] = 1;
        
        for( int i = 0; i < N; i++) {
            for( int k = 0; k <= K; k++ ) {
                for( int j = 0; j <= M[ i+1 ]; j++ ) {
                    if( k+g[ i+1 ][ j ] > K ) continue;
                    if( ( dp[ 0 ][ i+1 ][ k+g[ i+1 ][ j ] ] )*( dp[ 1 ][ i ][ k ]*b[ i+1 ][ j ]*1.0 ) <
                        ( dp[ 1 ][ i+1 ][ k+g[ i+1 ][ j ] ] )*( dp[ 0 ][ i ][ k ]*a[ i+1 ][ j ]*1.0 ) ) {
                        ull mcd = __gcd( dp[ 0 ][ i ][ k ]*a[ i+1 ][ j ], dp[ 1 ][ i ][ k ]*b[ i+1 ][ j ] );
                        dp[ 0 ][ i+1 ][ k+g[ i+1 ][ j ] ] = dp[ 0 ][ i ][ k ]*a[ i+1 ][ j ]/mcd;
                        dp[ 1 ][ i+1 ][ k+g[ i+1 ][ j ] ] = dp[ 1 ][ i ][ k ]*b[ i+1 ][ j ]/mcd;
                    }
                }
            }
        }
        
        cout << dp[ 1 ][ N ][ K ]-dp[ 0 ][ N ][ K ] << "/" << dp[ 1 ][ N ][ K ] << "\n";
        
    }
    
    return 0;
    
}