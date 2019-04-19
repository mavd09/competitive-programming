#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second
#define Edge pair< int, int >

#define MAXN 50
#define MAXL 30

#define INF  ( 1<<29 )

typedef long long ll;

using namespace std;

int nTest;
string a, b, c, d;

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    cin >> nTest;
    while( nTest-- ) {
        cin >> a >> b;
        c = d = string( 31, '0' );
        cout << a << " " << b << "\n";
        while( true ) {
            for( int i = 0; i < 31; i++ ) {
                c[ i ] = ( a[ i ] == b[ i ] ? '0' : '1' );
                d[ i ] = ( ( a[ i ] == b[ i ] && a[ i ] == '1' ) ? '1' : '0' );
            }
            a = c;
            b = d;
            cout << a << " ";
            if( b[ 0 ] == '1' ) {
                cout << "overflow\n";
                break;
            }
            else {
                bool flag = true;
                for( int i = 0; i < 30; i++ ) {
                    b [ i ] = b[ i+1 ];
                    flag &= ( b[ i ] == '0' );
                }
                b[ 30 ] = '0';
                cout << b << "\n";
                if( flag ) break;
            }
        }
        if( nTest ) cout << "\n";
    }

    return 0;

}
