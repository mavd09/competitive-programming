#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second

#define MAX  50

#define INF  ( 1<<29 )

typedef long long ll;

using namespace std;

int n;
string d;

int cmp( string a, string b ) {
    
    int szA = int( a.size( ) ), szB = int( b.size( ) );
    if( szA != szB ) return szA-szB;
    
    for( int i = 0; i < szA; i++ ) {
        int curA = a[ i ]-'0', curB = b[ i ]-'0';
        if( curA > curB ) return 1;
        if( curA < curB ) return -1;
    }
    
    return 0;
    
}

string add( string cur ) {
    
    int sz = int( cur.size( ) ), carry = 1;
    for( int i = (sz+1)/2-1; i >= 0 && carry; i-- ) {
        if( cur[ i ] == '9' ) cur[ i ] = cur[ sz-i-1 ] = '0';
        else cur[ i ] = cur[ sz-i-1 ] = cur[ i ]+1, carry = 0;
    }
    if( carry ) return "1"+string( sz-1, '0' )+"1";
    return cur;
    
}


string nextPalindromic( string cur ) {
    
    int sz = int( cur.size( ) );
    string ret( sz, '0' );
    
    for( int i = 0; i < (sz+1)/2; i++ ) ret[ i ] = ret[ sz-i-1 ] = cur[ i ];
    
    while( cmp( ret, cur ) <= 0 ) ret = add( ret );
    
    return ret;
    
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> n >> d )
        while( n-- )
            cout << ( d = nextPalindromic( d ) ) << "\n";
    
    return 0;
    
}
