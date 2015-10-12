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

int nQueries;
string str;
int cnt[ MAX ];

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    if( FILE&1 ) freopen( "input" , "r", stdin  );
    if( FILE&2 ) freopen( "output", "w", stdout );

    for( int tc = 1; ( cin >> str ); tc++ ) {
        str = "x"+str;
        int sz = int( str.size( ) );
        for( int i = 1; i < sz; i++ ) cnt[ i ] = cnt[ i-1 ]+( str[ i ] == '0' );
        cin >> nQueries;
        cout << "Case " << tc << ":\n";
        for( int i = 1, f, t; i <= nQueries; i++ ) {
            cin >> f >> t;
            f++; t++;
            if( f > t ) swap( f, t );
            int cur = cnt[ t ]-cnt[ f-1 ];
            cout << ( ( cur == t-f+1 || cur == 0 ) ? "Yes\n" : "No\n" );
        }
    }

    return 0;
}
