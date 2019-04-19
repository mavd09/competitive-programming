#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         1000

#define MAX_PRIMES  1245

#define INF         ( INT_MAX )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

bool go( string& u, vector< int >& used, int i, bool flag, ll ans ) {
    if( i == int( u.size( ) ) ) {
        cout << ans << "\n";
        return true;
    }
    if( flag ) {
        for( int d = 9; d >= 0; d-- ) {
            if( used[ d ]+1 <= 2 ) {
                used[ d ]++;
                if( go( u, used, i+1, flag, ans*10LL+d ) )
                    return true;
                used[ d ]--;
            }
        }
    }
    else {
        for( int d = ( u[ i ]-'0' ), j = 0; d >= 0; d--, j++ ) {
            if( used[ d ]+1 <= 2 ) {
                used[ d ]++;
                if( go( u, used, i+1, j != 0, ans*10LL+d ) )
                    return true;
                used[ d ]--;
            }
        }
    }
    return false;
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    string u;
    while( cin >> u ) {
        vector< int > used( 10, 0 );
        go( u, used, 0, false, 0 );
    }
    
    return 0;
}