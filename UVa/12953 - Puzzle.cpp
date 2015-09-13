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

int l, c, cnt;
string b[ MAX ][ MAX ];
int vals[ MAX ][ MAX ], sumRow[ MAX ], sumCol[ MAX ];
set< pair< string, int > > ans;

void initialize( ) {
    for( int i = 0; i < MAX; i++ )
        for( int j = 0; j < MAX; j++ )
            vals[ i ][ j ] = INF;
    ans.clear( );
    cnt = 0;
}

void update( string x, int y ) {
    for( int i = 0; i < l; i++ ) {
        for( int j = 0; j < c; j++ ) {
            if( b[ i ][ j ] == x ) {
                vals[ i ][ j ] = y;
                cnt++;
            }
        }
    }
    ans.insert( MP( x, y ) );
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> l >> c ) {
        initialize( );
        for( int i = 0; i < l; i++ ) {
            for( int j = 0; j <= c; j++ ) {
                if( j < c ) cin >> b[ i ][ j ];
                else        cin >> sumRow[ i ];
            }
        }
        for( int j = 0; j < c; j++ ) cin >> sumCol[ j ];
        while( cnt < l*c ) {
            bool can;
            string last;
            int cant, sum;
            for( int i = 0; i < l; i++ ) {
                can = true;
                last = "";
                sum = cant = 0;
                for( int j = 0; j < c; j++ ) {
                    if( vals[ i ][ j ] != INF ) {
                        sum += vals[ i ][ j ];
                        continue;
                    }
                    if( last == "" ) last = b[ i ][ j ];
                    else if( b[ i ][ j ] != last ) {
                        can = false;
                        break;
                    }
                    cant++;
                }
                if( can && cant ) update( last, (sumRow[ i ]-sum)/cant );
            }
            for( int j = 0; j < c; j++ ) {
                can = true;
                last = "";
                sum = cant = 0;
                for( int i = 0; i < l; i++ ) {
                    if( vals[ i ][ j ] != INF ) {
                        sum += vals[ i ][ j ];
                        continue;
                    }
                    if( last == "" ) last = b[ i ][ j ];
                    else if( b[ i ][ j ] != last ) {
                        can = false;
                        break;
                    }
                    cant++;
                }
                if( can && cant ) update( last, (sumCol[ j ]-sum)/cant );
            }
        }
        for( set< pair< string, int > >::iterator it = ans.begin( ); it != ans.end( ); it++ )
            cout << (*it).FI << " " << (*it).SE << "\n";
    }
    
    return 0;
    
}