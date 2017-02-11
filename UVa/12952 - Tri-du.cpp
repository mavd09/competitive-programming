#include <bits/stdc++.h>

#define PB  push_back
#define MP  make_pair
#define FI  first
#define SE  second

using namespace std;

int n, m;

int main( ) {

    while( cin >> n >> m ) {
        if( n == m ) cout << n << "\n";
        else cout << max( n, m ) << "\n";
    }

    return 0;
}
