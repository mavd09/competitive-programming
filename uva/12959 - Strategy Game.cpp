#include <bits/stdc++.h>

#define PB  push_back
#define MP  make_pair
#define FI  first
#define SE  second

#define MAX 1000

using namespace std;

int j, r;
int points[ MAX ];

int main( ) {

    while( cin >> j >> r ) {
        memset( points, 0, sizeof( points ) );
        for( int i = 0; i < r; i++ ) {
            for( int k = 0, cur; k < j; k++ ) {
                cin >> cur;
                points[ k ] += cur;
            }
        }
        int ans1 = -1, ans2 = -1;
        for( int i = 0; i < j; i++ ) {
            if( points[ i ] >= ans1 ) {
                ans1 = points[ i ];
                ans2 = i;
            }
        }
        cout << ans2+1 << "\n";
    }

    return 0;
}
