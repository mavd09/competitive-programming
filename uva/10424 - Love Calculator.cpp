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

string name1, name2;
int p1, p2, sz;

int get( int cur ) {

    while( cur >= 10 ) {
        int tmp = 0;
        while( cur ) {
            tmp += ( cur%10 );
            cur /= 10;
        }
        cur = tmp;
    }

    return cur;

}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    if( FILE&1 ) freopen( "input" , "r", stdin  );
    if( FILE&2 ) freopen( "output", "w", stdout );

    while( getline( cin, name1 ) && getline( cin, name2 ) ) {
        sz = int( name1.size( ) );
        p1 = 0;
        for( int i = 0; i < sz; i++ )
            if( ( 'a' <= name1[ i ] && name1[ i ] <= 'z' ) || ( 'A' <= name1[ i ] && name1[ i ] <= 'Z' ) )
                p1 += tolower( name1[ i ] )-'a'+1;
        p1 = get( p1 );
        sz = int( name2.size( ) );
        p2 = 0;
        for( int i = 0; i < sz; i++ )
            if( ( 'a' <= name2[ i ] && name2[ i ] <= 'z' ) || ( 'A' <= name2[ i ] && name2[ i ] <= 'Z' ) )
                p2 += tolower( name2[ i ] )-'a'+1;
        p2 = get( p2 );
        double ans = ( min( p1, p2 )*1.0 )/( max( p1, p2 )*1.0 )*100.0;
        cout << fixed << setprecision( 2 ) << ans << " %\n";
    }

    return 0;
}
