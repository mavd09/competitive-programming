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

int h, w;
string picture[ MAX ];

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> h >> w ) {
        for( int i = 0; i < h; i++ ) cin >> picture[ i ];
        int ans = 0;
        for( int i = 0; i < h; i++ ) {
            bool open = false;
            for( int j = 0; j < w; j++ ) {
                if( picture[ i ][ j ] != '.' ) {
                    ans += open;
                    open = !open;
                }
                else ans += open;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
    
}