#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second
#define Edge pair< int, int >

#define MAXN 100000
#define MAXB 17
#define MAXH 24

#define INF  ( 1<<29 )

typedef long long ll;

using namespace std;

int nTest, n, ans;
string board;
int dp[ 2 ][ MAXH ][ MAXB ];

int min3( int a, int b, int c ) { 
    int ret = min( a, min( b, c ) );
    ans = min( ans, ret );
    return ret;
}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    cin >> nTest;
    for( int tc = 1; nTest--; tc++ ) {
        
        cin >> board;
        n = int( board.size( ) );
    
        for( int i = 0; i < 2; i++ )
            for( int j = 0; j < MAXH; j++ )
                for( int k = 0; k < MAXB; k++ )
                    dp[ i ][ j ][ k ] = INF;
    
        board[ 0 ] = board[ n-1 ] = '.';
        dp[ 0 ][ 6 ][ 0 ] = 0;
        for( int i = 0; i < n-1; i++ ) {
            ans = INF;
            int id = i&1;
            for( int j = 0; j < MAXH; j++ ) {
                for( int k = 0; k < MAXB; k++ ) {
                    if( ( board[ i ] == '.' && k+1 <= 16 ) || ( board[ i ] == '*' && ( 6 < j && j < 18 ) && k+1 <= 16 ) )
                        dp[ !id ][ (j+1)%MAXH ][ k+1 ] = min3( dp[ !id ][ (j+1)%MAXH ][ k+1 ], dp[ id ][ j ][ k ]+1 , INF );
                    if( board[ i ] == '.' ) {
                        dp[ !id ][ (j+9)%MAXH  ][ 1 ]  = min3( dp[ !id ][ (j+9)%MAXH  ][ 1 ] , dp[ id ][ j ][ k ]+9 , INF );
                        dp[ !id ][ (j+17)%MAXH ][ 1 ]  = min3( dp[ !id ][ (j+17)%MAXH ][ 1 ] , dp[ id ][ j ][ k ]+17, INF );
                        dp[ !id ][ (j+25)%MAXH ][ 1 ]  = min3( dp[ !id ][ (j+25)%MAXH ][ 1 ] , dp[ id ][ j ][ k ]+25, INF );
                    }
                    dp[ id ][ j ][ k ] = INF;
                }
            }
        }
    
        cout << "Case #" << tc << ": ";
        if( ans == INF ) cout << -1 << "\n";
        else cout << ans << "\n";

  }

  return 0;

}
