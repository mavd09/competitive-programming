#include <bits/stdc++.h>

#define FILE    0

#define MP      make_pair
#define PB      push_back
#define FI      first
#define SE      second

#define MOD1    256
#define MOD2    100

#define INF     ( 1<<29 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const char id[ ] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    if( FILE&1 ) freopen( "input" , "r", stdin  );
    if( FILE&2 ) freopen( "output", "w", stdout );

    int nTest;
    cin >> nTest;
    for( int tc = 1, p; nTest--; tc++ ) {
        p = 0;
        string str;
        cin >> str;
        vector< int > ans( 100, 0 );
        for( auto& c: str ) {
            if( c == '>' ) p = ( p+1+MOD2 )%MOD2;
            if( c == '<' ) p = ( p-1+MOD2 )%MOD2;
            if( c == '+' ) ans[ p ] = ( ans[ p ]+1+MOD1 )%MOD1;
            if( c == '-' ) ans[ p ] = ( ans[ p ]-1+MOD1 )%MOD1;
        }
        cout << "Case " << tc << ":";
        for( auto& a : ans ) cout << " " << id[ (a/16)%16 ] << id[ a%16 ];
        cout << "\n";
    }

    return 0;
}
