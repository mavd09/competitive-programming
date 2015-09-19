#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#include <math.h>
#include <iomanip>
#include <algorithm>
#include <limits.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second

#define MAX  2500

#define INF  ( 1<<29 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
string s;
bool valid[ MAX ];
int dp1[ MAX ][ MAX ], dp2[ MAX ][ MAX ];

void go( int i, int j ) {
    
    int& ans1 = dp1[ i ][ j ];
    int& ans2 = dp2[ i ][ j ];
    
    if( i == j ) {
        ans1 = valid[ i ];
        ans2 = 1;
        return ;
    }
    if( i > j ) {
        ans1 = 0;
        ans2 = 0;
        return ;
    }
    if( ans1 != -1 ) return ;
    
    ans1 = ans2 = 0;
    
    go( i+1, j );
    if( dp1[ i+1 ][ j ] > ans1 ) {
        ans1 = dp1[ i+1 ][ j ];
        ans2 = dp2[ i+1 ][ j ];
    }
    else if( dp1[ i+1 ][ j ] == ans1 ) {
        ans2 = max( ans2, dp2[ i+1 ][ j ] );
    }
    
    go( i, j-1 );
    if( dp1[ i ][ j-1 ] > ans1 ) {
        ans1 = dp1[ i ][ j-1 ];
        ans2 = dp2[ i ][ j-1 ];
    }
    else if( dp1[ i ][ j-1 ] == ans1 ) {
        ans2 = max( ans2, dp2[ i ][ j-1 ] );
    }
    
    if( s[ i ] == s[ j ] ) {
        go( i+1, j-1 );
        if( dp1[ i+1 ][ j-1 ]+valid[ i ]+valid[ j ]  > ans1 ) {
            ans1 = dp1[ i+1 ][ j-1 ]+valid[ i ]+valid[ j ];
            ans2 = dp2[ i+1 ][ j-1 ]+2;
        }
        else if( dp1[ i+1 ][ j-1 ]+valid[ i ]+valid[ j ] == ans1 ) {
            ans2 = max( ans2, dp2[ i+1 ][ j-1 ]+2 );
        }
    }
    
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> s >> n ) {
        memset( valid, false, sizeof( valid ) );
        memset( dp1, -1, sizeof( dp1 ) );
        memset( dp2, -1, sizeof( dp2 ) );
        for( int i = 0, pos; i < n; i++ ) {
            cin >> pos;
            valid[ pos-1 ] = true;
        }
        int sz = int( s.size( ) );
        go( 0, sz-1 );
        cout << dp2[ 0 ][ sz-1 ] << "\n";
    }
    
    return 0;
    
}