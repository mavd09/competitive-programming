#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second

#define MAX 32

#define INF  INT_MAX/10

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int p;
int t[ MAX ][ MAX ];

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    for( int i = 0; i < MAX; i++ ) t[ i ][ 0 ] = t[ i ][ i ] = 1;
    for( int i = 1; i < MAX; i++ )
        for( int j = 1; j < i; j++ )
            t[ i ][ j ] = t[ i-1 ][ j ]+t[ i-1 ][ j-1 ];
    
    while( cin >> p ) {
        int ans1 = 0, ans2 = 0, sgn;
        for( int i = 0; i < MAX; i++ ) {
            if( p&(1<<i) ) {
                sgn = 1;
                for( int j = 0; j < i+1; j++ ) {
                    int k = (i-j)%4;
                    if( k == 0 ) ans1 += t[ i ][ j ]*sgn;
                    if( k == 1 ) ans2 += t[ i ][ j ]*sgn;
                    if( k == 2 ) ans1 -= t[ i ][ j ]*sgn;
                    if( k == 3 ) ans2 -= t[ i ][ j ]*sgn;
                    sgn *= -1;
                }
            }
        }
        cout << ans1 << " " << ans2 << "\n";
    }
    
    return 0;
    
}