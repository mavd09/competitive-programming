#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second
#define Edge pair< int, int >

#define MAXN 100000
#define MAXS 10

#define INF  ( 1<<29 )

typedef long long ll;

using namespace std;

int N, M;
int G[ 30 ][ 2 ];
bool valid[ 30 ];
int dp[ 40 ][ 40 ];
char u, a, b, t;

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
  
    while( cin >> N ) {
        for( int i = 0; i < N; i++ ) {
            cin >> u >> a >> b >> t;
            G[ u-'A' ][ 0 ] = a-'A';
            G[ u-'A' ][ 1 ] = b-'A';
            valid[ u-'A' ] = ( t == 'x' );
        }
        cin >> M;

        memset( dp, 0, sizeof( dp ) );
        dp[ 0 ][ 0 ] = 1;
        for( int j = 0; j < M; j++ ) {
            for( int i = 0; i < N; i++ ) {
                dp[ G[ i ][ 0 ] ][ j+1 ] += dp[ i ][ j ];
                dp[ G[ i ][ 1 ] ][ j+1 ] += dp[ i ][ j ];
            }
        }

        int ans = 0;
        for( int i = 0; i < N; i++ ) {
            if( valid[ i ] )
                ans += dp[ i ][ M ];
        }
        cout << ans << "\n";
    }

    return 0;

}
