#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         50020
#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         ( INT_MAX )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
int p[ MAX ], l[ MAX ];
map< string, int > lst;
string msg;

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> n ) {
        memset( p, -1, sizeof( p ) );
        memset( l, 0, sizeof( l ) );
        lst.clear( );
        cin.ignore( );
        int best = 1;
        for( int i = 1; i <= n; i++ ) {
            getline( cin, msg );
            stringstream ss( msg );
            string handle, cur;
            ss >> handle;
            handle = handle.substr( 0, int( handle.size( ) )-1 );
            l[ i ] = 1;
            while( ss >> cur ) {
                if( cur[ 0 ] != '@' || cur == handle ) continue;
                if( lst.count( cur ) ) {
                    int pos = lst[ cur ];
                    if( l[ i ] < l[ pos ]+1 ) {
                        l[ i ] = l[ pos ]+1;
                        p[ i ] = pos;
                    }
                }
            }
            if( l[ best ] < l[ i ] ) best = i;
            if( l[ lst[ handle ] ] < l[ i ] ) lst[ handle ] = i;
        }
        vector< int > ans;
        for( int i = best; i != -1; i = p[ i ] ) ans.PB( i );
        cout << l[ best ] << "\n";
        for( int i = l[ best ]-1; i >= 0; i-- ) {
            if( i+1 != l[ best ] ) cout << " ";
            cout << ans[ i ];
        }
        cout << "\n";
    }
    
    return 0;
    
}
