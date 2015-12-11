#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         10100
#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         1e18

#define EPS         1e-9

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    int t;
    
    while( cin >> t ) {
        int ans = 0, a;
        for( int i = 0; i < 5; i++ ) {
            cin >> a;
            ans += ( t == a );
        }
        cout << ans << "\n";
    }
    
    return 0;
}