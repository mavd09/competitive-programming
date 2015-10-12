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

    string str;

    for( int L, lastR = -INF, lastD = -INF, ans = INF; ( cin >> L ) && ( L > 0 ); lastR = lastD = -INF, ans = INF ) {
        cin >> str;
        for( int i = 0; i < L && ans > 0; i++ ) {
            if( str[ i ] == 'D' ) ans = min( ans, i-lastR ), lastD = i;
            if( str[ i ] == 'R' ) ans = min( ans, i-lastD ), lastR = i;
            if( str[ i ] == 'Z' ) ans = 0;
        }
        cout << ans << "\n";
    }

    return 0;
}
