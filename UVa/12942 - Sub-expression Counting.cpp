#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second

#define MAX  400100

#define INF  ( 1<<29 )

typedef long long ll;

using namespace std;

int k, phi[ MAX ];
string t, p;

string modifyStraing( string a ) {

    int szA = int( a.size( ) );
    string b = "";
    for( int i = 0; i < szA; i++ ) {
        if( a[ i ] == '(' || a[ i ] == ')' )
            b += a[ i ];
        else if( a[ i ] == '+' || a[ i ] == '*' || a[ i ] == '-' || a[ i ] == '/' )
            b += '+';
        else if( ( int( b.size( ) ) && b[ int( b.size( ) )-1 ] != 'a' ) || int( b.size( ) ) == 0 )
            b += 'a';
    }
    return b;
    
}

int kmp( ) {
    
    int ans = 0;
    
    t = modifyStraing( t );
    p = modifyStraing( p );
    
    phi[ 0 ] = k = -1;
    for( int i = 1; i <= int( p.size( ) ); i++ ) {
        while( k > -1 && p[ k ] != p[ i-1 ] ) k = phi[ k ];
        phi[ i ] = ++k;
    }
    
    k = 0;
    for( int i = 0; i < int( t.size( ) ); i++ ) {
        while( k > -1 && p[ k ] != t[ i ] ) k = phi[ k ];
        ++k;
        if( k == int( p.size( ) ) ) ans++, k = phi[ k ];
    }
    
    return ans;
    
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> p >> t ) cout << kmp( ) << "\n";
    
    return 0;
    
}
