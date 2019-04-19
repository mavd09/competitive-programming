#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second

#define MAX_R   5010
#define MAX   10010

#define INF  ( 1<<29 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Line {
    
    int a_1;
    int b_1, b_2;
    bool state;
    
    Line( ) { }
    Line( int a_1, int b_1, int b_2, bool state ) : a_1( a_1 ), b_1( b_1 ), b_2( b_2 ), state( state ) { }
    
    bool operator < ( const Line& o )const {
        return a_1 < o.a_1;
    }
    
};

int nRectangles;
vector< Line > lines[ 2 ];
int used[ 2 ][ 2*MAX ];

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    cin >> nRectangles;
    for( int i = 0, xLeft, yLeft, xRight, yRight; i < nRectangles; i++ ) {
        cin >> xLeft >> yLeft >> xRight >> yRight;
        
        lines[ 0 ].PB( Line( xLeft , yLeft+MAX, yRight+MAX, true  ) );
        lines[ 0 ].PB( Line( xRight, yLeft+MAX, yRight+MAX, false ) );
        
        lines[ 1 ].PB( Line( yLeft , xLeft+MAX, xRight+MAX, true  ) );
        lines[ 1 ].PB( Line( yRight, xLeft+MAX, xRight+MAX, false ) );
    }
    
    sort( lines[ 0 ].begin( ), lines[ 0 ].end( ) );
    sort( lines[ 1 ].begin( ), lines[ 1 ].end( ) );
    
    int ans = 0;
    
    for( int i = 0; i < 2*nRectangles; i++ ) {
        int cur = 0;
        for( int j = lines[ 0 ][ i ].b_1; j < lines[ 0 ][ i ].b_2; j++ ) {
            if(  lines[ 0 ][ i ].state ) used[ 0 ][ j ]++;
            if( !lines[ 0 ][ i ].state ) used[ 0 ][ j ]--, cur += !used[ 0 ][ j ];
        }
        ans += 2*cur;
        cur = 0;
        for( int j = lines[ 1 ][ i ].b_1; j < lines[ 1 ][ i ].b_2; j++ ) {
            if(  lines[ 1 ][ i ].state ) used[ 1 ][ j ]++;
            if( !lines[ 1 ][ i ].state ) used[ 1 ][ j ]--, cur += !used[ 1 ][ j ];
        }
        ans += 2*cur;
    }
    
    cout << ans << "\n";
    
    return 0;
    
}