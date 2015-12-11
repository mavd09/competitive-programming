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

typedef complex< ll > pt;

#define x(P)        real(P)
#define y(P)        imag(P)
#define cross(A,B)  y(conj(A)*(B))
#define dot(A,B)    x(conj(A)*(B))

const int RP = 3;

istream& operator >> ( istream& in, pt& p ) {
    ll x, y;
    in >> x >> y;
    p = pt( x, y );
    return in;
}

ll getArea( vector< pt >& P, vector< ll >& acc, ll& totalArea, int i, int j ) {
    ll area = acc[ j-1 ]+cross( P[ j ], P[ i ] )-acc[ i-1 ];
    return max( area, totalArea-area );
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    int n;
    
    while( cin >> n ) {
        vector< pt > P( RP*n );
        for( int i = 0; i < n; i++ ) {
            cin >> P[ i ];
            for( int j = 1; j < RP; j++ )
                P[ n*j+i ] = P[ i ];
        }
        vector< ll > acc( RP*n, 0 );
        for( int i = 0; i+1 < RP*n; i++ ) {
            if( i ) acc[ i ] = acc[ i-1 ];
            acc[ i ] += cross( P[ i ], P[ i+1 ] );
        }
        ll totalArea = abs( acc[ n-1 ] ), ans = 0;
        for( int i = n, j = n; i < 2*n; i++ ) {
            ll curArea, lastArea = getArea( P, acc, totalArea, i, j );
            while( ( curArea = getArea( P, acc, totalArea, i, j+1 ) ) <= lastArea ) {
                j++;
                lastArea = curArea;
            }
            ans = max( ans, getArea( P, acc, totalArea, i, j ) );
        }
        cout << ans << " " << totalArea-ans << "\n";
    }
    
    return 0;
}