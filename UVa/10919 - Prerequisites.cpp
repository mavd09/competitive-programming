#include <bits/stdc++.h>

#define FILE    0

#define MP      make_pair
#define PB      push_back
#define FI      first
#define SE      second

#define MAX     1001000

#define INF     ( 1LL<<60 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    if( FILE&1 ) freopen( "input" , "r", stdin  );
    if( FILE&2 ) freopen( "output", "w", stdout );

    int k, m;
    while( ( cin >> k ) && ( k > 0 ) ) {
        cin >> m;
        set< string > course;
        string w;
        for( int i = 0; i < k; i++ ) {
            cin >> w;
            course.insert( w );
        }
        int ans = 0;
        for( int i = 0, c, r, cnt; i < m; i++ ) {
            cin >> c >> r;
            cnt = 0;
            for( int j = 0; j < c; j++ ) {
                cin >> w;
                if( course.count( w ) ) cnt++;
            }
            if( r <= cnt ) ans++;
        }
        cout << ( ans == m  ? "yes\n" : "no\n" );
    }

    return 0;
}
