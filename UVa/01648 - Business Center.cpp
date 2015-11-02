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

int n, m, u, d;

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> n >> m ) {
        int ans = INT_MAX;
        for( int i = 0; i < m; i++ ) {
            cin >> u >> d;
            int x = d*n/( u+d )+1;
            ans = min( ans, ( u+d )*x - d*n );
        }
        cout << ans << "\n";
    }
    
    return 0;
    
}