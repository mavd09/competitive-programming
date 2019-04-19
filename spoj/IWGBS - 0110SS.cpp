#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second

#define MAX  400100
#define MAX_LEN  10100
#define MAXN 10
#define MAXM 20
#define MAXK 1010

#define INF  ( 1<<29 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
string dp[ MAX_LEN ][ 2 ];

string add( string a, string b ) {
    
    int sz = max( int( a.size( ) ), int( b.size( ) ) );
    if( int( a.size( ) ) < sz ) a = string( sz-int( a.size( ) ), '0' )+a;
    if( int( b.size( ) ) < sz ) b = string( sz-int( b.size( ) ), '0' )+b;
    
    string ans = "";
    int carry = 0;
    
    for( int i = sz-1; i >= 0; i-- ) {
        ans += char( ( ( a[ i ]-'0' + b[ i ]-'0'+carry )%10 )+'0' );
        carry = ( a[ i ]-'0' + b[ i ]-'0'+carry )/10;
    }
    
    if( carry ) ans += char( carry+'0' );
    reverse( ans.begin( ), ans.end( ) );
    
    return ans;
    
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    dp[ 1 ][ 0 ] = "1";
    dp[ 1 ][ 1 ] = "1";
    
    for( int i = 2; i < MAX_LEN; i++ ) {
        dp[ i ][ 0 ] = dp[ i-1 ][ 1 ];
        dp[ i ][ 1 ] = add( dp[ i-1 ][ 0 ], dp[ i-1 ][ 1 ] );
    }
    
    cin >> n;
    cout << add( dp[ n ][ 0 ], dp[ n ][ 1 ] ) << "\n";
    
    return 0;
    
}
