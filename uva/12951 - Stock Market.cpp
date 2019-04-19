#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second

#define MAX 200100

#define INF  INT_MAX/10

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, c;
int b[ MAX ];
int dp[ MAX ][ 2 ];

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> n >> c ) {
        for( int i = 0; i < n; i++ ) cin >> b[ i ];
        dp[ n ][ 0 ] = dp[ n ][ 1 ] = 0;
        for( int i = n-1; i >= 0; i-- ) {
            dp[ i ][ 0 ] = max( dp[ i+1 ][ 1 ]-c-b[ i ], dp[ i+1 ][ 0 ] );
            dp[ i ][ 1 ] = max( dp[ i+1 ][ 0 ]+b[ i ], dp[ i+1 ][ 1 ] );
        }
        cout << dp[ 0 ][ 0 ] << "\n";
    }
    
    return 0;
    
}