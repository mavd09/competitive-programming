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

string convertToString( int n ) {
    string ret = "";
    while( n ) {
        ret += ( n%10 + '0' );
        n /= 10;
    }
    reverse( ret.begin( ), ret.end( ) );
    return ret;
}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    if( FILE&1 ) freopen( "input" , "r", stdin  );
    if( FILE&2 ) freopen( "output", "w", stdout );

    string x;
    while( ( cin >> x ) && ( x != "END" ) ) {
        string lst = "";
        int ans = 0;
        while( lst != x ) {
            ans++;
            lst = x;
            x   = convertToString( int( x.size( ) ) );
        }
        cout << ans << "\n";
    }

    return 0;
}
