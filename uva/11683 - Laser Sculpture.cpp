#include <bits/stdc++.h>

#define FILE    0

#define MP      make_pair
#define PB      push_back
#define FI      first
#define SE      second

#define MAX     55

#define INF     ( 1<<29 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    if( FILE&1 ) freopen( "input" , "r", stdin  );
    if( FILE&2 ) freopen( "output", "w", stdout );

    int r, c, lst;
    while( ( cin >> r ) && ( r > 0 ) ) {
        cin >> c;
        vector< int > H( c );
        lst = r;
        int ans = 0;
        for( auto& h : H ) {
            cin >> h;
            if( lst > h ) ans += lst-h;
            lst = h;
        }
        cout << ans << "\n";
    }

    return 0;
}
