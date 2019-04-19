#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second

#define MAX 110

#define INF  INT_MAX/120

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll N, B, C;

ll calc( ll x ) {
    return N*N - ( 4*x*x - ( C ? 4*x-1 : 0 ) );
}

bool can( ll x ) {
    return calc( x ) >= B;
}

void printAnswer( ll x, ll y ) {
    cout << x << " " << y << "\n";
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> N >> B ) {
        C = N&1;
        ll lo = 1, hi = (N+C)/2, mi;
        while( lo <= hi ) {
            mi = ( lo+hi )/2;
            if( can( mi ) ) lo = mi+1;
            else            hi = mi-1;
        }
        ll a = calc( lo ), b = a+2*lo-C;
        if( a < B && B <= b )
            printAnswer( (N+C)/2-lo+1, ( (N+C)/2-lo+1 )+( B-a-1 ) );
        else {
            a = b; b = b+2*lo-C-1;
            if( a < B && B <= b )
                printAnswer( ( (N+C)/2-lo+1 )+( B-a-1 )+1, ( N+1 )-( (N+C)/2-lo+1 ) );
            else {
                a = b; b = b+2*lo-C-1;
                if( a < B && B <= b )
                    printAnswer( ( N+1 )-( (N+C)/2-lo+1 ), ( ( N+1 )-( (N+C)/2-lo+1 ) )-( B-a ) );
                else {
                    a = b; b = b+2*lo-C-1;
                    printAnswer( ( ( N+1 )-( (N+C)/2-lo+1 ) )-( B-a ), (N+C)/2-lo+1 );
                }
            }
        }
    }
    
    return 0;
    
}