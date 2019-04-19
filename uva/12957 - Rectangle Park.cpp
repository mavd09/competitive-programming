#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second

#define MAX  3500

#define INF  ( 1<<29 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
pair< int, int > p[ MAX ];

bool cmp( const pair< int, int >& a, const pair< int, int >& b ) {
    return a.FI < b.FI;
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> n ) {
        for( int i = 0; i < n; i++ ) cin >> p[ i ].FI >> p[ i ].SE;
        sort( p, p+n, cmp );
        int ans = 0;
        for( int i = 0; i < n; i++ ) {
            int mn = INF, mx = -INF;
            for( int j = i+1; j < n; j++ ) {
                if( p[ i ].SE > p[ j ].SE && p[ j ].SE > mx ) {
                    ans++;
                    mx = p[ j ].SE;
                }
                if( p[ i ].SE < p[ j ].SE && p[ j ].SE < mn ) {
                    ans++;
                    mn = p[ j ].SE;
                }
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
    
}